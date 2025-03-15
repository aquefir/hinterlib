/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_ALLOC_H
#define INC_API__HN_ALLOC_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

#include "types/base.h"
#include "types/mem.h"

/**
 *
 * @brief Try to allocate an 8-bit knot, aborting on failure.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot8 hn_allockn8( void );

/**
 *
 * @brief Try to allocate a 12-bit knot, aborting on failure.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot12 hn_allockn12( void );

/**
 *
 * @brief Try to allocate a 16-bit knot, aborting on failure.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot16 hn_allockn16( void );

/**
 *
 * @brief Try to allocate a 20-bit knot, aborting on failure.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot20 hn_allockn20( void );

/**
 *
 * @brief Try to allocate an 8-bit knot, returning NULL on failure.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot8 hn_tryallockn8( void );

/**
 *
 * @brief Try to allocate a 12-bit knot, returning NULL on failure.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot12 hn_tryallockn12( void );

/**
 *
 * @brief Try to allocate a 16-bit knot, returning NULL on failure.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot16 hn_tryallockn16( void );

/**
 *
 * @brief Try to allocate a 20-bit knot, returning NULL on failure.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot20 hn_tryallockn20( void );

/**
 *
 * @brief Try to allocate a contiguous multitude of 8-bit knots,
 *        aborting on failure.
 * @param n The number of knots to allocate.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot8 hn_allocmkn8( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 12-bit knots,
 *        aborting on failure.
 * @param n The number of knots to allocate.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot12 hn_allocmkn12( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 16-bit knots,
 *        aborting on failure.
 * @param n The number of knots to allocate.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot16 hn_allocmkn16( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 20-bit knots,
 *        aborting on failure.
 * @param n The number of knots to allocate.
 * @returns The allocated knot.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note This routine will die upon out-of-memory error.
 */
hn_knot20 hn_allocmkn20( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 8-bit knots,
 *        returning NULL upon failure.
 * @param n The number of knots to attempt allocating.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot8 hn_tryallocmkn8( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 12-bit knots,
 *        returning NULL upon failure.
 * @param n The number of knots to attempt allocating.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot12 hn_tryallocmkn12( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 16-bit knots,
 *        returning NULL upon failure.
 * @param n The number of knots to attempt allocating.
 * @returns The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot16 hn_tryallocmkn16( hn_ptri );

/**
 *
 * @brief Try to allocate a contiguous multitude of 20-bit knots,
 *        returning NULL upon failure.
 * @param n The number of knots to attempt allocating.
 * @return The allocated knot, or NULL on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 */
hn_knot20 hn_tryallocmkn20( hn_ptri );

/**
 *
 * @brief Frees up memory allocated to a pointer returned by the heap
 *        allocator routine family.
 * @param ptr The pointer to the memory to free.
 * @note This routine performs dynamic memory deallocation.
 */
void hn_free( void * );

#endif /* INC_API__HN_ALLOC_H */
