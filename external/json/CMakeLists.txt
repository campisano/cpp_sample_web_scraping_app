cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME json)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

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

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${VAR_NAME}_target)
add_dependencies(${VAR_NAME}_target ${VAR_NAME}_ext)

add_library(${VAR_NAME} STATIC IMPORTED GLOBAL)
add_dependencies(${VAR_NAME} ${VAR_NAME}_target)
