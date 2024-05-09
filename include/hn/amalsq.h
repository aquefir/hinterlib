/*********************************************************************\
 *                      Hinterlib/Neopolitan 2.                      *
 *                                                                   *
 *                  Copyright (C) 2019-2024 Aquefir                  *
 *           Released under Artisan Software Licence v1.1.           *
\*********************************************************************/

#ifndef INC_API__HN_AMALSQ_H
#define INC_API__HN_AMALSQ_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/mem.h"

void hn_amalsq8_init( hn_ptri, hn_knot8 *, hn_amalsq8 * );

void hn_amalsq8_fini( hn_amalsq8 * );

void hn_amalsq8_cpy( hn_amalsq8 *, hn_amalsq8 * );

hn_knot8 hn_amalsq8_get( hn_amalsq8 *, ptri );

hn_knot8 hn_amalsq8_ovr( hn_amalsq8 *, ptri, hn_knot8 );

void hn_amalsq12_init( hn_ptri, hn_knot12 *, hn_amalsq12 * );

void hn_amalsq12_fini( hn_amalsq12 * );

void hn_amalsq12_cpy( hn_amalsq12 *, hn_amalsq12 * );

hn_knot12 hn_amalsq12_get( hn_amalsq12 *, ptri );

hn_knot12 hn_amalsq12_ovr( hn_amalsq12 *, ptri, hn_knot12 );

void hn_amalsq16_init( hn_ptri, hn_knot16 *, hn_amalsq16 * );

void hn_amalsq16_fini( hn_amalsq16 * );

void hn_amalsq16_cpy( hn_amalsq16 *, hn_amalsq16 * );

hn_knot16 hn_amalsq16_get( hn_amalsq16 *, ptri );

hn_knot16 hn_amalsq16_ovr( hn_amalsq16 *, ptri, hn_knot16 );

void hn_amalsq20_init( hn_ptri, hn_knot20 *, hn_amalsq20 * );

void hn_amalsq20_fini( hn_amalsq20 * );

void hn_amalsq20_cpy( hn_amalsq20 *, hn_amalsq20 * );

hn_knot20 hn_amalsq20_get( hn_amalsq20 *, ptri );

hn_knot20 hn_amalsq20_ovr( hn_amalsq20 *, ptri, hn_knot20 );

#endif /* INC_API__HN_AMALSQ_H */
