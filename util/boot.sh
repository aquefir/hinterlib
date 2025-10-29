#!/bin/sh
##
## EARTHBOUND bootstrapper
##
## Written by Alexander Nicholi <//nich.fi/>
## Copyright (C) 2025 Aquefir Consulting LLC <//aquefir.co/>

echo=/bin/echo; # avoid shell builtins
command -v gecho >/dev/null && echo=gecho; # for macOS
command -v stdbuf >/dev/null && echo="stdbuf -o0 ${echo}";
echon="${echo} -n";
test=/bin/test; # avoid shell builtins
command -v gtest >/dev/null && test=gtest;
mkdir=mkdir;
command -v gmkdir >/dev/null && mkdir=gmkdir;

if ${test} "$CC" = '' && ! command -v cc >/dev/null 2>&1; then
	${echon} "An ANSI C compiler under the name 'cc' is required";
	${echo} ' to be available in';
	${echo} 'the $PATH to bootstrap Earthbound.';
	${echon} 'Alternatively, one may be provided under the';
	${echo} ' environment variable $CC.';
	${echo} 'Exiting...';
	exit 2;
fi

${test} "$1" = '-q' && echo="${echo} >/dev/null";
${test} "$1" = '--quiet' && echo="${echo} >/dev/null";

${test} "$URL" = '' && URL='tohoku.ac/eb.c';
${test} "$CC" = '' && CC=cc;

if command -v curl >/dev/null 2>&1; then
	cmd='curl -fsSL';
elif command -v wget >/dev/null 2>&1; then
	cmd='wget -qO- -UwUget';
else
	${echon} 'Either curl or wget is required to bootstrap';
	${echo} ' Earthbound.';
	exit 1;
fi

${mkdir} -p data;
${cmd} "${URL}" 2>/dev/null > data/eb.c;
${test} "$?" -ne '0' && {
	${echo} 'Failed to download Earthbound source code.';
	${echon} 'If the URL broke, it can be overridden by passing a';
	${echo} ' new one as $URL to';
	${echo} 'the script.';
	${echo} 'Exiting...';
	exit 3;
};
${CC} ${CFLAGS} -odata/eb.bin data/eb.c;
${echo} 'Earthbound bootstrapped to "data/eb.bin".';
