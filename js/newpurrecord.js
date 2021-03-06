
const eosjs = require('eosjs');
const fetch = require('node-fetch');                            // node only; not needed in browsers
const { TextDecoder, TextEncoder } = require('text-encoding');  // node, IE11 and IE Edge Browsers

const defaultPrivateKey = "5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi"; // useraaaaaaaa
const signatureProvider = new eosjs.SignatureProvider([defaultPrivateKey]);

const rpc = new eosjs.Rpc.JsonRpc('http://127.0.0.1:8888', { fetch });
const api = new eosjs.Api({ rpc, signatureProvider, textDecoder: new TextDecoder, textEncoder: new TextEncoder });

(async () => {
    const result = await api.transact({
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
                    gggamebuyer: 'gamebuyer1',
                    eosgamebuyer: 'racquetball1',
                    recorder: 'ggrocket1111',
                    source: 'Source 763',
                    game: 'World of Warcraft',
                    purchase_name: 'New Armor and Potion Kit',
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