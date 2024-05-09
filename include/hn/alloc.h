/*********************************************************************\
 *                      Hinterlib/Neopolitan 2.                      *
 *                                                                   *
 *                  Copyright (C) 2019-2024 Aquefir                  *
 *           Released under Artisan Software Licence v1.1.           *
\*********************************************************************/

#ifndef INC_API__HN_ALLOC_H
#define INC_API__HN_ALLOC_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/mem.h"

hn_knot8 hn_allock8( void );

hn_knot12 hn_allock12( void );

hn_knot16 hn_allock16( void );

hn_knot20 hn_allock20( void );

hn_knot8 hn_tryallock8( void );

hn_knot12 hn_tryallock12( void );

hn_knot16 hn_tryallock16( void );

hn_knot20 hn_tryallock20( void );

hn_knot8 hn_allocmk8( hn_ptri );

hn_knot12 hn_allocmk12( hn_ptri );

hn_knot16 hn_allocmk16( hn_ptri );

hn_knot20 hn_allocmk20( hn_ptri );

hn_knot8 hn_tryallocmk8( hn_ptri );

hn_knot12 hn_tryallocmk12( hn_ptri );

hn_knot16 hn_tryallocmk16( hn_ptri );

hn_knot20 hn_tryallocmk20( hn_ptri );

void hn_free( void * );

#endif /* INC_API__HN_ALLOC_H */
