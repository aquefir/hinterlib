/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/exec.h>

#include <hn/err.h>
#include <hn/memops.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

bl hn_getcwd( chr p[HN_PATHMAX + 1] )
{
	chr * const ret = getcwd( p, HN_PATHMAX );

	return ret == NULL ? HN_TRUE : HN_FALSE;
}

bl hn_setcwd( chr * p )
{
	const int r = chdir( p );

	return r == 0 ? HN_FALSE : HN_TRUE;
}

bl hn_getenv( chr * key, chr * val, ptri val_sz )
{
	HN_CHK_RETV( key != NULL, HN_TRUE );
	HN_CHK_RETV( val != NULL, HN_TRUE );
	HN_CHK_RETV( val_sz > 0, HN_TRUE );

	/* make room for the NUL terminator */
	val_sz -= 1;

	{
		chr * const v   = getenv( (const char *)key );
		const ptri v_sz = strlen( (const char *)v );
		const ptri cpy  = v_sz > val_sz ? val_sz : v_sz;

		hn_memcpy( val, cpy, v );
		val[cpy] = '\0';
	}

	return HN_FALSE;
}

bl hn_setenv( chr * key, chr * val, hn_bl ovr )
{
	HN_CHK_RETV( key != NULL, HN_TRUE );
	HN_CHK_RETV( val != NULL, HN_TRUE );

	{
		const int r = setenv(
			(const chr *)key, (const chr *)val, (int)ovr );

		return r == 0 ? HN_FALSE : HN_TRUE;
	}
}
