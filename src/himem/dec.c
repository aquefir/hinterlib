/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/alloc.h>
#include <hn/err.h>
#include <hn/himem.h>
#include <hn/memops.h>
#include <hn/types/int.h>
#include <hn/types/mem.h>

static bl _dec1(
	am16d2 * am,
	u16 dimct,
	amoffs * ofs
	)
{
	am16d2 ** const am_list = alloca( sizeof(am16d2 *) * dimct );
	am16d2 * last_am        = am;
	u16 i;
	bl decr = HN_FALSE;

	/* populate a list of amalgams as selected by offset */
	for(i = 0; i < dimct; ++i)
	{
		if(ofs[i].n + 1 >= HN_AMALGAM_MAX_ELEMS)
		{
			ofs[i].n = HN_AMALGAM_MAX_ELEMS - 1;
		}

		if(ofs[i].n + 1 >= last_am->len)
		{
			ofs[i].n = last_am->len - 1;
		}

		am_list[i] = last_am;
		last_am    = (am16d2 *)last_am->data[ofs[i].n];
	}

	/* start from the innermost and go out, performing the decrement
	   on the first non-full offset segment. carry will happen later
	 */
	for(i = dimct; i > 0; --i)
	{
		if(ofs[i - 1].n > 0)
		{
			ofs[i - 1].n -= 1;
			decr = HN_TRUE;

			break;
		}
	}

	if(!decr)
	{
		/* out of memory */
		return HN_TRUE;
	}

	/* propagate subtraction carry through the rest of the offset */
	for(; i < dimct; ++i)
	{
		ofs[i].n = HN_AMALGAM_MAX_ELEMS - 1;
	}

	return HN_FALSE;
}

struct hn_err hn_himem_dec(
	void * am_,
	struct hn_amalgam am_opts,
	amoffs * ofs
	)
{
	struct hn_err ret;
	bl r;

	hn_memset( &ret, 0, sizeof ret );

	HN_CHK_GOTO( am_ != NULL, inval );
	HN_CHK_GOTO( ofs != NULL, inval );

	r = _dec1( am_, am_opts.subdiv_ct + 1, ofs );

	ret.id = r == HN_FALSE ? HN_ERR_ID_SUCCESS : HN_ERR_ID_ERANGE;

	goto finish;

inval:
	ret.fatal = 1;
	ret.id    = HN_ERR_ID_EINVAL;

finish:

	return ret;
}
