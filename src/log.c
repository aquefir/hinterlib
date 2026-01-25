/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/log.h>

#if !defined(_CFGOPT_NOSTDIO)
#include <hn/memops.h>
#include <stdarg.h>
#include <stdio.h>

hn_bl hn_log_grp( struct hn_log * log )
{
	if((log == NULL) || (log->indent_lvl >= 7))
	{
		return HN_TRUE;
	}

	log->indent_lvl += 1;

	return HN_FALSE;
}

hn_bl hn_log_ungrp( struct hn_log * log )
{
	if((log == NULL) || (log->indent_lvl <= 0))
	{
		return HN_TRUE;
	}

	log->indent_lvl -= 1;

	return HN_FALSE;
}

void hn_log_info( struct hn_log * log, const chr * fmt, ... )
{
	chr prefix[HN_LOG_PREFIX_SZ + 1];
	u16 i;
	va_list args;

	if((log == NULL) || (fmt == NULL))
	{
		return;
	}

	hn_memset( prefix, 0, HN_LOG_PREFIX_SZ + 1 );
	hn_memcpy( prefix, log->prefix_info, HN_LOG_PREFIX_SZ + 1 );

	for(i = 0; i < log->indent_lvl; ++i)
	{
		fputs( "\t", stderr );
	}

	fprintf( stderr, "%s", prefix );

	va_start( args, fmt );
	vfprintf( stderr, fmt, args );
	va_end( args );

	fputs( "\n", stderr );
	fflush( stderr );
}

void hn_log_warn( struct hn_log * log, const chr * fmt, ... )
{
	chr prefix[HN_LOG_PREFIX_SZ + 1];
	u16 i;
	va_list args;

	if((log == NULL) || (fmt == NULL))
	{
		return;
	}

	hn_memset( prefix, 0, HN_LOG_PREFIX_SZ + 1 );
	hn_memcpy( prefix, log->prefix_warn, HN_LOG_PREFIX_SZ + 1 );

	for(i = 0; i < log->indent_lvl; ++i)
	{
		fputs( "\t", stderr );
	}

	fprintf( stderr, "%s", prefix );

	va_start( args, fmt );
	vfprintf( stderr, fmt, args );
	va_end( args );

	fputs( "\n", stderr );
	fflush( stderr );
}

void hn_log_err( struct hn_log * log, const chr * fmt, ... )
{
	chr prefix[HN_LOG_PREFIX_SZ + 1];
	u16 i;
	va_list args;

	if((log == NULL) || (fmt == NULL))
	{
		return;
	}

	hn_memset( prefix, 0, HN_LOG_PREFIX_SZ + 1 );
	hn_memcpy( prefix, log->prefix_err, HN_LOG_PREFIX_SZ + 1 );

	for(i = 0; i < log->indent_lvl; ++i)
	{
		fputs( "\t", stderr );
	}

	fprintf( stderr, "%s", prefix );

	va_start( args, fmt );
	vfprintf( stderr, fmt, args );
	va_end( args );

	fputs( "\n", stderr );
	fflush( stderr );
}
#endif /* !defined( _CFGOPT_NOSTDIO ) */
