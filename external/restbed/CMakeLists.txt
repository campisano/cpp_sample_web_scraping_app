cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME restbed)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://github.com/Corvusoft/restbed/archive/4.6.zip
    URL_HASH                MD5=2424a7f89792d61f783a6581273a0410
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -Dasio_INCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/../asio/install/include -Dkashmir_INCLUDE=${CMAKE_CURRENT_SOURCE_DIR}/../kashmir/install/include -DBUILD_TESTS=NO -DBUILD_EXAMPLES=NO -DBUILD_SSL=YES -DBUILD_SHARED=ON
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
SET(${TARGET_NAME}_LIBRARY_DIRS ${INSTALL_DIR}/library CACHE STRING "")
SET(${TARGET_NAME}_LIBRARIES ${${TARGET_NAME}_LIBRARY_DIRS}/librestbed.so CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} SHARED IMPORTED GLOBAL)
set_target_properties(
    ${TARGET_NAME} PROPERTIES
    IMPORTED_LOCATION ${${TARGET_NAME}_LIBRARIES})
add_dependencies(${TARGET_NAME} asio kashmir ${TARGET_NAME}_clean_no_custom)
