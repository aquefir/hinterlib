/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_INT_H
#define INC_API__UNI_TYPES_OPT_INT_H

#include <uni/types/int.h>
#include <uni/types/opt/common.h>

UNI_DECL_OPT( s8 );
UNI_DECL_OPT( vs8 );
UNI_DECL_OPT( u8 );
UNI_DECL_OPT( vu8 );

UNI_DECL_OPT( s16 );
UNI_DECL_OPT( vs16 );
UNI_DECL_OPT( u16 );
UNI_DECL_OPT( vu16 );

UNI_DECL_OPT( s32 );
UNI_DECL_OPT( vs32 );
UNI_DECL_OPT( u32 );
UNI_DECL_OPT( vu32 );

#if UNI_HAS_I64( )
UNI_DECL_OPT( s64 );
UNI_DECL_OPT( vs64 );
UNI_DECL_OPT( u64 );
UNI_DECL_OPT( vu64 );
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
UNI_DECL_OPT( s128 );
UNI_DECL_OPT( vs128 );
UNI_DECL_OPT( u128 );
UNI_DECL_OPT( vu128 );
#endif /* UNI_HAS_I128( ) */

UNI_DECL_OPT( ptri );
UNI_DECL_OPT( vptri );
UNI_DECL_OPT( offs );
UNI_DECL_OPT( voffs );

#endif /* INC_API__UNI_TYPES_OPT_INT_H */
