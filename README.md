# Hinterlib

![Hinterlib](https://cdn.tohoku.ac/f/02e51f73418d4d7ba33559893035bddd/unknown.png)

**Hinterlib** is a `libc` surrogate and supplemental support library not
unlike [GLib](https://docs.gtk.org/glib/) or
[`stb`](https://github.com/nothings/stb). It provides greater provision
than other such libraries for old and/or embedded targets, and is thus
serving as the backbone of the ongoing
[Sirius DOS](https://kb.xion.mt/Sirius_DOS) research project.

Originally it was named `unilib` for lack of a better name, and the 1.x
API still reflects this with its symbol prefix `uni_`. Since version 2.0
Hinterlib uses the prefix `hn_` instead.

## Tell me more!

Hinterlib is one of the most heavily developed projects under the
[Aquefir namesake](https://aquefir.co/). Its purpose is simple: provide
primitive support functionality for programs on a variety of platforms.
This is broken up into several **focus areas**:

- quasi-portable type system normalisation
	- basic provision of things like attribute decorators, booleans, and
	  pointer types are in `hn/types/base.h`
	- 7-bit ASCII and 21-bit Unicode character types and bounds checking
	  macros are in `hn/types/char.h`
	- floating-point and integer types are provided in `hn/types/float.h`
	  and `hn/types/int.h` respectively
	- SIMD-capable vector types for floating-point and integer numerics
	  are in `hn/types/floatvec.h` and `hn/types/intvec.h` respectively
- &lsquo;software modular memory&rsquo; primitives via `hn/types/mem.h`
	- this includes knots, plus sparse &amp; sequential amalgams thereof
- modular memory allocation routines via `hn/alloc.h`
- arbitrary precision integer via `hn/nimb.h`
- the &lsquo;modular memory toolkit&rsquo; via `hn/mmt.h`
- quasi-portable memory operation routines via `hn/memops.h`

These focus areas form the low-level foundation for both consumers of
Hinterlib and Hinterlib itself in the context of higher level services.
Such higher-level services include in-memory tabular data management,
text encoding and decoding, mechanicalist container provisions, and a
cornucopia of mathematics utilities.

Like all native software projects from Aquefir Consulting LLC, Hinterlib
is written in **ANSI C**, and always will be.

Since version 2.0, Hinterlib is compiled with an insourced version of
the [Inbound](https://kb.xion.mt/Inbound) Makefile suite. This allows it
to be targeted to many platforms without needing to resort to
poorly-architected meta-build systems like CMake or SCons.

Hinterlib intends to work as fully as possible on platforms that lack a
compelling `libc` implementation, such as the Nintendo Game Boy Advance.
It accomplishes this by supplicating its own code to provide `libc`
features like dynamic memory allocation and standard I/O.

## Data type lingua franca

Hinterlib adopted a shorthand for fixed-size integer primitives
originally observed in vintage Nintendo SDKs decades ago. This shorthand
was then generalised to articulate many other primitives, including
booleans, pointers, offsets, vector aggregates, and more recently
Hinterlib&rsquo;s _software modular memory_ system of knots and
amalgams. The main benefit is that they are a good deal cleaner-looking
and quicker to type out than those provided by `<stdint.h>`. Observe:

```c
	/* the "standard" way using C99 (!!!) stdint.h */
	uint32_t, int16_t, uint8_t, uint64_t, ...

	/* the Hinterlib equivalent, using only ANSI C =) */
	u32, s16, u8, u64, ...
```

Hinterlib denotes vector aggregates (for SIMD) by combining its base
element type with the number of elements, like so:

```c
	u32v2 a; /* vector type of two u32s */
```

This is the preferred way to carry around common geometry primitives as
often seen in game development with names like `Vec3` or `Point2`.

Since version 2.0, Hinterlib offers these with its symbol prefix `hn_`.
While the default behaviour is to also define the unqualified names seen
above, one can opt out of this by defining the Inbound configuration
option `NOSHORTHAND` (`-D_CFGOPT_NOSHORTHAND`).

## Footnotes

Versions 1.x of Hinterlib, Hinterlib/Neopolitan, and/or unilib were
released under the BSD-2-Clause licence.

Starting with version 2.0, Hinterlib is now available under version 1.1
of the Artisan Software Licence. See the COPYING file for full terms.

### Origin of the name

Geneticist [Razib Khan](https://twitter.com/razibkhan) once
[wrote an article](https://archive.ph/CFwmZ) detailing the genetic
history of those inhabiting the Italian peninsula. In it he showed that
during the height of imperial Rome, an intense cosmopolitanism attracted
a powerful lineage of rulers from as far away as Syria around the time
of its decline. Remarkably, when Rome depopulated in late antiquity to a
mere 30,000 people, the inhabitants were the same genetically as those
who had lived in Italy before the Roman Empire, as Etruscans. The rural
*hinterland* proved more lasting in our genetics, as those cosmopolitan
people lived and died in Rome leaving no trace of their lineage.

In the time between Hinterlib 2 and the original `unilib`, Hinterlib was
actually one half of a hybrid fork called **Hinterlib/Neopolitan**. This
was created to accommodate the now extraneous &ldquo;Actually Portable
Executable&rdquo; file format, which provided more guarantees Neopolitan
could then presume and pass on downstream that Hinterlib could not.
Despite this fork being defunct, Neopolitan bore the name as a nod to
the &ldquo;Actually Portable Executable&rdquo; format&rsquo;s reference
implementation, &ldquo;Cosmopolitan&rdquo;. In contrast to Neopolitan,
regular `unilib` was renamed to **Hinterlib**.
