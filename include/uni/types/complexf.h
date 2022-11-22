/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_TYPES_COMPLEXF_H
#define INC_API__UNI_TYPES_COMPLEXF_H

#if !defined( __clang__ ) && !defined( __GNUC__ )
#pragma message( \
	"Complex number support only works with GCC and clang. The types and functions for this will be unavailable." )
#else

#include <uni/types/float.h>

typedef __complex__ float cf32;
typedef __complex__ double cf64;

typedef __complex__ volatile float vcf32;
typedef __complex__ volatile double vcf64;

#endif /* !defined( __clang__) && !defined( __GNUC__ ) */

#endif /* INC_API__UNI_TYPES_COMPLEXF_H */
