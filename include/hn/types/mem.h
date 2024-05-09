/*********************************************************************\
 *                      Hinterlib/Neopolitan 2.                      *
 *                                                                   *
 *                  Copyright (C) 2019-2024 Aquefir                  *
 *           Released under Artisan Software Licence v1.1.           *
\*********************************************************************/

#ifndef INC_API__HN_TYPES_MEM_H
#define INC_API__HN_TYPES_MEM_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
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
 * These limits naturally do not apply to sequential amalgams, which
 * are only limited by the amount of installed memory. If you are
 * dealing with so much sparse data anyway, these structures can only
 * impose a linear at worst cost basis for use, which is negligible
 * compared to the overall cost of using a linked list strategy to
 * handle large data anyway. More robust solutions will invariably
 * require transforming such sparse data into contiguous runs where
 * needed.
 */

/* Gets a traversable pointer from an 8-bit knot. */
#define HN_PTRFROMKNOT8( _k ) \
	(__UINT8_TYPE__ *)( (__UINTPTR_TYPE__)( _k ) << 8 )

/* Gets an 8-bit knot from a pointer that was created for use within
 * that knot. */
#define HN_KNOT8FROMPTR( _p ) \
	(hn_knot8)( (__UINTPTR_TYPE__)( _p ) >> 8 )

/* Controlled increment of an 8-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT8PTR_INCR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 8 ) << 8 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFF ) + ( _n ) ) & 0xFF ) )

/* Controlled decrement of an 8-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT8PTR_DECR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 8 ) << 8 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFF ) - ( _n ) ) & 0xFF ) )

/* Gets a traversable pointer from a 12-bit knot. */
#define HN_PTRFROMKNOT12( _k ) \
	(__UINT8_TYPE__ *)( (__UINTPTR_TYPE__)( _k ) << 12 )

/* Gets a 12-bit knot from a pointer that was created for use within
 * that knot. */
#define HN_KNOT12FROMPTR( _p ) \
	(hn_knot12)( (__UINTPTR_TYPE__)( _p ) >> 12 )

/* Controlled increment of a 12-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT12PTR_INCR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 12 ) << 12 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFF ) + ( _n ) ) & 0xFFF ) )

/* Controlled decrement of a 12-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT12PTR_DECR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 12 ) << 12 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFF ) - ( _n ) ) & 0xFFF ) )

/* Gets a traversable pointer from a 16-bit knot. */
#define HN_PTRFROMKNOT16( _k ) \
	(__UINT8_TYPE__ *)( (__UINTPTR_TYPE__)( _k ) << 16 )

/* Gets a 16-bit knot from a pointer that was created for use within
 * that knot. */
#define HN_KNOT16FROMPTR( _p ) \
	(hn_knot16)( (__UINTPTR_TYPE__)( _p ) >> 16 )

/* Controlled increment of a 16-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT16PTR_INCR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 16 ) << 16 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFFF ) + ( _n ) ) & 0xFFFF ) )

/* Controlled decrement of a 16-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT16PTR_DECR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 16 ) << 16 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFFF ) - ( _n ) ) & 0xFFFF ) )

/* Gets a traversable pointer from a 20-bit knot. */
#define HN_PTRFROMKNOT20( _k ) \
	(__UINT8_TYPE__ *)( (__UINTPTR_TYPE__)( _k ) << 20 )

/* Gets a 20-bit knot from a pointer that was created for use within
 * that knot. */
#define HN_KNOT20FROMPTR( _p ) \
	(hn_knot20)( (__UINTPTR_TYPE__)( _p ) >> 20 )

/* Controlled increment of a 20-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT20PTR_INCR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 20 ) << 20 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFFFF ) + ( _n ) ) & 0xFFFFF ) )

/* Controlled decrement of a 20-bit knot so that it overflows in a
 * predictable way like unsigned integers usually do. */
#define HN_KNOT20PTR_DECR( _k, _n ) \
	(void *)( ( ( (__UINTPTR_TYPE__)( _k ) >> 20 ) << 20 ) | \
	( ( ( (__UINTPTR_TYPE__)( _k ) & 0xFFFFF ) - ( _n ) ) & 0xFFFFF ) )

/* 8-bit memory knot addressing a contiguous block of 256 bytes. */
typedef __UINT8_TYPE__ (* hn_knot8)[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef __UINT8_TYPE__ (* hn_knot12)[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef __UINT8_TYPE__ (* hn_knot16)[65536] HN_TYPELESS;
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef __UINT8_TYPE__ (* hn_knot20)[1048576] HN_TYPELESS;

/* Sequential amalgam of 8-bit knots. */
struct hn_amalsq8
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Pointer to the first knot. The rest are assumed to follow in
	 * memory. */
	hn_knot8 * data;
};

/* Sequential amalgam of 12-bit knots. */
struct hn_amalsq12
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Pointer to the first knot. The rest are assumed to follow in
	 * memory. */
	hn_knot12 * data;
};

/* Sequential amalgam of 16-bit knots. */
struct hn_amalsq16
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Pointer to the first knot. The rest are assumed to follow in
	 * memory. */
	hn_knot16 * data;
};

/* Sequential amalgam of 20-bit knots. */
struct hn_amalsq20
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Pointer to the first knot. The rest are assumed to follow in
	 * memory. */
	hn_knot20 * data;
};

/* Sparse amalgam of 8-bit knots. */
struct hn_amalsp8
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot8 * data[0];
};

/* Sparse amalgam of 12-bit knots. */
struct hn_amalsp12
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot12 * data[0];
};

/* Sparse amalgam of 16-bit knots. */
struct hn_amalsp16
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot16 * data[0];
};

/* Sparse amalgam of 20-bit knots. */
struct hn_amalsp20
{
	/* Length of amalgam, denominated in elements. */
	__UINTPTR_TYPE__ len;
	/* Flexible array head containing the beginning of the array of
	 * pointers to the knots. */
	hn_knot20 * data[0];
};

/* Sequential amalgam of 8-bit knots. */
typedef struct hn_amalsq8 hn_amalsq8;

/* Sequential amalgam of 12-bit knots. */
typedef struct hn_amalsq12 hn_amalsq12;

/* Sequential amalgam of 16-bit knots. */
typedef struct hn_amalsq16 hn_amalsq16;

/* Sequential amalgam of 20-bit knots. */
typedef struct hn_amalsq20 hn_amalsq20;

/* Sparse amalgam of 8-bit knots. */
typedef struct hn_amalsp8 hn_amalsp8;

/* Sparse amalgam of 12-bit knots. */
typedef struct hn_amalsp12 hn_amalsp12;

/* Sparse amalgam of 16-bit knots. */
typedef struct hn_amalsp16 hn_amalsp16;

/* Sparse amalgam of 20-bit knots. */
typedef struct hn_amalsp20 hn_amalsp20;

#if !defined( _CFGOPT_NOSHORTHAND )

/* 8-bit memory knot addressing a contiguous block of 256 bytes. */
typedef __UINT8_TYPE__ (* knot8)[256] HN_TYPELESS;
/* 12-bit memory knot addressing a contiguous block of 4096 bytes. */
typedef __UINT8_TYPE__ (* knot12)[4096] HN_TYPELESS;
/* 16-bit memory knot addressing a contiguous block of 64 kibibytes. */
typedef __UINT8_TYPE__ (* knot16)[65536] HN_TYPELESS;
/* 20-bit memory knot addressing a contiguous block of 1 mebibyte. */
typedef __UINT8_TYPE__ (* knot20)[1048576] HN_TYPELESS;

/* Sequential amalgam of 8-bit knots. */
typedef struct hn_amalsq8 amalsq8;

/* Sequential amalgam of 12-bit knots. */
typedef struct hn_amalsq12 amalsq12;

/* Sequential amalgam of 16-bit knots. */
typedef struct hn_amalsq16 amalsq16;

/* Sequential amalgam of 20-bit knots. */
typedef struct hn_amalsq20 amalsq20;

/* Sparse amalgam of 8-bit knots. */
typedef struct hn_amalsp8 amalsp8;

/* Sparse amalgam of 12-bit knots. */
typedef struct hn_amalsp12 amalsp12;

/* Sparse amalgam of 16-bit knots. */
typedef struct hn_amalsp16 amalsp16;

/* Sparse amalgam of 20-bit knots. */
typedef struct hn_amalsp20 amalsp20;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_MEM_H */
