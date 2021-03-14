/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_FLOAT_H
#define INC_API__UNI_TYPES_OPT_FLOAT_H

#include <uni/types/float.h>
#include <uni/types/opt/common.h>

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

#endif /* INC_API__UNI_TYPES_OPT_FLOAT_H */
