# CUSTOM dependencies folder and script
DEPS_DIR :=			ext
DEPS_DIR_SCRIPT :=		prepare_deps.sh
# DEPS_MAKEFILE :=		$(shell test \! -f "$(DEPS_DIR)/Makefile.inc" && curl -L -s "https://raw.githubusercontent.com/campisano/GenericMakefile/master/Makefile.inc" -o "$(DEPS_DIR)/Makefile.inc")

# CUSTOM output executable and lib files
DEFAULT_TARGET :=		debug
TARGET_EXEC :=			scraper
TARGET_LIB :=
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp

# CUSTOM paths
INC_DIRS :=
INC_EXT_DIRS :=			/usr/include/postgresql $(DEPS_DIR)/cpr/include $(DEPS_DIR)/sqlpp11/include $(DEPS_DIR)/date/include $(DEPS_DIR)/json $(DEPS_DIR)/recycle
FORMAT_INC_DIRS :=
SRC_DIRS :=			src/bs
TEST_SRC_DIRS :=
FORMAT_SRC_DIRS :=		src
MAIN_SRC :=			src/main.cpp
LIB_DIRS :=			$(DEPS_DIR)/cpr/lib $(DEPS_DIR)/sqlpp11/lib
ROOT_BUILD_DIR :=		build

# CUSTOM libs for different targets
RELEASE_LIBS :=			cpr curl sqlpp11-connector-postgresql pq pthread stdc++
STATIC_LIBS :=			$(RELEASE_LIBS)
LIBRARY_LIBS :=			$(RELEASE_LIBS)
DEBUG_LIBS :=			$(RELEASE_LIBS)
PROFILE_LIBS :=			$(RELEASE_LIBS)
TEST_LIBS :=			$(RELEASE_LIBS)

# finally, include the generic makefile
include $(DEPS_DIR)/Makefile.inc
