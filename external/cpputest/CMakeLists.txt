cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(NAME cpputest)

externalproject_add(
    ${NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${NAME}.zip
    URL                     https://github.com/cpputest/cpputest/releases/download/v3.8/cpputest-3.8.tar.gz
    URL_HASH                MD5=e8fdbbb5dd37d32d65919f240f984905
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -DC++11=ON -DTESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

externalproject_get_property(${NAME}_external INSTALL_DIR)
set(${NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
set(${NAME}_LIBRARY_DIRS ${INSTALL_DIR}/lib CACHE STRING "")
set(${NAME}_LIBRARIES ${${NAME}_LIBRARY_DIRS}/libCppUTest.a ${${NAME}_LIBRARY_DIRS}/libCppUTestExt.a CACHE STRING "")
list(GET ${NAME}_LIBRARIES 0 TARGET_LOCATION)

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${NAME}_clean_no_custom)
add_dependencies(${NAME}_clean_no_custom ${NAME}_external)

add_library(${NAME} STATIC IMPORTED GLOBAL)
set_target_properties(${NAME} PROPERTIES IMPORTED_LOCATION ${TARGET_LOCATION})
add_dependencies(${NAME} ${NAME}_clean_no_custom)
