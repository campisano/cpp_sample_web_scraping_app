cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME json)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NO_EXTRACT     true
    URL                     https://github.com/nlohmann/json/releases/download/v3.7.0/json.hpp
    URL_HASH                MD5=3a33df05082ae70e663f19477c63b13e
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/download/json.hpp <INSTALL_DIR>/include/json.hpp
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} INTERFACE)
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
