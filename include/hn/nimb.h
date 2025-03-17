/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_NIMB_H
#define INC_API__HN_NIMB_H

/**
 * Functions for manipulating nimbs. Nimbs are arbitrary precision
 * integers composed of arrays of u16s in memory using sentinel bits to
 * link them together. They are a foundational component of data types
 * in Hinterlib such as buffers and trees, where their semantics are
 * used to provide unlimited extensibility without depending on having
 * large machine pointers. Given a pointer to a u16 as a nimb, it can
 * be comprehended by traversing it, advancing to the next element when
 * the current element has its most significant bit (bit 15) high, and
 * stopping at the first element that has its MSB low. All memory
 * management is left to the user and should be equally workable with
 * both heap-based and automatic stack-based storage.
 *
 * Hinterlib's nimb ABI uses both sparse and sequential amalgams of
 * 8-bit knots which contain the underlying integer data. This module
 * will always respect the .len field of the given amalgam, so one can
 * use compressed amalgams with this ABI.
 */

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

#include "types/base.h"
#include "types/char.h"
#include "types/int.h"
#include "types/mem.h"

enum hn_numbase
{
	HN_NUMBASE_BIN,
	HN_NUMBASE_OCT,
	HN_NUMBASE_DEC,
	HN_NUMBASE_HEX,
	HN_NUMBASE_DTH,
	HN_NUMBASE_THR,
	HN_NUMBASE_B64,
	HN_MAX_NUMBASE
};

struct hn_nimb
{
	/* Whether the amalgam is sequential: 1 if so, 0 if sparse. */
	hn_bl seq;
	/* The amalgam containing the knots containing the nimb data.
	 * If the amalgam is actually sparse, cast it as such and use it
	 * while respecting the value of .len. */
	hn_am8seq am;
};

/* Arbitrary precision integer container and serialisation format. */
typedef struct hn_nimb hn_nimb;

/* Initialise the sentinel bits of a new nimb in memory of a given
 * size. */
hn_bl hn_nimb_init( hn_ptri, hn_bl, hn_nimb * );

/* Propagate the sentinel bits through the nimb's underlying memory to
 * occupy a new physical storage size. */
hn_bl hn_nimb_resize( hn_ptri, hn_nimb * );

/* Create a nimb from a 16-bit unsigned integer primitive. */
hn_bl hn_nimb_from16( hn_u16, hn_nimb * );

#if defined( _SYNDEF_HAVE_I32 )
/* Create a nimb from a 32-bit unsigned integer primitive. */
hn_bl hn_nimb_from32( hn_u32, hn_nimb * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
/* Create a nimb from a 64-bit unsigned integer primitive. */
hn_bl hn_nimb_from64( hn_u64, hn_nimb * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Create a nimb from an ASCII character string. */
hn_bl hn_nimb_fromstr( hn_chr *, enum hn_numbase, hn_nimb * );

/* Create a 16-bit unsigned integer primitive from a nimb. */
hn_bl hn_nimb_to16( hn_nimb *, hn_u16 * );

#if defined( _SYNDEF_HAVE_I32 )
/* Create a 32-bit unsigned integer primitive from a nimb. */
hn_bl hn_nimb_to32( hn_nimb *, hn_u32 * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
/* Create a 64-bit unsigned integer primitive from a nimb. */
hn_bl hn_nimb_to64( hn_nimb *, hn_u64 * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Create an ASCII character string from a nimb. */
hn_bl hn_nimb_tostr( hn_nimb *, enum hn_numbase, hn_chr * );

/* Get the size of the nimb by traversing the sentinel bits therein. */
hn_ptri hn_nimb_size( hn_nimb * );

/* Perform a full comparison of two nimbs. */
hn_u8 hn_nimb_cmp( hn_nimb, hn_nimb * );

/* Add two nimbs together. */
hn_bl hn_nimb_add( hn_nimb, hn_nimb * );

/* Subtract one nimb from another. */
hn_bl hn_nimb_sub( hn_nimb, hn_nimb * );

/* Logically shift a nimb left. */
void hn_nimb_lsl( hn_nimb, hn_nimb * );

/* Logically shift a nimb right. */
void hn_nimb_lsr( hn_nimb, hn_nimb * );

/* Rotate a nimb left. */
void hn_nimb_rol( hn_nimb, hn_nimb * );

/* Rotate a nimb right. */
void hn_nimb_ror( hn_nimb, hn_nimb * );

/* Logically AND two nimbs. */
void hn_nimb_and( hn_nimb, hn_nimb * );

/* Logically OR two nimbs. */
hn_bl hn_nimb_orr( hn_nimb, hn_nimb * );

/* Logically bit inverse a nimb. */
void hn_nimb_not( hn_nimb * );

/* Logically exclusive-OR two nimbs. */
hn_bl hn_nimb_xor( hn_nimb, hn_nimb * );

/* Count the leading zero bits of a nimb. */
hn_bl hn_nimb_clz( hn_nimb, hn_nimb * );

/* Count the trailing zero bits of a nimb. */
hn_bl hn_nimb_ctz( hn_nimb, hn_nimb * );

/* Count the number of high bits in a nimb. */
hn_bl hn_nimb_pct( hn_nimb, hn_nimb * );

#endif /* INC_API__HN_NIMB_H */
