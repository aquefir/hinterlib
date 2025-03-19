/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/conio.h>

#if !defined( _CFGOPT_NOSTDIO )

#include <stdio.h>

void hn_wri_o( const hn_chr * s, ... )
{
	va_list args;

	if( s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( stdout, s, args );
	va_end( args );

	fflush( stdout );
}

void hn_wri_e( const hn_chr * s, ... )
{
	va_list args;

	if( s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( stderr, s, args );
	va_end( args );

	fflush( stderr );
}

void hn_wri_f( struct hn_file * f, const hn_chr * s, ... )
{
	va_list args;

	if( f == NULL || s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( (FILE *)f, s, args );
	va_end( args );

	fflush( (FILE *)f );
}

void hn_wriln_o( const hn_chr * s, ... )
{
	va_list args;

	if( s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( stdout, s, args );
	va_end( args );

	fprintf( stdout, "\n" );
	fflush( stdout );
}

void hn_wriln_e( const hn_chr * s, ... )
{
	va_list args;

	if( s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( stderr, s, args );
	va_end( args );

	fprintf( stderr, "\n" );
	fflush( stderr );
}

void hn_wriln_f( struct hn_file * f, const hn_chr * s, ... )
{
	va_list args;

	if( f == NULL || s == NULL )
	{
		return;
	}

	va_start( args, s );
	vfprintf( (FILE *)f, s, args );
	va_end( args );

	fprintf( (FILE *)f, "\n" );
	fflush( (FILE *)f );
}

hn_ptri hn_readn_i( hn_chr * buf, hn_ptri count )
{
	if( buf == NULL || count == 0 )
	{
		return 0;
	}

	return fread( buf, 1, count, stdin );
}

hn_ptri hn_readn_f( struct hn_file * f, hn_chr * buf, hn_ptri count )
{
	if( buf == NULL || count == 0 )
	{
		return 0;
	}

	return fread( buf, 1, count, (FILE *)f );
}

hn_ptri hn_readln_i( hn_chr * buf, hn_ptri count )
{
	ptri r;

	if( buf == NULL || count == 0 )
	{
		return 0;
	}

	for( r = 0; r < count; ++r )
	{
		buf[r] = fgetc( stdin );

		if( buf[r] == '\n' )
		{
			break;
		}
	}

	return r;
}

hn_ptri hn_readln_f( struct hn_file * f, hn_chr * buf, hn_ptri count )
{
	ptri r;

	if( f == NULL || buf == NULL || count == 0 )
	{
		return 0;
	}

	for( r = 0; r < count; ++r )
	{
		buf[r] = fgetc( (FILE *)f );

		if( buf[r] == '\n' )
		{
			break;
		}
	}

	return r;
}

#endif /* !defined( _CFGOPT_NOSTDIO ) */
