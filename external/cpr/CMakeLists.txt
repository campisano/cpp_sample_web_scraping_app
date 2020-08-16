cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME cpr)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://github.com/whoshuu/cpr/archive/1.4.0.zip
    URL_HASH                MD5=3b023f981a7c93d25b0c3832a5c68073
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} -E copy_directory <SOURCE_DIR>/include <INSTALL_DIR>/include && ${CMAKE_COMMAND} -E copy_directory <BINARY_DIR>/lib <INSTALL_DIR>/lib
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
SET(${TARGET_NAME}_LIBRARY_DIRS ${INSTALL_DIR}/lib CACHE STRING "")
SET(${TARGET_NAME}_LIBRARIES ${${TARGET_NAME}_LIBRARY_DIRS}/libcpr.a CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} STATIC IMPORTED GLOBAL)
set_target_properties(
    ${TARGET_NAME} PROPERTIES
    IMPORTED_LOCATION ${${TARGET_NAME}_LIBRARIES})
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
