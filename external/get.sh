#!/bin/bash

set -o errtrace -o pipefail

fn_abort()
{
    ERRCODE=$?
    echo >&2 "Error code '${ERRCODE}' executing ${BASH_COMMAND} on line ${BASH_LINENO[0]}"
    exit ${ERRCODE}
}

trap fn_abort ERR

fn_get()
{
    DEST=$1; URL=$2; BASE_DIR=`pwd`
    echo -e " * getting \\033[1;33m${URL}\\033[0;39m"
    mkdir -p "${BASE_DIR}/src"
    cd "${BASE_DIR}/src"
    curl -L "${URL}" -o "${DEST}" --progress-bar
    cd "${BASE_DIR}"
}

fn_get_zip()
{
    URL=$1; BASE_DIR=`pwd`
    fn_get tmp.zip "${URL}"
    cd "${BASE_DIR}/src"
    unzip -q tmp.zip && rm -f tmp.zip
    cd "${BASE_DIR}"
}

# GenericMakefile
rm -f src/GenericMakefile-master Makefile.inc
fn_get_zip https://codeload.github.com/campisano/GenericMakefile/zip/master
cp -a src/GenericMakefile-master/Makefile.inc .
