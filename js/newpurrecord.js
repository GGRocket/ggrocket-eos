Eos = require('eosjs')

chain = {
    main: 'aca376f206b8fc25a6ed44dbdc66547c36c6c33e3a119ffbeaef943642f0e906', // main network
    jungle: '038f4b0fc8ff18a4f0842a8f0564611f6e96e8535901dd45e43ac8691a1c4dca', // jungle testnet
    sys: 'cf057bbfb72640471fd910bcb67639c22df9f92470936cddc1ade0e2f2e7dc4f' // local developer
}

eos = Eos({
    keyProvider: '5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi',// private key
    httpEndpoint: 'http://127.0.0.1:8888',
    chainId: chain.sys,
});

eos.transaction(
    {
        // ...headers,
        // context_free_actions: [],
        actions: [
            {
                account: 'ggrobot',
                name: 'newpurrecord',
                authorization: [{
                    actor: 'ggrobot',
                    permission: 'active'
                }],
                data: {
                    purchase_id: 987678,
                    gamebuyer: 'gamebuyer1',
                    source: 'Source 763',
                    game: 'World of Warcraft',
                    purchase_name: 'New Armor and Potion Kit',
                    price: '2.5000 GGR',
                    purchase_date: 564323
                }
            }
        ]
    }
    // config -- example: {broadcast: false, sign: true}
)