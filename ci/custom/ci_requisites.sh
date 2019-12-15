#!/usr/bin/env bash

set -o errexit -o nounset -o pipefail

REQS=""

type -P docker &>/dev/null || REQS="${REQS} docker"
type -P git &>/dev/null || REQS="${REQS} git"

if test -n "${REQS}"
then
    apt-get -qq -y update
    apt-get -qq -y install ${REQS} > /dev/null
    apt-get -qq -y clean
fi;
