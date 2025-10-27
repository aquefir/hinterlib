/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/checked.h>
#include <hn/ct.h>
#include <hn/err.h>
#include <hn/memops.h>

static void init_flat( struct hn_ct * );
static void init_am8d1( struct hn_ct * );
static void init_am12d1( struct hn_ct * );
static void init_am16d1( struct hn_ct * );
static void init_am20d1( struct hn_ct * );
static void init_am8d2( struct hn_ct * );
static void init_am12d2( struct hn_ct * );
static void init_am16d2( struct hn_ct * );
static void init_am20d2( struct hn_ct * );
static void init_am8d3( struct hn_ct * );
static void init_am12d3( struct hn_ct * );
static void init_am16d3( struct hn_ct * );
static void init_am20d3( struct hn_ct * );
static void init_am8d4( struct hn_ct * );
static void init_am12d4( struct hn_ct * );
static void init_am16d4( struct hn_ct * );
static void init_am20d4( struct hn_ct * );
static void init_file( struct hn_ct * );

typedef void (* init_subroutine)( struct hn_ct * );

static const init_subroutine init_sub[HN_MAX_CT_TYPE] =
{
	init_flat,
	init_am8d1,
	init_am12d1,
	init_am16d1,
	init_am20d1,
	init_am8d2,
	init_am12d2,
	init_am16d2,
	init_am20d2,
	init_am8d3,
	init_am12d3,
	init_am16d3,
	init_am20d3,
	init_am8d4,
	init_am12d4,
	init_am16d4,
	init_am20d4,
	init_file
};

static const u8 ct_bits[HN_MAX_CT_TYPE] =
{
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

static void init_flat( struct hn_ct * ct )
{
	ct->data.flat = (u8 *)ct + sizeof(*ct);
}

static void init_am8d1( struct hn_ct * ct ) { }

static void init_am12d1( struct hn_ct * ct ) { }

static void init_am16d1( struct hn_ct * ct ) { }

static void init_am20d1( struct hn_ct * ct ) { }

static void init_am8d2( struct hn_ct * ct ) { }

static void init_am12d2( struct hn_ct * ct ) { }

static void init_am16d2( struct hn_ct * ct ) { }

static void init_am20d2( struct hn_ct * ct ) { }

static void init_am8d3( struct hn_ct * ct ) { }

static void init_am12d3( struct hn_ct * ct ) { }

static void init_am16d3( struct hn_ct * ct ) { }

static void init_am20d3( struct hn_ct * ct ) { }

static void init_am8d4( struct hn_ct * ct ) { }

static void init_am12d4( struct hn_ct * ct ) { }

static void init_am16d4( struct hn_ct * ct ) { }

static void init_am20d4( struct hn_ct * ct ) { }

static void init_file( struct hn_ct * ct ) { }

hn_bl hn_ct_init( hn_u16 sz[4], enum hn_ct_type type, hn_ptri ct_sz,
                  struct hn_ct * ct )
{
	HN_CHK_RETV( type < HN_MAX_CT_TYPE, HN_TRUE );
	HN_CHK_RETV( ct != NULL, HN_TRUE );
	HN_CHK_RETV( ct_sz > 0, HN_TRUE );

	if(type != HN_CT_TYPE_FILE)
	{
		const ptri base_sz = 1 << (ptri)ct_bits[type];
		ptri tmp;
		bl tst;

		/* this approach is for flat memory model machines with
		   no greater provisions for memory banking (i.e. 32-
		   and 64-bit mainstream computers). Eventually, this
		   dumb multiplicative logic can be special-cased on
		   processors with banking tools to utilise those tools
		   to handle more memory than is addressable :) */
		tst = HN_CHECKED_MUL((ptri)sz[0], (ptri)sz[1], &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL((ptri)sz[2], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		tst = HN_CHECKED_MUL((ptri)sz[3], tmp, &tmp );
		HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );

		/* save the trouble on flat backings */
		if(base_sz > 1)
		{
			tst = HN_CHECKED_MUL( base_sz, tmp, &tmp );
			HN_CHK_RETV( tst == HN_FALSE, HN_TRUE );
		}

		tmp += sizeof(*ct);

		HN_CHK_RETV( tmp <= ct_sz, HN_TRUE );
	}
	else
	{
		const ptri sz = sizeof(struct hn_ct_file) +
		                HN_PATHMAX + 1 + sizeof(struct hn_ct);

		HN_CHK_RETV( sz <= ct_sz, HN_TRUE );
	}

	hn_memset( 0, ct_sz, ct );
	ct->type = type;

	init_sub[type]( ct );

	return HN_FALSE;
}
