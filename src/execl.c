/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/err.h>
#include <hn/exec.h>
#include <hn/memops.h>
#include <unistd.h>

bl hn_execpath( chr p[HN_PATHMAX + 1] )
{
	HN_CHK_RETV( p != NULL, HN_TRUE );

	hn_memset( 0, HN_PATHMAX + 1, p );

	{
		const int r
		        = readlink( "/proc/self/exe", p, HN_PATHMAX );

		HN_CHK_RETV( r != -1, HN_TRUE );
	}

	return HN_FALSE;
}
