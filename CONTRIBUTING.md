
# Contributing guide

Written by Alexander Nicholi  
Copyright &copy; 2025 Aquefir Consulting LLC  
Released under [Artisan Software Licence v1.1](https://aquefir.co/asl).

-----

Hinterlib has a straightforward process for anyone to author and submit
patches for integration into the mainline codebase.

For now, Hinterlib&rsquo;s development takes place on GitHub. This will
eventually change in favour of a more robust solution! Until it does,
though, this is our expectation out of you, the contributor:

1. Ensure you have set up commit signing with OpenPGP
2. &ldquo;Fork&rdquo; the repository onto your personal GitHub profile
3. Make your changes to that &ldquo;fork&rdquo;
4. Read and adhere to the [Contribution
requirements](#contribution-requirements) checklist below
5. Open a &ldquo;pull request&rdquo; on our repository via the GitHub UI
6. We&rsquo;ll correspond with you on any needed changes; just work with
us

## Contribution requirements

1. You agree to licence your work, which includes all changes to all
files checked into version control, under **version 1.1** of the
**Artisan Software Licence**, which can be read in full in the Appendix
of this document or online at <https://aquefir.co/asl>.
2. Before opening a &ldquo;pull request&rdquo;, make sure that all code
files are auto-formatted. Often, `clangd` can do this for you via your
editor, but if it doesn&rsquo;t, simply run `make format`. The
`clang-format` process can be pretty slow to start; you can speed it up
with the `-j` flag (e.g. `make format -j$(nproc)` on most Unices, or
`make format -j$(sysctl -n hw.ncpu)` on macOS).
3. Make sure all commits are signed using your OpenPGP keypair.
4. Make sure your signing key is publicly available on a PGP keyserver
(e.g. `keys.openpgp.org`, `keyserver.ubuntu.com` or
`keyserver.pgp.com`).
5. Make sure your commits are coherently authored!
	1. One commit should correspond to one clean feature, subroutine or
	other code collection and nothing else.
	2. Avoid making petty commits for things like typos; instead, roll
	back the commit history and reauthor the commit.

## Project policies

1. We do not practise squash merging of any submitted patches, so
don&rsquo;t ask us to do so.
2. For the 1.x series and the pre-release development lifecycle of v2,
Hinterlib has an unstable `master` with no release schedule. This WILL
change when Hinterlib v2 is released!
3. When Hinterlib v2 is fully released, contributors will be expected
to start basing their patches on release tags. From that time onward
DO NOT base patches on the `master` branch!

## Workflow tips

1. Hinterlib uses Inbound as its build system, which is built on top of
GNU Make 3.82+. Inbound is able to generate `compile_commands.json` for
use by `clangd`, which gives editors intelligence about the codebase.
Simply run `make schema` to create it.
2. Avoid using the GitHub UI for making any changes to your patches, as
GitHub does not support OpenPGP at all and will create an unsigned
commit which you will either have to redo or we will have to throw out.
3. In light of the coherent commit policy, you should still try to keep
works-in-progress remotely synced. The way we recommend accomplishing
this is as follows:
	1. If you are a maintainer, create a separate branch for your work on
	the main repository; if you are a contributor, create that branch on
	your own GitHub &ldquo;fork&rdquo;.
		- Do not perform any work on a `master` branch anywhere!
		- Understand that you are the custodian of that branch; think of
		yourself as the arbiter of its commit history.
	2. Perform your work targeting that branch, making _proper commits_
	as outlined in [Contribution requirements &sect;&sect;
	5.1](#contribution-requirements), and creating
	&ldquo;work-in-progress&rdquo; commits for any partially-completed
	work at the end of the work day.
	3. At the start of the next work day, roll back those unfinished
	commits by doing `git reset HEAD~$1` where `$1` is the number of
	unfinished commits.
	4. Rewrite the branch&rsquo;s history with the next day&rsquo;s
	commits, including unfinished ones, by doing
	`git push --force-with-lease`. This is preferable to a simple
	`git push --force` as it won&rsquo;t overwrite anyone else&rsquo;s
	work in case another collaborator pushed to your branch without
	notifying you. We recommend `alias`ing `git push --force-with-lease`
	in your shell.
	5. Continue working as usual and repeat steps 2, 3 and 4 each day
	until the &ldquo;pull request&rdquo; is complete.
