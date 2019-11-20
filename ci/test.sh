#!/bin/bash

apt-get -q update
apt-get -q -y install libssl1.0.2 libcurl3
./run.sh release test
