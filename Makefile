LIB_DIR = lib
PWD = $(shell pwd)
MAKE = make --no-print-directory
all:
	@echo "make: [COMMAND]"
	@echo "COMMAND: "
	@echo "    init: init"
	@echo "    build: build"
	@echo

init: libs
	@echo all [over]

build: init

libs: $(LIB_DIR) editline
	@echo libs [over]

# ======== editline ==============
LIB_editline = $(LIB_DIR)/editline
LIB_editline_target = $(PWD)/$(LIB_DIR)/target
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
	touch $(LIB_editline_build)
# ======== editline end ==============

$(LIB_DIR):
	mkdir $@

$(LIB_editline):
	git clone https://github.com/troglobit/editline.git -b 1.17.1 $@

clean:
	rm -rf $(LIB_DIR)