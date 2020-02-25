# -*- coding: utf-8 -*-
## This Makefile provides the bodies of a variety of build targets (or
## ‘recipes’) normally used in building native executables and libraries.
## These include: debug, release, sanity check, code coverage, and address
## sanitisation tunings. Using the conventional *FILES and *FLAGS Makefile
## variables, the toolchain program variables (like ‘$(CC)’), the $(PROJECT)
## variable, and some miscellaneous helpers, it will fill out all of the
## typical details for these targets automatically, just by including it in
## the main Makefile.
## This works with both C and C++ code, and is continuously tested on macOS
## Mojave and Arch Linux.
## this file expects the following variables to be defined:
## CFILES, CPPFILES, HFILES, HPPFILES, GCNOFILES, GCDAFILES, CFLAGS, CXXFLAGS,
## LDFLAGS, CC, CXX, AR, FMT, INCLUDES, INCLUDEL, LIBDIRS, LIBS, FWORKS,
## OFILES, PROJECT, EXEFILE, AFILE, SOFILE, 3PLIBS, 3PLIBDIR, TES_CFILES,
## TES_CPPFILES, TES_HFILES, TES_HPPFILES, TES_GCNOFILES, TES_GCDAFILES

# Add 3rd-party includes
INCLUDES += $(patsubst %,$(3PLIBDIR)/%lib/include,$(3PLIBS))

INCLUDES += $(3PLIBDIR)/teslib/include
ifeq ($(strip $(NO_TES)),)
3PLIBS += tes
endif

# Add 3rd-party library directories
LIBDIRS += $(patsubst %,$(3PLIBDIR)/%lib,$(3PLIBS))
LIBS += $(3PLIBS)

# Variable transformations for command invocation
LIB := $(patsubst %,-L%,$(LIBDIRS)) $(patsubst %,-l%,$(LIBS))
ifeq ($(CC.CUSTOM),tcc)
INCLUDE := $(patsubst %,-I%,$(INCLUDES)) $(patsubst %,-isystem %,$(INCLUDEL))
else
INCLUDE := $(patsubst %,-isystem %,$(INCLUDES)) \
	$(patsubst %,-iquote %,$(INCLUDEL))
endif
FWORK := $(patsubst %,-framework %,$(FWORKS))

# Populated below
TARGETS :=

TESTARGETS := $(TES_CFILES:.tes.c=.c.tes) $(TES_CPPFILES:.tes.cpp=.cpp.tes)

# specify all target filenames
EXETARGET := $(PROJECT)
SOTARGET  := lib$(PROJECT).$(SO)
ATARGET   := lib$(PROJECT).a

ifeq ($(strip $(EXEFILE)),1)
TARGETS += $(EXETARGET)
endif
ifeq ($(strip $(SOFILE)),1)
TARGETS += $(SOTARGET)
endif
ifeq ($(strip $(AFILE)),1)
TARGETS += $(ATARGET)
endif

# Use ?= so that this can be overridden. This is useful when some projects in
# a solution need $(CXX) linkage when the main project lacks any $(CPPFILES)
ifeq ($(strip $(CPPFILES)),)
	CCLD ?= $(CC)
else
	CCLD ?= $(CXX)
endif

.PHONY: debug release check cov asan clean format

## Debug build
## useful for: normal testing, valgrind, LLDB
##
ifeq ($(CC.CUSTOM),tcc)
debug: CFLAGS += -UNDEBUG
else
debug: CFLAGS += -O0 -g3 -UNDEBUG
endif
debug: CXXFLAGS += -O0 -g3 -UNDEBUG
debug: REALSTRIP := ':' ; # : is a no-op
debug: $(TARGETS)

## Release build
## useful for: deployment
##
ifeq ($(CC.CUSTOM),tcc)
release: CFLAGS += -DNDEBUG=1
else
release: CFLAGS += -O2 -DNDEBUG=1
endif
release: CXXFLAGS += -O2 -DNDEBUG=1
release: REALSTRIP := $(STRIP) ;
release: $(TARGETS)

## Sanity check build
## useful for: pre-tool bug squashing
##
ifeq ($(CC.CUSTOM),tcc)
check: CFLAGS += -Werror -Wunsupported -DNDEBUG=1
else
check: CFLAGS += -Wextra -Werror -Wno-unused-variable -Os -DNDEBUG=1
endif
check: CXXFLAGS += -Wextra -Werror -Wno-unused-variable -Os -DNDEBUG=1
check: REALSTRIP := ':' ; # : is a no-op
check: $(TARGETS)

## Code coverage build
## useful for: checking coverage of test suite
##
cov: REALSTRIP := ':' ; # : is a no-op
ifeq ($(CC.CUSTOM),tcc)
cov: CFLAGS += -UNDEBUG
cov: $(TARGETS)
else
ifeq ($(strip $(NO_TES)),)
ifeq ($(strip $(CC.NAME)),gcc)
cov: CFLAGS += -O1 -g3 -UNDEBUG -fprofile-arcs -ftest-coverage -DTES_BUILD=1
cov: LDFLAGS += -fprofile-arcs -ftest-coverage
else ifeq ($(strip $(CC.NAME)),clang)
cov: CFLAGS += -O1 -g3 -UNDEBUG -fprofile-instr-generate -fcoverage-mapping \
	-DTES_BUILD=1
cov: LDFLAGS += -fprofile-instr-generate -fcoverage-mapping
endif
else
cov: -UTES_BUILD
endif # NO_TES
endif # CC.CUSTOM
ifeq ($(strip $(NO_TES)),)
ifeq ($(strip $(CXX.NAME)),g++)
cov: CXXFLAGS += -O1 -g3 -UNDEBUG -fprofile-arcs -ftest-coverage -DTES_BUILD=1
else ifeq ($(strip $(CC.NAME)),clang++)
cov: CXXFLAGS += -O1 -g3 -UNDEBUG -fprofile-instr-generate \
	-fcoverage-mapping -DTES_BUILD=1
endif
cov: $(TESTARGETS)
else
cov: -UTES_BUILD
cov: $(TARGETS)
endif # NO_TES

## Address sanitised build
## useful for: squashing memory issues
##
asan: REALSTRIP := ':' ; # : is a no-op
ifeq ($(CC.CUSTOM),tcc)
asan: CFLAGS += -UNDEBUG
asan: $(TARGETS)
else
ifeq ($(strip $(NO_TES)),)
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer -O1 -g3 \
	-fno-common -fno-optimize-sibling-calls -fsanitize=undefined \
	-fno-sanitize-recover=all -DTES_BUILD=1
else
asan: CFLAGS += -fsanitize=address -fno-omit-frame-pointer -O1 -g \
	-fno-common -fno-optimize-sibling-calls -UTES_BUILD
endif # NO_TES
endif # CC.CUSTOM
ifeq ($(strip $(NO_TES)),)
asan: CXXFLAGS += -fsanitize=address -fno-omit-frame-pointer -O1 -g3 \
	-fno-common -fno-optimize-sibling-calls -fsanitize=undefined \
	-fno-sanitize-recover=all -DTES_BUILD=1
#asan: LDFLAGS += -fsanitize=address -L$(3PLIBDIR)/teslib
asan: $(TESTARGETS)
else
asan: CXXFLAGS += -UTES_BUILD
asan: $(TARGETS)
endif

# Object file builds
%.cpp.o: %.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $(INCLUDE) $<

%.c.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDE) $<

%.tes.cpp.o: %.tes.cpp
	$(CXX) -c -o $@ $(CXXFLAGS) $(INCLUDE) $<

%.tes.c.o: %.tes.c
	$(CC) -c -o $@ $(CFLAGS) $(INCLUDE) $<

%.cpp.tes: %.tes.cpp.o $(ATARGET)
	$(CCLD) $(LDFLAGS) -o $@ $^ $(LIB)

%.c.tes: %.tes.c.o $(ATARGET)
	$(CCLD) $(LDFLAGS) -o $@ $^ $(LIB)

# Static library builds
$(ATARGET): $(OFILES)
	$(AR) $(ARFLAGS) $@ $^

# Shared library builds
$(SOTARGET): $(OFILES)
	$(CCLD) $(LDFLAGS) -shared -o $@ $^ $(LIB)
	$(REALSTRIP) -s $^

# Executable builds
$(EXETARGET): $(OFILES)
	$(CCLD) $(LDFLAGS) -o $@ $^ $(LIB)
	$(REALSTRIP) -s $^

DSYMS := $(patsubst %,%.dSYM,$(TARGETS)) $(patsubst %,%.dSYM,$(TESTARGET))

clean:
	$(RM) $(TARGETS)
	$(RM) $(TESTARGETS)
	$(RM) -r $(DSYMS)
	$(RM) $(OFILES)
	$(RM) $(GCNOFILES)
	$(RM) $(GCDAFILES)
	$(RM) $(TES_OFILES)
	$(RM) $(TES_GCNOFILES)
	$(RM) $(TES_GCDAFILES)

ifeq ($(strip $(NO_TES)),)
format: $(TES_CFILES) $(TES_HFILES) $(TES_CPPFILES) $(TES_HPPFILES)
endif
format: $(CFILES) $(HFILES) $(CPPFILES) $(HPPFILES)
	for _file in $^; do \
		$(FMT) -i -style=file $$_file ; \
	done
	unset _file
