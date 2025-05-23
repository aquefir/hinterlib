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
 * @brief Try to allocate several 8-bit knots at once.
 * @param n How many 8-bit knots to allocate in total.
 * @param ret Array of 8-bit knots to write the allocation result into,
 *        sized to hold at least `n` 8-bit knots.
 * @returns The number of 8-bit knots actually allocated and written.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note Each knot is allocated separately for the purposes of later
 *       calls to `hn_free()`.
 * @note Each allocated knot will be aligned so the lowest 8 bits are
 *       zero (ergo, aligned to the nearest whole 256 bytes).
 */
HN_API hn_ptri hn_allock8a( hn_ptri, hn_knot8 * );

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
 * @brief Try to allocate several 12-bit knots at once.
 * @param n How many 12-bit knots to allocate in total.
 * @param ret Array of 12-bit knots to write the allocation result into,
 *        sized to hold at least `n` 12-bit knots.
 * @returns The number of 12-bit knots actually allocated and written.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note Each knot is allocated separately for the purposes of later
 *       calls to `hn_free()`.
 * @note Each allocated knot will be aligned so the lowest 12 bits are
 *       zero (ergo, aligned to the nearest whole 4 kibibytes).
 */
HN_API hn_ptri hn_allock12a( hn_ptri, hn_knot12 * );

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

/**
 *
 * @brief Try to allocate several 16-bit knots at once.
 * @param n How many 16-bit knots to allocate in total.
 * @param ret Array of 16-bit knots to write the allocation result into,
 *        sized to hold at least `n` 16-bit knots.
 * @returns The number of 16-bit knots actually allocated and written.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note Each knot is allocated separately for the purposes of later
 *       calls to `hn_free()`.
 * @note Each allocated knot will be aligned so the lowest 16 bits are
 *       zero (ergo, aligned to the nearest whole 64 kibibytes).
 */
HN_API hn_ptri hn_allock16a( hn_ptri, hn_knot16 * );

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

/**
 *
 * @brief Try to allocate several 20-bit knots at once.
 * @param n How many 20-bit knots to allocate in total.
 * @param ret Array of 20-bit knots to write the allocation result into,
 *        sized to hold at least `n` 20-bit knots.
 * @returns The number of 20-bit knots actually allocated and written.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note Each knot is allocated separately for the purposes of later
 *       calls to `hn_free()`.
 * @note Each allocated knot will be aligned so the lowest 20 bits are
 *       zero (ergo, aligned to the nearest whole 1 mebibytes).
 */
HN_API hn_ptri hn_allock20a( hn_ptri, hn_knot20 * );
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
