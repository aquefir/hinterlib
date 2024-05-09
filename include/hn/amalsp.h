/*********************************************************************\
 *                      Hinterlib/Neopolitan 2.                      *
 *                                                                   *
 *                  Copyright (C) 2019-2024 Aquefir                  *
 *           Released under Artisan Software Licence v1.1.           *
\*********************************************************************/

#ifndef INC_API__HN_AMALSP_H
#define INC_API__HN_AMALSP_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/mem.h"

#if !defined( HN_AMALSP_SPACE )
#define HN_AMALSP_SPACE( _n ) \
	( sizeof( void * ) * ( ( _n ) + 1 ) )
#endif /* !defined( HN_AMALSP_SPACE ) */

void hn_amalsp8_init( hn_ptri, hn_knot8 *, hn_amalsp8 * );

void hn_amalsp8_cpy( hn_amalsp8 *, hn_amalsp8 * );

hn_knot8 hn_amalsp8_get( hn_amalsp8 *, ptri );

hn_knot8 hn_amalsp8_ovr( hn_amalsp8 *, ptri, hn_knot8 );

hn_knot8 hn_amalsp8_del( hn_amalsp8 *, ptri );

void hn_amalsp8_ins( hn_amalsp8 *, ptri, hn_knot8 );

void hn_amalsp12_init( hn_ptri, hn_knot12 *, hn_amalsp12 * );

void hn_amalsp12_cpy( hn_amalsp12 *, hn_amalsp12 * );

hn_knot12 hn_amalsp12_get( hn_amalsp12 *, ptri );

hn_knot12 hn_amalsp12_ovr( hn_amalsp12 *, ptri, hn_knot12 );

hn_knot12 hn_amalsp12_del( hn_amalsp12 *, ptri );

void hn_amalsp12_ins( hn_amalsp12 *, ptri, hn_knot12 );

void hn_amalsp16_init( hn_ptri, hn_knot16 *, hn_amalsp16 * );

void hn_amalsp16_cpy( hn_amalsp16 *, hn_amalsp16 * );

hn_knot16 hn_amalsp16_get( hn_amalsp16 *, ptri );

hn_knot16 hn_amalsp16_ovr( hn_amalsp16 *, ptri, hn_knot16 );

hn_knot16 hn_amalsp16_del( hn_amalsp16 *, ptri );

void hn_amalsp16_ins( hn_amalsp16 *, ptri, hn_knot16 );

void hn_amalsp20_init( hn_ptri, hn_knot20 *, hn_amalsp20 * );

void hn_amalsp20_cpy( hn_amalsp20 *, hn_amalsp20 * );

hn_knot20 hn_amalsp20_get( hn_amalsp20 *, ptri );

hn_knot20 hn_amalsp20_ovr( hn_amalsp20 *, ptri, hn_knot20 );

hn_knot20 hn_amalsp20_del( hn_amalsp20 *, ptri );

void hn_amalsp20_ins( hn_amalsp20 *, ptri, hn_knot20 );

#endif /* INC_API__HN_AMALSP_H */
