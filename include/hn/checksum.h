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

struct hn_crc16
{
	hn_u16 data[1];
};

struct hn_crc32
{
	hn_u16 data[2];
};

struct hn_crc64
{
	hn_u16 data[4];
};

struct hn_md4
{
	hn_u16 data[4];
};

struct hn_md5
{
	hn_u16 data[4];
};

struct hn_sha1
{
	hn_u16 data[10];
};

struct hn_sha2_224
{
	hn_u16 data[14];
};

struct hn_sha2_256
{
	hn_u16 data[16];
};

struct hn_sha2_384
{
	hn_u16 data[24];
};

struct hn_sha2_512
{
	hn_u16 data[32];
};

struct hn_sha2_512_224
{
	hn_u16 data[14];
};

struct hn_sha2_512_256
{
	hn_u16 data[16];
};

struct hn_sha3_224
{
	hn_u16 data[14];
};

struct hn_sha3_256
{
	hn_u16 data[16];
};

struct hn_sha3_384
{
	hn_u16 data[24];
};

struct hn_sha3_512
{
	hn_u16 data[32];
};

struct hn_shake128
{
	hn_u16 data[8];
};

struct hn_shake256
{
	hn_u16 data[16];
};

hn_bl hn_crc16( struct hn_ct *, struct hn_crc16 * );

hn_bl hn_crc32( struct hn_ct *, struct hn_crc32 * );

hn_bl hn_crc64( struct hn_ct *, struct hn_crc64 * );

hn_bl hn_md4( struct hn_ct *, struct hn_md4 * );

hn_bl hn_md5( struct hn_ct *, struct hn_md5 * );

hn_bl hn_sha1( struct hn_ct *, struct hn_sha1 * );

hn_bl hn_sha2_224( struct hn_ct *, struct hn_sha2_224 * );

hn_bl hn_sha2_256( struct hn_ct *, struct hn_sha2_256 * );

hn_bl hn_sha2_384( struct hn_ct *, struct hn_sha2_384 * );

hn_bl hn_sha2_512( struct hn_ct *, struct hn_sha2_512 * );

hn_bl hn_sha2_512_224( struct hn_ct *, struct hn_sha2_512_224 * );

hn_bl hn_sha2_512_256( struct hn_ct *, struct hn_sha2_512_256 * );

hn_bl hn_sha3_224( struct hn_ct *, struct hn_sha3_224 * );

hn_bl hn_sha3_256( struct hn_ct *, struct hn_sha3_256 * );

hn_bl hn_sha3_384( struct hn_ct *, struct hn_sha3_384 * );

hn_bl hn_sha3_512( struct hn_ct *, struct hn_sha3_512 * );

hn_bl hn_shake128( struct hn_ct *, struct hn_shake128 * );

hn_bl hn_shake256( struct hn_ct *, struct hn_shake256 * );

#endif /* INC_API__HN_CHECKSUM_H */
