/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_MEMOPS_H
#define INC_API__HN_MEMOPS_H

#include "types/base.h"
#include "types/int.h"

/**
 *
 * @brief Set the contents of a stretch of memory, octet-by-octet, to a
 *        given value.
 * @param buf The pointer to the memory buffer.
 * @param oct The octet to use as the fill value.
 * @param buf_sz The length of the buffer, denominated in octets.
 */
HN_API void hn_memset( void *, hn_u8, hn_ptri );

/**
 *
 * @brief Copies the contents of one memory buffer to another buffer
 *        in-place.
 * @param dst The pointer to the destination memory buffer, the
 *        contents of which must be at least as large as @param src_sz.
 * @param src The pointer to the source memory buffer.
 * @param src_sz The length of the source buffer, denominated in octets.
 */
HN_API void hn_memcpy( void *, void *, hn_ptri );

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
HN_API hn_bl hn_memequ( void *, hn_ptri, void * );

#endif /* INC_API__HN_MEMOPS_H */
