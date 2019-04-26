cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME pistache)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    URL                     https://codeload.github.com/oktal/pistache/zip/6dca6a0cb229981b928fe36ccdc6fb1741906444
    URL_HASH                MD5=ff895155cb2020d861a5903cb63ad05f
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext ${VAR_CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install -DPISTACHE_BUILD_EXAMPLES=false -DPISTACHE_BUILD_TESTS=false -DPISTACHE_BUILD_DOCS=false -DPISTACHE_USE_SSL=true
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

add_library(${VAR_NAME} SHARED IMPORTED)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libtz.so)
