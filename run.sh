#!/bin/bash

TARGET="$1"
TEST="$2"
APP_PATH="./build/${TARGET}/scraper"

if test -z "${TARGET}"
then
    echo "Usage: "`basename $0`" <debug|release> [test]" >&2
    exit 1
fi

if test "${TEST}" = "test"
then
   APP_PATH="${APP_PATH}_test"
fi

if test ! -x "${APP_PATH}"
then
    echo "Binary not found: '${APP_PATH}'" >&2
    echo "(use 'make ${TARGET}' to compile it)" >&2
    exit 2
fi

unset LD_LIBRARY_PATH

for D in external/*/install/lib*
do
    export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:${D}"
done

exec "${APP_PATH}"

# End
