![Hinterlib](https://cdn2.arqadium.com/f/02e51f73418d4d7ba33559893035bddd/unknown.png)

# Hinterlib

**Hinterlib** is a *libc surrogate* like GLib or `stb_*` with better support
for old ‘embedded’ platforms like the IBM PC and the Game Boy Advance.

Originally it was named `unilib` for lack of a better name, and the 1.x API
still reflects this. `unilib` was forked into Neopolitan to provide dedicated
support for [APE](https://justine.lol/ape.html) and its implementing
[Cosmopoltian libc](https://justine.lol/cosmopolitan/index.html).

Geneticist [Razib Khan](https://twitter.com/razibkhan) [wrote an
article](https://razib.substack.com/p/they-came-they-saw-they-left-no-trace)
detailing the genetic history of those inhabiting the Italian peninsula. In it
he showed that during the height of imperial Rome, an intense cosmopolitanism
attracted a powerful lineage of rulers from as far away as Syria around the
time of its decline. Remarkably, when Rome depopulated in late antiquity to a
mere 30,000 people, the inhabitants were the same genetically as those who had
lived in Italy before the Roman Empire, as Etruscans. The rural *hinterland*
proved more lasting in our genetics, as those cosmopolitan people lived and
died in Rome leaving no trace of their lineage. As a nod to Cosmopolitan and
in contrast to the fork Neopolitan, `unilib` was renamed to **Hinterlib**.

## What is it?

Hinterlib is one of the most heavily developed projects under the [Aquefir
namesake](https://aquefir.co/). Its purpose is simple: provide primitive
support functionality for programs on a variety of platforms. These features
are similar in nature to the standard C library, and Hinterlib does work
without libc where it is unavailable. The growing list of platforms it
supports includes Microsoft Windows (via Win32 APIs), Apple macOS, GNU/Linux,
and the Nintendo Game Boy Advance. Support for DOS systems on the IBM-PC is in
planning too.

Hinterlib is written in ANSI C, and always will be. The project uses [Slick
Makefiles](https://aquefir.co/adp4) for tooling out the development process.

## What’s in the box

Hinterlib provides shorthands for all kinds of primitive data types. These are
a good deal cleaner and quicker to type than those in `<stdint.h>`:

Hinterlib:

```c
	u32, s16, u8, u64, ...
```

stdint:

```c
	uint32_t, int16_t, uint8_t, uint64_t, ...
```

There is also another shorthand called `ptri` (pronounced like ‘petri’). It is
an integer the same size as a pointer, and is used in place of size_t and the
like. There are also shorthands for exact-size floating point primitives.

Hinterlib provides math primitive `struct`s for basic geometry in the 2D and 3D
contexts. It also includes `struct`s for ranges (signed) and bounds (unsigned).
Additionally, there are also primitives for ‘vector types’; these use SIMD
intrinsics provided by the compiler where available, and transparently fall
back to plain array semantics otherwise.

Checked math macros are available to ensure against integer overflow. There
are also macros for endianness conversion operations. Hinterlib also provides
a portable `uni_die()` function that aborts the program, which is
[ideal](https://en.wikipedia.org/wiki/Fail-fast) for dealing with programmer
errors.

UTF-8 validation, conversion, and inspection routines are also available.
There are also high-level `struct`s and function collections for
automatically-memory-managed strings and generic arrays.

Lastly, there are cross-platform wrappers for standard I/O and heap usage,
which either wrap or implement logging and `malloc()` where necessary.

## Footnotes

Hinterlib is released under the BSD-2-Clause licence. See the `COPYING` file
for full terms.

Hinterlib adheres to [ADP 1](https://aquefir.co/adp1) for its repository
layout, and [ADP 2](https://aquefir.co/adp2) for its documentation.
