# Primus
GUI to calculate prime numbers

## Installation

### Debian

Do in the directory you choosed
```shell
wget https://github.com/AirSThib/Primus/releases/download/0.2.1-beta/primus_0.2.1-beta.deb
```

And install it
```shell
sudo dpkg -i primus_0.2.1-beta.deb
```

Launch it with
```shell
primus
```

### Windows

[Download the `.zip`](https://github.com/AirSThib/Primus/releases/download/0.2.1-beta/primus_0.2.1-beta_mingw32.zip). De-zip it. Launch the file called `Primus.exe`.

## Use Primus

<img align="right" width="auto" src="https://github.com/AirSThib/Primus/raw/main/doc/screenshots/primus_0.2.1-beta.png" alt="Screenshot of the 0.2.1 beta version" />

Define where the algorithm will start (the minimum is the 2, because there is no primes before), and where it will end (no maximum).

Launch calculating by clicking on `Calculate` button. The progress bar will indicate the avancment of the calculating.

At the end of the calculating you get the results. You can download advanced results with the list of all primes founded by clicking on the bottom button. It generates a file in `.txt` like that :
```txt
##########################
    Generated by Primus
 on 2021-04-10T18:42:32.856Z
From: 2
To: 1000
##########################


2
3
5
7
11
13
...
...
983
991
997

Calculating ended 2021-04-10T18:42:32.923Z

################
Examinated: 999
Found: 168
Percentage: 16.817

Ended 2021-04-10T18:42:32.937Z
```

## Contribute

[Report issues](https://github.com/AirSThib/Primus/issues), fork, push merge requets, all can help the project !

Primus is published in [GPL v3.0](https://www.gnu.org/licenses/gpl-3.0).
