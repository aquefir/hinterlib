/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_COMPLEXI_H
#define INC_API__UNI_TYPES_COMPLEXI_H

#if !defined( __clang__ ) && !defined( __GNUC__ )
#pragma message( \
	"Complex number support only works with GCC and clang. The types and functions for this will be unavailable." )
#else

#include <uni/types/int.h>

#if defined( __VSCODE_INTELLISENSE__ )

typedef __complex__ float cs8;
typedef __complex__ float cs16;
typedef __complex__ float cs32;
#if UNI_HAS_I64( )
typedef __complex__ float cs64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ float cs128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ float cu8;
typedef __complex__ float cu16;
typedef __complex__ float cu32;
#if UNI_HAS_I64( )
typedef __complex__ float cu64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ float cu128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ volatile float vcs8;
typedef __complex__ volatile float vcs16;
typedef __complex__ volatile float vcs32;
#if UNI_HAS_I64( )
typedef __complex__ volatile float vcs64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ volatile float vcs128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ volatile float vcu8;
typedef __complex__ volatile float vcu16;
typedef __complex__ volatile float vcu32;
#if UNI_HAS_I64( )
typedef __complex__ volatile float vcu64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ volatile float vcu128;
#endif /* UNI_HAS_I128( ) */

#else

typedef __complex__ signed char cs8;
typedef __complex__ signed short cs16;
typedef __complex__ signed int cs32;
#if UNI_HAS_I64( )
typedef __complex__ signed long long cs64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ signed __int128 cs128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ unsigned char cu8;
typedef __complex__ unsigned short cu16;
typedef __complex__ unsigned int cu32;
#if UNI_HAS_I64( )
typedef __complex__ unsigned long long cu64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ unsigned __int128 cu128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ volatile signed char vcs8;
typedef __complex__ volatile signed short vcs16;
typedef __complex__ volatile signed int vcs32;
#if UNI_HAS_I64( )
typedef __complex__ volatile signed long long vcs64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ volatile signed __int128 vcs128;
#endif /* UNI_HAS_I128( ) */

typedef __complex__ volatile unsigned char vcu8;
typedef __complex__ volatile unsigned short vcu16;
typedef __complex__ volatile unsigned int vcu32;
#if UNI_HAS_I64( )
typedef __complex__ volatile unsigned long long vcu64;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef __complex__ volatile unsigned __int128 vcu128;
#endif /* UNI_HAS_I128( ) */

#endif /* defined( __VSCODE_INTELLISENSE__ ) */

#endif /* !defined( __clang__) && !defined( __GNUC__ ) */

#endif /* INC_API__UNI_TYPES_COMPLEXI_H */
