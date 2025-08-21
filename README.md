# Hinterlib

![Hinterlib](https://cdn.tohoku.ac/hn-banner.jpg)

**Hinterlib** is a `libc` surrogate and support library not unlike
[GLib](https://docs.gtk.org/glib/). It boasts greater provision than
other such libraries for old and embedded targets, and is thus serving
as the backbone of the [Sirius DOS](https://kb.xion.mt/Sirius_DOS)
research project.

Originally it was named `unilib` for lack of a better name, and the 1.x
API still reflects this with its symbol prefix `uni_`. Since version 2.0
Hinterlib uses the prefix `hn_` instead. Legend has it that it documents
our secret unrequited love for Hacker News&hellip; we can neither
confirm nor deny that.

## Introduction

Hinterlib is one of the most heavily developed projects under the
[Aquefir namesake](https://aquefir.co/). As a `libc` surrogate it exists
to jumpstart ANSI C program development &ndash; therefore, it has a few
broad &lsquo;focus areas&rsquo;:

1. Shorthanded type system
	- basic types like pointers and booleans
	- character types for ASCII and Unicode
	- integral types up to 64 bits
	- floating-point types up to double precision
	- SIMD vector types for both integrals and floating-points
	- modular memory type primitives
	- type decorators for bit-packing, aliasing and so on
2. General purpose I/O
	- streaming I/O _a la_ `FILE*`
	- textual logging I/O
	- buffering facilities
3. Memory management facilities
	- software modular memory (SMM) toolkit, Himem
	- backing for textual data
	- provision for error stacking
	- stack allocation help
4. Non-generic general-purpose containers
	- uses SMM-capable algorithms
	- separation of algorithm from data structure
5. Operating system polyfills
	- Newline introspection
	- Current working directory
	- Command invocation _a la_ `system()`
6. Textual/string manipulation tools
	- Unicode-centric alternative primitives
	- SMM-aware containers
	- ASCII/Unicode dichotomy
7. Comprehensive error handling
	- return value based code propagation
	- application-centric bookkeeping of codes
	- extensibility for the application level
	- pre-allocated error stack
8. General-purpose data handling utilities
	- checksum utilities
	- endian conversion routines
	- BigInt implementation
	- common mathematical functions
9. INI/config file parser
	- INI schema parser and validator

## Focus areas

### Shorthanded type system

Hinterlib offers shorthands for all of the common primitive types used
in ANSI C programming. The following table enumerates them:

|  Vernacular       | Hinterlib | General definition                  |
|:-----------------:|:---------:|:------------------------------------|
|      `bool`       |   `bl`    | Boolean                             |
|    `uintptr_t`    |  `ptri`   | Pointer-sized unsigned integral     |
|    `intptr_t`     |  `offs`   | Pointer-sized signed integral       |
| _(no equivalent)_ |   `sbf`   | Explicitly signed bitfield type     |
| _(no equivalent)_ |   `ubf`   | Explicitly unsigned bitfield type   |
|      `char`       |   `chr`   | ASCII character type                |
|     `char32`      |  `uchr`   | Unicode character type              |
|     `uint8_t`     |   `u8`    | Unsigned 8-bit integral             |
|    `uint16_t`     |   `u16`   | Unsigned 16-bit integral            |
|    `uint32_t`     |   `u32`   | Unsigned 32-bit integral            |
|    `uint64_t`     |   `u64`   | Unsigned 64-bit integral            |
|    `uint128_t`    |  `u128`   | Unsigned 128-bit integral           |
|     `int8_t`      |   `s8`    | Signed 8-bit integral               |
|     `int16_t`     |   `s16`   | Signed 16-bit integral              |
|     `int32_t`     |   `s32`   | Signed 32-bit integral              |
|     `int64_t`     |   `s64`   | Signed 64-bit integral              |
|    `int128_t`     |  `s128`   | Signed 128-bit integral             |
|      `float`      |   `f32`   | Single-precision floating-point     |
|     `double`      |   `f64`   | Double-precision floating-point     |
| _(no equivalent)_ |  `u8v2`   | 2-element vector of `u8`s           |
| _(no equivalent)_ |  `u8v4`   | 4-element vector of `u8`s           |
| _(no equivalent)_ |  `u8v8`   | 8-element vector of `u8`s           |
| _(no equivalent)_ |  `u8v16`  | 16-element vector of `u8`s          |
| _(no equivalent)_ |  `u8v32`  | 32-element vector of `u8`s          |
| _(no equivalent)_ |  `u8v64`  | 64-element vector of `u8`s          |
| _(no equivalent)_ |  `u16v2`  | 2-element vector of `u16`s          |
| _(no equivalent)_ |  `u16v4`  | 4-element vector of `u16`s          |
| _(no equivalent)_ |  `u16v8`  | 8-element vector of `u16`s          |
| _(no equivalent)_ | `u16v16`  | 16-element vector of `u16`s         |
| _(no equivalent)_ | `u16v32`  | 32-element vector of `u16`s         |
| _(no equivalent)_ |  `u32v2`  | 2-element vector of `u32`s          |
| _(no equivalent)_ |  `u32v4`  | 4-element vector of `u32`s          |
| _(no equivalent)_ |  `u32v8`  | 8-element vector of `u32`s          |
| _(no equivalent)_ | `u32v16`  | 16-element vector of `u32`s         |
| _(no equivalent)_ |  `u64v2`  | 2-element vector of `u64`s          |
| _(no equivalent)_ |  `u64v4`  | 4-element vector of `u64`s          |
| _(no equivalent)_ |  `u64v8`  | 8-element vector of `u64`s          |
| _(no equivalent)_ |  `s8v2`   | 2-element vector of `s8`s           |
| _(no equivalent)_ |  `s8v4`   | 4-element vector of `s8`s           |
| _(no equivalent)_ |  `s8v8`   | 8-element vector of `s8`s           |
| _(no equivalent)_ |  `s8v16`  | 16-element vector of `s8`s          |
| _(no equivalent)_ |  `s8v32`  | 32-element vector of `s8`s          |
| _(no equivalent)_ |  `s8v64`  | 64-element vector of `s8`s          |
| _(no equivalent)_ |  `s16v2`  | 2-element vector of `s16`s          |
| _(no equivalent)_ |  `s16v4`  | 4-element vector of `s16`s          |
| _(no equivalent)_ |  `s16v8`  | 8-element vector of `s16`s          |
| _(no equivalent)_ | `s16v16`  | 16-element vector of `s16`s         |
| _(no equivalent)_ | `s16v32`  | 32-element vector of `s16`s         |
| _(no equivalent)_ |  `s32v2`  | 2-element vector of `s32`s          |
| _(no equivalent)_ |  `s32v4`  | 4-element vector of `s32`s          |
| _(no equivalent)_ |  `s32v8`  | 8-element vector of `s32`s          |
| _(no equivalent)_ | `s32v16`  | 16-element vector of `s32`s         |
| _(no equivalent)_ |  `s64v2`  | 2-element vector of `s64`s          |
| _(no equivalent)_ |  `s64v4`  | 4-element vector of `s64`s          |
| _(no equivalent)_ |  `s64v8`  | 8-element vector of `s64`s          |
| _(no equivalent)_ |  `f32v2`  | 2-element vector of `f32`s          |
| _(no equivalent)_ |  `f32v4`  | 4-element vector of `f32`s          |
| _(no equivalent)_ |  `f32v8`  | 8-element vector of `f32`s          |
| _(no equivalent)_ | `f32v16`  | 16-element vector of `f32`s         |
| _(no equivalent)_ |  `f64v2`  | 2-element vector of `f64`s          |
| _(no equivalent)_ |  `f64v4`  | 4-element vector of `f64`s          |
| _(no equivalent)_ |  `f64v8`  | 8-element vector of `f64`s          |
| _(no equivalent)_ |  `knot8`  | 8-bit (256 byte) memory knot        |
| _(no equivalent)_ | `knot12`  | 12-bit (4 KiB) memory knot          |
| _(no equivalent)_ | `knot16`  | 16-bit (64 KiB) memory knot         |
| _(no equivalent)_ | `knot20`  | 20-bit (1 MiB) memory knot          |
| _(no equivalent)_ | `knot24`  | 24-bit (16 MiB) memory knot         |
| _(no equivalent)_ |  `am8d1`  | 1-dimensional 8-bit memory amalgam  |
| _(no equivalent)_ | `am12d1`  | 1-dimensional 12-bit memory amalgam |
| _(no equivalent)_ | `am16d1`  | 1-dimensional 16-bit memory amalgam |
| _(no equivalent)_ | `am20d1`  | 1-dimensional 20-bit memory amalgam |
| _(no equivalent)_ | `am24d1`  | 1-dimensional 24-bit memory amalgam |
| _(no equivalent)_ |  `am8d2`  | 2-dimensional 8-bit memory amalgam  |
| _(no equivalent)_ | `am12d2`  | 2-dimensional 12-bit memory amalgam |
| _(no equivalent)_ | `am16d2`  | 2-dimensional 16-bit memory amalgam |
| _(no equivalent)_ | `am20d2`  | 2-dimensional 20-bit memory amalgam |
| _(no equivalent)_ | `am24d2`  | 2-dimensional 24-bit memory amalgam |
| _(no equivalent)_ |  `am8d3`  | 3-dimensional 8-bit memory amalgam  |
| _(no equivalent)_ | `am12d3`  | 3-dimensional 12-bit memory amalgam |
| _(no equivalent)_ | `am16d3`  | 3-dimensional 16-bit memory amalgam |
| _(no equivalent)_ | `am20d3`  | 3-dimensional 20-bit memory amalgam |
| _(no equivalent)_ | `am24d3`  | 3-dimensional 24-bit memory amalgam |
| _(no equivalent)_ |  `am8d4`  | 4-dimensional 8-bit memory amalgam  |
| _(no equivalent)_ | `am12d4`  | 4-dimensional 12-bit memory amalgam |
| _(no equivalent)_ | `am16d4`  | 4-dimensional 16-bit memory amalgam |
| _(no equivalent)_ | `am20d4`  | 4-dimensional 20-bit memory amalgam |
| _(no equivalent)_ | `am24d4`  | 4-dimensional 24-bit memory amalgam |

The Hinterlib boolean type is based on an ANSI C enumeration with two
members: `HN_FALSE` followed by `HN_TRUE`.

All integral types use GCC/Clang compiler builtins to avoid involving
`<stdint.h>` which is pedantically not available in ANSI C.

Hinterlib&rsquo;s `chr` type is directly defined as an unqualified
`char` type to respect its indeterminate signedness and the resulting
aliasing requirements of many standard library routines. The `uchr` type
is created as a structure of a bitfield so that it works on machines
lacking true 32-bit integrals.

The `sbf` and `ubf` types exist to enable mitigation of the ANSI C edge
case where unqualified integral bitfields have unspecified signedness.
Their use is recommended in the general case as ANSI C only permits
deriving bitfields from `int`s, `unsigned int`s or `signed ints` anyway.

Vector-aware static array types up to 512 bits in size are provided for
semantic richness with regard to SIMD processing techniques of both
integral and floating-point arithmetic.

Memory knot types are provided with addressability ranging from 8 to 24
bits in 4-bit steps. These are the basic building blocks of the novel
[software modular memory](https://archive.ph/EnNKK) technique.

Amalgams provide dimension-based scalability to memory knots with up to
4 dimensions built into Hinterlib. These data types are best used with
the Himem modular memory toolkit provided in `<hn/himem.h>`.

#### Decorators

Hinterlib provides the following decorators that expand appropriately
in the presence of compiler support:

- `HN_PACKED`
- `HN_TYPELESS` (ergo `may_alias`)
- `HN_NORETURN`
- `HN_NOTHROW`
- `HN_PURE`
- `HN_ALIGN(n)` where `n` is the number of bits
- `HN_DEPRECATED`
- `HN_VECSIZE(n)` to create vector-aware array types

#### Definitions

Hinterlib makes out many important details about the dimensions of the
target machine the code being compiled will run on. It exposes these as
CPP macros to the user as follows:

- `HN_CCVERSION` version of the compiler in use
	- see also `HN_MAKE_CCVERSION` for how to interpret its value
- Compiler identification macro which will be one of:
	- `HN_CC_CLANG`
	- `HN_CC_GCC`
	- `HN_CC_MSVC`
	- `HN_CC_TCC`
	- `HN_CC_PACIFICC`
	- `HN_CC_DMC`
	- `HN_CC_SDCC`
- &lsquo;Platform&rsquo; identification macro which will be one or more
  of:
	- `HN_PLATFORM_UNIX`
	- `HN_PLATFORM_BSD` (not defined on macOS)
	- `HN_PLATFORM_FREEBSD`
	- `HN_PLATFORM_NETBSD`
	- `HN_PLATFORM_OPENBSD`
	- `HN_PLATFORM_LINUX` (not defined on Android)
	- `HN_PLATFORM_ANDROID`
	- `HN_PLATFORM_IOS`
	- `HN_PLATFORM_MACOS`
	- `HN_PLATFORM_SOLARIS`
	- `HN_PLATFORM_SUNOS`
	- `HN_PLATFORM_ILLUMOS`
	- `HN_PLATFORM_WINDOWS`
- Processor architecture identification macro which will be one or more
  of:
	- `HN_ARCH_AMD64`
	- `HN_ARCH_ARM32`
	- `HN_ARCH_ARMV4`
	- `HN_ARCH_ARMV5`
	- `HN_ARCH_ARMV6`
	- `HN_ARCH_ARMV7`
	- `HN_ARCH_ARM64`
	- `HN_ARCH_ARMV8`
	- `HN_ARCH_IA16`
	- `HN_ARCH_IA32`
	- `HN_ARCH_IA64`
	- `HN_ARCH_M68K`
	- `HN_ARCH_PPC32`
	- `HN_ARCH_PPC64`
	- `HN_ARCH_RISCV32`
	- `HN_ARCH_RISCV64`
	- `HN_ARCH_SPARC`
- `HN_HAVE_I32` if true 32-bit integrals are available
- `HN_HAVE_I64` if true 64-bit integrals are available
- `HN_HAVE_I128` if compiler-based 128-bit integrals are available
- Endianness identification macros which will be one of:
	- `HN_LILENDIAN`
	- `HN_BIGENDIAN`
	- `HN_PDPENDIAN`
- Pointer size identification macros which will be one of:
	- `HN_PTRSZ_16`
	- `HN_PTRSZ_32`
	- `HN_PTRSZ_64`

### General purpose I/O

Hinterlib provides a functionally congruent wrapper over the classic
`FILE*`-based streaming I/O utilities of `libc`. This wrapper provides
more clarity in its routine type signatures by employing an opaque
structure pointer directly with no macro or `typedef` business, using
shorthands for integrals in seek subroutine parameters, a pure data
mode structure in place of `libc`&rsquo;s string representation, and
friendly utility functions for getting a hold of standard I/O handles
and manipulating the internal standard I/O buffer. All of this is found
in `<hn/file.h>`.

The library also provides a high-level logging utility with message
categorisation, file descriptor redirection and intelligent nesting, all
using pure data structures. All of this is found in `<hn/log.h>`.

### Modular memory toolkit

Hinterlib provides a module called Himem for managing amalgams and knots
_a la_ [software modular memory](https://archive.ph/EnNKK). This is used
by other high level modules in Hinterlib and is to be used by downstream
software to help simplify the abstractions involved without compromising
opacity of the underlying data.

### Non-generic general-purpose containers

The chief in-tree consumer of the Himem software modular memory toolkit,
Hinterlib&rsquo;s container system aims to provide typeless, concrete
data containerisation with SMM characteristic without compromising the
transparency of the underlying data in the view of downstream code. This
will allow data to have the greatest freedom of allocation lifetime,
including even residing on the stack, as full user control of allocation
is preserved by the interface design.

Instead of trying to supplicate a nonexistent abstract type system, it
provides [mechanicalist](https://archive.ph/UOuG1) views of the
underlying data&rsquo;s dimensionality and the quantities and limits
thereof, giving meaningful boundaries for users to ensure validity of
data elements directly.

In addition to this concreteness, Hinterlib&rsquo;s container toolkit
tries to distinguish [abstract data types](https://archive.ph/TBjSM)
from so-called data structures so that it is straightforward to select
arbitrary algorithms that implement the former&rsquo;s desired semantics
regardless of the data type being targeted with it.

### Operating system polyfills

Hinterlib of course must provide agnosticism of various eccentricities
that differ between target operating systems, such as path particle
separator strings and canonical newline forms. It will also provide an
agnostic interface for introspecting about the running program&rsquo;s
location in the file system and the working directory it was invoked
from. It will provide routines to modify the working directory and the
program&rsquo;s apparent environment variable set. Finally, it will
provide a smarter interface for invoking other programs on the running
system, similar in spirit to `libc`&rsquo;s `system()` routine.

### Textual string manipulation tools

Hinterlib&rsquo;s container toolkit will be specialised to provide for
textual data in two forms: ASCII and Unicode. Working copies of ASCII
text will be 8-bit byte-oriented, while Unicode codepoint elements will
be stored as UCS-4 in 32-bit unsigned integers. Separate algorithms will
be implemented to provide ingress and egress of Unicode data from other
encodings which may be used, like UTF-8.

### Comprehensive error handling

Error code propagation is a problem Hinterlib aims to comprehensively
solve by unifying two ideas: return codes and error stacks. The library
facilitates two error code domains: the standard 8-bit POSIX error code
list, and a wider 16-bit &lsquo;extended error code&rsquo; domain which
is application-specific.

Hinterlib library modules must maintain $O(1)$ complexity of their own
error code propagation so as to not need their own error stacks as state
burdening downstream applications. However, downstream applications can
(and _should_) use error stacks to effectively manage complex error
states, especially when some or all of the error codes are non-fatal.

A legible interface will be provided to keep track of a downstream
application&rsquo;s extended error codes, their attributes and their
strings.

### General-purpose data handling utilities

As a matter of course, Hinterlib will help facilitate a great variety of
checksum algorithms, endian conversion, checked integral arithmetic, a
software arbitrary-precision integer (&lsquo;big int&rsquo;) system, and
various common mathematical functions.

### INI/config file parser

Hinterlib provides C subroutines for parsing and serialising INI type
configuration files with various compatibility options for both
Microsoft Windows and Unix style config files. Additionally, it provides
tools to validate INI files against so-called [INI schemas][1], which
also recognise said compatibility options in the course of running the
validation algorithm.

## Footnotes

Versions 1.x of Hinterlib, Hinterlib/Neopolitan, and/or unilib were
released under the BSD-2-Clause licence.

Starting with version 2.0, Hinterlib is now available under version 1.1
of the Artisan Software Licence. See the COPYING file for full terms.

### Origin of the name

[Razib Khan](https://x.com/razibkhan) [wrote](https://archive.ph/CFwmZ)
about the genetic history of those inhabiting the Italian peninsula. In
it he showed that during the height of imperial Rome, an intense
cosmopolitanism attracted an incredible lineage of rulers from as far
away as Syria around the time of its decline. Remarkably, when Rome
depopulated in late antiquity to a mere 30,000 people, the inhabitants
were the same genetically as those who had lived in Italy before the
Roman Empire, as Etruscans. The rural *hinterland* proved more lasting
in our genetics, as those cosmopolitan people lived and died in Rome
leaving no trace of their lineage.

In the time between Hinterlib 2 and the original `unilib`, Hinterlib was
actually one half of a hybrid fork called **Hinterlib/Neopolitan**. This
was created to accommodate the now extraneous &ldquo;Actually Portable
Executable&rdquo; file format, which provided more guarantees Neopolitan
could then presume and pass on downstream that Hinterlib could not.
Despite this fork being defunct, Neopolitan bore the name as a nod to
the &ldquo;Actually Portable Executable&rdquo; format&rsquo;s reference
implementation, &ldquo;Cosmopolitan&rdquo;. In contrast to Neopolitan,
regular `unilib` was renamed to **Hinterlib**.

[1]:https://gist.github.com/nicholatian/05cae747b0d3a8928c85c12d65187ff3
