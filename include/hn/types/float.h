/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_FLOAT_H
#define INC_API__HN_TYPES_FLOAT_H

/* Double-precision IEEE 754 floating-point number. */
typedef double hn_f64;
/* Single-precision IEEE 754 floating-point number. */
typedef float hn_f32;

#if !defined(_CFGOPT_NOSHORTHAND)
/* Double-precision IEEE 754 floating-point number. */
typedef double f64;
/* Single-precision IEEE 754 floating-point number. */
typedef float f32;
#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_FLOAT_H */
