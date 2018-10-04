
const eosjs = require('eosjs');
const fetch = require('node-fetch');                            // node only; not needed in browsers
const { TextDecoder, TextEncoder } = require('text-encoding');  // node, IE11 and IE Edge Browsers

const defaultPrivateKey = "5K8NBD4skWKZjyCv6TeSDG6jDMXcboaL7g3UY38funpSA5Kkb67"; // useraaaaaaaa
const signatureProvider = new eosjs.SignatureProvider([defaultPrivateKey]);

const rpc = new eosjs.Rpc.JsonRpc('http://dev.cryptolions.io:38888', { fetch });
const api = new eosjs.Api({ rpc, signatureProvider, textDecoder: new TextDecoder, textEncoder: new TextEncoder });

(async () => {
    const result = await api.transact({
        actions: [
            {
                account: 'ggrobot12345',
                name: 'newpurrecord',
                authorization: [{
                    actor: 'ggrobot11112',
                    permission: 'active'
                }],
                data: {
                    purchase_id: 987678,
                    gamebuyer: 'ggrobot11112',
                    source: 'Source 763',
                    game: 'A Game that we are testing with',
                    purchase_name: 'Shield and Bomb Gun',
                    price: '2.5000 GGR',
                    purchase_date: 564323
                }
            }
        ]
    }, {
      blocksBehind: 3,
      expireSeconds: 30,
    });
    console.dir(result);
  })();