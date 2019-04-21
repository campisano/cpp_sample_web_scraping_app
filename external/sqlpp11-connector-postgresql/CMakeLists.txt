cmake_minimum_required(VERSION 3.2.3)

INCLUDE(ExternalProject)

ExternalProject_Add(
        sqlpp11-connector-postgresql
        DOWNLOAD_DIR            ${CMAKE_SOURCE_DIR}/download
        URL                     https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
        URL_HASH                MD5=a61ad1172083e01c62aa9187f2532fc0
        SOURCE_DIR              ${CMAKE_BINARY_DIR}/src
        BINARY_DIR              ${CMAKE_BINARY_DIR}/bin
        CONFIGURE_COMMAND       ${CMAKE_COMMAND} ${CMAKE_BINARY_DIR}/src -DCMAKE_RULE_MESSAGES=OFF -DCMAKE_INSTALL_MESSAGE=NEVER -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DHinnantDate_ROOT_DIR=${CMAKE_SOURCE_DIR}/../date/install -DSqlpp11_DIR=${CMAKE_SOURCE_DIR}/../sqlpp11/install/lib/cmake/Sqlpp11/ -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql -DENABLE_TESTS=OFF
        BUILD_COMMAND           make --silent
        INSTALL_COMMAND         make --silent install
)
