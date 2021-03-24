/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_COMPLEXF_H
#define INC_API__UNI_TYPES_OPT_COMPLEXF_H

#if !defined( __clang__ ) && !defined( __GNUC__ )
#pragma message( \
	"Complex number support only works with GCC and clang. The types and functions for this will be unavailable." )
#else

#include <uni/types/complexf.h>
#include <uni/types/opt/common.h>

UNI_DECL_OPT( cf16 );
UNI_DECL_OPT( cf32 );
UNI_DECL_OPT( cf64 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( cf128 );
#endif /* UNI_HAS_F128 */

UNI_DECL_OPT( vcf16 );
UNI_DECL_OPT( vcf32 );
UNI_DECL_OPT( vcf64 );
#if UNI_HAS_F128( )
UNI_DECL_OPT( vcf128 );
#endif /* UNI_HAS_F128 */

#endif /* !defined( __clang__) && !defined( __GNUC__ ) */

#endif /* INC_API__UNI_TYPES_OPT_COMPLEXF_H */
