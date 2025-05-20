/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_FLOATVEC_H
#define INC_API__HN_TYPES_FLOATVEC_H

#include "base.h"

#if defined( __has_attribute )
#if __has_attribute( vector_size )
#if !defined( HN_VECTOR )
#define HN_VECTOR( _b, _a, _n ) _b _a HN_VECSIZE( _n )
#endif /* !defined( HN_VECTOR ) */
#endif /* __has_attribute( vector_size ) */
#endif /* defined( __has_attribute ) */

/* Define the vector as a plain array if vector support is absent. */
#if !defined( HN_VECTOR )
#define HN_VECTOR( _b, _a, _n ) _b[_n] _a
#endif /* !defined( HN_VECTOR ) */

/* 2-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double hn_f64v2 HN_VECSIZE( 16 );
/* 4-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double hn_f64v4 HN_VECSIZE( 32 );
/* 8-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double hn_f64v8 HN_VECSIZE( 64 );

/* 2-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float hn_f32v2 HN_VECSIZE( 8 );
/* 4-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float hn_f32v4 HN_VECSIZE( 16 );
/* 8-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float hn_f32v8 HN_VECSIZE( 32 );
/* 16-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float hn_f32v16 HN_VECSIZE( 64 );

#if !defined( _CFGOPT_NOSHORTHAND )

/* 2-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double f64v2 HN_VECSIZE( 16 );
/* 4-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double f64v4 HN_VECSIZE( 32 );
/* 8-wide vector of double-precision IEEE 754 floating-point numbers.
 */
typedef double f64v8 HN_VECSIZE( 64 );

/* 2-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float f32v2 HN_VECSIZE( 8 );
/* 4-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float f32v4 HN_VECSIZE( 16 );
/* 8-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float f32v8 HN_VECSIZE( 32 );
/* 16-wide vector of single-precision IEEE 754 floating-point numbers.
 */
typedef float f32v16 HN_VECSIZE( 64 );

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_FLOATVEC_H */
