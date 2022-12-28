/*****************************************************************************\
 *                          Hinterlib/Neopolitan 2.                          *
 *                                                                           *
 *                      Copyright (C) 2019-2023 Aquefir                      *
 *               Released under Artisan Software Licence v1.1.               *
\*****************************************************************************/

#ifndef INC_API__HN_TYPES_FLOAT_H
#define INC_API__HN_TYPES_FLOAT_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#if defined( _SYNDEF_HAVE_FP )

/* Double-precision IEEE 754 floating-point number. */
typedef double hn_f64;
/* Single-precision IEEE 754 floating-point number. */
typedef float hn_f32;

#if !defined( _CFGOPT_NOSHORTHAND )

/* Double-precision IEEE 754 floating-point number. */
typedef double f64;
/* Single-precision IEEE 754 floating-point number. */
typedef float f32;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* defined( _SYNDEF_HAVE_FP ) */

#endif /* INC_API__HN_TYPES_FLOAT_H */
