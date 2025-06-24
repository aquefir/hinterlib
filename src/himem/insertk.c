/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/himem.h>

#include <hn/memops.h>
#include <hn/types/int.h>
#include <hn/types/mem.h>

typedef bl ( *_insertk_f )( void *, amoffs *, void * );

static bl _insertk_d1( void *, amoffs *, void * );
static bl _insertk_d2( void *, amoffs *, void * );
static bl _insertk_d3( void *, amoffs *, void * );
static bl _insertk_d4( void *, amoffs *, void * );

static _insertk_f const _insertk[] = {
	&_insertk_d1, &_insertk_d2, &_insertk_d3, &_insertk_d4 };

static void _insert( am16d1 * am, u16 offs, void * k )
{
	ptri i;

	/* step 1: move the second half of the amalgam forward by one */
	for( i = am->len - 1; i >= offs; --i )
	{
		am->data[i + 1] = am->data[i];
	}

	/* emplace the knot into the new hole opened up */
	am->data[offs] = k;
}

static bl _insertk_d1( void * am_, amoffs * offs, void * k_ )
{
	am16d1 * const am = am_;

	if( am->len >= HN_MAX_AMALGAM_ELEMS - 1 )
	{
		/* out of memory */
		return HN_TRUE;
	}

	_insert( am, offs[0].n, k_ );

	return HN_FALSE;
}

static bl _insertk_d2( void * am_, amoffs * offs, void * k_ )
{
	am16d1 * const am = am_;

	if( am->len >= HN_MAX_AMALGAM_ELEMS - 1 )
	{
		/* out of memory */
		return HN_TRUE;
	}

	_insert( am, offs[0].n, k_ );

	return HN_FALSE;
}

static bl _insertk_d3( void * am_, amoffs * offs, void * k_ )
{
	return HN_FALSE;
}

static bl _insertk_d4( void * am_, amoffs * offs, void * k_ )
{
	return HN_FALSE;
}

static void _chk_offs( u8 subdiv_ct, volatile amoffs * offs )
{
	const u8 lim = subdiv_ct + 1;
	u8 i;

	for( i = 0; i < lim; ++i )
	{
		(void)offs[i].n;
	}
}

struct hn_err hn_himem_insertk(
	void * am, struct hn_amalgam am_opts, amoffs * offs, void * k )
{
	struct hn_err ret;

	hn_memset( 0, sizeof ret, &ret );

	HN_CHK_GOTO( am != NULL, inval );
	HN_CHK_GOTO( offs != NULL, inval );
	HN_CHK_GOTO( k != NULL, inval );

	_chk_offs( am_opts.subdiv_ct, offs );

	{
		const bl r = _insertk[am_opts.subdiv_ct]( am, offs, k );
	}

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
