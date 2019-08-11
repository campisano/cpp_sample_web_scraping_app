cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME json)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)
set(VAR_CMAKE_BASE_ARGS ${VAR_CMAKE_BASE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    URL                     https://github.com/nlohmann/json/releases/download/v3.7.0/json.hpp
    URL_HASH                MD5=3a33df05082ae70e663f19477c63b13e
    DOWNLOAD_NO_EXTRACT     true
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/download/json.hpp ${CMAKE_CURRENT_SOURCE_DIR}/install/json.hpp
    )
