alias cleos='docker exec -it ggrocket_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900'
alias eosiocpp='docker exec -it ggrocket_nodeosd_1 eosiocpp'

cleos create account eosio ggrobot EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio gamebuyer1 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio gamebuyer2 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio databuyer1 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio databuyer2 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio ggtoken EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn

eosiocpp -g /eosdev/ggrobot/ggrobot.abi /eosdev/ggrobot/ggrobot.hpp && eosiocpp -o /eosdev/ggrobot/ggrobot.wast /eosdev/ggrobot/ggrobot.cpp

cleos set contract ggrobot /eosdev/ggrobot
cleos set contract ggtoken /eosdev/eosio.token

cleos push action eosio updateauth '{"account":"ggrobot","permission":"active","parent":"owner","auth":{"keys":[{"key":"EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn", "weight":1}],"threshold":1,"accounts":[{"permission":{"actor":"ggrobot","permission":"eosio.code"},"weight":1}],"waits":[]}}' -p ggrobot

cleos push action ggtoken create '["ggrobot", "1000000.00 GGR"]' -p ggtoken
cleos push action ggtoken issue '["ggrobot", "100.00 GGR"]' -p ggrobot
cleos push action ggtoken issue '["databuyer1", "100.00 GGR"]' -p ggrobot
cleos push action ggtoken transfer '["databuyer1", "ggrobot", "10.00 GGR", "memo"]' -p databuyer1

cleos push action ggrobot newpurrecord '[24567, "gamebuyer1", "Source #4", "World of Warcraft", "Potion #99", "10.0000 GGR", 234]' -p ggrobot
cleos push action ggrobot newidentity '["Max", "gravitt@yep.com"]' -p ggrobot

cleos push action ggrobot reveal '["gamebuyer1", 4129428988]' -p ggrobot

g