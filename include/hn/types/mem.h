/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_MEM_H
#define INC_API__HN_TYPES_MEM_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

#if defined( __has_attribute )

#if __has_attribute( packed )
#if !defined( HN_PACKED )
/* Force the structure to be tightly packed into as few octets as
 * possible. */
#define HN_PACKED __attribute__( ( packed ) )
#endif /* !defined( HN_PACKED ) */
#endif /* __has_attribute( packed ) */

#if __has_attribute( may_alias )
#if !defined( HN_TYPELESS )
/* Prevents the compiler from doing type analysis based optimisations
 * on the type, treating it as octet-addressable cast-friendly data. */
#define HN_TYPELESS __attribute__( ( may_alias ) )
#endif /* !defined( HN_TYPELESS ) */
#endif /* __has_attribute( may_alias ) */

#endif /* defined( __has_attribute ) */

#if !defined( HN_SIZEOF_PTR )
#if defined( _SYNDEF_PTRSZ_64 )
/* Denotes the size of a pointer at runtime, denominated in octets. */
#define HN_SIZEOF_PTR 8
#elif defined( _SYNDEF_PTRSZ_32 )
/* Denotes the size of a pointer at runtime, denominated in octets. */
#define HN_SIZEOF_PTR 4
#elif defined( _SYNDEF_PTRSZ_16 )
/* Denotes the size of a pointer at runtime, denominated in octets. */
#define HN_SIZEOF_PTR 2
#else
#error Pointer size is not 64, 32 or 16 bits.
#endif
#endif /* !defined( HN_SIZEOF_PTR ) */

/* fallback #defines in case attributes are not supported */

#if !defined( HN_PACKED )
#define HN_PACKED
#endif /* !defined( HN_PACKED ) */

#if !defined( HN_TYPELESS )
#define HN_TYPELESS
#endif /* !defined( HN_TYPELESS ) */

/**
 * Software Modular Memory Technique
 *
 * knot: a block of memory sized to a fixed number of octets that is an
 *       exponent of two. Usually this exponent is 8, 12, 16 or 20.
 * amalgam: a small collection of metadata used to string knots
 *          together into larger pieces of structured memory
 *
 * Hinterlib's heap allocators will not provide arbitrary stretches of
 * memory upon request as this does not bode well with machines that
 * do not provide the incredibly energy-intensive virtual memory
 * provisions via an MMU. To help fight the incidence of fragmentation
 * without such smoke-and-mirrors, the allocators instead will give
 * callers a knot of memory of a certain size. With masking of higher
 * bits, this knot can be looped over in a circular fashion at quite a
 * negligible computational cost.
 *
 * Container implementations will work on amalgams of these building
 * blocks, which may be sequential (i.e. contiguous) or sparse.
 * Amalgams have a length, an element size, and a pointer dataset: in
 * sequential amalgams, the pointer dataset is merely one pointer to
 * the head of the sequence of knots, while in sparse amalgams, the
 * pointer dataset is an array of pointers to each knot in sequence.
 *
 * Amalgams themselves would either occupy automatic storage or reside
 * in a knot in their own right. Sparse amalgams may need larger knots
 * to hold their full pointer lists. For reference:
 *   - 8-knots => 63 (32-bit) / 31 (64-bit) elements
 *   - 12-knots => 1023 (32-bit) / 511 (64-bit) elements
 *   - 16-knots => 16383 (32-bit) / 8191 (64-bit) elements
 *   - 20-knots => 262143 (32-bit) / 131071 (64-bit) elements
 *
 * We can then chart this to see total memory capacity of every kind of
 * sparse amalgam. First is on 32-bit machines, then on 64-bit:
 *
 * Elem=> |  8-bit  |  12-bit |  16-bit | 20-bit
 * -------+---------+---------+---------+-----------
 *  8-bit |  ~16KB  |  ~258KB |   ~4MB  |   ~66MB
 * 12-bit |  ~261KB |  ~4.2MB |  ~67MB  |  ~1073MB
 * 16-bit |  ~4.2MB |  ~67MB  | ~1074MB |  ~17.2GB
 * 20-bit | ~67.1MB | ~1074MB | ~17.2GB |  ~274.9GB
 *
 * Elem=> |  8-bit  |  12-bit |  16-bit | 20-bit
 * -------+---------+---------+---------+-----------
 *  8-bit |   ~8KB  |  ~129KB |   ~2MB  |   ~33MB
 * 12-bit |  ~131KB |  ~2.1MB | ~33.5MB |  ~535.8MB
 * 16-bit |  ~2.1MB | ~33.5MB |  ~537MB |   ~8.6GB
 * 20-bit | ~33.5MB |  ~537MB |  ~8.6GB |  ~137.4GB
 *
 * Additionally, here are the memory capacities of 8-, 12- and 16-bit
 * amalgams on 16-bit machines:
 *
 * Elem=> |  8-bit |  12-bit  |  16-bit
 * -------+---------+---------+----------
 *  8-bit |  ~32KB |  ~520KB  |  ~8.3MB
 * 12-bit | ~524KB |  ~8.4MB  | ~134.1MB
 * 16-bit | ~8.4MB | ~134.2MB |  ~2.1GB
 *
 * These limits naturally do not apply to sequential amalgams, which
 * are only limited by the amount of installed memory. If you are
 * dealing with so much sparse data anyway, these structures can only
 * impose a linear at worst cost basis for use, which is negligible
 * compared to the overall cost of using a linked list strategy to
 * handle large data anyway. More robust solutions will invariably
 * require transforming such sparse data into contiguous runs where
 * needed.
 */

#if !defined( HN_KNOT8_NORM )
/* Normalise an 8-bit knot by zeroing out its lower bits. */
#define HN_KNOT8_NORM( _kn ) \
	(void *)( ( (__UINTPTR_TYPE__)( _kn ) >> 8 ) << 8 )
#endif /* !defined( HN_KNOT8_NORM ) */

#if !defined( HN_KNOT12_NORM )
/* Normalise a 12-bit knot by zeroing out its lower bits. */
#define HN_KNOT12_NORM( _kn ) \
	(void *)( ( (__UINTPTR_TYPE__)( _kn ) >> 12 ) << 12 )
#endif /* !defined( HN_KNOT12_NORM ) */

#if !defined( HN_KNOT16_NORM )
/* Normalise a 16-bit knot by zeroing out its lower bits. */
#define HN_KNOT16_NORM( _kn ) \
	(void *)( ( (__UINTPTR_TYPE__)( _kn ) >> 16 ) << 16 )
#endif /* !defined( HN_KNOT16_NORM ) */

#if HN_SIZEOF_PTR > 2 && !defined( HN_KNOT20_NORM )
/* Normalise a 20-bit knot by zeroing out its lower bits. */
#define HN_KNOT20_NORM( _kn ) \
	(void *)( ( (__UINTPTR_TYPE__)( _kn ) >> 20 ) << 20 )
#endif /* !defined( HN_KNOT20_NORM ) */

/* 8-bit memory knot addressing a contiguous block of 256 bytes. */
typedef __UINT8_TYPE__ ( *hn_knot8 )[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef __UINT8_TYPE__ ( *hn_knot12 )[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef __UINT8_TYPE__ ( *hn_knot16 )[65536] HN_TYPELESS;
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef __UINT8_TYPE__ ( *hn_knot20 )[1048576] HN_TYPELESS;

/* Sparse 1D amalgam of 8-bit knots. */
struct hn_am8d1
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot8 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 1D amalgam of 12-bit knots. */
struct hn_am12d1
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot12 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 1D amalgam of 16-bit knots. */
struct hn_am16d1
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot16 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 1D amalgam of 20-bit knots. */
struct hn_am20d1
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot20 data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 2D amalgam of 8-bit knots. */
struct hn_am8d2
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 2D amalgam of 12-bit knots. */
struct hn_am12d2
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 2D amalgam of 16-bit knots. */
struct hn_am16d2
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 2D amalgam of 20-bit knots. */
struct hn_am20d2
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d1 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 3D amalgam of 8-bit knots. */
struct hn_am8d3
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 3D amalgam of 12-bit knots. */
struct hn_am12d3
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 3D amalgam of 16-bit knots. */
struct hn_am16d3
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 3D amalgam of 20-bit knots. */
struct hn_am20d3
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d2 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

/* Sparse 4D amalgam of 8-bit knots. */
struct hn_am8d4
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am8d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 4D amalgam of 12-bit knots. */
struct hn_am12d4
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am12d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

/* Sparse 4D amalgam of 16-bit knots. */
struct hn_am16d4
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am16d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;

#if HN_SIZEOF_PTR > 2
/* Sparse 4D amalgam of 20-bit knots. */
struct hn_am20d4
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	struct hn_am20d3 * data[( 65536 / HN_SIZEOF_PTR ) - 1];
} HN_TYPELESS;
#endif /* HN_SIZEOF_PTR > 2 */

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
typedef __UINT8_TYPE__ ( *knot8 )[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef __UINT8_TYPE__ ( *knot12 )[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef __UINT8_TYPE__ ( *knot16 )[65536] HN_TYPELESS;
#if HN_SIZEOF_PTR > 2
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef __UINT8_TYPE__ ( *knot20 )[1048576] HN_TYPELESS;
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

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_MEM_H */
