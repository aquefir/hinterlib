/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_TYPES_CHAR_H
#define INC_API__HN_TYPES_CHAR_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#if defined( __has_attribute )
#if __has_attribute( packed )
#if !defined( HN_PACKED )
/* Force the structure to be tightly packed into as few octets as possible.
 */
#define HN_PACKED __attribute__( ( packed ) )
#endif /* !defined( HN_PACKED ) */
#endif /* __has_attribute( packed ) */
#endif /* defined( __has_attribute ) */

/* fallback #defines in case attributes are not supported */

#if !defined( HN_PACKED )
#define HN_PACKED
#endif /* !defined( HN_PACKED ) */

/* Helper function to check if a character is valid ASCII. */
#define HN_CHR_ISVALID( _chr ) (((_chr) >= 0) && ((_chr) <= 127))

/* Helper function to check if a code point is valid Unicode. */
#define HN_UCHR_ISVALID( _uchr) \
	((((hn_uchr)_uchr).hi >= 0) && (((hn_uchr)_uchr).hi <= 31) )

#define HN_CHR_TRUNCATE( _chr ) ((_chr) &= 0x7F)

#define HN_UCHR_TRUNCATE( _uchr ) ((((hn_uchr)_uchr).hi &= 31))

/* A single ASCII character. */
typedef __UINT8_TYPE__ hn_chr;
/* A single Unicode code point. */
struct hn_uchr
{
#if defined( _SYNDEF_LILENDIAN )
	/* The lower 16 bits of the code point. */
	__UINT16_TYPE__ lo;
	/* The upper 5 bits of the code point. */
	__UINT16_TYPE__ hi;
#else
	/* The upper 5 bits of the code point. */
	__UINT16_TYPE__ hi;
	/* The lower 16 bits of the code point. */
	__UINT16_TYPE__ lo;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

/* A single Unicode code point. */
typedef struct hn_uchr hn_uchr;

#if !defined( _CFGOPT_NOSHORTHAND )

/* A single ASCII character. */
typedef __UINT8_TYPE__ chr;
/* A single Unicode code point. */
typedef struct hn_uchr uchr;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_CHAR_H */
