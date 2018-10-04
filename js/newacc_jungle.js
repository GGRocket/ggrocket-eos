
const eosjs = require('eosjs');
const fetch = require('node-fetch');                            // node only; not needed in browsers
const { TextDecoder, TextEncoder } = require('text-encoding');  // node, IE11 and IE Edge Browsers

const defaultPrivateKey = "5K8NBD4skWKZjyCv6TeSDG6jDMXcboaL7g3UY38funpSA5Kkb67"; // useraaaaaaaa
const signatureProvider = new eosjs.SignatureProvider([defaultPrivateKey]);

const rpc = new eosjs.Rpc.JsonRpc('http://dev.cryptolions.io:38888', { fetch });
const api = new eosjs.Api({ rpc, signatureProvider, textDecoder: new TextDecoder, textEncoder: new TextEncoder });
(async () => {
    const result = await api.transact({
        actions: [{
            account: 'eosio',
            name: 'newaccount',
            authorization: [{
                actor: 'ggrobot11111',
                permission: 'active',
            }],
            data: {
                creator: 'ggrobot11111',
                name: 'ggrobot11112', // change this
                owner: {
                    threshold: 1,
                    keys: [{
                        key: 'EOS8ThaKBHihQo1FXJ2UsL7gkaV77Z2Yr2U6fsatK5L1CXyYvVXh1',
                        weight: 1
                    }],
                    accounts: [],
                    waits: []
                },
                active: {
                    threshold: 1,
                    keys: [{
                        key: 'EOS8ThaKBHihQo1FXJ2UsL7gkaV77Z2Yr2U6fsatK5L1CXyYvVXh1',
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
                actor: 'ggrobot11111',
                permission: 'active',
            }],
            data: {
                payer: 'ggrobot11111',
                receiver: 'ggrobot11112',
                bytes: 8192,
            },
        },
        {
            account: 'eosio',
            name: 'delegatebw',
            authorization: [{
                actor: 'ggrobot11111',
                permission: 'active',
            }],
            data: {
                from: 'ggrobot11111',
                receiver: 'ggrobot11112',
                stake_net_quantity: '1.0000 EOS',
                stake_cpu_quantity: '1.0000 EOS',
                transfer: false,
            }
        }]
    }, {
            blocksBehind: 3,
            expireSeconds: 30,
        });
    console.dir(result);
})();