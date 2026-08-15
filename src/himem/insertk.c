/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/alloc.h>
#include <hn/himem.h>
#include <hn/memops.h>
#include <hn/types/int.h>
#include <hn/types/mem.h>

typedef bl (* _insertk_f)(
	void *,
	amoffs *,
	void *
	);

static bl _insertk_d1(
	void *,
	amoffs *,
	void *
	);
static bl _insertk_d2(
	void *,
	amoffs *,
	void *
	);
static bl _insertk_d3(
	void *,
	amoffs *,
	void *
	);
static bl _insertk_d4(
	void *,
	amoffs *,
	void *
	);

static _insertk_f const _insertk[] =
{
	&_insertk_d1, &_insertk_d2, &_insertk_d3, &_insertk_d4
};

static void _insert(
	am16d1 * am,
	u16 offs,
	void * k
	)
{
	ptri i;

	/* step 1: move the second half of the amalgam forward by one */
	for(i = am->len - 1; i >= offs; --i)
	{
		am->data[i + 1] = am->data[i];
	}

	/* emplace the knot into the new hole opened up */
	am->data[offs] = k;
}

static bl _insertk_d1(
	void * am_,
	amoffs * offs,
	void * k
	)
{
	am16d1 * const am = am_;

	if(am->len >= HN_AMALGAM_MAX_ELEMS - 1)
	{
		/* out of memory */
		return HN_TRUE;
	}

	_insert( am, offs[0].n, k );

	return HN_FALSE;
}

static bl _insertk_d2(
	void * am_,
	amoffs * offs,
	void * k
	)
{
	am16d2 * const am = am_;
	const u16 d2_idx  = offs[0].n;
	const ptri d2_sz  = am->len;
	const u16 d1_idx  = offs[1].n;
	const ptri d1_sz  = am->data[d2_idx]->len;

	if(d2_sz >= HN_AMALGAM_MAX_ELEMS - 1 && d1_sz >=
	   HN_AMALGAM_MAX_ELEMS - 1)
	{
		/* out of memory to split */
		return HN_TRUE;
	}

	/* in this case, the total container is not full but the target
	 * dimension is, requiring us to split it into two at the index
	 * of offset.
	 * the way this is done is by inserting an empty 1st dimension
	 *.amalgam just after the index of offset, copying the latter
	 * half of the original 1st dimension amalgam into it, zeroing
	 * out the source of that copy, and finally placing the new knot
	 * at the end of the original amalgam.
	 * this does create some fragmentation but it is of no
	 * performance concern as these are all linked lists anyway. */
	if(d1_sz >= HN_AMALGAM_MAX_ELEMS - 1)
	{
		void * const k2 = hn_allock16( );

		HN_CHK_RETV( k2 != NULL, HN_TRUE );

		/* insert the higher order amalgam the same as if it
		 * were a lower order one */
		_insert((am16d1 *)am, d2_idx, k2 );

		/* copy over the old latter half */
		hn_memcpy( am->data[d2_idx + 1],
		           &(am->data[d2_idx]->
		             data[d1_idx]),
		           d1_sz );
		/* zero it out after copy */
		hn_memset( &(am->data[d2_idx]->data[d1_idx]), 0, d1_sz )
		;
		/* emplace the new knot at the end of the original 1st
		 * dimension amalgam */
		am->data[d2_idx]->data[d1_idx] = k;
	}

	return HN_FALSE;
}

static bl _insertk_d3_1and2(
	am16d3 * am,
	u16 d3_idx,
	ptri d3_sz,
	u16
	d2_idx,
	ptri d2_sz,
	u16 d1_idx,
	ptri d1_sz,
	void * k,
	void * k2,
	void * k3
	)
{
	/* this gets more complicated than with a 2nd dimension amalgam
	 * as we have to split multiple orders distinctly as this is the
	 * special edge case where both the 1st and 2nd dimensions are
	 * full (but not the third). */
	return HN_FALSE;
}

static bl _insertk_d3(
	void * am_,
	amoffs * offs,
	void * k
	)
{
	am16d3 * const am = am_;
	const u16 d3_idx  = offs[0].n;
	const ptri d3_sz  = am->len;
	const u16 d2_idx  = offs[1].n;
	const ptri d2_sz  = am->data[d3_idx]->len;
	const u16 d1_idx  = offs[2].n;
	const ptri d1_sz  = am->data[d3_idx]->data[d2_idx]->len;

	if(d3_sz >= HN_AMALGAM_MAX_ELEMS - 1 && d2_sz >=
	   HN_AMALGAM_MAX_ELEMS - 1 && d1_sz >= HN_AMALGAM_MAX_ELEMS - 1
	   )
	{
		/* out of memory to split */
		return HN_TRUE;
	}

	if(d2_sz >= HN_AMALGAM_MAX_ELEMS - 1 && d1_sz >=
	   HN_AMALGAM_MAX_ELEMS - 1)
	{
		bl r;
		void * k3;
		void * const k2 = hn_allock16( );

		HN_CHK_RETV( k2 != NULL, HN_TRUE );

		k3 = hn_allock16( );
		HN_CHK_RETV( k3 != NULL, HN_TRUE );

		r = _insertk_d3_1and2( am, d3_idx, d3_sz, d2_idx, d2_sz,
		                       d1_idx, d1_sz, k, k2, k3 );

		HN_CHK_RETV( r == HN_FALSE, HN_TRUE );
	}

	return HN_FALSE;
}

static bl _insertk_d4(
	void * am_,
	amoffs * offs,
	void * k
	)
{
	return HN_FALSE;
}

static void _chk_offs(
	u8 subdiv_ct,
	volatile amoffs * offs
	)
{
	const u8 lim = subdiv_ct + 1;
	u8 i;

	for(i = 0; i < lim; ++i)
	{
		(void)offs[i].n;
	}
}

struct hn_err hn_himem_insertk(
	void * am,
	struct hn_amalgam am_opts,
	amoffs * offs,
	void * k
	)
{
	struct hn_err ret;

	hn_memset( &ret, 0, sizeof ret );

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
