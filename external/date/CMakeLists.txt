cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME date)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    URL                     https://github.com/HowardHinnant/date/archive/v2.4.1.zip
    URL_HASH                MD5=6bb7a7180339566bd36eaeb1785125de
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext ${VAR_CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install -DBUILD_SHARED_LIBS=ON
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

add_library(${VAR_NAME} SHARED IMPORTED)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libtz.so)