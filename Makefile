#######################################################################
##                            Hinterlib 2                            ##
##                                                                   ##
##             Copyright (C) 2019-2024 Alexander Nicholi             ##
##          Copyright (C) 2024-2025 Aquefir Consulting LLC.          ##
##           Released under Artisan Software Licence v1.1.           ##
#######################################################################

ifeq ($(strip $(BYBLOS)),)
$(error "Byblos was not found in the environment. Please install the Byblos SDK from byblos.tohoku.ac to continue, or having done so ensure the environment variable is set in the shell rc.")
endif

include $(BYBLOS)/include/inbound/prologue.mk

# name of project used in output binary naming
PROJECT := hinter

# put a '1' for the desired target types to compile
EXEFILE :=
SOFILE  :=
AFILE   := 1

# space-separated path list for #includes
# <system> includes
INCLUDES := include
# "local" includes
INCLUDEL := src

# space-separated library name list
LIBS    :=
LIBDIRS :=

# '3P' are in-tree 3rd-party dependencies
# 3PLIBDIR is the base directory
# 3PLIBS is the folder names in the base directory for each library
3PLIBDIR :=
3PLIBS   :=

# sources
SFILES.GBA := \
	src/gbabios.s \
	src/memcpy.s \
	src/memset.s
CFILES.GBA := \
	src/gbahimem.c
CFILES     := \
	src/arr.c \
	src/clarg.c \
	src/err.c \
	src/evt.c \
	src/futils.c \
	src/log.c \
	src/memory.c \
	src/piper.c \
	src/random.c \
	src/str.c \
	src/table.c \
	src/utf8.c
PUBHFILES  := \
	include/mt19937/random.h \
	include/uni/types/opt/bound.h \
	include/uni/types/opt/common.h \
	include/uni/types/opt/complexf.h \
	include/uni/types/opt/complexi.h \
	include/uni/types/opt/float.h \
	include/uni/types/opt/int.h \
	include/uni/types/opt/point.h \
	include/uni/types/opt/quant.h \
	include/uni/types/opt/range.h \
	include/uni/types/opt/vecf.h \
	include/uni/types/opt/veci.h \
	include/uni/types/bound.h \
	include/uni/types/complexf.h \
	include/uni/types/complexi.h \
	include/uni/types/float.h \
	include/uni/types/geo.h \
	include/uni/types/int.h \
	include/uni/types/mathprim.h \
	include/uni/types/opt.h \
	include/uni/types/options.h \
	include/uni/types/point.h \
	include/uni/types/quant.h \
	include/uni/types/range.h \
	include/uni/types/vec.h \
	include/uni/types/vecf.h \
	include/uni/types/veci.h \
	include/uni/arr.h \
	include/uni/ascii.h \
	include/uni/chkmath.h \
	include/uni/clarg.h \
	include/uni/decl.h \
	include/uni/endian.h \
	include/uni/err.h \
	include/uni/evt.h \
	include/uni/futils.h \
	include/uni/log.h \
	include/uni/memory.h \
	include/uni/piper.h \
	include/uni/str.h \
	include/uni/table.h \
	include/uni/utf8.h \
	include/uni/ver.h
PRVHFILES  := \
	src/arr.h \
	src/clarg.h \
	src/evt.h \
	src/gbabios.h \
	src/gbahimem.h \
	src/piper.h \
	src/str.h \
	src/table.h \
	src/utf8.h

# this defines all our usual targets
include $(BYBLOS)/include/inbound/epilogue.mk
