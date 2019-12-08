#!/bin/bash

set -o errtrace -o errexit -o nounset -o pipefail

apt-get -q update
apt-get -q -y install libssl1.0.2 libcurl3
apt-get clean
./run.sh release test
