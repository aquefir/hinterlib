/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_COMPLEXI_H
#define INC_API__UNI_TYPES_OPT_COMPLEXI_H

#if !defined( __clang__ ) && !defined( __GNUC__ )
#pragma message( \
	"Complex number support only works with GCC and clang. The types and functions for this will be unavailable." )
#else

#include <uni/types/complexi.h>
#include <uni/types/opt/common.h>

#ifndef REAL
#define REAL __real__
#endif /* REAL */

#ifndef IMAG
#define IMAG __imag__
#endif /* IMAG */

UNI_DECL_OPT( cs8 );
UNI_DECL_OPT( cs16 );
UNI_DECL_OPT( cs32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( cs64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( cs128 );
#endif /* UNI_HAS_I128 */

UNI_DECL_OPT( cu8 );
UNI_DECL_OPT( cu16 );
UNI_DECL_OPT( cu32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( cu64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( cu128 );
#endif /* UNI_HAS_I128 */

UNI_DECL_OPT( vcs8 );
UNI_DECL_OPT( vcs16 );
UNI_DECL_OPT( vcs32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( vcs64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( vcs128 );
#endif /* UNI_HAS_I128 */

UNI_DECL_OPT( vcu8 );
UNI_DECL_OPT( vcu16 );
UNI_DECL_OPT( vcu32 );
#if UNI_HAS_I64( )
UNI_DECL_OPT( vcu64 );
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
UNI_DECL_OPT( vcu128 );
#endif /* UNI_HAS_I128 */

#endif /* !defined( __clang__) && !defined( __GNUC__ ) */

#endif /* INC_API__UNI_TYPES_OPT_COMPLEXI_H */
