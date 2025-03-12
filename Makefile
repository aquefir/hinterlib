#######################################################################
##                            Hinterlib 2                            ##
##                                                                   ##
##             Copyright (C) 2019-2024 Alexander Nicholi             ##
##          Copyright (C) 2024-2025 Aquefir Consulting LLC.          ##
##           Released under Artisan Software Licence v1.1.           ##
#######################################################################

include etc/prologue.mk

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
CFILES := \
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
PUBHFILES := \
	include/hn/types/base.h \
	include/hn/types/char.h \
	include/hn/types/float.h \
	include/hn/types/floatvec.h \
	include/hn/types/int.h \
	include/hn/types/intvec.h \
	include/hn/types/mem.h \
	include/hn/alloc.h \
	include/hn/buffer.h \
	include/hn/endian.h \
	include/hn/memops.h \
	include/hn/nimb.h
PRVHFILES := \
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
include etc/epilogue.mk
