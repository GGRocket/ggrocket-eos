
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>
#include <eosiolib/currency.hpp>


using namespace eosio;
using std::string;

class ggrobot: public contract {
public: 
    ggrobot (account_name self) : contract (self) {}

    // @abi action
    void newpurrecord (const uint64_t      purchase_id,
                                const account_name  recorder,
                                const account_name  eosgamebuyer,
                                const string        gggamebuyer,
                                //const string        battlenetuser,
                                const string        source,
                                const string        game,
                                const string        purchase_name,
                                const asset         price,
                                const uint32_t      purchase_date) ;

    // @abi action
    void newidentity (  const string        name,
                        const string        email_address );

    // // @abi action
    void buyidentity (  const account_name  gamebuyer, 
                        const account_name  databuyer);

    // @abi action
    void reveal ( const account_name    gamebuyer,
                  const uint64_t  identity);

    void apply(const account_name contract, const account_name act);

    void transferReceived(const currency::transfer &transfer, const account_name code);


private: 
  
    // @abi table balances i64
    struct balance {
        asset funds;
        uint64_t primary_key() const { return funds.symbol; }
    };

    typedef eosio::multi_index<N(balances), balance> balance_table;

    // @abi table purrecords
    struct purrecord {
        uint64_t        purrecord_id;   // increment
        uint64_t        purchase_id;    // comes from game (?)
        account_name    gamebuyer;
        string          source;
        string          game;
        string          purchase_name;
        asset           price;
        uint32_t        purchase_date;
       
        uint64_t    primary_key() const { return purrecord_id; }
    };

    typedef eosio::multi_index<N(purrecords), purrecord> purrecord_table;

    // @abi table identities
    struct identity {
        uint64_t        identity_hash;
        string          name;
        string          email_address;

        uint64_t    primary_key() const { return identity_hash; }
    };

    typedef eosio::multi_index<N(identities), identity> identity_table;

    // @abi table ridentities
    struct ridentity {
        uint64_t        revidentity_id;
        account_name    gamebuyer;
        uint64_t        identity;

        uint64_t    primary_key () const { return revidentity_id; }
        account_name    bygamebuyer() const { return gamebuyer; }
    };

    typedef eosio::multi_index<N(ridentities), ridentity,
        indexed_by<N(bygamebuyer),
        const_mem_fun<ridentity, account_name, &ridentity::bygamebuyer>>>
     ridentity_table;

    // @abi table buyers 
    struct databuyer {
        account_name            databuyer_id;
        vector<account_name>    gamebuyers;
        vector<uint64_t>        identities;

        account_name primary_key () const { return databuyer_id; }
    };

    typedef eosio::multi_index<N(databuyers), databuyer> databuyer_table;

    uint64_t hashidentity   (const string name,
                             const string email_address)
    {
        std::string s = string {name + email_address};
        std::hash<std::string> hash_fn;
        size_t hash = hash_fn(s);
        return hash;
    }

};
