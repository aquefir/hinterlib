#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def run(command):
	import subprocess
	try:
		return subprocess.check_output(command).decode()
	except subprocess.CalledProcessError as e:
		from sys import stderr
		print(e.output.decode(), file=stderr)
		exit(1)

def parse(t):
	lines = t.replace('\r\n', '\n').replace('\r', '\n').split('\n')
	i = 0
	lines_len = len(lines)
	import re
	cell_expr = re.compile(r'\s+')
	ret = []
	while i < lines_len:
		if i == 0 or lines[i].startswith('-'):
			i += 1
			continue
		cells = re.split(cell_expr, lines[i])
		ret.append(','.join(cells))
		i += 1
	return ret

def main(args):
	import platform
	MAKE = 'gmake' if platform.system() == 'Darwin' else 'make'
	from os.path import isfile
	for arg in args:
		if not isfile(arg):
			print('path ‘%s’ does not exist or access is denied.' % arg,
				file=stderr)
			return 127
		run(arg)
		out = run([MAKE, 'report', 'FILE=' + arg])
		print('\n'.join(parse(out)[1:-1]))
	return 0

if __name__ == '__main__':
	from sys import argv, exit
	exit(main(argv[1:]))
