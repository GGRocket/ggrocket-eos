
#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
#include <eosiolib/asset.hpp>

using namespace eosio;
using std::string;

class ggmarket: public contract {
public: 
    ggmarket (account_name self) : contract (self) {}

    // @abi action
    void newitem (  const string  item_name,
                    const string  game);

    // @abi action
    void newlisting (   const uint64_t      item_id, 
                        const account_name  seller,
                        const asset         list_price );

    // @abi action
    void neworder   (   const uint64_t      item_id,
                        const account_name  seller,
                        const account_name  buyer,
                        const asset         paid_price);

    // @abi action  
    void additem    (   const account_name  owner,
                        const uint64_t      item_id);

private: 
  
    const uint8_t   OPENED      = 1;
    const uint8_t   PAID        = 2;
    const uint8_t   CANCELLED   = 3;
   
    // @abi table items
    struct item {
        uint64_t    item_id;
        string      item_name;
        string      game;
       
        uint64_t    primary_key() const { return item_id; }
    };

    typedef eosio::multi_index<N(items), item> item_table;

    // @abi table listings
    struct listing {
        uint64_t        listing_id;
        account_name    seller;
        uint64_t        item_id;
        asset           list_price;

        uint64_t    primary_key() const { return listing_id; }
    };

    typedef eosio::multi_index<N(listings), listing> listing_table;

    // @abi table orders
    struct order {
        uint64_t            order_id;
        account_name        seller;
        account_name        buyer;
        asset               paid_price;
        uint8_t             status;

        uint64_t primary_key()  const { return order_id; }
    };

    typedef eosio::multi_index<N(orders), order> order_table;

    // TODO: transition to NFT token standard
    // @abi table inventories
    struct inventory {
        account_name        owner;
        vector<uint64_t>    items;

        uint64_t    primary_key() const { return owner; }        
    };

    typedef eosio::multi_index<N(inventories), inventory> inventory_table;

};

EOSIO_ABI(ggmarket, (newitem)(newlisting)(neworder)(additem))