/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#include <uni/err.h>

#ifdef CFG_GBA
void _bios_halt( void );
#else
#include <stdlib.h>
#endif /* CFG_GBA */

#include <uni/log.h>
#include <uni/memory.h>
#include <uni/str.h>
#include <pthread.h>

static const char * const k_err_desc[UNI_MAX_ERR_DESC] = {
	"Success", "Out of memory" };

static const char * const k_err_mod[] = { "Common",
	"Hinterlib array",
	"Hinterlib CLI args",
	"Hinterlib file utils",
	"Hinterlib HIMEM",
	"Hinterlib logging",
	"Hinterlib MT19937",
	"Hinterlib strings",
	"Hinterlib tables",
	"", /* NEOPOLITAN ONLY: "Cosmopolitan" */
	"Windows NT",
	"System V",
	"GBA BIOS",
	"DOS Protected Mode Interface",
	"Win32 APIs",
	"Linux kernel",
	"Darwin kernel",
	"X11",
	"OpenGL/Vulkan",
	"POSIX subsystem" };

static const char * const k_err_lvl[UNI_ERR_LVL_FATAL + 1] = { "Success",
	"Info",
	"Status",
	"Temporary",
	"Permanent",
	"Usage",
	"Reset",
	"Fatal" };

static const char * const k_err_eflags[UNI_ERR_EFLAG_RESERVED3 + 1] = {
	"Blocking",
	"Out of resources",
	"Not found",
	"Bad state",
	"Not supported",
	"Bad input",
	"Internal",
	"Reserved (1)",
	"Reserved (2)",
	"Reserved (3)" };

static const ptri k_err_eflags_strsz[UNI_ERR_EFLAG_RESERVED3 + 1] = {
	sizeof( "Blocking" ),
	sizeof( "Out of resources" ),
	sizeof( "Not found" ),
	sizeof( "Bad state" ),
	sizeof( "Not supported" ),
	sizeof( "Bad input" ),
	sizeof( "Internal" ),
	sizeof( "Reserved (1)" ),
	sizeof( "Reserved (2)" ),
	sizeof( "Reserved (3)" ) };

#define ERR_EFLAGS_ALL_STRSZ \
	( sizeof( "Blocking" ) + sizeof( "Out of resources" ) + \
		sizeof( "Not found" ) + sizeof( "Bad state" ) + \
		sizeof( "Not supported" ) + sizeof( "Bad input" ) + \
		sizeof( "Internal" ) + sizeof( "Reserved (1)" ) + \
		sizeof( "Reserved (2)" ) + sizeof( "Reserved (3)" ) + \
		( UNI_ERR_EFLAG_RESERVED3 * 2 ) )

#if defined( CFG_POSIX )
static int err_eflags_buf_mut_init = 0;
static pthread_mutex_t err_eflags_buf_mut;
#endif /* defined( CFG_POSIX ) */

static char err_eflags_buf[ERR_EFLAGS_ALL_STRSZ] = { 0 };

void uni_die( void )
{
#ifdef CFG_GBA
	_bios_halt( );
#else
	abort( );
#endif
}

void uni_assert_fail( const char * expr,
	const char * file,
	unsigned line,
	const char * func )
{
#ifdef CFG_GBA
	_bios_halt( );
#else
	uni_perror(
		"Assertion failed in file \"%s\" on line \"%u\", in function"
		" \"%s\".\nExpression: %s",
		file,
		line,
		func,
		expr );
	abort( );
#endif
}

const char * uni_err_desc_tostr( uni_err_t n )
{
	return n < UNI_MAX_ERR_DESC ? k_err_desc[n] : NULL;
}

const char * uni_err_mod_tostr( uni_err_t n )
{
	return n < UNI_MAX_ERR_MOD ? k_err_mod[n] : NULL;
}

const char * uni_err_eff_tostr( uni_err_t n )
{
	/* i := counter of different effects
	 * j := counter of chars used in buffer */
	ptri i, j;
	/* just the flags */
	const u16 f = UNI_ERRCODE_GET_EFLAGS( n );
	/* whether the buffer is locked yet */
#if defined( CFG_POSIX )
	int lock = 0, r;
#endif /* defined( CFG_POSIX ) */

	for( i = 0, j = 0; i <= UNI_ERR_EFLAG_RESERVED3; ++i )
	{
		const u16 b = 1 << i;

		if( ( f & b ) == b )
		{
#if defined( CFG_POSIX )
			/* initialise the buffer’s mutex */
			if( !err_eflags_buf_mut_init )
			{
				r = pthread_mutex_init(
					&err_eflags_buf_mut, NULL );

				if( r )
				{
					return NULL;
				}

				err_eflags_buf_mut_init = 1;
			}

			/* lock the buffer */
			if( !lock )
			{
				r = pthread_mutex_lock( &err_eflags_buf_mut );
				lock = 1;

				if( r )
				{
					return NULL;
				}
			}
#endif /* defined( CFG_POSIX ) */

			if( j > 0 && j < ERR_EFLAGS_ALL_STRSZ - 2 )
			{
				err_eflags_buf[j] = ',';
				err_eflags_buf[j] = ' ';

				j += 2;
			}

			uni_memcpy( ( (u8 *)err_eflags_buf ) + j,
				k_err_eflags[i],
				k_err_eflags_strsz[i] );
			j += k_err_eflags_strsz[i];
		}
	}

#if defined( CFG_POSIX )
	if( lock )
	{
		r = pthread_mutex_unlock( &err_eflags_buf_mut );
	}
#endif /* defined( CFG_POSIX ) */

	return (const char *)err_eflags_buf;
}

const char * uni_err_lvl_tostr( uni_err_t n )
{
	return n <= UNI_ERR_LVL_FATAL ? k_err_lvl[n] : NULL;
}
