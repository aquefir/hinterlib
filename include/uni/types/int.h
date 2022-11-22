/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_TYPES_INT_H
#define INC_API__UNI_TYPES_INT_H

#if !defined( NULL )
#if defined( __cplusplus )
#define NULL ( (void *)0 )
#else
#define NULL 0
#endif /* defined( __cplusplus ) */
#endif /* !defined( NULL ) */

#if defined( __clang__ ) || defined( __GNUC__ )
#define UNI_HAS_I128( ) 1
#define UNI_HAS_I64( ) 1
#elif defined( __TINYC__ )
#define UNI_HAVE_I128( ) 0
#define UNI_HAVE_I64( ) 1
#endif /* defined( __clang__ ) || defined( __GNUC__ ) */

enum
{
	SIZEOF_CHAR = 1,
#if defined( __i386__ ) || defined( CFG_GBA )
	SIZEOF_PTR = 4,
#elif defined( __x86_64__ )
	SIZEOF_PTR = 8,
#endif
	S8_MIN  = -128,
	S8_MAX  = 127,
	S16_MIN = -32768,
	S16_MAX = 32767,
	U8_MAX  = 255,
	U16_MAX = 65535
};

enum
{
	S32_MIN = -2147483648,
	S32_MAX = 2147483647,
};

enum
{
	U32_MAX = 4294967295U
};

enum
{
	U64_MAX = 18446744073709551615UL
};

enum
{
	S64_MIN = -9223372036854775808LL,
	S64_MAX = 9223372036854775807LL
};

enum
{
#if defined( __i386__ ) || defined( CFG_GBA )
	OFFS_MIN = S32_MIN,
	OFFS_MAX = S32_MAX
#elif defined( __x86_64__ )
	OFFS_MIN   = S64_MIN,
	OFFS_MAX   = S64_MAX
#endif
};

enum
{
#if defined( __i386__ ) || defined( CFG_GBA )
	PTRI_MAX = U32_MAX
#elif defined( __x86_64__ )
	PTRI_MAX   = U64_MAX
#else
#error "Unknown platform."
#endif
};

#if UNI_HAS_I128( )
#define U128_MAX ( ( ( U64_MAX + 1 ) * ( U64_MAX + 1 ) ) - 1 )
#define S128_MIN ( ( ( S64_MIN * -1 ) * ( S64_MIN * -1 ) ) * -1 )
#define S128_MAX ( ( ( S64_MAX + 1 ) * ( S64_MAX + 1 ) ) - 1 )
#endif /* UNI_HAS_I128( ) */

#ifdef _MSC_VER
typedef unsigned __int8 u8;
typedef unsigned __int16 u16;
typedef unsigned __int32 u32;
typedef unsigned __int64 u64;
typedef signed __int8 s8;
typedef signed __int16 s16;
typedef signed __int32 s32;
typedef signed __int64 s64;
typedef signed __int128 s128;
#ifdef _M_IX86
typedef unsigned __int32 ptri;
typedef __int32 offs;
#elif defined( _M_X64 )
typedef unsigned __int64 ptri;
typedef __int64 offs;
#else
#error "Must be compiling for i386 or AMD64 when targeting Windows"
#endif /* _M_ arch */
/* UNIX land */
#elif defined( CFG_GBA )
typedef __INT32_TYPE__ s32;
typedef __INT16_TYPE__ s16;
typedef __INT8_TYPE__ s8;
typedef __UINT32_TYPE__ u32;
typedef __UINT16_TYPE__ u16;
typedef __UINT8_TYPE__ u8;
typedef __UINT32_TYPE__ ptri;
typedef __INT32_TYPE__ offs;
#define UNI_HAS_I128( ) 0
#define UNI_HAS_I64( ) 0
#elif defined( __clang__ ) || defined( __GNUC__ )
typedef signed __int128 s128;
typedef __INT64_TYPE__ s64;
typedef __INT32_TYPE__ s32;
typedef __INT16_TYPE__ s16;
typedef __INT8_TYPE__ s8;
typedef unsigned __int128 u128;
typedef __UINT64_TYPE__ u64;
typedef __UINT32_TYPE__ u32;
typedef __UINT16_TYPE__ u16;
typedef __UINT8_TYPE__ u8;
typedef __UINTPTR_TYPE__ ptri;
typedef __INTPTR_TYPE__ offs;
#define UNI_HAS_I128( ) 1
#define UNI_HAS_I64( ) 1
#elif defined( __TINYC__ )
#include <stdint.h>
typedef int64_t s64;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uintptr_t ptri;
typedef intptr_t offs;
#define UNI_HAS_I128( ) 0
#define UNI_HAS_I64( ) 1
#endif

typedef u16 char16;
typedef u32 char32;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
#if UNI_HAS_I64( )
typedef volatile s64 vs64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef volatile s128 vs128;
#endif /* UNI_HAS_I128( ) */

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
#if UNI_HAS_I64( )
typedef volatile u64 vu64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef volatile u128 vu128;
#endif /* UNI_HAS_I128( ) */

typedef volatile ptri vptri;
typedef volatile offs voffs;

typedef volatile char vchar;
typedef volatile char16 vchar16;
typedef volatile char32 vchar32;

#endif /* INC_API__UNI_TYPES_INT_H */
