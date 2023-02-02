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

/* Allocate memory from heap. */
void * hn_alloc( hn_ptri );

/* Allocate memory from heap, aligned to 2^n octets. */
void * hn_allocal( hn_ptri, hn_u16 );

/* Reallocate a previous heap allocation to a new size. */
void * hn_realloc( void *, hn_ptri );

/* Reallocate a previous heap allocation to a new size, aligned to 2^n
 * octets. */
void * hn_reallocal( void *, hn_ptri, hn_u16 );

/* Allocate memory from heap, or return NULL as failure. */
void * hn_tryalloc( hn_ptri );

/* Allocate memory from heap, aligned to 2^n octets, or return NULL as
 * failure. */
void * hn_tryallocal( hn_ptri, hn_u16 );

/* Reallocate a previous heap allocation to a new size, or return NULL as
 * failure. */
void * hn_tryrealloc( void *, hn_ptri );

/* Reallocate a previous heap allocation to a new size, aligned to 2^n
 * octets, or return NULL as failure. */
void * hn_tryreallocal( void *, hn_ptri, hn_u16 );

/* Free an allocation from heap. */
void hn_free( void * );

/* Set the contents of a stretch of memory, octet-by-octet, to a given value.
 */
void hn_memset( void *, hn_ptri, hn_u8 );

/* Copy some memory from one place to another. */
void hn_memcpy( void *, void *, hn_ptri );

/* Compare two blocks of memory to see if their contents match. */
hn_bl hn_memequ( void *, void *, hn_ptri );

#endif /* INC_API__HN_MEMORY_H */
