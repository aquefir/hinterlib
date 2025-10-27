/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_CHECKSUM_H
#define INC_API__HN_CHECKSUM_H

#include "ct.h"
#include "types/base.h"
#include "types/int.h"

/**
 *
 * @brief CRC-16, standard (X.25, Bluetooth, etc.)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, OpenSafety-A variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16a( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, OpenSafety-B variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16b( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, CDMA2000 variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16c( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, DIF variant (SCSI)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16d( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-64, IBM variant (ANSI X3.28)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16i( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, M-bus variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16m( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, Profibus variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16p( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, ARINC variant (ACARS aviation)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16r( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, DECT variant for cordless telephones
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc16t( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-16, Chakravarty variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 * @note This variant is optimal for payloads <= 64 bits.
 */
HN_API hn_bl hn_crc16y( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief CRC-24 standard (FlexRay)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc24( struct hn_ct *, hn_u8(*)[3] );

/**
 *
 * @brief CRC-24, Radix-64 variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc24r( struct hn_ct *, hn_u8(*)[3] );

/**
 *
 * @brief CRC-24, WCDMA variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc24w( struct hn_ct *, hn_u8(*)[3] );

/**
 *
 * @brief CRC-32 standard (ISO, ANSI, etc.)
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc32( struct hn_ct *, hn_u8(*)[4] );

/**
 *
 * @brief CRC-32, Castagnoli variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc32c( struct hn_ct *, hn_u8(*)[4] );

/**
 *
 * @brief CRC-64, Koopman variant {1,3,28}
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc32k28( struct hn_ct *, hn_u8(*)[4] );

/**
 *
 * @brief CRC-32, Koopman variant {1,1,30}
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc32k30( struct hn_ct *, hn_u8(*)[4] );

/**
 *
 * @brief CRC-40 from GSM
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc40( struct hn_ct *, hn_u8(*)[5] );

/**
 *
 * @brief CRC-64, ECMA variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc64e( struct hn_ct *, hn_u8(*)[8] );

/**
 *
 * @brief CRC-64, ISO variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc64i( struct hn_ct *, hn_u8(*)[8] );

/**
 *
 * @brief CRC-64, NVMe variant
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_crc64n( struct hn_ct *, hn_u8(*)[8] );

/**
 *
 * @brief Fletcher's checksum
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_fletcher16( struct hn_ct *, hn_u8(*)[2] );

/**
 *
 * @brief Adler's checksum
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_adler32( struct hn_ct *, hn_u8(*)[4] );

/**
 *
 * @brief Message Digest 2 hashing function
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md2( struct hn_ct *, hn_u8(*)[16] );

/**
 *
 * @brief Message Digest 4 hashing function
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md4( struct hn_ct *, hn_u8(*)[16] );

/**
 *
 * @brief Message Digest 5 hashing function
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md5( struct hn_ct *, hn_u8(*)[16] );

/**
 *
 * @brief Message Digest 6 hashing function, 224-bit digest
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md6_224( struct hn_ct *, hn_u8(*)[28] );

/**
 *
 * @brief Message Digest 6 hashing function, 256-bit digest
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md6_256( struct hn_ct *, hn_u8(*)[32] );

/**
 *
 * @brief Message Digest 6 hashing function, 384-bit digest
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md6_384( struct hn_ct *, hn_u8(*)[48] );

/**
 *
 * @brief Message Digest 6 hashing function, 512-bit digest
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_md6_512( struct hn_ct *, hn_u8(*)[64] );

/**
 *
 * @brief Secure Hash Algorithm 0
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha0( struct hn_ct *, hn_u8(*)[20] );

/**
 *
 * @brief Secure Hash Algorithm 1
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha1( struct hn_ct *, hn_u8(*)[20] );

/**
 *
 * @brief Secure Hash Algorithm 2, 224-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_224( struct hn_ct *, hn_u8(*)[28] );

/**
 *
 * @brief Secure Hash Algorithm 2, 256-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_256( struct hn_ct *, hn_u8(*)[32] );

/**
 *
 * @brief Secure Hash Algorithm 2, 384-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_384( struct hn_ct *, hn_u8(*)[48] );

/**
 *
 * @brief Secure Hash Algorithm 2, 512-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_512( struct hn_ct *, hn_u8(*)[64] );

/**
 *
 * @brief Secure Hash Algorithm 2, 512-bit truncated to 224-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_512_224( struct hn_ct *, hn_u8(*)[28] );

/**
 *
 * @brief Secure Hash Algorithm 2, 512-bit truncated to 256-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha2_512_256( struct hn_ct *, hn_u8(*)[32] );

/**
 *
 * @brief Secure Hash Algorithm 3, 224-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha3_224( struct hn_ct *, hn_u8(*)[28] );

/**
 *
 * @brief Secure Hash Algorithm 3, 256-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha3_256( struct hn_ct *, hn_u8(*)[32] );

/**
 *
 * @brief Secure Hash Algorithm 3, 384-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha3_384( struct hn_ct *, hn_u8(*)[48] );

/**
 *
 * @brief Secure Hash Algorithm 3, 512-bit
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_sha3_512( struct hn_ct *, hn_u8(*)[64] );

/**
 *
 * @brief Raw SHA-3 SHAKE hashing algorithm with 128-bit output
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_shake128( struct hn_ct *, hn_u8(*)[16] );

/**
 *
 * @brief Raw SHA-3 SHAKE hashing algorithm with 256-bit output
 * @param c Container of data to perform the algorithm upon.
 * @param o Reference to array to deposit the result into.
 * @returns `HN_FALSE` on success, or `HN_TRUE` on failure.
 */
HN_API hn_bl hn_shake256( struct hn_ct *, hn_u8(*)[32] );

#endif /* INC_API__HN_CHECKSUM_H */
