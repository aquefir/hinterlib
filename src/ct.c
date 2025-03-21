/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/ct.h>

#include <hn/checked.h>
#include <hn/err.h>

static u8 bitsfromtype( enum hn_cr_type type )
{
	switch( type )
	{
	case HN_CT_TYPE_AM8D1:
	case HN_CT_TYPE_AM8D2:
	case HN_CT_TYPE_AM8D3:
	case HN_CT_TYPE_AM8D4:
		return 8;
	case HN_CT_TYPE_AM12D1:
	case HN_CT_TYPE_AM12D2:
	case HN_CT_TYPE_AM12D3:
	case HN_CT_TYPE_AM12D4:
		return 12;
	case HN_CT_TYPE_AM16D1:
	case HN_CT_TYPE_AM16D2:
	case HN_CT_TYPE_AM16D3:
	case HN_CT_TYPE_AM16D4:
		return 16;
	case HN_CT_TYPE_AM20D1:
	case HN_CT_TYPE_AM20D2:
	case HN_CT_TYPE_AM20D3:
	case HN_CT_TYPE_AM20D4:
		return 20;
	case HN_CT_TYPE_FLAT:
	case HN_CT_TYPE_FILE:
	default:
		return 0;
	}
}

hn_bl hn_ct_init( hn_u16 sz[4],
	enum hn_cr_type type,
	hn_ptri ct_sz,
	struct hn_ct * ct )
{
	if( type != HN_CT_TYPE_FILE )
	{
		ptri tmp;
		const ptri base_sz = 1 << (ptri)bitsfromtype( type );
		bl tst;

		tst = HN_CHECKED_MUL( (ptri)sz[0], (ptri)sz[1], &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL( (ptri)sz[2], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL( (ptri)sz[3], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL( (ptri)base_sz, tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );

		tmp += sizeof( struct hn_ct );

		HN_CHK_RETV( tmp <= ct_sz, HN_TRUE );
	}

	return HN_FALSE;
}
