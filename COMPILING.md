
## Compiling instructions

Written by Alexander Nicholi  
Copyright &copy; 2025 Aquefir Consulting LLC  
Released under [Artisan Software Licence v1.1](https://aquefir.co/asl).

-----

Hinterlib compiles for every platform that can be targeted with Inbound,
however many of those platforms are not actively used and probably
won&rsquo;t work out-of-the-box. Our active usage list so far includes:
- Apple macOS on AArch64
- GNU/Linux on x86-64

To compile, run GNU `make` on the command line. Job control is
supported. See Inbound&rsquo;s documentation for a full list of features
and help guides.

If your editor leverages the `clangd` language server, Inbound provides
a `make schema` phony target to generate its requisite JSON command
database.
