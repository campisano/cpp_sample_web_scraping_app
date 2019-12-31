#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

TOKEN="$1"

apt-get -qq -y update
apt-get -qq -y install gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev > /dev/null
apt-get -qq -y install libssl1.0.2 libcurl3 > /dev/null
apt-get -qq -y install curl git lcov > /dev/null
apt-get -qq -y clean

make -e debug

./run.sh debug test

for F in `find build/debug -name '*.cpp'`;
do
  gcov -n -o . "${F}" > /dev/null;
done

lcov --directory "build/debug" --capture --output-file coverage.info
ls -alt --color
lcov --remove coverage.info "/usr/*" "`pwd`/external/*" "`pwd`/src/test/*" --output-file coverage.info
lcov --list coverage.info

bash <(curl -s https://codecov.io/bash) -f coverage.info -t "${TOKEN}"

rm -f coverage.info
make distclean
