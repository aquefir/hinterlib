/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_INT_H
#define INC_API__HN_TYPES_INT_H

#include "def.h"

#if defined( HN_HAVE_I64 )
/* Signed 64-bit integer. */
typedef __INT64_TYPE__ hn_s64;
#endif /* defined( HN_HAVE_I64 ) */
#if defined( HN_HAVE_I32 )
/* Signed 32-bit integer. */
typedef __INT32_TYPE__ hn_s32;
/* Signed 16-bit integer. */
#endif /* defined( HN_HAVE_I32 ) */
typedef __INT16_TYPE__ hn_s16;
/* Signed 8-bit integer. */
typedef __INT8_TYPE__ hn_s8;
#if defined( HN_HAVE_I64 )
/* Unsigned 64-bit integer. */
typedef __UINT64_TYPE__ hn_u64;
#endif /* defined( HN_HAVE_I64 ) */
#if defined( HN_HAVE_I32 )
/* Unsigned 32-bit integer. */
typedef __UINT32_TYPE__ hn_u32;
#endif /* defined( HN_HAVE_I32 ) */
/* Unsigned 16-bit integer. */
typedef __UINT16_TYPE__ hn_u16;
/* Unsigned 8-bit integer. */
typedef __UINT8_TYPE__ hn_u8;

#if !defined( _CFGOPT_NOSHORTHAND )

#if defined( HN_HAVE_I64 )
/* Signed 64-bit integer. */
typedef __INT64_TYPE__ s64;
#endif /* defined( HN_HAVE_I64 ) */
#if defined( HN_HAVE_I32 )
/* Signed 32-bit integer. */
typedef __INT32_TYPE__ s32;
#endif /* defined( HN_HAVE_I32 ) */
/* Signed 16-bit integer. */
typedef __INT16_TYPE__ s16;
/* Signed 8-bit integer. */
typedef __INT8_TYPE__ s8;
#if defined( HN_HAVE_I64 )
/* Unsigned 64-bit integer. */
typedef __UINT64_TYPE__ u64;
#endif /* defined( HN_HAVE_I64 ) */
#if defined( HN_HAVE_I32 )
/* Unsigned 32-bit integer. */
typedef __UINT32_TYPE__ u32;
#endif /* defined( HN_HAVE_I32 ) */
/* Unsigned 16-bit integer. */
typedef __UINT16_TYPE__ u16;
/* Unsigned 8-bit integer. */
typedef __UINT8_TYPE__ u8;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_INT_H */
