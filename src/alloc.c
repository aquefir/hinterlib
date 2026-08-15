/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/alloc.h>

#define _POSIX_C_SOURCE 200112L

#include <hn/err.h>
#include <stdlib.h>

knot8 hn_allock8( void )
{
	knot8 ret   = NULL;
	const int r = posix_memalign((void **)&ret, 1 << 8, 1 << 8 );

	return r == 0 ? ret : NULL;
}

ptri hn_allock8a(
	ptri n,
	knot8 * ret
	)
{
	ptri i;

	HN_CHK_RETV( ret != NULL, 0 );

	for(i = 0; i < n; ++i)
	{
		const knot8 k = hn_allock8( );

		if(k != NULL)
		{
			ret[i] = k;
		}
		else
		{
			break;
		}
	}

	return i;
}

knot12 hn_allock12( void )
{
	knot12 ret  = NULL;
	const int r = posix_memalign((void **)&ret, 1 << 12, 1 << 12 );

	return r == 0 ? ret : NULL;
}

ptri hn_allock12a(
	ptri n,
	knot12 * ret
	)
{
	ptri i;

	HN_CHK_RETV( ret != NULL, 0 );

	for(i = 0; i < n; ++i)
	{
		const knot12 k = hn_allock12( );

		if(k != NULL)
		{
			ret[i] = k;
		}
		else
		{
			break;
		}
	}

	return i;
}

knot16 hn_allock16( void )
{
	knot16 ret  = NULL;
	const int r = posix_memalign((void **)&ret, 1 << 16, 1 << 16 );

	return (r == 0) ? ret : NULL;
}

ptri hn_allock16a(
	ptri n,
	knot16 * ret
	)
{
	ptri i;

	HN_CHK_RETV( ret != NULL, 0 );

	for(i = 0; i < n; ++i)
	{
		const knot16 k = hn_allock16( );

		if(k != NULL)
		{
			ret[i] = k;
		}
		else
		{
			break;
		}
	}

	return i;
}

#if HN_SIZEOF_PTR > 2
knot20 hn_allock20( void )
{
	knot20 ret  = NULL;
	const int r = posix_memalign((void **)&ret, 1 << 20, 1 << 20 );

	return r == 0 ? ret : NULL;
}

ptri hn_allock20a(
	ptri n,
	knot20 * ret
	)
{
	ptri i;

	HN_CHK_RETV( ret != NULL, 0 );

	for(i = 0; i < n; ++i)
	{
		const knot20 k = hn_allock20( );

		if(k != NULL)
		{
			ret[i] = k;
		}
		else
		{
			break;
		}
	}

	return i;
}
#endif /* HN_SIZEOF_PTR > 2 */

void * hn_alloc( ptri sz )
{
	if(sz == 0)
	{
		return NULL;
	}

	{
		void * ret = NULL;
		/* never gonna get less than 64 bytes */
		const int r = posix_memalign((void **)&ret,
		                             64,
		                             (sz < 64
		                             ) ? 64 : sz );

		return r == 0 ? ret : NULL;
	}
}

void hn_free( void * ptr )
{
	if(ptr == NULL)
	{
		return;
	}

	free( ptr );
}
