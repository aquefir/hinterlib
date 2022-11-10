/****************************************************************************\
 *                         Hinterlib error handling                         *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_ERR_H
#define INC_API__UNI_ERR_H

#include <uni/log.h>
#include <uni/types/int.h>

/** Err code bits
 *   0-9 : main description (10 bits)
 * 10-18 : module of origin (9 bits)
 * 19-21 : error level (3 bits)
 * 22-31 : error flags (sub-bitfield) (10 bits)
 */

#define UNI_ERRCODE_GET_DESC( C ) ( (C)&1023 )
#define UNI_ERRCODE_GET_MOD( C ) ( ( ( C ) >> 10 ) & 511 )
#define UNI_ERRCODE_GET_LVL( C ) ( ( ( C ) >> 18 ) & 8 )
#define UNI_ERRCODE_GET_EFLAGS( C ) ( ( C ) >> 22 )

#define UNI_ERRCODE_MAKE( D, M, E, L ) \
	( ( D ) | ( ( M ) << 10 ) | ( ( E ) << 21 ) | ( ( L ) << 27 ) )

#define UNI_ERR_POOL_DECLARE_SM( SYM ) \
	u8 SYM[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

#define UNI_ERR_POOL_DECLARE_LG( SYM ) \
	u8 SYM[512] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }

#define UNI_ERR_POOL_GET( POOLID, MAPSYM ) \
	((POOLID <= 0 || POOLID > 31) ? NULL : MAPSYM[POOLID])

/* so this can be extended later perhaps */
typedef u32 uni_err_t;

struct uni_err
{
	u32 module : 15;
	u32 poolid : 5;
	u32 code : 12;
};

enum
{
	UNI_ERR_DESC_SUCCESS = 0,
	UNI_ERR_DESC_OOM,
	UNI_MAX_ERR_DESC
};

enum
{
	UNI_ERR_MOD_COMMON = 0,
	UNI_ERR_MOD_ARR,
	UNI_ERR_MOD_CLARG,
	UNI_ERR_MOD_FUTILS,
	UNI_ERR_MOD_HIMEM,
	UNI_ERR_MOD_LOG,
	UNI_ERR_MOD_MT19937,
	UNI_ERR_MOD_STR,
	UNI_ERR_MOD_TABLE,
	UNI_ERR_MOD_COSMO,
	UNI_ERR_MOD_NT,
	UNI_ERR_MOD_SYSV,
	UNI_ERR_MOD_GBABIOS,
	UNI_ERR_MOD_DPMI,
	UNI_ERR_MOD_WIN32,
	UNI_ERR_MOD_LINUX,
	UNI_ERR_MOD_DARWIN,
	UNI_ERR_MOD_X11,
	UNI_ERR_MOD_GL,
	UNI_ERR_MOD_POSIX,
	UNI_MAX_ERR_MOD
};

enum
{
	UNI_ERR_LVL_SUCCESS = 0,
	UNI_ERR_LVL_INFO,
	UNI_ERR_LVL_STATUS,
	UNI_ERR_LVL_TEMP,
	UNI_ERR_LVL_PERM,
	UNI_ERR_LVL_USAGE,
	UNI_ERR_LVL_RESET,
	UNI_ERR_LVL_FATAL
};

enum
{
	UNI_ERR_EFLAG_BLOCKING = 0,
	UNI_ERR_EFLAG_OORES,
	UNI_ERR_EFLAG_NOTFOUND,
	UNI_ERR_EFLAG_BADSTATE,
	UNI_ERR_EFLAG_NOSUPPORT,
	UNI_ERR_EFLAG_BADINPUT,
	UNI_ERR_EFLAG_INTERNAL,
	UNI_ERR_EFLAG_RESERVED1,
	UNI_ERR_EFLAG_RESERVED2,
	UNI_ERR_EFLAG_RESERVED3
};

enum
{
	UNI_ERR_EMASK_BLOCKING  = 1 << UNI_ERR_EFLAG_BLOCKING,
	UNI_ERR_EMASK_OORES     = 1 << UNI_ERR_EFLAG_OORES,
	UNI_ERR_EMASK_NOTFOUND  = 1 << UNI_ERR_EFLAG_NOTFOUND,
	UNI_ERR_EMASK_BADSTATE  = 1 << UNI_ERR_EFLAG_BADSTATE,
	UNI_ERR_EMASK_NOSUPPORT = 1 << UNI_ERR_EFLAG_NOSUPPORT,
	UNI_ERR_EMASK_BADINPUT  = 1 << UNI_ERR_EFLAG_BADINPUT,
	UNI_ERR_EMASK_INTERNAL  = 1 << UNI_ERR_EFLAG_INTERNAL,
	UNI_ERR_EMASK_RESERVED1 = 1 << UNI_ERR_EFLAG_RESERVED1,
	UNI_ERR_EMASK_RESERVED2 = 1 << UNI_ERR_EFLAG_RESERVED2,
	UNI_ERR_EMASK_RESERVED3 = 1 << UNI_ERR_EFLAG_RESERVED3
};

#if defined( NDEBUG )
#define UNI_ASSERT( cnd ) ( (void)0 )
#else /* !defined( NDEBUG ) */
#define UNI_ASSERT( cnd ) \
	( ( cnd ) ? (void)0 \
		  : uni_assert_fail( #cnd, __FILE__, __LINE__, __func__ ) )
#endif /* defined( NDEBUG ) */

#if !defined( ASSERT )
#define ASSERT( cnd ) \
	_Pragma( \
		"ASSERT( ) CPP macro is deprecated. Use UNI_ASSERT( ) instead" ) \
		UNI_ASSERT( cnd )
#endif /* !defined( ASSERT ) */

extern const char * uni_err_desc_tostr( uni_err_t );
extern const char * uni_err_mod_tostr( uni_err_t );
extern const char * uni_err_eff_tostr( uni_err_t );
extern const char * uni_err_lvl_tostr( uni_err_t );

extern void uni_die( void );
extern void uni_assert_fail(
	const char *, const char *, unsigned, const char * );

#endif /* INC_API__UNI_ERR_H */
