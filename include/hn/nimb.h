/*****************************************************************************\
 *                          Hinterlib/Neopolitan 2.                          *
 *                                                                           *
 *                      Copyright (C) 2019-2023 Aquefir                      *
 *               Released under Artisan Software Licence v1.1.               *
\*****************************************************************************/

#ifndef INC_API__HN_TYPES_NIMB_H
#define INC_API__HN_TYPES_NIMB_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"

/* Initialise the sentinel bits of a new nimb in memory of a given size. */
void hn_nimb_init( hn_u16 *, hn_ptri );

/* Propagate the sentinel bits through the nimb's underlying memory to occupy
 * a new physical storage size. */
void hn_nimb_resize( hn_u16 *, hn_ptri );

/* Create a nimb from a 16-bit unsigned integer primitive. */
void hn_nimb_from16( hn_u16 *, hn_u16 );

#if defined( _SYNDEF_HAVE_I32 )
/* Create a nimb from a 32-bit unsigned integer primitive. */
void hn_nimb_from32( hn_u16 *, hn_u32 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
/* Create a nimb from a 64-bit unsigned integer primitive. */
void hn_nimb_from64( hn_u16 *, hn_u64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Get the size of the nimb by traversing the sentinel bits therein. */
hn_ptri hn_nimb_getsize( hn_u16 * );

/* Perform a full comparison of two nimbs. */
hn_u8 hn_nimb_compare( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Add two nimbs together. */
hn_bl hn_nimb_add( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Subtract one nimb from another. */
hn_bl hn_nimb_sub( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Logically shift a nimb left. */
void hn_nimb_lsl( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Logically shift a nimb right. */
void hn_nimb_lsr( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Rotate a nimb left. */
void hn_nimb_rol( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Rotate a nimb right. */
void hn_nimb_ror( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Logically AND two nimbs. */
void hn_nimb_and( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Logically OR two nimbs. */
hn_bl hn_nimb_or( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Logically bit inverse a nimb. */
void hn_nimb_not( hn_u16 *, hn_ptri );

/* Logically exclusive-OR two nimbs. */
hn_bl hn_nimb_xor( hn_u16 *, hn_ptri, hn_u16 *, hn_ptri );

/* Count the leading zero bits of a nimb. */
hn_ptri hn_nimb_clz( hn_u16 *, hn_ptri );

/* Count the trailing zero bits of a nimb. */
hn_ptri hn_nimb_ctz( hn_u16 *, hn_ptri );

/* Count the number of high bits in a nimb. */
hn_ptri hn_nimb_pct( hn_u16 *, hn_ptri );

#endif /* INC_API__HN_TYPES_NIMB_H */
