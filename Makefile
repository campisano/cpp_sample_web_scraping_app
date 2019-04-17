# CUSTOM output executable and lib files
DEFAULT_TARGET :=		debug
TARGET_EXEC :=			scraper
TARGET_LIB :=
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp

# CUSTOM paths
INC_DIRS :=
INC_EXT_DIRS :=			/usr/include/postgresql external/cpr/include external/sqlpp11/include external/date/include external/json external/recycle
FORMAT_INC_DIRS :=
SRC_DIRS :=			src/bs
TEST_SRC_DIRS :=
FORMAT_SRC_DIRS :=		src
MAIN_SRC :=			src/main.cpp
LIB_DIRS :=			external/cpr/lib external/sqlpp11/lib
ROOT_BUILD_DIR :=		build

# CUSTOM libs for different targets
RELEASE_LIBS :=			cpr curl sqlpp11-connector-postgresql pq pthread stdc++
STATIC_LIBS :=			$(RELEASE_LIBS)
LIBRARY_LIBS :=			$(RELEASE_LIBS)
DEBUG_LIBS :=			$(RELEASE_LIBS)
PROFILE_LIBS :=			$(RELEASE_LIBS)
TEST_LIBS :=			$(RELEASE_LIBS)

# finally, include the generic makefile
include external/Makefile.inc
