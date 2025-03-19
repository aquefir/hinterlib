/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_CT_H
#define INC_API__HN_CT_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"
#include "types/mem.h"

#include "file.h"

/**
 * Container - polymorphic data storage
 *
 * This is a generalised ABI that provides an interface for accessing
 * potentially infinitely large stores of data backed by a variety of
 * known storage methods through the streaming iterator approach.
 *
 * This abstraction is fully transparent (and therefore decomposable by
 * ABI consumers) with no opaque data types or implicit structure
 * padding. It provides algorithmic modules a general-purpose data
 * context for their own public interfaces, not unlike database cursors
 * or iterators/ranges in genericised systems languages.
 */

enum hn_cr_type
{
	HN_CT_TYPE_FLAT,
	HN_CT_TYPE_AM8D1,
	HN_CT_TYPE_AM12D1,
	HN_CT_TYPE_AM16D1,
	HN_CT_TYPE_AM20D1,
	HN_CT_TYPE_AM8D2,
	HN_CT_TYPE_AM12D2,
	HN_CT_TYPE_AM16D2,
	HN_CT_TYPE_AM20D2,
	HN_CT_TYPE_AM8D3,
	HN_CT_TYPE_AM12D3,
	HN_CT_TYPE_AM16D3,
	HN_CT_TYPE_AM20D3,
	HN_CT_TYPE_AM8D4,
	HN_CT_TYPE_AM12D4,
	HN_CT_TYPE_AM16D4,
	HN_CT_TYPE_AM20D4,
	HN_CT_TYPE_FILE,
	HN_MAX_CT_TYPE
};

struct hn_ct_i_flat
{
	hn_ptri n;
} HN_PACKED;

struct hn_ct_i_am8d1
{
	hn_u32 n : 8;
	hn_u32 _padding1 : 24;
	hn_u16 idx[1];
	hn_u16 _padding2[3];
} HN_PACKED;

struct hn_ct_i_am12d1
{
	hn_u32 n : 12;
	hn_u32 _padding1 : 20;
	hn_u16 idx[1];
	hn_u16 _padding2[3];
} HN_PACKED;

struct hn_ct_i_am16d1
{
	hn_u32 n : 16;
	hn_u32 _padding1 : 16;
	hn_u16 idx[1];
	hn_u16 _padding2[3];
} HN_PACKED;

struct hn_ct_i_am20d1
{
	hn_u32 n : 20;
	hn_u32 _padding1 : 12;
	hn_u16 idx[1];
	hn_u16 _padding2[3];
} HN_PACKED;

struct hn_ct_i_am8d2
{
	hn_u32 n : 8;
	hn_u32 _padding1 : 24;
	hn_u16 idx[2];
	hn_u16 _padding2[2];
} HN_PACKED;

struct hn_ct_i_am12d2
{
	hn_u32 n : 12;
	hn_u32 _padding1 : 20;
	hn_u16 idx[2];
	hn_u16 _padding2[2];
} HN_PACKED;

struct hn_ct_i_am16d2
{
	hn_u32 n : 16;
	hn_u32 _padding1 : 16;
	hn_u16 idx[2];
	hn_u16 _padding2[2];
} HN_PACKED;

struct hn_ct_i_am20d2
{
	hn_u32 n : 20;
	hn_u32 _padding1 : 12;
	hn_u16 idx[2];
	hn_u16 _padding2[2];
} HN_PACKED;

struct hn_ct_i_am8d3
{
	hn_u32 n : 8;
	hn_u32 _padding1 : 24;
	hn_u16 idx[3];
	hn_u16 _padding2;
} HN_PACKED;

struct hn_ct_i_am12d3
{
	hn_u32 n : 12;
	hn_u32 _padding1 : 20;
	hn_u16 idx[3];
	hn_u16 _padding2;
} HN_PACKED;

struct hn_ct_i_am16d3
{
	hn_u32 n : 16;
	hn_u32 _padding1 : 16;
	hn_u16 idx[3];
	hn_u16 _padding2;
} HN_PACKED;

struct hn_ct_i_am20d3
{
	hn_u32 n : 20;
	hn_u32 _padding1 : 12;
	hn_u16 idx[3];
	hn_u16 _padding2;
} HN_PACKED;

struct hn_ct_i_am8d4
{
	hn_u32 n : 8;
	hn_u32 _padding : 24;
	hn_u16 idx[4];
} HN_PACKED;

struct hn_ct_i_am12d4
{
	hn_u32 n : 12;
	hn_u32 _padding : 20;
	hn_u16 idx[4];
} HN_PACKED;

struct hn_ct_i_am16d4
{
	hn_u32 n : 16;
	hn_u32 _padding : 16;
	hn_u16 idx[4];
} HN_PACKED;

struct hn_ct_i_am20d4
{
	hn_u32 n : 20;
	hn_u32 _padding : 12;
	hn_u16 idx[4];
} HN_PACKED;

struct hn_ct_i_file
{
	struct hn_fpos * pos;
} HN_PACKED;

/* Container. */
struct hn_ct
{
	/* Type of container. See `enum hn_ct_type` for valid values.
	 */
	hn_ubf type : 8;
	/* Equivalent to stdio's EOF notion. This also applies if an
	 * iteration happening in reverse gets stopped at the beginning
	 * of the container. */
	hn_ubf reach_end : 1;
	/* Equivalent to stiod's ferror() status. */
	hn_ubf outside_err : 1;
	hn_ubf : 6;
	hn_ubf : 16;
	hn_ubf : 16;
	hn_ubf : 16;
	union
	{
		void * flat;
		hn_am8d1 * am8d1;
		hn_am12d1 * am12d1;
		hn_am16d1 * am16d1;
#if HN_SIZEOF_PTR > 2
		hn_am20d1 * am20d1;
#endif /* HN_SIZEOF_PTR > 2 */
		hn_am8d2 * am8d2;
		hn_am12d2 * am12d2;
		hn_am16d2 * am16d2;
#if HN_SIZEOF_PTR > 2
		hn_am20d2 * am20d2;
#endif /* HN_SIZEOF_PTR > 2 */
		hn_am8d3 * am8d3;
		hn_am12d3 * am12d3;
		hn_am16d3 * am16d3;
#if HN_SIZEOF_PTR > 2
		hn_am20d3 * am20d3;
#endif /* HN_SIZEOF_PTR > 2 */
		hn_am8d4 * am8d4;
		hn_am12d4 * am12d4;
		hn_am16d4 * am16d4;
#if HN_SIZEOF_PTR > 2
		hn_am20d4 * am20d4;
#endif /* HN_SIZEOF_PTR > 2 */
		struct hn_file * file;
	} data HN_PACKED;
	union
	{
		struct hn_ct_i_flat flat;
		struct hn_ct_i_am8d1 am8d1;
		struct hn_ct_i_am12d1 am12d1;
		struct hn_ct_i_am16d1 am16d1;
#if HN_SIZEOF_PTR > 2
		struct hn_ct_i_am20d1 am20d1;
#endif /* HN_SIZEOF_PTR > 2 */
		struct hn_ct_i_am8d2 am8d2;
		struct hn_ct_i_am12d2 am12d2;
		struct hn_ct_i_am16d2 am16d2;
#if HN_SIZEOF_PTR > 2
		struct hn_ct_i_am20d2 am20d2;
#endif /* HN_SIZEOF_PTR > 2 */
		struct hn_ct_i_am8d3 am8d3;
		struct hn_ct_i_am12d3 am12d3;
		struct hn_ct_i_am16d3 am16d3;
#if HN_SIZEOF_PTR > 2
		struct hn_ct_i_am20d3 am20d3;
#endif /* HN_SIZEOF_PTR > 2 */
		struct hn_ct_i_am8d4 am8d4;
		struct hn_ct_i_am12d4 am12d4;
		struct hn_ct_i_am16d4 am16d4;
#if HN_SIZEOF_PTR > 2
		struct hn_ct_i_am20d4 am20d4;
#endif /* HN_SIZEOF_PTR > 2 */
		struct hn_ct_i_file file;
	} idx HN_PACKED;
} HN_PACKED;

hn_bl hn_ct_init( hn_u16[4], enum hn_cr_type, hn_ptri, struct hn_ct * );

hn_bl hn_ct_make( hn_u16[4], enum hn_cr_type, struct hn_ct * );

hn_bl hn_ct_readu8( struct hn_ct *, hn_u8 * );

hn_bl hn_ct_readu16( struct hn_ct *, hn_u16 * );

#if defined( _SYNDEF_HAVE_I32 )
hn_bl hn_ct_readu32( struct hn_ct *, hn_u32 * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
hn_bl hn_ct_readu64( struct hn_ct *, hn_u64 * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

hn_bl hn_ct_readk8( struct hn_ct *, hn_knot8 );

hn_bl hn_ct_readk12( struct hn_ct *, hn_knot12 );

hn_bl hn_ct_readk16( struct hn_ct *, hn_knot16 );

#if HN_SIZEOF_PTR > 2
hn_bl hn_ct_readk20( struct hn_ct *, hn_knot20 );
#endif /* HN_SIZEOF_PTR > 2 */

hn_bl hn_ct_writeu8( hn_u8, struct hn_ct * );

hn_bl hn_ct_writeu16( hn_u16, struct hn_ct * );

#if defined( _SYNDEF_HAVE_I32 )
hn_bl hn_ct_writeu32( hn_u32, struct hn_ct * );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
hn_bl hn_ct_writeu64( hn_u64, struct hn_ct * );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

hn_bl hn_ct_writek8( hn_knot8, struct hn_ct * );

hn_bl hn_ct_writek12( hn_knot12, struct hn_ct * );

hn_bl hn_ct_writek16( hn_knot16, struct hn_ct * );

#if HN_SIZEOF_PTR > 2
hn_bl hn_ct_writek20( hn_knot20, struct hn_ct * );
#endif /* HN_SIZEOF_PTR > 2 */

hn_bl hn_ct_seek16( struct hn_ct *, hn_s16 );

#if defined( _SYNDEF_HAVE_I32 )
hn_bl hn_ct_seek32( struct hn_ct *, hn_s32 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )
hn_bl hn_ct_seek64( struct hn_ct *, hn_s64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

hn_bl hn_ct_extend( struct hn_ct *, hn_ptri );

hn_bl hn_ct_shrink( struct hn_ct *, hn_ptri );

void hn_ct_copy( struct hn_ct *, struct hn_ct * );

#endif /* INC_API__HN_CT_H */
