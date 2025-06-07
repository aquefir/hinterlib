/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_MEM_H
#define INC_API__HN_TYPES_MEM_H

#include "base.h"
#include "int.h"

/**
 * Software Modular Memory Technique
 *
 * knot: a block of memory sized to a fixed number of octets that is an
 *       exponent of two. Usually this exponent is 8, 12, 16 or 20.
 * amalgam: a small collection of metadata used to string knots
 *          together into larger pieces of structured memory
 *
 * While Hinterlib does provide a typical flat heap allocator with a
 * modest alignment of 64 octets, this is prone to fragmentation on many
 * systems where the energy-intensive machinations of an MMU giving it
 * virtual addresses does not exist. To help prevent fragmentation while
 * ensuring full control of memory management to the API consumer, a
 * technique called "software modular memory" has been invented.
 *
 * Small, fixed size allocations are strung together as elements of a
 * linked list and treated by the program as a coherent structure of a
 * larger block of memory. These small, fixed size allocations are
 * called "knots" and they come in sizes of 8, 12, 16 and 20 bits for
 * capacities of 256, 4096, 65535 and 1048576 bytes, respectively.
 *
 * To bind these knots together, a small metadata structure that should
 * fit in all practicable machine registers (no more than 16 bits) is
 * used. This is called an "amalgam" and it holds the information on how
 * many dimensions are ultimately to be found in its contents, and from
 * there it can be deduced by examining the knot headers what the
 * ultimate size of the amalgamated memory allocation is. Amalgams refer
 * to anywhere from 1 to 4 layers, or dimensions, of 16-bit knots,
 * beneath which is a knot of any size that contains all of the user
 * data. This knot bearing the data is called the "base knot".
 *
 * With up to 4 dimensions, the tables below show the maximum capacity
 * of amalgams with various base sizes on machines of various memory
 * space sizes. Actual sizes are very slightly (sub-linearly) less as
 * each amalgam consumes one element at the start to hold its size.
 *
 * 16-BIT MEMORY SPACE :-
 *     | BASE KNOT
 * DIM |    8   |   12   |    16
 *  1  |   8MiB | 128MiB |   2GiB
 *  2  | 256GiB |   4TiB |  64TiB
 *  3  |   8PiB | 128PiB |   2EiB
 *  4  | 256EiB |   4ZiB |  64ZiB
 *
 * 32-BIT MEMORY SPACE :-
 *     | BASE KNOT
 * DIM |    8   |   12   |   16   |    20
 *  1  |   4MiB |  64MiB |   1GiB |   16GiB
 *  2  |  64GiB |   1TiB |  16TiB |  256TiB
 *  3  |   1PiB |  16PiB | 256PiB |    4EiB
 *  4  |  16EiB | 256EiB |   4ZiB |   64ZiB
 *
 * 64-BIT MEMORY SPACE :-
 *     | BASE KNOT
 * DIM |    8   |   12   |   16   |    20
 *  1  |   2MiB |  32MiB | 512MiB |   8GiB
 *  2  |  16GiB | 256GiB |   4TiB |  64TiB
 *  3  | 128TiB |   2PiB |  32PiB | 512PiB
 *  4  |   1EiB |  16EiB | 256EiB |   4ZiB
 *
 * From this, several things become apparent:
 *  1. Even in the worst case on 64-bit machines, amalgams with 20-bit
 *     base knots outperform flat pointers in sheer addressability,
 *     providing 2^72 bits over a theoretical maximum of 2^64 addresses
 *     and a practical maximum of 2^48 addresses.
 *  2. Overall, smaller pointer sizes are better for addressibility:
 *     16-bit machines provide 20^76 addresses with 4 dimensions. They
 *     are also the least wasteful when using smaller base knot sizes.
 *  3. For a given dimension count, 16-bit pointers with 16-bit base
 *     knots provide as much addressability as 32-bit pointers with
 *     20-bit base knots.
 *  4. Adding an interface boundary to the transition between knots
 *     makes addressing such vast sums of memory practical, as it can be
 *     implemented arbitrarily to change out any number of backing
 *     devices while maintaining coherence for the program.
 *
 * While this interface is only for defining the structures of software
 * modular memory, implementations should nonetheless follow a few
 * rules:
 *  1. When allocating knots, they must be self-aligned; that is, they
 *     begin on a memory addressing boundary that matches their size.
 *     This allows one to simply zero out the lower bits according to
 *     its size and the result is the beginning of the knot.
 *  2. A knot should always be fully allocated according to its size and
 *     dumbly addressable sequentially. Any non-continuity must be
 *     transparent to the program, and should be nonexistent if the
 *     efficiency gains from this technique are desired.
 */

#if !defined( HN_KNOT8_NORM )
/* Normalise an 8-bit knot by zeroing out its lower bits. */
#define HN_KNOT8_NORM( _kn ) (void *)( ( (hn_ptri)( _kn ) >> 8 ) << 8 )
#endif /* !defined( HN_KNOT8_NORM ) */

#if !defined( HN_KNOT12_NORM )
/* Normalise a 12-bit knot by zeroing out its lower bits. */
#define HN_KNOT12_NORM( _kn ) \
	(void *)( ( (hn_ptri)( _kn ) >> 12 ) << 12 )
#endif /* !defined( HN_KNOT12_NORM ) */

#if !defined( HN_KNOT16_NORM )
/* Normalise a 16-bit knot by zeroing out its lower bits. */
#define HN_KNOT16_NORM( _kn ) \
	(void *)( ( (hn_ptri)( _kn ) >> 16 ) << 16 )
#endif /* !defined( HN_KNOT16_NORM ) */

#if HN_SIZEOF_PTR > 2 && !defined( HN_KNOT20_NORM )
/* Normalise a 20-bit knot by zeroing out its lower bits. */
#define HN_KNOT20_NORM( _kn ) \
	(void *)( ( (hn_ptri)( _kn ) >> 20 ) << 20 )
#endif /* !defined( HN_KNOT20_NORM ) */

/* 8-bit memory knot addressing a contiguous block of 256 bytes. */
typedef hn_u8 ( *hn_knot8 )[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef hn_u8 ( *hn_knot12 )[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef hn_u8 ( *hn_knot16 )[65536] HN_TYPELESS;
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef hn_u8 ( *hn_knot20 )[1048576] HN_TYPELESS;

/* Sparse 1D amalgam of 8-bit knots. */
struct hn_am8d1
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot8 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 1D amalgam of 12-bit knots. */
struct hn_am12d1
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot12 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 1D amalgam of 16-bit knots. */
struct hn_am16d1
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot16 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 1D amalgam of 20-bit knots. */
struct hn_am20d1
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot20 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 2D amalgam of 8-bit knots. */
struct hn_am8d2
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 2D amalgam of 12-bit knots. */
struct hn_am12d2
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 2D amalgam of 16-bit knots. */
struct hn_am16d2
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 2D amalgam of 20-bit knots. */
struct hn_am20d2
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 3D amalgam of 8-bit knots. */
struct hn_am8d3
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 3D amalgam of 12-bit knots. */
struct hn_am12d3
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 3D amalgam of 16-bit knots. */
struct hn_am16d3
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 3D amalgam of 20-bit knots. */
struct hn_am20d3
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 4D amalgam of 8-bit knots. */
struct hn_am8d4
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 4D amalgam of 12-bit knots. */
struct hn_am12d4
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 4D amalgam of 16-bit knots. */
struct hn_am16d4
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 4D amalgam of 20-bit knots. */
struct hn_am20d4
{
	/* Length of amalgam, denominated in elements. */
	hn_ptri len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Offset particle of an amalgam. */
struct hn_amoffs
{
#if HN_SIZEOF_PTR == 2
	hn_ubf n : 15 HN_PACKED;
	hn_ubf : 1 HN_PACKED;
#elif HN_SIZEOF_PTR == 4
	hn_ubf n : 14 HN_PACKED;
	hn_ubf : 2 HN_PACKED;
#elif HN_SIZEOF_PTR == 8
	/* Amalgam offset. */
	hn_ubf n : 13 HN_PACKED;
	hn_ubf : 3 HN_PACKED;
#endif /* HN_SIZEOF_PTR */
};

/* Sparse 1D amalgam of 8-bit knots. */
typedef struct hn_am8d1 hn_am8d1;
/* Sparse 1D amalgam of 12-bit knots. */
typedef struct hn_am12d1 hn_am12d1;
/* Sparse 1D amalgam of 16-bit knots. */
typedef struct hn_am16d1 hn_am16d1;
#if HN_SIZEOF_PTR > 2
/* Sparse 1D amalgam of 20-bit knots. */
typedef struct hn_am20d1 hn_am20d1;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 2D amalgam of 8-bit knots. */
typedef struct hn_am8d2 hn_am8d2;
/* Sparse 2D amalgam of 12-bit knots. */
typedef struct hn_am12d2 hn_am12d2;
/* Sparse 2D amalgam of 16-bit knots. */
typedef struct hn_am16d2 hn_am16d2;
#if HN_SIZEOF_PTR > 2
/* Sparse 2D amalgam of 20-bit knots. */
typedef struct hn_am20d2 hn_am20d2;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 3D amalgam of 8-bit knots. */
typedef struct hn_am8d3 hn_am8d3;
/* Sparse 3D amalgam of 12-bit knots. */
typedef struct hn_am12d3 hn_am12d3;
/* Sparse 3D amalgam of 16-bit knots. */
typedef struct hn_am16d3 hn_am16d3;
#if HN_SIZEOF_PTR > 2
/* Sparse 3D amalgam of 20-bit knots. */
typedef struct hn_am20d3 hn_am20d3;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 4D amalgam of 8-bit knots. */
typedef struct hn_am8d4 hn_am8d4;
/* Sparse 4D amalgam of 12-bit knots. */
typedef struct hn_am12d4 hn_am12d4;
/* Sparse 4D amalgam of 16-bit knots. */
typedef struct hn_am16d4 hn_am16d4;
#if HN_SIZEOF_PTR > 2
/* Sparse 4D amalgam of 20-bit knots. */
typedef struct hn_am20d4 hn_am20d4;
#endif /* HN_SIZEOF_PTR > 2 */

/* Offset particle of an amalgam. */
typedef struct hn_amoffs hn_amoffs;

enum hn_max_amoffs
{
#if HN_SIZEOF_PTR == 2
	HN_MAX_AMALGAM_ELEMS = 32768
#elif HN_SIZEOF_PTR == 4
	HN_MAX_AMALGAM_ELEMS = 16384
#elif HN_SIZEOF_PTR == 8
	HN_MAX_AMALGAM_ELEMS = 8192
#endif /* HN_SIZEOF_PTR */
};

enum hn_baseknotsz
{
	HN_BASEKNOTSZ_8,
	HN_BASEKNOTSZ_12,
	HN_BASEKNOTSZ_16,
	HN_BASEKNOTSZ_20,
	HN_MAX_BASEKNOTSZ
};

/* Amalgam shape description structure. */
struct hn_amalgam
{
	/* Knot base; see `enum hn_baseknotsz` for valid values. */
	hn_ubf baseknot_sz : 2;
	/* Number of subdivisions; this is the number of dimensions
	 * minus one (one-dimensional amalgams have zero subdivisions).
	 */
	hn_ubf subdiv_ct : 2;
	hn_ubf : 2;
	hn_ubf : 10;
	hn_ubf : 16;
};

/* Custom allocator options structure. */
struct hn_malloc_opts
{
	/* Exponent for alignment in `log(2)`. Can align up to 2GiB. */
	hn_ubf alignment : 5;
	/* Whether allocator is the x variant (succeeds or dies). */
	hn_ubf succeedordie : 1;
	hn_ubf : 10;
	hn_ubf : 16;
};

/* Allocation subroutine signature for custom allocators. */
typedef void * ( *hn_malloc_f )( hn_ptri );

/* Deallocation subroutine signature for custom allocators. */
typedef void ( *hn_free_f )( void * );

#if !defined( _CFGOPT_NOSHORTHAND )

/* 8-bit memory knot addressing a contiguous block of 256 bytes. */
typedef hn_u8 ( *knot8 )[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef hn_u8 ( *knot12 )[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef hn_u8 ( *knot16 )[65536] HN_TYPELESS;
#if HN_SIZEOF_PTR > 2
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef hn_u8 ( *knot20 )[1048576] HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 1D amalgam of 8-bit knots. */
typedef struct hn_am8d1 am8d1;
/* Sparse 1D amalgam of 12-bit knots. */
typedef struct hn_am12d1 am12d1;
/* Sparse 1D amalgam of 16-bit knots. */
typedef struct hn_am16d1 am16d1;
#if HN_SIZEOF_PTR > 2
/* Sparse 1D amalgam of 20-bit knots. */
typedef struct hn_am20d1 am20d1;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 2D amalgam of 8-bit knots. */
typedef struct hn_am8d2 am8d2;
/* Sparse 2D amalgam of 12-bit knots. */
typedef struct hn_am12d2 am12d2;
/* Sparse 2D amalgam of 16-bit knots. */
typedef struct hn_am16d2 am16d2;
#if HN_SIZEOF_PTR > 2
/* Sparse 2D amalgam of 20-bit knots. */
typedef struct hn_am20d2 am20d2;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 3D amalgam of 8-bit knots. */
typedef struct hn_am8d3 am8d3;
/* Sparse 3D amalgam of 12-bit knots. */
typedef struct hn_am12d3 am12d3;
/* Sparse 3D amalgam of 16-bit knots. */
typedef struct hn_am16d3 am16d3;
#if HN_SIZEOF_PTR > 2
/* Sparse 3D amalgam of 20-bit knots. */
typedef struct hn_am20d3 am20d3;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 4D amalgam of 8-bit knots. */
typedef struct hn_am8d4 am8d4;
/* Sparse 4D amalgam of 12-bit knots. */
typedef struct hn_am12d4 am12d4;
/* Sparse 4D amalgam of 16-bit knots. */
typedef struct hn_am16d4 am16d4;
#if HN_SIZEOF_PTR > 2
/* Sparse 4D amalgam of 20-bit knots. */
typedef struct hn_am20d4 am20d4;
#endif /* HN_SIZEOF_PTR > 2 */

/* Offset particle of an amalgam. */
typedef struct hn_amoffs amoffs;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_MEM_H */
