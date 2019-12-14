#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

apt-get -qq -y update
apt-get -qq -y install libssl1.0.2 libcurl3 > /dev/null
apt-get -qq -y clean

./run.sh release test
