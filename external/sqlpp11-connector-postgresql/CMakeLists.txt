cmake_minimum_required(VERSION 3.3.2)

include(ExternalProject)

set(TARGET_NAME sqlpp11-connector-postgresql)

ExternalProject_Add(
    ${TARGET_NAME}_external
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${TARGET_NAME}.zip
    URL                     https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
    URL_HASH                MD5=a61ad1172083e01c62aa9187f2532fc0
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    BINARY_DIR              ${CMAKE_CURRENT_BINARY_DIR}/build
    INSTALL_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/install
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_CXX_STANDARD=11 -DHinnantDate_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../date/install -DSqlpp11_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../sqlpp11/install/lib/cmake/Sqlpp11/ -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql -DENABLE_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

ExternalProject_Get_property(${TARGET_NAME}_external INSTALL_DIR)
SET(${TARGET_NAME}_INCLUDE_DIRS ${INSTALL_DIR}/include CACHE STRING "")
SET(${TARGET_NAME}_LIBRARIES ${INSTALL_DIR}/lib CACHE STRING "")

set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM 1)
add_custom_target(${TARGET_NAME}_clean_no_custom)
add_dependencies(${TARGET_NAME}_clean_no_custom ${TARGET_NAME}_external)

add_library(${TARGET_NAME} SHARED IMPORTED GLOBAL)
set_target_properties(
    ${TARGET_NAME} PROPERTIES
    IMPORTED_LOCATION ${${TARGET_NAME}_LIBRARIES}/libsqlpp11-connector-postgresql-dynamic.so)
add_dependencies(${TARGET_NAME} sqlpp11 ${TARGET_NAME}_clean_no_custom)
