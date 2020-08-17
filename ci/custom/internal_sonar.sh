#!/usr/bin/env bash

set -x -o errexit -o nounset -o pipefail

SONAR_ORGANIZATION="$1"
SONAR_TOKEN="$2"
SONAR_PROJECT_KEY="$3"

export DEBIAN_FRONTEND=noninteractive

rm -f /etc/apt/apt.conf.d/docker*
apt-get -qq -y update
apt-get -qq -y install --no-install-recommends apt-utils > /dev/null
apt-get -qq -y install --no-install-recommends libssl1.0.2 libcurl3 > /dev/null
apt-get -qq -y install --no-install-recommends gcc g++ make cmake libssl1.0-dev libcurl4-openssl-dev > /dev/null
apt-get -qq -y install --no-install-recommends wget unzip > /dev/null

mkdir -p /srv/sonar
wget -P /srv/cache -c -nv --no-check-certificate https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip
unzip -d /srv/sonar -q -n /srv/cache/build-wrapper-linux-x86.zip
wget -P /srv/cache -c -nv --no-check-certificate https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-4.4.0.2170-linux.zip
unzip -d /srv/sonar -q -n /srv/cache/sonar-scanner-cli-4.4.0.2170-linux.zip



make -e clean
/srv/sonar/build-wrapper-linux-x86/build-wrapper-linux-x86-64 --out-dir bw-output make -e debug



./run.sh debug test

mkdir -p gcov
cd gcov
for F in `find ../build/debug/CMakeFiles -name '*.cpp.o'`
do
  gcov -p "${F}" > /dev/null
done
cd ..



export SONAR_TOKEN
export SONAR_USER_HOME=/srv/cache/sonar
/srv/sonar/sonar-scanner-4.4.0.2170-linux/bin/sonar-scanner \
    -Dsonar.host.url=https://sonarcloud.io \
    -Dsonar.organization=${SONAR_ORGANIZATION} \
    -Dsonar.projectKey=${SONAR_PROJECT_KEY} \
    -Dsonar.scm.provider=git \
    -Dsonar.sources=src \
    -Dsonar.sourceEncoding=UTF-8 \
    -Dsonar.working.directory=.scannerwork \
    -Dsonar.cfamily.threads=2 \
    -Dsonar.cfamily.gcov.reportsPath=gcov \
    -Dsonar.cfamily.build-wrapper-output=bw-output \
    -Dsonar.cfamily.cache.enabled=false

rm -rf bw-output gcov .scannerwork
