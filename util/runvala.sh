#!/bin/sh
########################################################################
##                            Hinterlib v2                            ##
##                                                                    ##
##             Copyright (C) 2019-2024 Alexander Nicholi.             ##
##           Copyright (C) 2024-2025 Aquefir Consulting LLC           ##
##            Released under Artisan Software Licence v1.1            ##
########################################################################

echo=/bin/echo;
command -v gecho >/dev/null && echo=gecho;
command -v stdbuf >/dev/null && echo="stdbuf -o0 ${echo}";
rm=rm;
command -v grm >/dev/null && rm=grm;

command -v valac >/dev/null || {
	${echo} 'valac is not installed on your system.';
	${echo} 'Exiting...';
	exit 127;
};

srcpath="$1";
srcdir="${srcpath%/*}";
srcfile="${srcpath##*/}";
binpath="${srcdir}/${srcfile%%.*}.bin";

valac \
	--enable-checking \
	--disable-version-header \
	--abi-stability \
	--pkg gtk4 \
	-o "${binpath}" "${srcpath}";
./"${binpath}";
${rm} "${binpath}";
