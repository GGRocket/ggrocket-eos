#include "ggmarket.hpp"

void ggmarket::newitem ( const string   item_name,
                         const string   game) {

    item_table i_t (_self, _self);
    i_t.emplace (_self, [&](auto &i) {
        i.item_id   = i_t.available_primary_key();
        i.item_name = item_name;
        i.game      = game;
    });            
}

void ggmarket::newlisting ( const uint64_t      item_id,
                            const account_name  seller,
                            const asset         list_price ) {

    listing_table l_t (_self, _self);
    l_t.emplace (_self, [&](auto &l) {
        l.listing_id    = l_t.available_primary_key();
        l.item_id       = item_id;
        l.seller        = seller;
        l.list_price    = list_price;
    });
}


void ggmarket::neworder (   const uint64_t  item_id,
                            const account_name  seller,
                            const account_name  buyer,
                            const asset         paid_price ) {
    order_table o_t (_self, _self);
    o_t.emplace (_self, [&](auto &o) {
        o.order_id  = o_t.available_primary_key();
        o.seller    = seller;
        o.buyer     = buyer;
        o.status    = OPENED;
    });
}


void ggmarket::additem (    const account_name  owner,
                            const uint64_t      item_id) {

    inventory_table i_t (_self, _self);
    auto i_itr = i_t.find (owner);

    if (i_itr == i_t.end()) {
        i_t.emplace (_self, [&](auto &i) {
            i.items.push_back (item_id);
        });
    } else {
        i_t.modify (i_itr, _self, [&](auto &i) {
            i.owner = owner;
            i.items.push_back(item_id);
        });
    }
    
}