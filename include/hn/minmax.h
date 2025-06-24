/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_MINMAX_H
#define INC_API__HN_MINMAX_H

#include "types/base.h"
#include "types/char.h"
#include "types/float.h"
#include "types/int.h"

static HN_PURE hn_ptri hn_min_ptri( hn_ptri x, hn_ptri y )
{
	return x < y ? x : y;
}

static HN_PURE hn_ptri hn_max_ptri( hn_ptri x, hn_ptri y )
{
	return x > y ? x : y;
}

static HN_PURE hn_offs hn_min_offs( hn_offs x, hn_offs y )
{
	return x < y ? x : y;
}

static HN_PURE hn_offs hn_max_offs( hn_offs x, hn_offs y )
{
	return x > y ? x : y;
}

static HN_PURE hn_chr hn_min_chr( hn_chr x, hn_chr y )
{
	const hn_s16 x2 = (hn_s16)x;
	const hn_s16 y2 = (hn_s16)y;

	return x2 < y2 ? x : y;
}

static HN_PURE hn_chr hn_max_chr( hn_chr x, hn_chr y )
{
	const hn_s16 x2 = (hn_s16)x;
	const hn_s16 y2 = (hn_s16)y;

	return x2 > y2 ? x : y;
}

static HN_PURE hn_uchr hn_min_uchr( hn_uchr x, hn_uchr y )
{
	return x.hi < y.hi ? x : x.hi == y.hi && x.lo < y.lo ? x : y;
}

static HN_PURE hn_uchr hn_max_uchr( hn_uchr x, hn_uchr y )
{
	return x.hi > y.hi ? x : x.hi == y.hi && x.lo > y.lo ? x : y;
}

static HN_PURE hn_f32 hn_min_f32( hn_f32 x, hn_f32 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_f32 hn_max_f32( hn_f32 x, hn_f32 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_f64 hn_min_f64( hn_f64 x, hn_f64 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_f64 hn_max_f64( hn_f64 x, hn_f64 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_s8 hn_min_s8( hn_s8 x, hn_s8 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_s8 hn_max_s8( hn_s8 x, hn_s8 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_s16 hn_min_s16( hn_s16 x, hn_s16 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_s16 hn_max_s16( hn_s16 x, hn_s16 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_s32 hn_min_s32( hn_s32 x, hn_s32 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_s32 hn_max_s32( hn_s32 x, hn_s32 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_s64 hn_min_s64( hn_s64 x, hn_s64 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_s64 hn_max_s64( hn_s64 x, hn_s64 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_u8 hn_min_u8( hn_u8 x, hn_u8 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_u8 hn_max_u8( hn_u8 x, hn_u8 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_u16 hn_min_u16( hn_u16 x, hn_u16 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_u16 hn_max_u16( hn_u16 x, hn_u16 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_u32 hn_min_u32( hn_u32 x, hn_u32 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_u32 hn_max_u32( hn_u32 x, hn_u32 y )
{
	return x > y ? x : y;
}

static HN_PURE hn_u64 hn_min_u64( hn_u64 x, hn_u64 y )
{
	return x < y ? x : y;
}

static HN_PURE hn_u64 hn_max_u64( hn_u64 x, hn_u64 y )
{
	return x > y ? x : y;
}

#endif /* INC_API__HN_MINMAX_H */
