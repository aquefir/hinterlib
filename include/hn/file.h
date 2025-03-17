/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_FILE_H
#define INC_API__HN_FILE_H

#include "types/base.h"
#include "types/char.h"
#include "types/int.h"

enum hn_forigin
{
	HN_SEEK_SET,
	HN_SEEK_CUR,
	HN_SEEK_END,
	HN_MAX_SEEK
};

struct hn_fpos;

struct hn_file;

struct hn_fmode
{
	/* Base mode: 0 = r, 1 = w, 2 = a, 3 = x. */
	hn_u32 approach : 2;
	/* The + in the libc mode string. */
	hn_u32 update : 1;
	hn_u32 _padding : 29;
} HN_PACKED;

struct hn_file * hn_fstdin( void );

struct hn_file * hn_fstdout( void );

struct hn_file * hn_fstderr( void );

struct hn_file * hn_fopen( const hn_chr *, struct hn_fmode );

struct hn_file * hn_freopen(
	const hn_chr *, struct hn_fmode, struct hn_file * );

hn_bl hn_fclose( struct hn_file * );

hn_bl hn_fflush( struct hn_file * );

hn_bl hn_fsetbuf( struct hn_file *, hn_u8 * );

hn_ptri hn_fgetbufsz( void );

hn_ptri hn_fread( hn_u8 *, hn_ptri, struct hn_file * );

hn_ptri hn_fwrite( hn_u8 *, hn_ptri, struct hn_file * );

hn_bl hn_fgetpos( struct hn_file *, struct hn_fpos * );

hn_bl hn_fsetpos( struct hn_file *, struct hn_fpos * );

hn_bl hn_fseek( struct hn_file *, hn_s64, enum hn_forigin );

void hn_fclear( struct hn_file * );

hn_bl hn_feof( struct hn_file * );

hn_bl hn_ferror( struct hn_file * );

#endif /* INC_API__HN_FILE_H */
