/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/file.h>

#include <hn/memops.h>
#include <stdio.h>

const int orig_stdio_map[3] = { SEEK_SET, SEEK_CUR, SEEK_END };

#if !defined( _CFGOPT_NOSTDIO )
struct hn_file * hn_fstdin( void ) { return (struct hn_file *)stdin; }

struct hn_file * hn_fstdout( void ) { return (struct hn_file *)stdout; }

struct hn_file * hn_fstderr( void ) { return (struct hn_file *)stderr; }
#endif /* !defined( _CFGOPT_NOSTDIO ) */

struct hn_file * hn_fopen( const hn_chr * path, struct hn_fmode mode )
{
	chr cmode[4];

	if( path == NULL )
	{
		return NULL;
	}

	hn_memset( 0, 4, cmode );

	switch( mode.approach )
	{
	case 0:
	default:
		cmode[0] = 'r';
		break;
	case 1:
		cmode[0] = 'w';
		break;
	case 2:
		cmode[0] = 'a';
		break;
	case 3:
		cmode[0] = 'w';
		break;
	}

	cmode[1] = mode.update ? '+' : '\0';

	{
		/* account for the possibility of "w+" */
		const u32 ofs = mode.update ? 2 : 1;
		/* add 'x' to the end for exclusive write */
		cmode[ofs] = mode.approach == 3 ? 'x' : '\0';
	}

	return (struct hn_file *)fopen( path, (const char *)cmode );
}

struct hn_file * hn_freopen( const hn_chr * path,
	struct hn_fmode mode,
	struct hn_file * file )
{
	chr cmode[4];

	if( path == NULL || file == NULL )
	{
		return NULL;
	}

	hn_memset( 0, 4, cmode );

	switch( mode.approach )
	{
	case 0:
	default:
		cmode[0] = 'r';
		break;
	case 1:
		cmode[0] = 'w';
		break;
	case 2:
		cmode[0] = 'a';
		break;
	case 3:
		cmode[0] = 'w';
		break;
	}

	cmode[1] = mode.update ? '+' : '\0';

#ifdef __STDC_VERSION__
#if __STDC_VERSION__ >= 201112L
	{
		/* account for the possibility of "w+" */
		const u32 ofs = mode.update ? 2 : 1;
		/* add 'x' to the end for exclusive write */
		cmode[ofs] = mode.approach == 3 ? 'x' : '\0';
	}
#endif
#endif

	return (struct hn_file *)freopen(
		path, (const char *)cmode, (FILE *)file );
}

hn_bl hn_fclose( struct hn_file * file )
{
	if( file == NULL )
	{
		return HN_TRUE;
	}

	return fclose( (FILE *)file ) == 0 ? HN_FALSE : HN_TRUE;
}

hn_bl hn_fflush( struct hn_file * file )
{
	if( file == NULL )
	{
		return HN_TRUE;
	}

	return fflush( (FILE *)file ) == 0 ? HN_FALSE : HN_TRUE;
}

hn_bl hn_fsetbuf( struct hn_file * file, hn_u8 * buf )
{
	if( file == NULL )
	{
		return HN_TRUE;
	}

	setbuf( (FILE *)file, (char *)buf );
}

hn_ptri hn_fgetbufsz( void ) { return BUFSIZ; }

hn_ptri hn_fread( hn_u8 * buf, hn_ptri buf_sz, struct hn_file * file )
{
	if( buf == NULL || buf_sz == 0 || file == NULL )
	{
		return 0;
	}

	return (ptri)fread( buf, 1, buf_sz, (FILE *)file );
}

hn_ptri hn_fwrite( hn_u8 * buf, hn_ptri buf_sz, struct hn_file * file )
{
	if( buf == NULL || buf_sz == 0 || file == NULL )
	{
		return 0;
	}

	return (ptri)fwrite( buf, 1, buf_sz, (FILE *)file );
}

struct hn_fpos * hn_fgetpos( struct hn_file * file )
{
	fpos_t p;
	const int r = fgetpos( (FILE *)file, &p );

	return r == 0 ? (struct hn_fpos *)p : NULL;
}

hn_bl hn_fsetpos( struct hn_fpos * fpos, struct hn_file * file )
{
	return fsetpos( (FILE *)file, (const fpos_t *)( &fpos ) ) == 0
		? HN_FALSE
		: HN_TRUE;
}

hn_bl hn_fseek16(
	struct hn_file * file, hn_s16 ofs, enum hn_forigin orig )
{
	return fseek( (FILE *)file, (long)ofs, orig_stdio_map[orig] ) ==
			0
		? HN_FALSE
		: HN_TRUE;
}

hn_bl hn_fseek32(
	struct hn_file * file, hn_s32 ofs, enum hn_forigin orig )
{
	return fseek( (FILE *)file, (long)ofs, orig_stdio_map[orig] ) ==
			0
		? HN_FALSE
		: HN_TRUE;
}

hn_bl hn_fseek64(
	struct hn_file * file, hn_s64 ofs, enum hn_forigin orig )
{
	return fseek( (FILE *)file, (long)ofs, orig_stdio_map[orig] ) ==
			0
		? HN_FALSE
		: HN_TRUE;
}

void hn_fclearerr( struct hn_file * file ) { clearerr( (FILE *)file ); }

hn_bl hn_feof( struct hn_file * file )
{
	return feof( (FILE *)file ) == 0 ? HN_FALSE : HN_TRUE;
}

hn_bl hn_ferror( struct hn_file * file )
{
	return ferror( (FILE *)file ) == 0 ? HN_FALSE : HN_TRUE;
}
