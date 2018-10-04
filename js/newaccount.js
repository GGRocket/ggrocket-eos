const eosjs = require('eosjs');
const fetch = require('node-fetch');                            // node only; not needed in browsers
const { TextDecoder, TextEncoder } = require('text-encoding');  // node, IE11 and IE Edge Browsers

const defaultPrivateKey = "5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi"; // useraaaaaaaa
const signatureProvider = new eosjs.SignatureProvider([defaultPrivateKey]);

const rpc = new eosjs.Rpc.JsonRpc('http://127.0.0.1:8888', { fetch });
const api = new eosjs.Api({ rpc, signatureProvider, textDecoder: new TextDecoder, textEncoder: new TextEncoder });


const result = await api.transact({
  actions: [{
    account: 'eosio',
    name: 'newaccount',
    authorization: [{
      actor: 'useraaaaaaaa',
      permission: 'active',
    }],
    data: {
      creator: 'useraaaaaaaa',
      name: 'mynewaccount',
      owner: {
        threshold: 1,
        keys: [{
          key: 'PUB_R1_6FPFZqw5ahYrR9jD96yDbbDNTdKtNqRbze6oTDLntrsANgQKZu',
          weight: 1
        }],
        accounts: [],
        waits: []
      },
      active: {
        threshold: 1,
        keys: [{
          key: 'PUB_R1_6FPFZqw5ahYrR9jD96yDbbDNTdKtNqRbze6oTDLntrsANgQKZu',
          weight: 1
        }],
        accounts: [],
        waits: []
      },
    },
  },
  {
    account: 'eosio',
    name: 'buyrambytes',
    authorization: [{
      actor: 'useraaaaaaaa',
      permission: 'active',
    }],
    data: {
      payer: 'useraaaaaaaa',
      receiver: 'mynewaccount',
      bytes: 8192,
    },
  },
  {
    account: 'eosio',
    name: 'delegatebw',
    authorization: [{
      actor: 'useraaaaaaaa',
      permission: 'active',
    }],
    data: {
      from: 'useraaaaaaaa',
      receiver: 'mynewaccount',
      stake_net_quantity: '1.0000 SYS',
      stake_cpu_quantity: '1.0000 SYS',
      transfer: false,
    }
  }]
}, {
  blocksBehind: 3,
  expireSeconds: 30,
});