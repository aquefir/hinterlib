#!/bin/sh
# -*- coding: utf-8 -*-

if test "$(uname -s)" = 'Darwin'; then
	_make=gmake;
	if test -f /usr/local/opt/coreutils/bin/gecho; then
		_echo=/usr/local/opt/coreutils/bin/gecho;
	else
		_echo='/bin/echo'; # ensure it is not a bashism
	fi
else
	_make=make;
	_echo='/bin/echo'; # ensure it is not a bashism
fi

${_echo} -e 'Cleaning all sub-repositories.\n' >/dev/stderr;

_repos="$(cat common/etc/projects.a.list)";

for _repo in ${_repos}; do
	cd ${_repo};
	${_echo} -n "Cleaning sub-repo ‘${_repo}’... " >/dev/stderr;
	${_make} clean 2>&1 >/dev/null;
	${_echo} 'done.' >/dev/stderr;
	cd ..;
done

${_echo} 'Cleaning up profiling data...' >/dev/stderr;
rm -f default.prof{raw,data};

${_echo} 'All done. Exiting...' >/dev/stderr;
unset _repo _repos _echo _make;
