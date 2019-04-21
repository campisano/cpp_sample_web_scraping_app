cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

set(VAR_NAME cpr)
set(VAR_CMAKE_ARGS -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)

ExternalProject_Add(
        ${VAR_NAME}_ext
        DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
        URL                     https://github.com/whoshuu/cpr/archive/1.3.0.zip
        URL_HASH                MD5=b7fd66e8e8f59801e264a3b927cc6e48
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext ${VAR_CMAKE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext/include ${CMAKE_CURRENT_SOURCE_DIR}/install/include && ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext-build/lib ${CMAKE_CURRENT_SOURCE_DIR}/install/lib
)

add_library(${VAR_NAME} STATIC IMPORTED)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libcpr.a)
