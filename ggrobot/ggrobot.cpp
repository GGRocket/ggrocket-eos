#include "ggrobot.hpp"

void ggrobot::newpurrecord  (const uint64_t   purchase_id,
                        const account_name  gamebuyer,
                        const string        source,
                        const string        game,
                        const string        purchase_name,
                        const asset         price,
                        uint32_t            purchase_date) {

    purrecord_table pr_t (_self, _self);
    pr_t.emplace (_self, [&](auto &p) {
        p.purrecord_id  = pr_t.available_primary_key();
        p.purchase_id   = purchase_id;
        p.gamebuyer     = gamebuyer;
        p.source        = source;
        p.game          = game;
        p.purchase_name = purchase_name;
        p.price         = price;
        p.purchase_date = purchase_date;
    });
}

void ggrobot::newidentity ( const string    name,
                            const string    email_address ) {

    identity_table i_t (_self, _self);
    i_t.emplace (_self, [&](auto& i) {
        i.identity_hash = hashidentity (name, email_address);
        i.name          = name;
        i.email_address = email_address;
    });

}

void ggrobot::reveal ( const account_name gamebuyer,
                        const uint64_t  identity) {
    ridentity_table r_t (_self, _self);
    r_t.emplace (_self, [&](auto &r) {
        r.revidentity_id    = r_t.available_primary_key();
        r.gamebuyer         = gamebuyer;
        r.identity          = identity;
    });
}

void ggrobot::buyidentity ( const account_name gamebuyer, 
                            const account_name databuyer ) {

    ridentity_table r_t (_self, _self);
    auto ri_index = r_t.get_index< N(bygamebuyer)>();
   
    auto ri_itr = ri_index.find (gamebuyer);
    print ("RI - identity : ", name{ri_itr->identity}, "\n");

    eosio_assert(ri_itr != ri_index.end(), "Invalid game buyer request.");
    
    databuyer_table db_t (_self, _self);
    auto db_itr = db_t.find (databuyer);
    if (db_itr == db_t.end()) {
        db_t.emplace (_self, [&](auto &db) {
            db.databuyer_id = databuyer;
            db.gamebuyers.push_back (ri_itr->gamebuyer);
            db.identities.push_back (ri_itr->identity);
        });
    } else {
        db_t.modify (db_itr, _self, [&](auto &db) {
            db.databuyer_id = databuyer;
            db.gamebuyers.push_back (ri_itr->gamebuyer);
            db.identities.push_back (ri_itr->identity);
        });
    }

    balance_table balances(_self, databuyer);
    auto b_itr = balances.find(string_to_symbol(2, "GGR"));
    eosio_assert (b_itr != balances.end(), "No balance found.");
    
    print(name{databuyer}, " has ", b_itr->funds, " available\n");
    asset purchase_amount = asset {1, string_to_symbol(2, "GGR")};
    eosio_assert (b_itr->funds > purchase_amount, "User does not have enough funds.");

    action{
        permission_level{_self, N(active)},
        N(ggtoken),
        N(transfer),
        currency::transfer{
            .from=_self, .to=gamebuyer, .quantity=purchase_amount, .memo=""}
    }.send();

    balances.modify (b_itr, _self, [&](auto &b) {
        b.funds -= purchase_amount;
    });
}

void ggrobot::apply(const account_name contract, const account_name act)
{

    if (act == N(transfer))
    {
        transferReceived(unpack_action_data<currency::transfer>(), contract);
        return;
    }

    auto &thiscontract = *this;

    switch (act)
    {
        EOSIO_API(ggrobot, (newpurrecord)(newidentity)(reveal)(buyidentity))
    };
}



void ggrobot::transferReceived(const currency::transfer &transfer, const account_name code)
{
    if (transfer.to != _self)
    {
        return;
    }

    print("Account Name     :   ", name{code}, "\n");
    print("From             :   ", name{transfer.from}, "\n");
    print("To               :   ", name{transfer.to}, "\n");
    print("Asset            :   ", transfer.quantity, "\n");
    print("Received Amount  :   ", transfer.quantity.amount, "\n");
    print("Received Symbol  :   ", transfer.quantity.symbol, "\n");
    print("Memo             :   ", transfer.memo, "\n");
    

    balance_table balances(_self, transfer.from);
    asset new_balance;
    auto it = balances.find(transfer.quantity.symbol);
    if(it != balances.end())
        balances.modify(it, transfer.from, [&](auto& bal){
            // Assumption: total currency issued by eosio.token will not overflow asset
            bal.funds += transfer.quantity;
            new_balance = bal.funds;
        });
    else
        balances.emplace(transfer.from, [&](auto& bal){
            bal.funds = transfer.quantity;
            new_balance = transfer.quantity;
        });

    print(name{transfer.from}, " deposited:       ", transfer.quantity, "\n");
    print(name{transfer.from}, " funds available: ", new_balance);
   
}


extern "C"
{
    //using namespace bay;
    using namespace eosio;

    void apply(uint64_t receiver, uint64_t code, uint64_t action)
    {
        auto self = receiver;
        ggrobot contract(self);
        contract.apply(code, action);
        eosio_exit(0);
    }
}
