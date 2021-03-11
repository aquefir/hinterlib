/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_INT_H
#define INC_API__UNI_TYPES_INT_H

#if !defined( NULL )
#if defined( __cplusplus )
#define NULL ( (void *)0 )
#else
#define NULL 0
#endif /* defined( __cplusplus ) */
#endif /* !defined( NULL ) */

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
#define UNI_HAS_I128() 1
#define UNI_HAS_I64() 1
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
#define UNI_HAS_I128() 0
#define UNI_HAS_I64() 1
#endif

typedef u32 char32;

#define U8_MAX ( (u8)0xFF )
#define U16_MAX ( (u16)0xFFFF )
#define U32_MAX ( (u32)0xFFFFFFFF )
#if UNI_HAS_I64()
#define U64_MAX ( (u64)0xFFFFFFFFFFFFFFFF )
#endif /* UNI_HAS_I64() */
#if UNI_HAS_I128()
#define U128_MAX ( (u128)0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF )
#endif /* UNI_HAS_I128() */
#define S8_MIN ( (s8)0x80 )
#define S16_MIN ( (s16)0x8000 )
#define S32_MIN ( (s32)0x80000000 )
#define S64_MIN ( (s64)0x8000000000000000 )
#define S8_MAX ( (s8)0x7F )
#define S16_MAX ( (s16)0x7FFF )
#define S32_MAX ( (s32)0x7FFFFFFF )
#if UNI_HAS_I64()
#define S64_MAX ( (s64)0x7FFFFFFFFFFFFFFF )
#endif /* UNI_HAS_I64() */
#if UNI_HAS_I128()
#define S128_MAX ( (s128)0x7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF )
#endif /* UNI_HAS_I128() */

#define PTRI_MAX __UINTPTR_MAX__
#define OFFS_MIN __INTPTR_MIN__
#define OFFS_MAX __INTPTR_MAX__

#endif /* INC_API__UNI_TYPES_INT_H */
