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

const u8 ct_bits[HN_MAX_CT_TYPE] = {
	0,
	8,
	12,
	16,
	20,
	8,
	12,
	16,
	20,
	8,
	12,
	16,
	20,
	8,
	12,
	16,
	20,
	0
};

hn_bl hn_ct_init( hn_u16 sz[4],
	enum hn_ct_type type,
	hn_ptri ct_sz,
	struct hn_ct * ct )
{
	if( type != HN_CT_TYPE_FILE )
	{
		const ptri base_sz = 1 << (ptri)ct_bits[type];
		ptri tmp;
		bl tst;

		/* this approach is for flat memory model machines with
		 * no greater provisions for memory banking (i.e. 32-
		 * and 64-bit mainstream computers). Eventually, this
		 * dumb multiplicative logic can be special-cased on
		 * processors with banking tools to utilise those tools
		 * to handle more memory than is addressable :)
		 */
		tst = HN_CHECKED_MUL( (ptri)sz[0], (ptri)sz[1], &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL( (ptri)sz[2], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL( (ptri)sz[3], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );

		/* save the trouble on flat backings */
		if( base_sz > 1 )
		{
			tst = HN_CHECKED_MUL(
				(ptri)base_sz, tmp, &tmp );
			HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		}

		tmp += sizeof( struct hn_ct );

		HN_CHK_RETV( tmp <= ct_sz, HN_TRUE );
	}

	return HN_FALSE;
}
