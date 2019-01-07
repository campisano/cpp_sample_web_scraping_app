#!/bin/bash

fn_abort()
{
    ERRCODE=$?
    echo >&2 "Error $ERRCODE executing $BASH_COMMAND on line ${BASH_LINENO[0]}"
    exit $ERRCODE
}

trap fn_abort ERR
set -o errtrace -o pipefail

fn_get_zip()
{
    BASE_DIR=$1
    URL=$2
    cd "${BASE_DIR}/src"
    rm -f tmp.zip
    echo -e " * \\033[1;33m${URL}\\033[0;39m"
    curl -s "${URL}" --output tmp.zip
    unzip -q tmp.zip
    rm -f tmp.zip
    cd "${BASE_DIR}"
}

PWD=`pwd`
mkdir -p src

fn_get_zip "$PWD" https://codeload.github.com/campisano/GenericMakefile/zip/master
cp -a src/GenericMakefile-master/Makefile.inc .

fn_get_zip "$PWD" https://codeload.github.com/whoshuu/cpr/zip/1.3.0

fn_get_zip "$PWD" https://codeload.github.com/rbock/sqlpp11/zip/0.57
fn_get_zip "$PWD" https://codeload.github.com/HowardHinnant/date/zip/v2.4.1
fn_get_zip "$PWD" https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
mv src/sqlpp11-connector-postgresql-5e834b311484a2f59a94e555723fb579fd0d95d9 src/sqlpp11-connector-postgresql_5e834b3

echo -e " * \\033[1;33m"'https://raw.githubusercontent.com/nlohmann/json/v3.5.0/single_include/nlohmann/json.hpp'"\\033[0;39m"
mkdir json
curl -s "https://raw.githubusercontent.com/nlohmann/json/v3.5.0/single_include/nlohmann/json.hpp" --output json/json.hpp
