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

wif = '5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi'
pubkey = 'EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn'

eos.transaction(tr => {
  tr.newaccount({
    creator: 'ggrobot',
    name: 'myaccount',
    owner: pubkey,
    active: pubkey
  })
})