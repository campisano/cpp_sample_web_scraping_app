cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME recycle)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://github.com/steinwurf/recycle/archive/4.0.0.zip
    URL_HASH                MD5=c94ec0540f459b58666221c60a9df040
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ""
    BUILD_COMMAND           ""
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/src/recycle <INSTALL_DIR>/include/recycle
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} INTERFACE)
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
