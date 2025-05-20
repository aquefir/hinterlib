/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_FLOATVEC_H
#define INC_API__HN_TYPES_FLOATVEC_H

#if defined( __has_attribute )
#if __has_attribute( vector_size )
#if !defined( HN_VECSIZE )
/* Resolves to compiler-specific intrinsics to create a Single
 * Instruction Multiple Data (SIMD) compatible vector type of a
 * particular size. */
#define HN_VECSIZE( _n ) __attribute__( ( vector_size( _n ) ) )
#endif /* !defined( HN_VECSIZE ) */
#endif /* __has_attribute( vector_size ) */
#endif /* defined( __has_attribute ) */

/* fallback #defines in case attributes are not supported */

#if !defined( HN_VECSIZE )
#define HN_VECSIZE( _n )
#endif /* !defined( HN_VECSIZE ) */

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

#endif /* defined( _SYNDEF_HAVE_FP ) */

#endif /* INC_API__HN_TYPES_FLOATVEC_H */
