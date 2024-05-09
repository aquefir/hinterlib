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

/**
 * TITLE: Allocate an 8-bit knot
 * DESCRIPTION: Try to allocate an 8-bit knot, aborting on failure.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot8 hn_allock8( void );

/**
 * TITLE: Allocate a 12-bit knot
 * DESCRIPTION: Try to allocate a 12-bit knot, aborting on failure.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot12 hn_allock12( void );

/**
 * TITLE: Allocate a 16-bit knot
 * DESCRIPTION: Try to allocate a 16-bit knot, aborting on failure.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot16 hn_allock16( void );

/**
 * TITLE: Allocate a 20-bit knot
 * DESCRIPTION: Try to allocate a 20-bit knot, aborting on failure.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot20 hn_allock20( void );

/**
 * TITLE: Try to allocate an 8-bit knot
 * DESCRIPTION: Try to allocate an 8-bit knot, returning NULL on
 *              failure.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot8 hn_tryallock8( void );

/**
 * TITLE: Try to allocate a 12-bit knot
 * DESCRIPTION: Try to allocate a 12-bit knot, returning NULL on
 *              failure.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot12 hn_tryallock12( void );

/**
 * TITLE: Try to allocate a 16-bit knot
 * DESCRIPTION: Try to allocate a 16-bit knot, returning NULL on
 *              failure.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot16 hn_tryallock16( void );

/**
 * TITLE: Try to allocate a 20-bit knot
 * DESCRIPTION: Try to allocate a 20-bit knot, returning NULL on
 *              failure.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot20 hn_tryallock20( void );

/**
 * TITLE: Allocate a multitude of 8-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 8-bit knots,
 *              aborting on failure.
 * PARAMETER: The number of knots to allocate.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot8 hn_allocmk8( hn_ptri );

/**
 * TITLE: Allocate a multitude of 12-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 12-bit knots,
 *              aborting on failure.
 * PARAMETER: The number of knots to allocate.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot12 hn_allocmk12( hn_ptri );

/**
 * TITLE: Allocate a multitude of 16-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 16-bit knots,
 *              aborting on failure.
 * PARAMETER: The number of knots to allocate.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot16 hn_allocmk16( hn_ptri );

/**
 * TITLE: Allocate a multitude of 20-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 20-bit knots,
 *              aborting on failure.
 * PARAMETER: The number of knots to allocate.
 * RETURNS: The allocated knot.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 * NOTES: This routine will die upon out-of-memory error.
 */
hn_knot20 hn_allocmk20( hn_ptri );

/**
 * TITLE: Try to allocate a multitude of 8-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 8-bit knots,
 *              returning NULL upon failure.
 * PARAMETER: The number of knots to attempt allocating.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot8 hn_tryallocmk8( hn_ptri );

/**
 * TITLE: Try to allocate a multitude of 12-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 12-bit knots,
 *              returning NULL upon failure.
 * PARAMETER: The number of knots to attempt allocating.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot12 hn_tryallocmk12( hn_ptri );

/**
 * TITLE: Try to allocate a multitude of 16-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 16-bit knots,
 *              returning NULL upon failure.
 * PARAMETER: The number of knots to attempt allocating.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot16 hn_tryallocmk16( hn_ptri );

/**
 * TITLE: Try to allocate a multitude of 20-bit knots
 * DESCRIPTION: Try to allocate a contiguous multitude of 20-bit knots,
 *              returning NULL upon failure.
 * PARAMETER: The number of knots to attempt allocating.
 * RETURNS: The allocated knot, or NULL on out-of-memory error.
 * NOTES: This routine performs dynamic memory allocation that will
 *        need to be manually deallocated later with `hn_free( )`.
 */
hn_knot20 hn_tryallocmk20( hn_ptri );

/**
 * TITLE: Free dynamic heap allocation
 * DESCRIPTION: Frees up memory allocated to a pointer returned by the
 *              heap allocator routine family.
 * PARAMETER: The pointer to the memory to free.
 * NOTES: This routine performs dynamic memory deallocation.
 */
void hn_free( void * );

#endif /* INC_API__HN_ALLOC_H */
