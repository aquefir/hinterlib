/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPTIONS_H
#define INC_API__UNI_TYPES_OPTIONS_H

#include "float.h"
#include "int.h"
#include "opt.h"
#include "vec.h"

UNI_DECL_OPT( u8 );
UNI_DECL_OPT( vu8 );
UNI_DECL_OPT( u16 );
UNI_DECL_OPT( vu16 );
UNI_DECL_OPT( u32 );
UNI_DECL_OPT( vu32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( u64 );
UNI_DECL_OPT( vu64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( u128 );
UNI_DECL_OPT( vu128 );
#endif /* UNI_HAS_I128( ) */
UNI_DECL_OPT( s8 );
UNI_DECL_OPT( vs8 );
UNI_DECL_OPT( s16 );
UNI_DECL_OPT( vs16 );
UNI_DECL_OPT( s32 );
UNI_DECL_OPT( vs32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( s64 );
UNI_DECL_OPT( vs64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( s128 );
UNI_DECL_OPT( vs128 );
#endif /* UNI_HAS_I128( ) */
UNI_DECL_OPT( ptri );
UNI_DECL_OPT( vptri );
UNI_DECL_OPT( offs );
UNI_DECL_OPT( voffs );

UNI_DECL_OPT( f16 );
UNI_DECL_OPT( vf16 );
UNI_DECL_OPT( f32 );
UNI_DECL_OPT( vf32 );
UNI_DECL_OPT( f64 );
UNI_DECL_OPT( vf64 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( f128 );
UNI_DECL_OPT( vf128 );
#endif /* UNI_HAS_F128( ) */

UNI_DECL_OPT( s8v2 );
UNI_DECL_OPT( s8v4 );
UNI_DECL_OPT( s8v8 );
UNI_DECL_OPT( s8v16 );
UNI_DECL_OPT( s8v32 );
UNI_DECL_OPT( s8v64 );

UNI_DECL_OPT( vs8v2 );
UNI_DECL_OPT( vs8v4 );
UNI_DECL_OPT( vs8v8 );
UNI_DECL_OPT( vs8v16 );
UNI_DECL_OPT( vs8v32 );
UNI_DECL_OPT( vs8v64 );

UNI_DECL_OPT( u8v2 );
UNI_DECL_OPT( u8v4 );
UNI_DECL_OPT( u8v8 );
UNI_DECL_OPT( u8v16 );
UNI_DECL_OPT( u8v32 );
UNI_DECL_OPT( u8v64 );

UNI_DECL_OPT( vu8v2 );
UNI_DECL_OPT( vu8v4 );
UNI_DECL_OPT( vu8v8 );
UNI_DECL_OPT( vu8v16 );
UNI_DECL_OPT( vu8v32 );
UNI_DECL_OPT( vu8v64 );

UNI_DECL_OPT( s16v2 );
UNI_DECL_OPT( s16v4 );
UNI_DECL_OPT( s16v8 );
UNI_DECL_OPT( s16v16 );
UNI_DECL_OPT( s16v32 );

UNI_DECL_OPT( vs16v2 );
UNI_DECL_OPT( vs16v4 );
UNI_DECL_OPT( vs16v8 );
UNI_DECL_OPT( vs16v16 );
UNI_DECL_OPT( vs16v32 );

UNI_DECL_OPT( u16v2 );
UNI_DECL_OPT( u16v4 );
UNI_DECL_OPT( u16v8 );
UNI_DECL_OPT( u16v16 );
UNI_DECL_OPT( u16v32 );

UNI_DECL_OPT( vu16v2 );
UNI_DECL_OPT( vu16v4 );
UNI_DECL_OPT( vu16v8 );
UNI_DECL_OPT( vu16v16 );
UNI_DECL_OPT( vu16v32 );

UNI_DECL_OPT( f16v2 );
UNI_DECL_OPT( f16v4 );
UNI_DECL_OPT( f16v8 );
UNI_DECL_OPT( f16v16 );
UNI_DECL_OPT( f16v32 );

UNI_DECL_OPT( vf16v2 );
UNI_DECL_OPT( vf16v4 );
UNI_DECL_OPT( vf16v8 );
UNI_DECL_OPT( vf16v16 );
UNI_DECL_OPT( vf16v32 );

UNI_DECL_OPT( s32v2 );
UNI_DECL_OPT( s32v4 );
UNI_DECL_OPT( s32v8 );
UNI_DECL_OPT( s32v16 );

UNI_DECL_OPT( vs32v2 );
UNI_DECL_OPT( vs32v4 );
UNI_DECL_OPT( vs32v8 );
UNI_DECL_OPT( vs32v16 );

UNI_DECL_OPT( u32v2 );
UNI_DECL_OPT( u32v4 );
UNI_DECL_OPT( u32v8 );
UNI_DECL_OPT( u32v16 );

UNI_DECL_OPT( vu32v2 );
UNI_DECL_OPT( vu32v4 );
UNI_DECL_OPT( vu32v8 );
UNI_DECL_OPT( vu32v16 );

UNI_DECL_OPT( f32v2 );
UNI_DECL_OPT( f32v4 );
UNI_DECL_OPT( f32v8 );
UNI_DECL_OPT( f32v16 );

UNI_DECL_OPT( vf32v2 );
UNI_DECL_OPT( vf32v4 );
UNI_DECL_OPT( vf32v8 );
UNI_DECL_OPT( vf32v16 );

#if UNI_HAS_I64( )
UNI_DECL_OPT( s64v2 );
UNI_DECL_OPT( s64v4 );
UNI_DECL_OPT( s64v8 );

UNI_DECL_OPT( vs64v2 );
UNI_DECL_OPT( vs64v4 );
UNI_DECL_OPT( vs64v8 );

UNI_DECL_OPT( u64v2 );
UNI_DECL_OPT( u64v4 );
UNI_DECL_OPT( u64v8 );

UNI_DECL_OPT( vu64v2 );
UNI_DECL_OPT( vu64v4 );
UNI_DECL_OPT( vu64v8 );
#endif /* UNI_HAS_I64( ) */

UNI_DECL_OPT( f64v2 );
UNI_DECL_OPT( f64v4 );
UNI_DECL_OPT( f64v8 );

UNI_DECL_OPT( vf64v2 );
UNI_DECL_OPT( vf64v4 );
UNI_DECL_OPT( vf64v8 );

#if UNI_HAS_I128( )
UNI_DECL_OPT( s128v2 );
UNI_DECL_OPT( s128v4 );

UNI_DECL_OPT( vs128v2 );
UNI_DECL_OPT( vs128v4 );

UNI_DECL_OPT( u128v2 );
UNI_DECL_OPT( u128v4 );

UNI_DECL_OPT( vu128v2 );
UNI_DECL_OPT( vu128v4 );
#endif /* UNI_HAS_I128( ) */

#if UNI_HAS_F128( )
UNI_DECL_OPT( f128v2 );
UNI_DECL_OPT( f128v4 );

UNI_DECL_OPT( vf128v2 );
UNI_DECL_OPT( vf128v4 );
#endif /* UNI_HAS_F128( ) */

#endif /* INC_API__UNI_TYPES_OPTIONS_H */
