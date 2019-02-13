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

fn_get_tgz()
{
    URL=$1; BASE_DIR=`pwd`
    fn_get tmp.tgz "${URL}"
    cd "${BASE_DIR}/src"
    tar -xzf tmp.tgz && rm -f tmp.tgz
    cd "${BASE_DIR}"
}

fn_build_cmake()
{
    SOURCE=$1; DEST=$2; CMAKE_ARGS=$3; MAKE_TARGET=$4; BASE_DIR=`pwd`
    echo -e " * building \\033[1;33m${DEST}\\033[0;39m"
    cd "${BASE_DIR}/${SOURCE}"
    rm -rf build && mkdir build && cd build
    cmake ${CMAKE_ARGS} "-DCMAKE_RULE_MESSAGES=OFF" "-DCMAKE_INSTALL_PREFIX=../../../${DEST}" ".." | grep -v -- '^-- ' || true
    test \! -z "${MAKE_TARGET}" && make ${MAKE_TARGET} || make
    cd "${BASE_DIR}"
    echo
}
