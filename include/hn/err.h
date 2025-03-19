/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_ERR_H
#define INC_API__HN_ERR_H

#include "types/base.h"

#include "conio.h"

/* TODO: Document this! */
#if defined( _CFGOPT_NOSTDIO )
/* fake out */
#define hn_wriln_e( x, y )
#endif /* !defined( _CFGOPT_NOSTDIO ) */

#if !defined( HN_CHK_DIE )
/* Assert an expression, otherwise die. */
#define HN_CHK_DIE( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			hn_die( ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_DIE ) */

#if !defined( HN_CHK_RET )
/* Assert an expression, otherwise return void. */
#define HN_CHK_RET( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			return; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_RET ) */

#if !defined( HN_CHK_PRET )
/* Assert an expression, otherwise print and return void. */
#define HN_CHK_PRET( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			return; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PRET ) */

#if !defined( HN_CHK_RETV )
/* Assert an expression, otherwise return a value. */
#define HN_CHK_RETV( _hn_expr, _hn_failval ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			return ( _hn_failval ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_RETV ) */

#if !defined( HN_CHK_PRETV )
/* Assert an expression, otherwise print and return a value. */
#define HN_CHK_PRETV( _hn_expr, _hn_failval, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			return ( _hn_failval ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PRETV ) */

#if !defined( HN_CHK_BREAK )
/* Assert an expression, otherwise break. */
#define HN_CHK_BREAK( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			break; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_BREAK ) */

#if !defined( HN_CHK_PBREAK )
/* Assert an expression, otherwise print and break. */
#define HN_CHK_PBREAK( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			break; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PBREAK ) */

#if !defined( HN_CHK_CONT )
/* Assert an expression, otherwise continue. */
#define HN_CHK_CONT( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			continue; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_CONT ) */

#if !defined( HN_CHK_PCONT )
/* Assert an expression, otherwise print and continue. */
#define HN_CHK_PCONT( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			continue; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PCONT ) */

#if !defined( HN_CHK_GOTO )
/* Assert an expression, otherwise goto a label. */
#define HN_CHK_GOTO( _hn_expr, _hn_label ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			goto _hn_label; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_GOTO ) */

#if !defined( HN_CHK_PGOTO )
/* Assert an expression, otherwise print and goto a label. */
#define HN_CHK_PGOTO( _hn_expr, _hn_label, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			goto _hn_label; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PGOTO ) */

/**
 *
 * @brief Terminate program execution immediately.
 * @note Internally this routine uses libc's abort() routine where
 *       available, falling back to its own implementation otherwise.
 */
HN_NORETURN void hn_die( void );

#endif /* INC_API__HN_ERR_H */
