/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_CHECKSUM_H
#define INC_API__HN_CHECKSUM_H

#include "types/base.h"
#include "types/int.h"

#include "ct.h"

hn_bl hn_crc16( struct hn_ct *, hn_u8 (*)[2] );

hn_bl hn_crc32( struct hn_ct *, hn_u8 (*)[4] );

hn_bl hn_crc64( struct hn_ct *, hn_u8 (*)[8] );

hn_bl hn_md4( struct hn_ct *, hn_u8 (*)[16] );

hn_bl hn_md5( struct hn_ct *, hn_u8 (*)[16] );

hn_bl hn_sha1( struct hn_ct *, hn_u8 (*)[20] );

hn_bl hn_sha2_224( struct hn_ct *, hn_u8 (*)[28] );

hn_bl hn_sha2_256( struct hn_ct *, hn_u8 (*)[32] );

hn_bl hn_sha2_384( struct hn_ct *, hn_u8 (*)[48] );

hn_bl hn_sha2_512( struct hn_ct *, hn_u8 (*)[64] );

hn_bl hn_sha2_512_224( struct hn_ct *, hn_u8 (*)[28] );

hn_bl hn_sha2_512_256( struct hn_ct *, hn_u8 (*)[32] );

hn_bl hn_sha3_224( struct hn_ct *, hn_u8 (*)[28] );

hn_bl hn_sha3_256( struct hn_ct *, hn_u8 (*)[32] );

hn_bl hn_sha3_384( struct hn_ct *, hn_u8 (*)[48] );

hn_bl hn_sha3_512( struct hn_ct *, hn_u8 (*)[64] );

hn_bl hn_shake128( struct hn_ct *, hn_u8 (*)[16] );

hn_bl hn_shake256( struct hn_ct *, hn_u8 (*)[32] );

#endif /* INC_API__HN_CHECKSUM_H */
