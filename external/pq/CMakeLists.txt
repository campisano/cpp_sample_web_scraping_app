cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME pq)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.tar.bz2
    URL                     https://ftp.postgresql.org/pub/source/v11.5/postgresql-11.5.tar.bz2
    URL_HASH                MD5=580da94f6d85046ff2a228785ab2cc89
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ./configure --quiet --prefix=<INSTALL_DIR> --without-readline --without-zlib
    BUILD_COMMAND           $(MAKE) MAKELEVEL=0 -C src/interfaces/libpq
    INSTALL_COMMAND         $(MAKE) MAKELEVEL=0 -C src/interfaces/libpq install
    COMMAND                 $(MAKE) MAKELEVEL=0 -C src/include install
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
SET(${TARGET_NAME}_LIBRARY_DIRS ${INSTALL_DIR}/lib CACHE STRING "")
SET(${TARGET_NAME}_LIBRARIES ${${TARGET_NAME}_LIBRARY_DIRS}/libpq.so.5 CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} SHARED IMPORTED GLOBAL)
set_target_properties(
    ${TARGET_NAME} PROPERTIES
    IMPORTED_LOCATION ${${TARGET_NAME}_LIBRARIES})
add_dependencies(${TARGET_NAME} ${TARGET_NAME}_clean_no_custom)
