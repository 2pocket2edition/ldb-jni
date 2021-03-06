ifneq ($(BUILD),$(notdir $(CURDIR)))
.PHONY: $(BUILD) clean

export OUTDIR	:=	$(CURDIR)/../src/main/resources/net/daporkchop/ldbjni/natives
BUILDDIR		:=	../build/native/$(BUILD_TYPE)/$(BUILD)

clean:
	@if [ -d ../build/native/ ]; then rm -rf ../build/native/; fi
	@rm -rf $(foreach arch,$(ARCHS),$(OUTDIR)/$(arch))

$(BUILD):
	@[ -d $(BUILDDIR) ] || mkdir -p $(BUILDDIR)
	@$(MAKE) --no-print-directory -C $(BUILDDIR) -f $(CURDIR)/Makefile BUILD=$(BUILD) build

else
.PHONY: build

include $(TOOLCHAINS)/$(BUILD)

SOURCES			:=	$(PROJDIR)/../src/main/native/common $(PROJDIR)/../src/main/native/$(BUILD)
SOURCES			:=	$(abspath $(SOURCES))

CFILES			:=	$(foreach dir,$(SOURCES),$(wildcard $(dir)/*.c))
CPPFILES		:=	$(foreach dir,$(SOURCES),$(wildcard $(dir)/*.cpp))
OFILES			:=	$(addsuffix .o,$(subst /,__,$(CFILES)) $(subst /,__,$(CPPFILES)))

INCLUDES		:=	$(INCLUDES) $(CURDIR)/lib-leveldb/include $(CURDIR)/lib-snappy
INCLUDE			:=	$(addprefix -I,$(INCLUDES) $(CURDIR))

build: libldb-jni.$(EXT)
	@echo "Copying libldb-jni.$(EXT) to $(OUTDIR)/..."
	@[ -d $(OUTDIR) ] || mkdir -p $(OUTDIR)
	@cp libldb-jni.$(EXT) $(OUTDIR)/$(BUILD).$(EXT)

libldb-jni.$(EXT): $(CFILES) $(CPPFILES) $(OFILES) $(CURDIR)/lib-leveldb/libleveldb.a $(CURDIR)/lib-zlib/libz.a
	@echo "Linking $@..."
	@$(LD) $(LDFLAGS) $(INCLUDE) -o $@ $(OFILES) $(CURDIR)/lib-leveldb/libleveldb.a $(CURDIR)/lib-zlib/libz.a $(CURDIR)/lib-snappy/libsnappy.a
	@echo "Stripping $@..."
	@$(STRIP) $@

%.c.o: $(CFILES) $(CURDIR)/lib-leveldb/libleveldb.a $(CURDIR)/lib-zlib/libz.a
	@echo "Building $(subst .o,,$(subst __,/,$@))..."
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(subst .o,,$(subst __,/,$@)) -o $@

%.cpp.o: $(CPPFILES) $(CURDIR)/lib-leveldb/libleveldb.a $(CURDIR)/lib-zlib/libz.a
	@echo "Building $(subst .o,,$(subst __,/,$@))..."
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $(subst .o,,$(subst __,/,$@)) -o $@

$(CURDIR)/lib-leveldb/libleveldb.a: $(TOPDIR)/leveldb-mcpe-1.22.tar.gz $(CURDIR)/lib-zlib/libz.a $(CURDIR)/lib-snappy/libsnappy.a
	@[ ! -d lib-leveldb/ ] || rm -rf lib-leveldb/
	@tar zxf $(TOPDIR)/leveldb-mcpe-1.22.tar.gz
	@mv leveldb-mcpe-1.22/ lib-leveldb/
	@[ -f "$(TOOLCHAINS)/$(BUILD).cmake" ]
	@cp $(TOPDIR)/leveldb-CMakeLists.txt lib-leveldb/CMakeLists.txt
	@cd lib-leveldb/ && cmake \
		-DCMAKE_TOOLCHAIN_FILE="$(TOOLCHAINS)/$(BUILD).cmake" \
		-DZLIB_LIBRARY="$(CURDIR)/lib-zlib/libz.a" -DZLIB_INCLUDE_DIR="$(CURDIR)/lib-zlib" \
		-DHAVE_SNAPPY=true -DSNAPPY_DIR="$(CURDIR)/lib-snappy" \
		-DLEVELDB_BUILD_TESTS=OFF -DLEVELDB_BUILD_BENCHMARKS=OFF -DLEVELDB_INSTALL=OFF .
	@$(MAKE) -C $(CURDIR)/lib-leveldb/ -f $(CURDIR)/lib-leveldb/Makefile

$(CURDIR)/lib-zlib/libz.a: $(TOPDIR)/zlib-ng-1.2.11.tar.gz
	@[ ! -d lib-zlib/ ] || rm -rf lib-zlib/
	@tar zxf $(TOPDIR)/zlib-ng-1.2.11.tar.gz
	@mv zlib-ng-1.2.11/ lib-zlib/
	@cd lib-zlib/ && ./configure --static --zlib-compat && cd ..
	@$(MAKE) -C $(CURDIR)/lib-zlib/ -f $(CURDIR)/lib-zlib/Makefile libz.a

$(CURDIR)/lib-snappy/libsnappy.a: $(TOPDIR)/snappy-1.1.8.tar.gz
	@[ ! -d lib-snappy/ ] || rm -rf lib-snappy/
	@tar zxf $(TOPDIR)/snappy-1.1.8.tar.gz
	@mv snappy-1.1.8/ lib-snappy/
	@[ -f "$(TOOLCHAINS)/$(BUILD).cmake" ]
	@cd lib-snappy/ && cmake \
		-DCMAKE_TOOLCHAIN_FILE="$(TOOLCHAINS)/$(BUILD).cmake" \
		-DSNAPPY_BUILD_TESTS=OFF -DSNAPPY_INSTALL=OFF .
	@$(MAKE) -C $(CURDIR)/lib-snappy/ -f $(CURDIR)/lib-snappy/Makefile

endif
