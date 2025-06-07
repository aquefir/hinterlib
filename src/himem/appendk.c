/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/himem.h>

#include <hn/alloc.h>
#include <hn/err.h>
#include <hn/memops.h>
#include <hn/types/int.h>
#include <hn/types/mem.h>

typedef bl ( *_appendk_f )( void *, void * );

static bl _appendk_d1( void *, void * );
static bl _appendk_d2( void *, void * );
static bl _appendk_d3( void *, void * );
static bl _appendk_d4( void *, void * );

static _appendk_f const _appendk[] = {
	&_appendk_d1, &_appendk_d2, &_appendk_d3, &_appendk_d4 };

static bl _appendk_d1( void * am_, void * k )
{
	am16d1 * const am = am_;

	if( am->len >= HN_MAX_AMALGAM_ELEMS )
	{
		return HN_TRUE;
	}

	am->data[am->len] = k;

	return HN_FALSE;
}

static bl _appendk_d2( void * am_, void * k )
{
	am16d2 * const am = am_;
	const u16 d2_idx  = am->len - 1;
	const u16 d1_idx  = am->data[d2_idx]->len - 1;

	if( d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		return HN_TRUE;
	}

	if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am->data[d2_idx + 1] = (am16d1 *)hn_allock16( );
		HN_CHK_RETV( am->data[d2_idx + 1] != NULL, HN_TRUE );

		am->data[d2_idx + 1]->data[0] = k;
		am->data[d2_idx + 1]->len     = 1;

		am->len += 1;
	}
	else
	{
		am->data[d2_idx]->data[d1_idx + 1] = k;
		am->data[d2_idx]->len += 1;
	}

	return HN_FALSE;
}

static bl _appendk_d3( void * am_, void * k )
{
	am16d3 * const am = am_;
	const u16 d3_idx  = am->len - 1;
	const u16 d2_idx  = am->data[d3_idx]->len - 1;
	const u16 d1_idx  = am->data[d3_idx]->data[d2_idx]->len - 1;

	if( d3_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		return HN_TRUE;
	}

	if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am->data[d3_idx + 1] = (am16d2 *)hn_allock16( );
		HN_CHK_RETV( am->data[d3_idx + 1] != NULL, HN_TRUE );

		am->data[d3_idx + 1]->data[0] =
			(am16d1 *)hn_allock16( );
		am->data[d3_idx + 1]->len = 1;

		am->data[d3_idx + 1]->data[0]->data[0] = k;
		am->data[d3_idx + 1]->data[0]->len     = 1;

		am->len += 1;
	}
	else if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am16d1 ** const data = am->data[d3_idx]->data;
		const u16 idx        = d2_idx + 1;

		data[idx] = (am16d1 *)hn_allock16( );
		HN_CHK_RETV( data[idx] != NULL, HN_TRUE );

		data[idx]->data[0] = k;
		data[idx]->len     = 1;

		am->data[d3_idx]->len += 1;
	}
	else
	{
		am->data[d3_idx]->data[d2_idx]->data[d1_idx + 1] = k;
		am->data[d3_idx]->data[d2_idx]->len += 1;
	}

	return HN_FALSE;
}

static bl _appendk_d4( void * am_, void * k )
{
	am16d4 * const am = am_;
	const u16 d4_idx  = am->len - 1;
	const u16 d3_idx  = am->data[d4_idx]->len - 1;
	const u16 d2_idx  = am->data[d4_idx]->data[d3_idx]->len - 1;
	const u16 d1_idx =
		am->data[d4_idx]->data[d3_idx]->data[d2_idx]->len - 1;

	if( d4_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d3_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		return HN_TRUE;
	}

	if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d3_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am->data[d4_idx + 1] = (am16d3 *)hn_allock16( );
		HN_CHK_RETV( am->data[d4_idx + 1] != NULL, HN_TRUE );

		am->data[d4_idx + 1]->data[0] =
			(am16d2 *)hn_allock16( );
		HN_CHK_RETV( am->data[d4_idx + 1]->data[0] != NULL,
			HN_TRUE );
		am->data[d4_idx + 1]->len = 1;

		am->data[d4_idx + 1]->data[0]->data[0] =
			(am16d1 *)hn_allock16( );
		HN_CHK_RETV(
			am->data[d4_idx + 1]->data[0]->data[0] != NULL,
			HN_TRUE );
		am->data[d4_idx + 1]->data[0]->len = 1;

		am->data[d4_idx + 1]->data[0]->data[0]->data[0] = k;
		am->data[d4_idx + 1]->data[0]->data[0]->len     = 1;

		am->len += 1;
	}
	else if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS &&
		d2_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am16d2 ** const data = am->data[d4_idx]->data;
		const u16 idx        = d3_idx + 1;

		data[idx] = (am16d2 *)hn_allock16( );
		HN_CHK_RETV( data[idx] != NULL, HN_TRUE );

		data[idx]->data[0] = (am16d1 *)hn_allock16( );
		HN_CHK_RETV( data[idx]->data[0] != NULL, HN_TRUE );
		data[idx]->len = 1;

		data[idx]->data[0]->data[0] = k;
		data[idx]->data[0]->len     = 1;

		am->data[d4_idx]->len += 1;
	}
	else if( d1_idx + 1 >= HN_MAX_AMALGAM_ELEMS )
	{
		am16d1 ** const data =
			am->data[d4_idx]->data[d3_idx]->data;
		const u16 idx = d2_idx + 1;

		data[idx] = (am16d1 *)hn_allock16( );
		HN_CHK_RETV( data[idx] != NULL, HN_TRUE );

		data[idx]->data[0] = k;
		data[idx]->len     = 1;

		am->data[d4_idx]->data[d3_idx]->len += 1;
	}
	else
	{
		am->data[d4_idx]
			->data[d3_idx]
			->data[d2_idx]
			->data[d1_idx + 1] = k;
		am->data[d4_idx]->data[d3_idx]->data[d2_idx]->len += 1;
	}

	return HN_FALSE;
}

struct hn_err hn_himem_appendk(
	void * am_, struct hn_amalgam am_opts, void * k_ )
{
	struct hn_err ret;
	bl r;

	hn_memset( 0, sizeof ret, &ret );

	HN_CHK_GOTO( am_ != NULL, inval );
	HN_CHK_GOTO( k_ != NULL, inval );

	r = _appendk[am_opts.subdiv_ct + 1]( am_, k_ );

	HN_CHK_GOTO( r == HN_FALSE, nomem );

	goto finish;

inval:
	ret.fatal = 1;
	ret.id    = HN_ERR_ID_EINVAL;
	goto finish;

nomem:
	ret.fatal = 1;
	ret.id    = HN_ERR_ID_ENOMEM;

finish:
	return ret;
}
