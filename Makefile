# CUSTOM output executable and lib files
DEFAULT_TARGET =		debug
TARGET_EXEC =			bitstamp_saver
TARGET_LIB =
HEADER_EXT =			.hpp
SOURCE_EXT =			.cpp

# CUSTOM paths
INC_DIRS =			include
INC_EXT_DIRS =			ext/cpr/include ext/sqlpp11/include ext/date/include /usr/include/postgresql ext/json ext/recycle
FORMAT_INC_DIRS =		include
SRC_DIRS =			src/bs
TEST_SRC_DIRS =			src/test
FORMAT_SRC_DIRS =		src
MAIN_SRC =			src/main.cpp
LIB_DIRS =			ext/cpr/lib ext/sqlpp11/lib
ROOT_BUILD_DIR =		build

# CUSTOM libs for different targets
RELEASE_LIBS =			cpr curl sqlpp11-connector-postgresql pq pthread stdc++
STATIC_LIBS =			$(RELEASE_LIBS)
LIBRARY_LIBS =			$(RELEASE_LIBS)
DEBUG_LIBS =			$(RELEASE_LIBS)
PROFILE_LIBS =			$(RELEASE_LIBS)
TEST_LIBS =			$(RELEASE_LIBS)

# finally, include the generic makefile
include ext/Makefile.inc
