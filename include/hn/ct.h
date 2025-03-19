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

#include <hn/types/base.h>
#include <hn/types/int.h>
#include <hn/types/mem.h>

#include <hn/file.h>

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
	hn_u32 type : 8;
	hn_u32 _reserved : 24;
	union
	{
		struct hn_ct_i_flat flat;
		struct hn_ct_i_am8d1 am8d1;
		struct hn_ct_i_am12d1 am12d1;
		struct hn_ct_i_am16d1 am16d1;
		struct hn_ct_i_am20d1 am20d1;
		struct hn_ct_i_am8d2 am8d2;
		struct hn_ct_i_am12d2 am12d2;
		struct hn_ct_i_am16d2 am16d2;
		struct hn_ct_i_am20d2 am20d2;
		struct hn_ct_i_am8d3 am8d3;
		struct hn_ct_i_am12d3 am12d3;
		struct hn_ct_i_am16d3 am16d3;
		struct hn_ct_i_am20d3 am20d3;
		struct hn_ct_i_am8d4 am8d4;
		struct hn_ct_i_am12d4 am12d4;
		struct hn_ct_i_am16d4 am16d4;
		struct hn_ct_i_am20d4 am20d4;
		struct hn_ct_i_file file;
	} u HN_PACKED;
} HN_PACKED;

#endif /* INC_API__HN_CT_H */
