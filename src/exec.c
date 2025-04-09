/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/exec.h>

#include <unistd.h>

bl hn_getcwd( chr p[HN_PATHMAX + 1] )
{
	chr * const ret = getcwd( p, HN_PATHMAX );

	return ret == NULL ? HN_TRUE : HN_FALSE;
}
