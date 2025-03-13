/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_MEMOPS_H
#define INC_API__HN_MEMOPS_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"

/**
 *
 * @brief Set the contents of a stretch of memory, octet-by-octet, to a
 *        given value.
 * @param oct The octet to use as the fill value.
 * @param buf_sz The length of the buffer, denominated in octets.
 * @param buf The pointer to the memory buffer.
 */
void hn_memset( hn_u8, hn_ptri, void * );

/**
 *
 * @brief Copies the contents of one memory buffer to another buffer
 *        in-place.
 * @param src The pointer to the source memory buffer.
 * @param src_sz The length of the source buffer, denominated in octets.
 * @param dst The pointer to the destination memory buffer, the
 *        contents of which must be at least as large as @param src_sz.
 */
void hn_memcpy( void *, hn_ptri, void * );

/**
 *
 * @brief Performs a deep octet-by-octet comparison of two buffers of
 *        memory to determine equality.
 * @param buf_a The pointer to the first memory buffer.
 * @param bufs_sz The size of both buffers, denominated in octets.
 * @param buf_b The pointer to the second memory buffer.
 * @returns HN_TRUE if equal, HN_FALSE otherwise.
 * @note Both buffers must be the same size, as inequality can be
 *       inferred without deep comparison if they differ.
 */
hn_bl hn_memequ( void *, hn_ptri, void * );

#endif /* INC_API__HN_MEMOPS_H */
