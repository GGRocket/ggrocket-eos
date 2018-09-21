
# To build Docker
docker-compose build

# To run containers
docker-compose up -d

# To unlock wallet (use your password)
docker exec -it securrency_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900 wallet unlock --password PW5K6tHhBdjD7JGK4jwJKNnduamH3GfwmgJjnkmGvSPokKtanDrt3

# Import this private key into your wallet
docker exec -it seccurency_nodeosd_1 cleos wallet import --private-key 5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi

# To view live logs
docker logs -f securrency_nodeosd_1

# Setup the following aliases
alias cleos='docker exec -it securrency_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900'
alias eosiocpp='docker exec -it securrency_nodeosd_1 eosiocpp'

# Here is the command to compile
eosiocpp -g /eosdev/stoken/stoken.abi /eosdev/stoken/stoken.hpp && eosiocpp -o /eosdev/stoken/stoken.wast /eosdev/stoken/stoken.cpp


# Run the Tests
Run the commands in stoken/stoken.sh to execute the tests