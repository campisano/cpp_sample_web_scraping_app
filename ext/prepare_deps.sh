#!/bin/bash

source deps_utils.sh

test -f DEPS_PREPARED && exit

#rm -f src/GenericMakefile-master Makefile.inc
#fn_get_zip https://codeload.github.com/campisano/GenericMakefile/zip/master
#cp -a src/GenericMakefile-master/Makefile.inc .

rm -rf src/cpr-1.3.0 cpr
fn_get_zip https://github.com/whoshuu/cpr/archive/1.3.0.zip
fn_build_cmake "src/cpr-1.3.0" "cpr" "-DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DUSE_SYSTEM_CURL=ON -DBUILD_CPR_TESTS=OFF" ""
mkdir cpr && cp -a src/cpr-1.3.0/include cpr && cp -a src/cpr-1.3.0/build/lib cpr

rm -rf src/date-2.4.1 date
fn_get_zip https://github.com/HowardHinnant/date/archive/v2.4.1.zip
fn_build_cmake "src/date-2.4.1" "date" "-DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_MESSAGE=NEVER -DBUILD_SHARED_LIBS=ON" "install"

rm -rf src/sqlpp11-0.57 sqlpp11
fn_get_zip https://github.com/rbock/sqlpp11/archive/0.57.zip
fn_build_cmake "src/sqlpp11-0.57" "sqlpp11" "-DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_MESSAGE=NEVER -DHinnantDate_ROOT_DIR=../../../date -DENABLE_TESTS=OFF" "install"

rm -rf src/sqlpp11-connector-postgresql_5e834b3
fn_get_zip https://codeload.github.com/matthijs/sqlpp11-connector-postgresql/zip/5e834b311484a2f59a94e555723fb579fd0d95d9
mv src/sqlpp11-connector-postgresql-5e834b311484a2f59a94e555723fb579fd0d95d9 src/sqlpp11-connector-postgresql_5e834b3
fn_build_cmake "src/sqlpp11-connector-postgresql_5e834b3" "sqlpp11" "-DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=11 -DCMAKE_INSTALL_MESSAGE=NEVER -DHinnantDate_ROOT_DIR=../../../date -DPostgreSQL_TYPE_INCLUDE_DIR=/usr/include/postgresql -DENABLE_TESTS=OFF" "install"

rm -rf src/json.hpp json
fn_get json.hpp https://github.com/nlohmann/json/releases/download/v3.5.0/json.hpp
mkdir json && cp src/json.hpp json

rm -rf src/recycle-4.0.0/src/recycle recycle
fn_get_zip https://github.com/steinwurf/recycle/archive/4.0.0.zip
mkdir recycle && cp -a src/recycle-4.0.0/src/recycle recycle

touch DEPS_PREPARED
