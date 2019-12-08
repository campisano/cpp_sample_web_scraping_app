#!/bin/bash

set -o errtrace -o errexit -o nounset -o pipefail

apt-get -q update
apt-get -q -y install gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev
apt-get clean
make -e release
