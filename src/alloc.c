/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/alloc.h>

#define _POSIX_C_SOURCE 200112L

#include <stdlib.h>

hn_knot8 hn_allockn8( void )
{
	hn_knot8 ret = NULL;
	const int r  = posix_memalign( (void **)&ret, 1 << 8, 1 << 8 );

	return r == 0 ? ret : NULL;
}

hn_knot12 hn_allockn12( void )
{
	hn_knot12 ret = NULL;
	const int r = posix_memalign( (void **)&ret, 1 << 12, 1 << 12 );

	return r == 0 ? ret : NULL;
}

hn_knot16 hn_allockn16( void )
{
	hn_knot16 ret = NULL;
	const int r = posix_memalign( (void **)&ret, 1 << 16, 1 << 16 );

	return r == 0 ? ret : NULL;
}

#if HN_SIZEOF_PTR > 2
hn_knot20 hn_allockn20( void )
{
	hn_knot20 ret = NULL;
	const int r = posix_memalign( (void **)&ret, 1 << 20, 1 << 20 );

	return r == 0 ? ret : NULL;
}
#endif /* HN_SIZEOF_PTR > 2 */

void * hn_alloc( hn_ptri sz )
{
	if( sz == 0 )
	{
		return NULL;
	}

	{
		void * ret = NULL;
		/* never gonna get less than 64 bytes */
		const int r = posix_memalign(
			(void **)&ret, 64, sz < 64 ? 64 : sz );

		return r == 0 ? ret : NULL;
	}
}

void hn_free( void * ptr )
{
	if( ptr == NULL )
	{
		return;
	}

	free( ptr );
}
