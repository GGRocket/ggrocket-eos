# GG Robot Tokenomics
![alt text](https://github.com/GGRocket/ggrocket-eos/blob/master/images/tokenomics.png "GG Robot Tokenomics")

![Image of GG Robot Tokenomics]
()

# To build Docker
docker-compose build

# To run containers
docker-compose up -d

# To unlock wallet (use your password)
docker exec -it securrency_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900 wallet unlock --password *<your-wallet-password>*

# Import this private key into your wallet
docker exec -it seccurency_nodeosd_1 cleos wallet import --private-key 5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi

# To view live logs
docker logs -f ggrocket_nodeosd_1

# Setup the following aliases
alias cleos='docker exec -it ggrocket_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900'
alias eosiocpp='docker exec -it ggrocket_nodeosd_1 eosiocpp'

# Here is the command to compile
eosiocpp -g /eosdev/ggrobot/ggrobot.abi /eosdev/ggrobot/ggrobot.hpp && eosiocpp -o /eosdev/ggrobot/ggrobot.wast /eosdev/ggrobot/ggrobot.cpp


# Run the Tests
Run the commands in ggrobot/ggrobot.sh to execute the tests
