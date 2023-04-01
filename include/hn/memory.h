/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_MEMORY_H
#define INC_API__HN_MEMORY_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"
#include "types/mem.h"

/* Attempt to allocate a 16-module. */
hn_faddr hn_new16mod( void );

/* Attempt to allocate a contiguous array of 16-modules. */
hn_faddr hn_new16mods( hn_ptri );

/* Set the contents of a stretch of memory, octet-by-octet, to a given value.
 */
void hn_memset( void *, hn_ptri, hn_u8 );

/* Copy some memory from one place to another. */
void hn_memcpy( void *, void *, hn_ptri );

/* Compare two blocks of memory to see if their contents match. */
hn_bl hn_memequ( void *, void *, hn_ptri );

#endif /* INC_API__HN_MEMORY_H */
