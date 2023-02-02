/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_TYPES_INTVEC_H
#define INC_API__HN_TYPES_INTVEC_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#if !defined( HN_VECSIZE )
#define HN_VECSIZE(_n) __attribute__( ( vector_size( _n ) ) )
#endif /* !defined( HN_VECSIZE ) */

#if defined( _SYNDEF_HAVE_I64 )
/* 2-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ hn_s64v2 HN_VECSIZE( 16 );
/* 4-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ hn_s64v4 HN_VECSIZE( 32 );
/* 8-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ hn_s64v8 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

#if defined( _SYNDEF_HAVE_I32 )
/* 2-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ hn_s32v2 HN_VECSIZE( 8 );
/* 4-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ hn_s32v4 HN_VECSIZE( 16 );
/* 8-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ hn_s32v8 HN_VECSIZE( 32 );
/* 16-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ hn_s32v16 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

/* 2-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ hn_s16v2 HN_VECSIZE( 4 );
/* 4-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ hn_s16v4 HN_VECSIZE( 8 );
/* 8-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ hn_s16v8 HN_VECSIZE( 16 );
/* 16-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ hn_s16v16 HN_VECSIZE( 32 );
/* 32-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ hn_s16v32 HN_VECSIZE( 64 );

/* 2-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v2 HN_VECSIZE( 2 );
/* 4-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v4 HN_VECSIZE( 4 );
/* 8-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v8 HN_VECSIZE( 8 );
/* 16-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v16 HN_VECSIZE( 16 );
/* 32-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v32 HN_VECSIZE( 32 );
/* 64-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ hn_s8v64 HN_VECSIZE( 64 );

#if defined( _SYNDEF_HAVE_I64 )
/* 2-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ hn_u64v2 HN_VECSIZE( 16 );
/* 4-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ hn_u64v4 HN_VECSIZE( 32 );
/* 8-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ hn_u64v8 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

#if defined( _SYNDEF_HAVE_I32 )
/* 2-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ hn_u32v2 HN_VECSIZE( 8 );
/* 4-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ hn_u32v4 HN_VECSIZE( 16 );
/* 8-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ hn_u32v8 HN_VECSIZE( 32 );
/* 16-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ hn_u32v16 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

/* 2-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ hn_u16v2 HN_VECSIZE( 4 );
/* 4-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ hn_u16v4 HN_VECSIZE( 8 );
/* 8-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ hn_u16v8 HN_VECSIZE( 16 );
/* 16-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ hn_u16v16 HN_VECSIZE( 32 );
/* 32-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ hn_u16v32 HN_VECSIZE( 64 );

/* 2-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v2 HN_VECSIZE( 2 );
/* 4-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v4 HN_VECSIZE( 4 );
/* 8-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v8 HN_VECSIZE( 8 );
/* 16-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v16 HN_VECSIZE( 16 );
/* 32-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v32 HN_VECSIZE( 32 );
/* 64-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ hn_u8v64 HN_VECSIZE( 64 );

#if !defined( _CFGOPT_NOSHORTHAND )

#if defined( _SYNDEF_HAVE_I64 )
/* 2-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ s64v2 HN_VECSIZE( 16 );
/* 4-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ s64v4 HN_VECSIZE( 32 );
/* 8-wide vector of signed 64-bit integers. */
typedef __INT64_TYPE__ s64v8 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

#if defined( _SYNDEF_HAVE_I32 )
/* 2-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v2 HN_VECSIZE( 8 );
/* 4-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v4 HN_VECSIZE( 16 );
/* 8-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v8 HN_VECSIZE( 32 );
/* 16-wide vector of signed 32-bit integers. */
typedef __INT32_TYPE__ s32v16 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

/* 2-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v2 HN_VECSIZE( 4 );
/* 4-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v4 HN_VECSIZE( 8 );
/* 8-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v8 HN_VECSIZE( 16 );
/* 16-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v16 HN_VECSIZE( 32 );
/* 32-wide vector of signed 16-bit integers. */
typedef __INT16_TYPE__ s16v32 HN_VECSIZE( 64 );

/* 2-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v2 HN_VECSIZE( 2 );
/* 4-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v4 HN_VECSIZE( 4 );
/* 8-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v8 HN_VECSIZE( 8 );
/* 16-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v16 HN_VECSIZE( 16 );
/* 32-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v32 HN_VECSIZE( 32 );
/* 64-wide vector of signed 8-bit integers. */
typedef __INT8_TYPE__ s8v64 HN_VECSIZE( 64 );

#if defined( _SYNDEF_HAVE_I64 )
/* 2-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ u64v2 HN_VECSIZE( 16 );
/* 4-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ u64v4 HN_VECSIZE( 32 );
/* 8-wide vector of unsigned 64-bit integers. */
typedef __UINT64_TYPE__ u64v8 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I64 ) */

#if defined( _SYNDEF_HAVE_I32 )
/* 2-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v2 HN_VECSIZE( 8 );
/* 4-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v4 HN_VECSIZE( 16 );
/* 8-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v8 HN_VECSIZE( 32 );
/* 16-wide vector of unsigned 32-bit integers. */
typedef __UINT32_TYPE__ u32v16 HN_VECSIZE( 64 );
#endif /* defined( _SYNDEF_HAVE_I32 ) */

/* 2-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v2 HN_VECSIZE( 4 );
/* 4-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v4 HN_VECSIZE( 8 );
/* 8-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v8 HN_VECSIZE( 16 );
/* 16-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v16 HN_VECSIZE( 32 );
/* 32-wide vector of unsigned 16-bit integers. */
typedef __UINT16_TYPE__ u16v32 HN_VECSIZE( 64 );

/* 2-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v2 HN_VECSIZE( 2 );
/* 4-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v4 HN_VECSIZE( 4 );
/* 8-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v8 HN_VECSIZE( 8 );
/* 16-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v16 HN_VECSIZE( 16 );
/* 32-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v32 HN_VECSIZE( 32 );
/* 64-wide vector of unsigned 8-bit integers. */
typedef __UINT8_TYPE__ u8v64 HN_VECSIZE( 64 );

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_INTVEC_H */
