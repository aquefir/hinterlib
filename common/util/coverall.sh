#!/bin/sh
# -*- coding: utf-8 -*-

. common/util/makeall.sh cov;

if test "$(uname -s)" = 'Darwin'; then
	_make=gmake;
	_jobs=$(($(sysctl -n hw.ncpu)))
	if test -f /usr/local/opt/coreutils/bin/gecho; then
		_echo=/usr/local/opt/coreutils/bin/gecho;
	else
		_echo='/bin/echo'; # ensure it is not a bashism
	fi
	if test -f /usr/local/opt/findutils/bin/gfind; then
		_find=/usr/local/opt/findutils/bin/gfind;
	else
		_find='find';
	fi
else
	_make=make;
	_jobs=$(($(nproc) * 2));
	_echo='/bin/echo'; # ensure it is not a bashism
	_find='find'
fi

_repos="$(cat common/etc/projects.a.list)";

for _repo in ${_repos}; do
	cd ${_repo};
	${_echo} "Building sub-repo ‘${_repo}’..." >/dev/stderr;
	${_make} cov -j${_jobs};
	${_echo} "Making reports for sub-repo ‘${_repo}’..." >/dev/stderr;
	env python3 ../common/util/covreport.py \
		$(${_find} src -type f -name '*.tes') > coverage.report;
	cd ..;
done
