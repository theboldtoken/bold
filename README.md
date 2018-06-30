Forked by:
Portions Copyright (c) 2018, The Intense Coin developers 
Copyright (c) 2014-2017, The Monero Project Portions 
Copyright (c) 2012-2013, The Cryptonote developers

# BOLD

<img src="https://www.boldprivate.network/ann_images/boldannsplashxx.png">

BOLD is a low-supply, private digital currency created solely and purposely with a vision to become a widely-accepted medium of exchange, but in particular, to be a safe and straight-forward store of value over time. BOLD is designed for long-term value, with a solid and dedicated team behind it.

Strong. Confidential. Anonymous.

Compiling BOLD


## 💾 UNIX Installation


```bash
$ apt-get update
$ apt-get upgrade
$ apt-get install qtbase5-dev libssl-dev cmake git libboost1.58-all-dev build-essential g++
$ git clone https://github.com/theboldtoken/boldprivate
$ cd boldprivate/
$ cmake CMakeLists.txt
$ make -j 8
$ cd cryptonote/
$ make -j 8
```

## Use

Once compiled, click on the BOLD binary.

This starts up the node, which will commence synchronization with peers. REMEMBER TO export your private key before creating a password to your wallet.

To mine with your CPU, click the "Start Mining" button.

## Configuration


## Official Links
* [Website](https://www.boldprivate.network/)
* [Pool](http://pool.boldprivate.network)

## Social
* [Facebook]()
* [Twitter]()
* [Telegram]()

## License
GNU General Public License v3.0
