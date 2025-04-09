/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#define _XOPEN_SOURCE 500

#include <hn/exec.h>

#include <hn/alloc.h>
#include <hn/err.h>
#include <hn/memops.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#include <stdlib.h>

bl hn_execpath( chr p[HN_PATHMAX + 1] )
{
	u32 sz          = HN_PATHMAX;
	chr * const buf = hn_allockn16( );
	const int r     = _NSGetExecutablePath( buf, &sz );

	HN_CHK_GOTO( buf != NULL, fail );
	HN_CHK_GOTO( r == 0, fail );

	/* zero out the result buffer to make NUL termination easy */
	hn_memset( 0, HN_PATHMAX + 1, p );

	/* dereference symlinks first, as we cannot assume dirname( ) is
	 * smart */
	{
		chr * const ret = realpath( buf, p );
		HN_CHK_GOTO( ret == p, fail );

		dirname( p );
	}

	hn_free( buf );
	return HN_FALSE;

fail:
	hn_free( buf );
	return HN_TRUE;
}
