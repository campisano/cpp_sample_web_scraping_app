cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME recycle)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
        ${VAR_NAME}_ext
        DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
        URL                     https://github.com/steinwurf/recycle/archive/4.0.0.zip
        URL_HASH                MD5=c94ec0540f459b58666221c60a9df040
        CONFIGURE_COMMAND       ""
        BUILD_COMMAND           ""
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext/src/recycle ${CMAKE_CURRENT_SOURCE_DIR}/install/recycle
)
