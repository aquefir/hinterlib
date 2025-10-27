/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_INTVEC_H
#define INC_API__HN_TYPES_INTVEC_H

#include "base.h"

#if defined(__has_attribute)
#if __has_attribute( vector_size )
#if !defined(HN_VECTOR)
#define HN_VECTOR( _b, _a, _n ) _b _a HN_VECSIZE( _n )
#endif /* !defined( HN_VECTOR ) */
#endif /* __has_attribute( vector_size ) */
#endif /* defined( __has_attribute ) */

/* Define the vector as a plain array if vector support is absent. */
#if !defined(HN_VECTOR)
#define HN_VECTOR( _b, _a, _n ) _b[_n] _a
#endif /* !defined( HN_VECTOR ) */

#if defined(HN_HAVE_I64)
/* 2-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, __INT64_TYPE__v2, 16 );
/* 4-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, __INT64_TYPE__v4, 32 );
/* 8-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, __INT64_TYPE__v8, 64 );
#endif /* defined( HN_HAVE_I64 ) */

#if defined(HN_HAVE_I32)
/* 2-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, hn_s32v2, 8 );
/* 4-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, hn_s32v4, 16 );
/* 8-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, hn_s32v8, 32 );
/* 16-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, hn_s32v16, 64 );
#endif /* defined( HN_HAVE_I32 ) */

/* 2-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, hn_s16v2, 4 );
/* 4-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, hn_s16v4, 8 );
/* 8-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, hn_s16v8, 16 );
/* 16-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, hn_s16v16, 32 );
/* 32-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, hn_s16v32, 64 );

/* 2-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v2, 2 );
/* 4-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v4, 4 );
/* 8-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v8, 8 );
/* 16-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v16, 16 );
/* 32-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v32, 32 );
/* 64-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, hn_s8v64, 64 );

#if defined(HN_HAVE_I64)
/* 2-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, hn_u64v2, 16 );
/* 4-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, hn_u64v4, 32 );
/* 8-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, hn_u64v8, 64 );
#endif /* defined( HN_HAVE_I64 ) */

#if defined(HN_HAVE_I32)
/* 2-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, hn_u32v2, 8 );
/* 4-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, hn_u32v4, 16 );
/* 8-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, hn_u32v8, 32 );
/* 16-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, hn_u32v16, 64 );
#endif /* defined( HN_HAVE_I32 ) */

/* 2-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, hn_u16v2, 4 );
/* 4-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, hn_u16v4, 8 );
/* 8-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, hn_u16v8, 16 );
/* 16-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, hn_u16v16, 32 );
/* 32-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, hn_u16v32, 64 );

/* 2-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v2, 2 );
/* 4-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v4, 4 );
/* 8-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v8, 8 );
/* 16-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v16, 16 );
/* 32-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v32, 32 );
/* 64-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, hn_u8v64, 64 );

#if !defined(_CFGOPT_NOSHORTHAND)
#if defined(HN_HAVE_I64)
/* 2-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, s64v2, 16 );
/* 4-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, s64v4, 32 );
/* 8-wide vector of signed 64-bit integers. */
typedef HN_VECTOR( __INT64_TYPE__, s64v8, 64 );
#endif /* defined( HN_HAVE_I64 ) */

#if defined(HN_HAVE_I32)
/* 2-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, s32v2, 8 );
/* 4-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, s32v4, 16 );
/* 8-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, s32v8, 32 );
/* 16-wide vector of signed 32-bit integers. */
typedef HN_VECTOR( __INT32_TYPE__, s32v16, 64 );
#endif /* defined( HN_HAVE_I32 ) */

/* 2-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, s16v2, 4 );
/* 4-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, s16v4, 8 );
/* 8-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, s16v8, 16 );
/* 16-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, s16v16, 32 );
/* 32-wide vector of signed 16-bit integers. */
typedef HN_VECTOR( __INT16_TYPE__, s16v32, 64 );

/* 2-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v2, 2 );
/* 4-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v4, 4 );
/* 8-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v8, 8 );
/* 16-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v16, 16 );
/* 32-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v32, 32 );
/* 64-wide vector of signed 8-bit integers. */
typedef HN_VECTOR( __INT8_TYPE__, s8v64, 64 );

#if defined(HN_HAVE_I64)
/* 2-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, u64v2, 16 );
/* 4-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, u64v4, 32 );
/* 8-wide vector of unsigned 64-bit integers. */
typedef HN_VECTOR( __UINT64_TYPE__, u64v8, 64 );
#endif /* defined( HN_HAVE_I64 ) */

#if defined(HN_HAVE_I32)
/* 2-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, u32v2, 8 );
/* 4-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, u32v4, 16 );
/* 8-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, u32v8, 32 );
/* 16-wide vector of unsigned 32-bit integers. */
typedef HN_VECTOR( __UINT32_TYPE__, u32v16, 64 );
#endif /* defined( HN_HAVE_I32 ) */

/* 2-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, u16v2, 4 );
/* 4-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, u16v4, 8 );
/* 8-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, u16v8, 16 );
/* 16-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, u16v16, 32 );
/* 32-wide vector of unsigned 16-bit integers. */
typedef HN_VECTOR( __UINT16_TYPE__, u16v32, 64 );

/* 2-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v2, 2 );
/* 4-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v4, 4 );
/* 8-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v8, 8 );
/* 16-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v16, 16 );
/* 32-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v32, 32 );
/* 64-wide vector of unsigned 8-bit integers. */
typedef HN_VECTOR( __UINT8_TYPE__, u8v64, 64 );
#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_INTVEC_H */
