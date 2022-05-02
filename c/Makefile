LIB_DIR = lib
PWD = $(shell pwd)
MAKE = make --no-print-directory
MAKEFLAGS += --no-print-directory

all:
	@echo "make: [COMMAND]"
	@echo "COMMAND: "
	@echo "    init: init"
	@echo "    build: build"
	@echo

init: libs
	@echo all [over]

CMAKE_BINARY_DIR = cmake-build-debug
LifeConsole = LifeConsole
build: init
	cmake -G 'CodeBlocks - Unix Makefiles' -B $(CMAKE_BINARY_DIR)
	cmake --build $(CMAKE_BINARY_DIR) --target $(LifeConsole) -- -j 9
run: build
	$(CMAKE_BINARY_DIR)/$(LifeConsole)
debug: build
	gdbserver :1234 $(CMAKE_BINARY_DIR)/$(LifeConsole)

# ======== libs ==============
libs: $(LIB_DIR) editline c_utils
	@echo libs [over]
$(LIB_DIR):
	mkdir $@

LIB_target = $(PWD)/$(LIB_DIR)/target
# ======== editline ==============
LIB_editline = $(LIB_DIR)/editline
LIB_editline_target = $(LIB_target)
LIB_editline_build = $(LIB_editline_target)/.editline_BUILD_SUCCESS
editline: $(LIB_editline) $(LIB_editline_build)
	@echo lib: editline [over]

$(LIB_editline_build):
	@echo $(LIB_editline_build)
	cd $(LIB_editline) 							&&\
	bash ./autogen.sh 							&&\
	mkdir -p $(LIB_editline_target) 			&&\
	./configure --prefix=$(LIB_editline_target)	&&\
	$(MAKE) -j && $(MAKE) install
	touch $@

$(LIB_editline):
	git clone https://github.com/troglobit/editline.git -b 1.17.1 $@

# ======== editline end ==============
# ======== c_utils ===================
LIB_c_utils = $(LIB_DIR)/c_utils
LIB_c_utils_build = $(LIB_target)/.c_utils_BUILD_SUCCESS

c_utils: $(LIB_c_utils) $(LIB_c_utils_build)
	@echo lib: c_utils [over]
$(LIB_c_utils):
	git clone https://github.com/barrust/c-utils.git -b v0.2.5 $@
$(LIB_c_utils_build):
	cd $(LIB_c_utils) &&\
	make
	touch $@

# ======== c_utils end ===============
clean:
	rm -rf $(LIB_DIR)