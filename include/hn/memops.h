/*********************************************************************\
 *                      Hinterlib/Neopolitan 2.                      *
 *                                                                   *
 *                  Copyright (C) 2019-2024 Aquefir                  *
 *           Released under Artisan Software Licence v1.1.           *
\*********************************************************************/

#ifndef INC_API__HN_MEMOPS_H
#define INC_API__HN_MEMOPS_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"

/* Set the contents of a stretch of memory, octet-by-octet, to a given
 * value. */
void hn_memset( hn_u8, hn_ptri, void * );

/* Copy some memory from one place to another. */
void hn_memcpy( void *, hn_ptri, void * );

/* Compare two blocks of memory to see if their contents match. */
hn_bl hn_memequ( void *, hn_ptri, void * );

#endif /* INC_API__HN_MEMOPS_H */
