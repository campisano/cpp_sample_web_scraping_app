# Generic Makefile.inc for CMake interface
#
# v 1.2



# make options
MAKEFLAGS +=			-s

# vars
BUILD_PATH :=			build
HEADER_EXT :=			.hpp
SOURCE_EXT :=			.cpp
FORMAT_INC_DIRS :=
FORMAT_SRC_DIRS :=		src



all: debug


.PHONY:		format
format:
	command -v astyle >/dev/null 2>&1 \
&& astyle --options=none --quiet --style=allman \
--indent=spaces=4 --lineend=linux --align-pointer=middle \
--pad-oper --pad-comma --unpad-paren \
--add-brackets --convert-tabs --max-code-length=80 \
--suffix=none \
$(shell find $(FORMAT_INC_DIRS) $(FORMAT_SRC_DIRS) -type f \( -name \*$(HEADER_EXT) -o -name \*$(SOURCE_EXT) \)) \
|| echo "Warning: can't find astyle executable";
	#&& astyle --style=ansi -r -n "./*.h" "./*.cpp" || echo "Warning: can't find astyle executable!";

debug:		format
	mkdir -p $(BUILD_PATH)/debug;
	cd $(BUILD_PATH)/debug; cmake ../.. -DCMAKE_BUILD_TYPE=debug;
	make -C $(BUILD_PATH)/debug;

release:	format
	mkdir -p $(BUILD_PATH)/release;
	cd $(BUILD_PATH)/release; cmake ../.. -DCMAKE_BUILD_TYPE=release;
	make -C $(BUILD_PATH)/release;

install:	release
	make -C $(BUILD_PATH)/release $(MAKECMDGOALS);

install_debug:	debug
	make -C $(BUILD_PATH)/debug install;

.PHONY:		clean
clean:
	test -d $(BUILD_PATH)/release && make -C $(BUILD_PATH)/release $(MAKECMDGOALS) || true;
	test -d $(BUILD_PATH)/debug && make -C $(BUILD_PATH)/debug $(MAKECMDGOALS) || true;
	test -d install/ && rm -f install/* || true;



# End
