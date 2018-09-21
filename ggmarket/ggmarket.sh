
 alias cleos='docker exec -it ggrocket_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900'
alias eosiocpp='docker exec -it ggrocket_nodeosd_1 eosiocpp'

cleos create account eosio ggmarket EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio buyer1 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio buyer2 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio seller1 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio seller2 EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn

cleos create account eosio ggtoken EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn

eosiocpp -g /eosdev/ggmarket/ggmarket.abi /eosdev/ggmarket/ggmarket.hpp && eosiocpp -o /eosdev/ggmarket/ggmarket.wast /eosdev/ggmarket/ggmarket.cpp
eosiocpp -g /eosdev/ggmarket/ggmarket.abi /eosdev/ggrobot/ggrobot.hpp && eosiocpp -o /eosdev/ggrobot/ggrobot.wast /eosdev/ggrobot/ggrobot.cpp
eosiocpp -g /eosdev/queue/queue.abi /eosdev/queue/queue.cpp && eosiocpp -o /eosdev/queue/queue.wast /eosdev/queue/queue.cpp
eosiocpp -o /eosdev/eosio.token/eosio.token.wast /eosdev/eosio.token/eosio.token.cpp

cleos set contract queue /eosdev/queue
cleos set contract ggmarket /eosdev/ggmarket
cleos set contract ggtoken /eosdev/eosio.token

cleos push action ggtoken create '["ggtoken", "1000000000.0000 GGR"]' -p ggtoken
cleos push action ggtoken issue '["buyer1", "1000.0000 GGR", "Initial Allowance"]' -p ggtoken
cleos push action ggtoken issue '["buyer2", "2500.0000 GGR", "Initial Allowance"]' -p ggtoken

cleos push action ggmarket newitem '["Large Fighter Sword", "World of Warcraft"]' -p ggmarket
cleos push action ggmarket newitem '["Small Protection Sword", "World of Warcraft"]' -p ggmarket
cleos push action ggmarket newitem '["Armor Level 2", "Overwatch"]' -p ggmarket
cleos push action ggmarket newitem '["Combat Helicopter", "Wargames"]' -p ggmarket

cleos push action ggmarket additem '["seller1", 0]' -p ggmarket
cleos push action ggmarket additem '["seller1", 1]' -p ggmarket
cleos push action ggmarket additem '["buyer1", 2]' -p ggmarket
cleos push action ggmarket additem '["buyer1", 3]' -p ggmarket
cleos push action ggmarket additem '["buyer1", 1]' -p ggmarket

cleos push action ggmarket newlisting '[0, "seller1", "13.5000 GGR"]' -p ggmarket
cleos push action ggmarket newlisting '[0, "seller1", "13.5000 GGR"]' -p ggmarket



cleos create account eosio queue EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio alice EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
cleos create account eosio bob EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn EOS7ckzf4BMgxjgNSYV22rtTXga8R9Z4XWVhYp8TBgnBi2cErJ2hn
