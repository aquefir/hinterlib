########################################################################
##                            Hinterlib v2                            ##
##                                                                    ##
##             Copyright (C) 2019-2024 Alexander Nicholi.             ##
##           Copyright (C) 2024-2025 Aquefir Consulting LLC           ##
##            Released under Artisan Software Licence v1.1            ##
########################################################################

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

# sources
SFILES.GBA := \
	src/gbabios.s \
	src/memcpy.s \
	src/memset.s
CFILES := \
	src/alloc.c \
	src/conio.c \
	src/ct.c \
	src/err.c \
	src/file.c \
	src/log.c \
	src/memops.c
PUBHFILES := \
	include/hn/types/base.h \
	include/hn/types/char.h \
	include/hn/types/float.h \
	include/hn/types/floatvec.h \
	include/hn/types/int.h \
	include/hn/types/intvec.h \
	include/hn/types/mem.h \
	include/hn/alloc.h \
	include/hn/checked.h \
	include/hn/conio.h \
	include/hn/ct.h \
	include/hn/endian.h \
	include/hn/err.h \
	include/hn/exec.h \
	include/hn/file.h \
	include/hn/log.h \
	include/hn/memops.h \
	include/hn/nimb.h
PRVHFILES :=

# this defines all our usual targets
include etc/epilogue.mk
