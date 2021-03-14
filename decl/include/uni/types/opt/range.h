/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_RANGE_H
#define INC_API__UNI_TYPES_OPT_RANGE_H

#include <uni/types/range.h>
#include <uni/types/opt/common.h>

UNI_DECL_OPT( rs8 );
UNI_DECL_OPT( vrs8 );
UNI_DECL_OPT( ru8 );
UNI_DECL_OPT( vru8 );

UNI_DECL_OPT( rs16 );
UNI_DECL_OPT( vrs16 );
UNI_DECL_OPT( ru16 );
UNI_DECL_OPT( vru16 );

UNI_DECL_OPT( rs32 );
UNI_DECL_OPT( vrs32 );
UNI_DECL_OPT( ru32 );
UNI_DECL_OPT( vru32 );

#if UNI_HAS_I64( )
UNI_DECL_OPT( rs64 );
UNI_DECL_OPT( vrs64 );
UNI_DECL_OPT( ru64 );
UNI_DECL_OPT( vru64 );
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
UNI_DECL_OPT( rs128 );
UNI_DECL_OPT( vrs128 );
UNI_DECL_OPT( ru128 );
UNI_DECL_OPT( vru128 );
#endif /* UNI_HAS_I128( ) */

#endif /* INC_API__UNI_TYPES_OPT_RANGE_H */
