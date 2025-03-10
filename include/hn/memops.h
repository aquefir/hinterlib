/*********************************************************************\
 *                            Hinterlib 2                            *
 *                                                                   *
 *             Copyright (C) 2019-2024 Alexander Nicholi             *
 *          Copyright (C) 2024-2025 Aquefir Consulting LLC.          *
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

/**
 * TITLE: Set memory
 * DESCRIPTION: Set the contents of a stretch of memory,
 *              octet-by-octet, to a given value.
 * PARAMETER: The octet to use as the fill value.
 * PARAMETER: The length of the buffer, denominated in octets.
 * PARAMETER: The pointer to the memory buffer.
 */
void hn_memset( hn_u8, hn_ptri, void * );

/**
 * TITLE: Copy memory
 * DESCRIPTION: Copies the contents of one memory buffer to another
 *              buffer in-place.
 * PARAMETER: The pointer to the source memory buffer.
 * PARAMETER: The length of the source buffer, denominated in octets.
 * PARAMETER: The pointer to the destination memory buffer, the
 *            contents of which must be at least as large as the
 *            length parameter given.
 */
void hn_memcpy( void *, hn_ptri, void * );

/**
 * TITLE: Compare memory
 * DESCRIPTION: Performs a deep octet-by-octet comparison of two
 *              buffers of memory to determine equality.
 * PARAMETER: The pointer to the first memory buffer.
 * PARAMETER: The size of both buffers, denominated in octets.
 * PARAMETER: The pointer to the second memory buffer.
 * RETURNS: HN_TRUE if equal, HN_FALSE otherwise.
 * NOTES: Both buffers must be the same size, as inequality can be
 *        inferred without deep comparison if they differ.
 */
hn_bl hn_memequ( void *, hn_ptri, void * );

#endif /* INC_API__HN_MEMOPS_H */
