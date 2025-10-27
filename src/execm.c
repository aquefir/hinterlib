/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#define _XOPEN_SOURCE 500

#include <hn/alloc.h>
#include <hn/err.h>
#include <hn/exec.h>
#include <hn/memops.h>
#include <libgen.h>
#include <mach-o/dyld.h>
#include <stdlib.h>

static bl _execpath2( chr p[HN_PATHMAX + 1], knot16 buf )
{
	u32 sz      = HN_PATHMAX;
	const int r = _NSGetExecutablePath((chr *)buf, &sz );

	HN_CHK_RETV( r == 0, HN_TRUE );

	/* zero out the result buffer to make NUL termination easy */
	hn_memset( 0, HN_PATHMAX + 1, p );

	/* dereference symlinks first, as we cannot assume dirname( ) is
	   smart */
	{
		chr * const ret = realpath((const chr *)buf, p );
		HN_CHK_RETV( ret == p, HN_TRUE );

		dirname( p );
	}

	return HN_FALSE;
}

static bl _execpath1( chr p[HN_PATHMAX + 1] )
{
	const knot16 buf = hn_allock16( );

	HN_CHK_RETV( buf != NULL, HN_TRUE );

	{
		const bl r = _execpath2( p, buf );

		hn_free( buf );

		return r;
	}
}

bl hn_execpath( chr p[HN_PATHMAX + 1] )
{
	HN_CHK_RETV( p != NULL, HN_TRUE );

	return _execpath1( p );
}
