/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_TYPES_MEM_H
#define INC_API__HN_TYPES_MEM_H

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

#if !defined( HN_ISTRUNK8 )
#define HN_ISTRUNK8(_a) (((__UINTPTR_TYPE__)(_a) & 255) == 0)
#endif /* !defined( HN_ISTRUNK8 ) */

#if !defined( HN_ISTRUNK12 )
#define HN_ISTRUNK12(_a) (((__UINTPTR_TYPE__)(_a) & 4095) == 0)
#endif /* !defined( HN_ISTRUNK12 ) */

#if !defined( HN_ISTRUNK16 )
#define HN_ISTRUNK16(_a) (((__UINTPTR_TYPE__)(_a) & 65535) == 0)
#endif /* !defined( HN_ISTRUNK16 ) */

struct hn_addr8
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT8_TYPE__ twig;
	__UINT8_TYPE__ trunk8;
#if defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#elif defined( _SYNDEF_WORDSZ_128 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT64_TYPE__ trunk64;
#endif /* word size */
#else /* big endian */
#if defined( _SYNDEF_WORDSZ_128 )
	__UINT64_TYPE__ trunk64;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#endif /* word size */
	__UINT8_TYPE__ trunk8;
	__UINT8_TYPE__ twig;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_addr12
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ twig : 12;
	__UINT16_TYPE__ trunk4 : 4;
#pragma GCC diagnostic pop
#if defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#elif defined( _SYNDEF_WORDSZ_128 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT64_TYPE__ trunk64;
#endif /* word size */
#else /* big endian */
#if defined( _SYNDEF_WORDSZ_128 )
	__UINT64_TYPE__ trunk64;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#endif /* word size */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ trunk4 : 4;
	__UINT16_TYPE__ twig : 12;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_addr16
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT16_TYPE__ twig;
#if defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#elif defined( _SYNDEF_WORDSZ_128 )
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT64_TYPE__ trunk64;
#endif /* word size */
#else /* big endian */
#if defined( _SYNDEF_WORDSZ_128 )
	__UINT64_TYPE__ trunk_c;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_64 )
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
#elif defined( _SYNDEF_WORDSZ_32 )
	__UINT16_TYPE__ trunk16;
#endif /* word size */
	__UINT16_TYPE__ twig;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk16p8
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT8_TYPE__ padding;
	__UINT8_TYPE__ trunk8;
#else /* big endian */
	__UINT8_TYPE__ trunk8;
	__UINT8_TYPE__ padding;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk32p8
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT8_TYPE__ padding;
	__UINT8_TYPE__ trunk8;
	__UINT16_TYPE__ trunk16;
#else /* big endian */
	__UINT16_TYPE__ trunk16;
	__UINT8_TYPE__ trunk8;
	__UINT8_TYPE__ padding;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk64p8
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT8_TYPE__ padding;
	__UINT8_TYPE__ trunk8;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#else /* big endian */
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT8_TYPE__ trunk8;
	__UINT8_TYPE__ padding;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk128p8
{
#if defined( _SYNDEF_LILENDIAN )
	__UINT8_TYPE__ padding;
	__UINT8_TYPE__ trunk8;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT64_TYPE__ trunk64;
#else /* big endian */
	__UINT64_TYPE__ trunk64;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT8_TYPE__ trunk8;
	__UINT8_TYPE__ padding;
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk16p12
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
#pragma GCC diagnostic pop
} HN_PACKED;

struct hn_trunk32p12
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
	__UINT16_TYPE__ trunk16;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk64p12
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk128p12
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT32_TYPE__ trunk64;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT32_TYPE__ trunk64;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding : 12;
	__UINT16_TYPE__ trunk4 : 4;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk32p16
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding;
	__UINT16_TYPE__ trunk16;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk64p16
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_trunk128p16
{
#if defined( _SYNDEF_LILENDIAN )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ padding;
	__UINT16_TYPE__ trunk16;
	__UINT32_TYPE__ trunk32;
	__UINT32_TYPE__ trunk64;
#pragma GCC diagnostic pop
#else /* big endian */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT32_TYPE__ trunk64;
	__UINT32_TYPE__ trunk32;
	__UINT16_TYPE__ trunk16;
	__UINT16_TYPE__ padding;
#pragma GCC diagnostic pop
#endif /* defined( _SYNDEF_LILENDIAN ) */
} HN_PACKED;

struct hn_twig8
{
	__UINT8_TYPE__ twig;
} HN_PACKED;

struct hn_twig12
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	__UINT16_TYPE__ twig : 12;
	__UINT16_TYPE__ padding : 4;
#pragma GCC diagnostic pop
} HN_PACKED;

struct hn_twig16
{
	__UINT16_TYPE__ twig;
} HN_PACKED;

typedef struct hn_addr8 hn_addr8;

typedef struct hn_addr12 hn_addr12;

typedef struct hn_addr16 hn_addr16;

typedef struct hn_trunk16p8 hn_trunk16p8;

typedef struct hn_trunk32p8 hn_trunk32p8;

typedef struct hn_trunk64p8 hn_trunk64p8;

typedef struct hn_trunk128p8 hn_trunk128p8;

typedef struct hn_trunk16p12 hn_trunk16p12;

typedef struct hn_trunk32p12 hn_trunk32p12;

typedef struct hn_trunk64p12 hn_trunk64p12;

typedef struct hn_trunk128p12 hn_trunk128p12;

typedef struct hn_trunk32p16 hn_trunk32p16;

typedef struct hn_trunk64p16 hn_trunk64p16;

typedef struct hn_trunk128p16 hn_trunk128p16;

typedef struct hn_twig8 hn_twig8;

typedef struct hn_twig12 hn_twig12;

typedef struct hn_twig16 hn_twig16;

#if !defined( _CFGOPT_NOSHORTHAND )

typedef struct hn_addr8 addr8;

typedef struct hn_addr12 addr12;

typedef struct hn_addr16 addr16;

typedef struct hn_trunk16p8 trunk16p8;

typedef struct hn_trunk32p8 trunk32p8;

typedef struct hn_trunk64p8 trunk64p8;

typedef struct hn_trunk128p8 trunk128p8;

typedef struct hn_trunk16p12 trunk16p12;

typedef struct hn_trunk32p12 trunk32p12;

typedef struct hn_trunk64p12 trunk64p12;

typedef struct hn_trunk128p12 trunk128p12;

typedef struct hn_trunk32p16 trunk32p16;

typedef struct hn_trunk64p16 trunk64p16;

typedef struct hn_trunk128p16 trunk128p16;

typedef struct hn_twig8 twig8;

typedef struct hn_twig12 twig12;

typedef struct hn_twig16 twig16;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

/* In modular memory:

- trunk (n.) := the most significant portion of a full memory address
- twig (n.) := the least significant portion of a full memory address
- trunk size := number of bits consumed by a trunk
- twig size := number of bits consumed by a twig
- total address size := twig size + trunk size
 */

#endif /* INC_API__HN_TYPES_MEM_H */
