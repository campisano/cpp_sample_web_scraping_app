#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

COVERAGE_TOKEN="$1"

export DEBIAN_FRONTEND=noninteractive

rm -f /etc/apt/apt.conf.d/docker*
apt-get -qq -y update
apt-get -qq -y install --no-install-recommends apt-utils > /dev/null
apt-get -qq -y install --no-install-recommends gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev > /dev/null
apt-get -qq -y install --no-install-recommends libssl1.0.2 libcurl3 > /dev/null
apt-get -qq -y install --no-install-recommends curl git lcov > /dev/null

make -e debug

./run.sh debug test

for F in `find build/debug -name '*.cpp'`;
do
  gcov -n -o . -p "${F}" > /dev/null;
done

lcov --directory "build/debug" --capture --output-file coverage.info
ls -alt --color
lcov --remove coverage.info "/usr/*" "`pwd`/external/*" "`pwd`/src/test/*" --output-file coverage.info
lcov --list coverage.info

bash <(curl -s https://codecov.io/bash) -f coverage.info -t "${COVERAGE_TOKEN}"

rm -f coverage.info
make distclean
