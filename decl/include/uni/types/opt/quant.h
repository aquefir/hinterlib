/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_QUANT_H
#define INC_API__UNI_TYPES_OPT_QUANT_H

#include <uni/types/quant.h>
#include <uni/types/opt/common.h>

UNI_DECL_OPT( q16d2 );
UNI_DECL_OPT( vq16d2 );
UNI_DECL_OPT( q32d2 );
UNI_DECL_OPT( vq32d2 );
UNI_DECL_OPT( q64d2 );
UNI_DECL_OPT( vq64d2 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( q128d2 );
UNI_DECL_OPT( vq128d2 );
#endif /* UNI_HAS_F128( ) */

UNI_DECL_OPT( q16d3 );
UNI_DECL_OPT( vq16d3 );
UNI_DECL_OPT( q32d3 );
UNI_DECL_OPT( vq32d3 );
UNI_DECL_OPT( q64d3 );
UNI_DECL_OPT( vq64d3 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( q128d3 );
UNI_DECL_OPT( vq128d3 );
#endif /* UNI_HAS_F128( ) */

UNI_DECL_OPT( q16d4 );
UNI_DECL_OPT( vq16d4 );
UNI_DECL_OPT( q32d4 );
UNI_DECL_OPT( vq32d4 );
UNI_DECL_OPT( q64d4 );
UNI_DECL_OPT( vq64d4 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( q128d4 );
UNI_DECL_OPT( vq128d4 );
#endif /* UNI_HAS_F128( ) */

UNI_DECL_OPT( q16d5 );
UNI_DECL_OPT( vq16d5 );
UNI_DECL_OPT( q32d5 );
UNI_DECL_OPT( vq32d5 );
UNI_DECL_OPT( q64d5 );
UNI_DECL_OPT( vq64d5 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( q128d5 );
UNI_DECL_OPT( vq128d5 );
#endif /* UNI_HAS_F128( ) */

UNI_DECL_OPT( q16d6 );
UNI_DECL_OPT( vq16d6 );
UNI_DECL_OPT( q32d6 );
UNI_DECL_OPT( vq32d6 );
UNI_DECL_OPT( q64d6 );
UNI_DECL_OPT( vq64d6 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( q128d6 );
UNI_DECL_OPT( vq128d6 );
#endif /* UNI_HAS_F128( ) */

#endif /* INC_API__UNI_TYPES_OPT_QUANT_H */
