#!/usr/bin/env bash

set -o errexit -o nounset -o pipefail

umask 0022
mkdir -m 777 -p ${HOME}/.custom_cache/srv/cache
mkdir -m 777 -p ${HOME}/.custom_cache/var/cache/apt/archives

REQS=""

type -P docker &>/dev/null || REQS="${REQS} docker"
type -P git &>/dev/null || REQS="${REQS} git"

REQS="${REQS} `./ci/custom/get_ci_requisites.sh`"
REQS=`echo ${REQS}`

if test -n "${REQS}"
then
    export DEBIAN_FRONTEND=noninteractive
    sudo apt-get -qq -y update
    sudo apt-get -qq -y install --no-install-recommends apt-utils > /dev/null
    sudo apt-get -qq -y install --no-install-recommends ${REQS} > /dev/null
fi;
