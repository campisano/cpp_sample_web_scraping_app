#!/bin/bash

fn_abort()
{
    ERRCODE=$?
    echo >&2 "Error $ERRCODE executing $BASH_COMMAND on line ${BASH_LINENO[0]}"
    exit $ERRCODE
}

trap fn_abort ERR
set -o errtrace -o pipefail

fn_get()
{
    NAME=$1
    URL=$2
    BASE_DIR=`pwd`
    mkdir -p "${BASE_DIR}/src"
    echo -e " * \\033[1;33m${URL}\\033[0;39m"
    cd "${BASE_DIR}/src" && curl -L -s "${URL}" -o "${NAME}"
    cd "${BASE_DIR}"
}

fn_get_zip()
{
    URL=$1
    BASE_DIR=`pwd`
    fn_get tmp.zip "${URL}"
    cd "${BASE_DIR}/src" && unzip -q tmp.zip && rm -f tmp.zip
    cd "${BASE_DIR}"
}

fn_get_zip https://codeload.github.com/campisano/GenericMakefile/zip/master
cp -a src/GenericMakefile-master/Makefile.inc .

fn_get_zip https://github.com/whoshuu/cpr/archive/1.3.0.zip

fn_get_zip https://github.com/rbock/sqlpp11/archive/0.57.zip
fn_get_zip https://github.com/HowardHinnant/date/archive/v2.4.1.zip
fn_get_zip https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
mv src/sqlpp11-connector-postgresql-5e834b311484a2f59a94e555723fb579fd0d95d9 src/sqlpp11-connector-postgresql_5e834b3

fn_get json.hpp https://github.com/nlohmann/json/releases/download/v3.5.0/json.hpp
mkdir json
cp src/json.hpp json
