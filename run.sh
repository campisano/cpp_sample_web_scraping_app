#!/bin/bash

TARGET="$1"
MODE="$2"
APP_PATH="./build/${TARGET}/scraper"

if test -z "${TARGET}"
then
    echo "Usage: "`basename $0`" <release|debug> [test|perf]" >&2
    exit 1
fi

if test "${MODE}" = "test"
then
   APP_PATH="${APP_PATH}_test"
   APP_OPT="-v"
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

if test "${MODE}" = "perf"
then
    chmod_data()
    {
        test -f perf.data && chmod a+r perf.data
        echo "(use 'perf report -g graph -s period,comm,dso,symbol' to analyze using TUI interface)"
        echo "(or  'perf script | c++filt | gprof2dot.py -f perf | dot -Tpng -o output.png' to analyze using graphviz)"
    }
    rm -f perf.data
    trap chmod_data SIGINT
    perf record -q -e cycles -g --call-graph fp -- "${APP_PATH}" "${APP_OPT}" && chmod_data
else
    "${APP_PATH}" "${APP_OPT}"
fi

# End
