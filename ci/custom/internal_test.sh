#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

export DEBIAN_FRONTEND=noninteractive

rm -f /etc/apt/apt.conf.d/docker*
apt-get -qq -y update
apt-get -qq -y install --no-install-recommends apt-utils > /dev/null
apt-get -qq -y install --no-install-recommends libssl1.0.2 libcurl3 > /dev/null

./run.sh release test
