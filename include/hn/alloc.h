/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_ALLOC_H
#define INC_API__HN_ALLOC_H

#include "types/base.h"
#include "types/mem.h"

#if defined( __STDC__ )
#include <alloca.h>
#endif

/**
 *
 * @brief Try to allocate an 8-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 8 bits are
 *       zero (ergo, aligned to the nearest whole 256 bytes).
 */
HN_API hn_knot8 hn_allock8( void );

/**
 *
 * @brief Try to allocate a 12-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 12 bits are
 *       zero (ergo, aligned to the nearest whole 4 kibibytes).
 */
HN_API hn_knot12 hn_allock12( void );

/**
 *
 * @brief Try to allocate a 16-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 16 bits are
 *       zero (ergo, aligned to the nearest whole 64 kibibytes).
 */
HN_API hn_knot16 hn_allock16( void );

#if HN_SIZEOF_PTR > 2
/**
 *
 * @brief Try to allocate a 20-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 20 bits are
 *       zero (ergo, aligned to the nearest whole 1 mebibyte).
 */
HN_API hn_knot20 hn_allock20( void );
#endif /* HN_SIZEOF_PTR > 2 */

/**
 *
 * @brief Allocates a memory block from the heap in a similar fashion as
 *        `malloc()`.
 * @param sz The amount of memory needing to be allocated, denominated
 *        in octets. Must be greater than 0. If the value is less than
 *        64 it will be promoted to be at least 64, to fit its alignment
 *        guarantees.
 * @returns The allocated memory, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated memory will be aligned so the lowest 6 bits are
 *       zero (ergo, aligned to the nearest whole 64 bytes).
 */
HN_API void * hn_alloc( hn_ptri );

/**
 *
 * @brief Frees up memory allocated to a pointer returned by the heap
 *        allocator routine family.
 * @param ptr The pointer to the memory to free.
 * @note This routine performs dynamic memory deallocation.
 */
HN_API void hn_free( void * );

#endif /* INC_API__HN_ALLOC_H */
