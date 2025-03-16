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
 * @brief Try to allocate an 8-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 8 bits are
 *       zero (ergo, aligned to the nearest whole 256 bytes).
 */
hn_knot8 hn_allockn8( void );

/**
 *
 * @brief Try to allocate a 12-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 12 bits are
 *       zero (ergo, aligned to the nearest whole 4 kibibytes).
 */
hn_knot12 hn_allockn12( void );

/**
 *
 * @brief Try to allocate a 16-bit knot, returning `NULL` on failure.
 * @returns The allocated knot, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated knot will be aligned so the lowest 16 bits are
 *       zero (ergo, aligned to the nearest whole 64 kibibytes).
 */
hn_knot16 hn_allockn16( void );

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
hn_knot20 hn_allockn20( void );
#endif /* HN_SIZEOF_PTR > 2 */

/**
 *
 * @brief Allocates a memory block from the heap in a similar fashion as
 *        `malloc()`.
 * @returns The allocated memory, or `NULL` on out-of-memory error.
 * @note This routine performs dynamic memory allocation that will need
 *       to be manually deallocated later with `hn_free()`.
 * @note The allocated memory will be aligned so the lowest 6 bits are
 *       zero (ergo, aligned to the nearest whole 64 bytes).
 */
void * hn_alloc( hn_ptri );

/**
 *
 * @brief Frees up memory allocated to a pointer returned by the heap
 *        allocator routine family.
 * @param ptr The pointer to the memory to free.
 * @note This routine performs dynamic memory deallocation.
 */
void hn_free( void * );

#endif /* INC_API__HN_ALLOC_H */
