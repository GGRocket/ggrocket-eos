
const eosjs = require('eosjs');
const fetch = require('node-fetch');                            // node only; not needed in browsers
const { TextDecoder, TextEncoder } = require('text-encoding');  // node, IE11 and IE Edge Browsers

const defaultPrivateKey = "5K4Q93eJU3nd4raaBjRCX4U34JtFxE9qPTvBL4KDcjteNWyo8NB"; // useraaaaaaaa
const signatureProvider = new eosjs.SignatureProvider([defaultPrivateKey]);

const rpc = new eosjs.Rpc.JsonRpc('https://kylin.eoscanada.com', { fetch });
const api = new eosjs.Api({ rpc, signatureProvider, textDecoder: new TextDecoder, textEncoder: new TextEncoder });

(async () => {
    const result = await api.transact({
        actions: [
            {
                account: 'ggrocket1111',
                name: 'newpurrecord',
                authorization: [{
                    actor: 'ggrocket1111',
                    permission: 'active'
                }],
                data: {
                    purchase_id: 987678,
                    gggamebuyer: 'padstinker',
                    eosgamebuyer: 'racquetball1',
                    recorder: 'ggrocket1111',
                    source: 'Source 763',
                    game: 'First end-to-end record being recorded',
                    purchase_name: 'Badass Weapons',
                    price: '145 BTC',
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