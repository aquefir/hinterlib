/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_VECI_H
#define INC_API__UNI_TYPES_OPT_VECI_H

#include <uni/types/veci.h>
#include <uni/types/opt/common.h>

UNI_DECL_OPT( s8v2 );
UNI_DECL_OPT( s8v4 );
UNI_DECL_OPT( s8v8 );
UNI_DECL_OPT( s8v16 );
UNI_DECL_OPT( s8v32 );
UNI_DECL_OPT( s8v64 );

UNI_DECL_OPT( u8v2 );
UNI_DECL_OPT( u8v4 );
UNI_DECL_OPT( u8v8 );
UNI_DECL_OPT( u8v16 );
UNI_DECL_OPT( u8v32 );
UNI_DECL_OPT( u8v64 );

UNI_DECL_OPT( s16v2 );
UNI_DECL_OPT( s16v4 );
UNI_DECL_OPT( s16v8 );
UNI_DECL_OPT( s16v16 );
UNI_DECL_OPT( s16v32 );

UNI_DECL_OPT( u16v2 );
UNI_DECL_OPT( u16v4 );
UNI_DECL_OPT( u16v8 );
UNI_DECL_OPT( u16v16 );
UNI_DECL_OPT( u16v32 );

UNI_DECL_OPT( s32v2 );
UNI_DECL_OPT( s32v4 );
UNI_DECL_OPT( s32v8 );
UNI_DECL_OPT( s32v16 );

UNI_DECL_OPT( u32v2 );
UNI_DECL_OPT( u32v4 );
UNI_DECL_OPT( u32v8 );
UNI_DECL_OPT( u32v16 );

#if UNI_HAS_I64( )
UNI_DECL_OPT( s64v2 );
UNI_DECL_OPT( s64v4 );
UNI_DECL_OPT( s64v8 );

UNI_DECL_OPT( u64v2 );
UNI_DECL_OPT( u64v4 );
UNI_DECL_OPT( u64v8 );
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
UNI_DECL_OPT( s128v2 );
UNI_DECL_OPT( s128v4 );

UNI_DECL_OPT( u128v2 );
UNI_DECL_OPT( u128v4 );
#endif /* UNI_HAS_I128( ) */

UNI_DECL_OPT( vs8v2 );
UNI_DECL_OPT( vs8v4 );
UNI_DECL_OPT( vs8v8 );
UNI_DECL_OPT( vs8v16 );
UNI_DECL_OPT( vs8v32 );
UNI_DECL_OPT( vs8v64 );

UNI_DECL_OPT( vu8v2 );
UNI_DECL_OPT( vu8v4 );
UNI_DECL_OPT( vu8v8 );
UNI_DECL_OPT( vu8v16 );
UNI_DECL_OPT( vu8v32 );
UNI_DECL_OPT( vu8v64 );

UNI_DECL_OPT( vs16v2 );
UNI_DECL_OPT( vs16v4 );
UNI_DECL_OPT( vs16v8 );
UNI_DECL_OPT( vs16v16 );
UNI_DECL_OPT( vs16v32 );

UNI_DECL_OPT( vu16v2 );
UNI_DECL_OPT( vu16v4 );
UNI_DECL_OPT( vu16v8 );
UNI_DECL_OPT( vu16v16 );
UNI_DECL_OPT( vu16v32 );

UNI_DECL_OPT( vs32v2 );
UNI_DECL_OPT( vs32v4 );
UNI_DECL_OPT( vs32v8 );
UNI_DECL_OPT( vs32v16 );

UNI_DECL_OPT( vu32v2 );
UNI_DECL_OPT( vu32v4 );
UNI_DECL_OPT( vu32v8 );
UNI_DECL_OPT( vu32v16 );

#if UNI_HAS_I64( )
UNI_DECL_OPT( vs64v2 );
UNI_DECL_OPT( vs64v4 );
UNI_DECL_OPT( vs64v8 );

UNI_DECL_OPT( vu64v2 );
UNI_DECL_OPT( vu64v4 );
UNI_DECL_OPT( vu64v8 );
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
UNI_DECL_OPT( vs128v2 );
UNI_DECL_OPT( vs128v4 );

UNI_DECL_OPT( vu128v2 );
UNI_DECL_OPT( vu128v4 );
#endif /* UNI_HAS_I128( ) */

#endif /* INC_API__UNI_TYPES_OPT_VECI_H */
