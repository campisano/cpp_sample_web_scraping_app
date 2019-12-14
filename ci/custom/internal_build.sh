#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

apt-get -qq -y update
apt-get -qq -y install gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev > /dev/null
apt-get -qq -y clean

make -e release
