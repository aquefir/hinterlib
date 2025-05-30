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

#include "types/base.h"
#include "types/char.h"
#include "types/int.h"

#include "ct.h"

enum hn_numbase
{
	HN_NUMBASE_BIN,
	HN_NUMBASE_OCT,
	HN_NUMBASE_DEC,
	HN_NUMBASE_HEX,
	HN_NUMBASE_DTH,
	HN_NUMBASE_NTH,
	HN_NUMBASE_THR,
	HN_NUMBASE_B64,
	HN_MAX_NUMBASE
};

/* Initialise the sentinel bits of a new nimb in memory of a given
 * size. */
HN_API hn_bl hn_nimb_init( hn_ptri, hn_bl, struct hn_ct * );

/* Propagate the sentinel bits through the nimb's underlying memory to
 * occupy a new physical storage size. */
HN_API hn_bl hn_nimb_resize( hn_ptri, struct hn_ct * );

/* Create a nimb from a 16-bit unsigned integer primitive. */
HN_API hn_bl hn_nimb_from16( hn_u16, struct hn_ct * );

#if defined( _SYNDEF_HAVE_I32 )
/* Create a nimb from a 32-bit unsigned integer primitive. */
HN_API hn_bl hn_nimb_from32( hn_u32, struct hn_ct * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
/* Create a nimb from a 64-bit unsigned integer primitive. */
HN_API hn_bl hn_nimb_from64( hn_u64, struct hn_ct * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Create a nimb from an ASCII character string. */
HN_API hn_bl hn_nimb_fromstr(
	hn_chr *, enum hn_numbase, struct hn_ct * );

/* Create a 16-bit unsigned integer primitive from a nimb. */
HN_API hn_bl hn_nimb_to16( struct hn_ct *, hn_u16 * );

#if defined( _SYNDEF_HAVE_I32 )
/* Create a 32-bit unsigned integer primitive from a nimb. */
HN_API hn_bl hn_nimb_to32( struct hn_ct *, hn_u32 * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
/* Create a 64-bit unsigned integer primitive from a nimb. */
HN_API hn_bl hn_nimb_to64( struct hn_ct *, hn_u64 * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Create an ASCII character string from a nimb. */
HN_API hn_bl hn_nimb_tostr( struct hn_ct *, enum hn_numbase, hn_chr * );

/* Get the size of the nimb by traversing the sentinel bits therein. */
HN_API hn_ptri hn_nimb_size( struct hn_ct * );

/* Perform a full comparison of two nimbs. */
HN_API hn_u8 hn_nimb_cmp( struct hn_ct, struct hn_ct * );

/* Add two nimbs together. */
HN_API hn_bl hn_nimb_add( struct hn_ct, struct hn_ct * );

/* Subtract one nimb from another. */
HN_API hn_bl hn_nimb_sub( struct hn_ct, struct hn_ct * );

/* Logically shift a nimb left. */
HN_API void hn_nimb_lsl( struct hn_ct, struct hn_ct * );

/* Logically shift a nimb right. */
HN_API void hn_nimb_lsr( struct hn_ct, struct hn_ct * );

/* Rotate a nimb left. */
HN_API void hn_nimb_rol( struct hn_ct, struct hn_ct * );

/* Rotate a nimb right. */
HN_API void hn_nimb_ror( struct hn_ct, struct hn_ct * );

/* Logically AND two nimbs. */
HN_API void hn_nimb_and( struct hn_ct, struct hn_ct * );

/* Logically OR two nimbs. */
HN_API hn_bl hn_nimb_orr( struct hn_ct, struct hn_ct * );

/* Logically bit inverse a nimb. */
HN_API void hn_nimb_not( struct hn_ct * );

/* Logically exclusive-OR two nimbs. */
HN_API hn_bl hn_nimb_xor( struct hn_ct, struct hn_ct * );

/* Count the leading zero bits of a nimb. */
HN_API hn_bl hn_nimb_clz( struct hn_ct, struct hn_ct * );

/* Count the trailing zero bits of a nimb. */
HN_API hn_bl hn_nimb_ctz( struct hn_ct, struct hn_ct * );

/* Count the number of high bits in a nimb. */
HN_API hn_bl hn_nimb_pct( struct hn_ct, struct hn_ct * );

#endif /* INC_API__HN_NIMB_H */
