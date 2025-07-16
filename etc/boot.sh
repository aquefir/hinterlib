#!/bin/sh
##
## EARTHBOUND bootstrapper
##
## Written by Alexander Nicholi <//nich.fi/>
## Copyright (C) 2025 Aquefir Consulting LLC <//aquefir.co/>

echo=/bin/echo; # avoid shell builtins
command -v gecho && echo=gecho; # for macOS
command -v stdbuf && echo="stdbuf -o0 ${echo}";

if test "$CC" = '' && ! command -v cc >/dev/null 2>&1; then
	${echo} "An ANSI C compiler under the name 'cc' is required to be";
	${echo} 'available in the $PATH to bootstrap Earthbound.';
	${echo} 'Alternatively, one may be provided under the environment';
	${echo} 'variable $CC.';
	exit 2;
fi

test "$1" = '-q' && echo="${echo} >/dev/null";
test "$1" = '--quiet' && echo="${echo} >/dev/null";

test "$CC" = '' && CC=cc;

if command -v curl >/dev/null 2>&1; then
	cmd='curl -fsSL';
elif command -v wget >/dev/null 2>&1; then
	cmd='wget -qO- -UwUget';
else
	${echo} 'Either curl or wget is required to bootstrap Earthbound.';
	exit 1;
fi

${cmd} tohoku.ac/eb.c > eb.c;
$CC $CFLAGS -oeb.bin eb.c;
${echo} 'Earthbound bootstrapped to "./eb.bin".';
