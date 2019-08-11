cmake_minimum_required(VERSION 3.2.3)

include(ExternalProject)

set(VAR_NAME sqlpp11-connector-postgresql)
set(VAR_CMAKE_BASE_ARGS -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11)
set(VAR_CMAKE_BASE_ARGS ${VAR_CMAKE_BASE_ARGS} -DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_SOURCE_DIR}/install ${CMAKE_CURRENT_BINARY_DIR}/${VAR_NAME}_ext-prefix/src/${VAR_NAME}_ext)

ExternalProject_Add(
    ${VAR_NAME}_ext
    DOWNLOAD_DIR            ${CMAKE_CURRENT_SOURCE_DIR}/download
    DOWNLOAD_NAME           ${VAR_NAME}.zip
    URL                     https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
    URL_HASH                MD5=a61ad1172083e01c62aa9187f2532fc0
    CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${VAR_CMAKE_BASE_ARGS} -DHinnantDate_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../date/install -DSqlpp11_DIR=${CMAKE_CURRENT_SOURCE_DIR}/../sqlpp11/install/lib/cmake/Sqlpp11/ -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql -DENABLE_TESTS=OFF
    BUILD_COMMAND           ${CMAKE_COMMAND} --build .
    INSTALL_COMMAND         ${CMAKE_COMMAND} --build . --target install
    )

add_library(${VAR_NAME} SHARED IMPORTED)
set_target_properties(${VAR_NAME} PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/install/lib/libsqlpp11-connector-postgresql-dynamic.so)
