cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME sqlpp11)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://github.com/rbock/sqlpp11/archive/0.58.zip
    URL_HASH                MD5=495bac43836f4c7ffcfd941319d6c58f
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -DHinnantDate_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../date/install -DENABLE_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} STATIC IMPORTED GLOBAL)
add_dependencies(${TARGET_NAME} date ${TARGET_NAME}_clean_no_custom)
