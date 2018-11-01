# Test Keys
Private key: 5K8NBD4skWKZjyCv6TeSDG6jDMXcboaL7g3UY38funpSA5Kkb67
Public key: EOS8ThaKBHihQo1FXJ2UsL7gkaV77Z2Yr2U6fsatK5L1CXyYvVXh1


# GG Robot Tokenomics
![alt text](https://github.com/GGRocket/ggrocket-eos/blob/master/images/tokenomics.png "GG Robot Tokenomics")

# To build Docker
```
docker-compose build
```

# To run containers
```
docker-compose up -d
```

# To unlock wallet (use your password)
```
docker exec -it ggrocket_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900 wallet unlock --password *<your-wallet-password>*
```

# Import this private key into your wallet
```
docker exec -it ggrocket_nodeosd_1 cleos wallet import --private-key 5JhhMGNPsuU42XXjZ57FcDKvbb7KLrehN65tdTQFrH51uruZLHi
```

# To view live logs
```
docker logs -f ggrocket_nodeosd_1
```

# Setup the following aliases
```
alias cleos='docker exec -it ggrocket_nodeosd_1 /opt/eosio/bin/cleos -u http://nodeosd:8888 --wallet-url http://keosd:8900'
alias eosiocpp='docker exec -it ggrocket_nodeosd_1 eosiocpp'
```

#kylin


# Here is the command to compile
```
eosiocpp -g /eosdev/ggrobot/ggrobot.abi /eosdev/ggrobot/ggrobot.hpp && eosiocpp -o /eosdev/ggrobot/ggrobot.wast /eosdev/ggrobot/ggrobot.cpp
```

# Run the Tests
Run the commands in ggrobot/ggrobot.sh to execute the tests

# Run JavaScript Files
Follow the below commands and you should be able to see new purchase records showing in the purrecords table.
```
cd js
npm install
node newpurrecord.js
cleos get table ggrobot ggrobot purrecords
```

To add a new account. Edit "myaccount" in "newaccount.js" to the name you want to create.
```
node newaccount.js
cleos get account myaccount
```