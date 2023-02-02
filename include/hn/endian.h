/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_ENDIAN_H
#define INC_API__HN_ENDIAN_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

/* Performs an endianness reversal on a 16-bit variable. */
#define HN_ENDIAN_SWAP16( _val ) \
	( ( (_val)&0x00FFu ) << 8 ) | ( ( (_val)&0xFF00u ) >> 8 )
#if defined( _SYNDEF_HAVE_I32 )
/* Performs an endianness reversal on a 32-bit variable. */
#define HN_ENDIAN_SWAP32( _val ) \
	( ( (_val)&0x000000FFu ) << 24 ) | ( ( (_val)&0x0000FF00u ) << 8 ) | \
		( ( (_val)&0x00FF0000u ) >> 8 ) | \
		( ( (_val)&0xFF000000u ) >> 24 )
#endif /* defined( _SYNDEF_HAVE_I32 ) */
#if defined( _SYNDEF_HAVE_I64 )
/* Performs an endianness reversal on a 64-bit variable. */
#define HN_ENDIAN_SWAP64( _val ) \
	( ( (_val)&0x00000000000000FFu ) << 56 ) | \
		( ( (_val)&0x000000000000FF00u ) << 40 ) | \
		( ( (_val)&0x0000000000FF0000u ) << 24 ) | \
		( ( (_val)&0x00000000FF000000u ) << 8 ) | \
		( ( (_val)&0x000000FF00000000u ) >> 8 ) | \
		( ( (_val)&0x0000FF0000000000u ) >> 24 ) | \
		( ( (_val)&0x00FF000000000000u ) >> 40 ) | \
		( ( (_val)&0xFF00000000000000u ) >> 56 )
#endif /* defined( _SYNDEF_HAVE_I64 ) */

#if defined( _SYNDEF_LILENDIAN )
/* Convert host endianness to network endianness. 16-bit variant. */
#define HN_HOST2NET16( _val ) ( HN_ENDIAN_SWAP16( _val ) )
#if defined( _SYNDEF_HAVE_I32 )
/* Convert host endianness to network endianness. 32-bit variant. */
#define HN_HOST2NET32( _val ) ( HN_ENDIAN_SWAP32( _val ) )
#endif /* defined( _SYNDEF_HAVE_I32 ) */
#if defined( _SYNDEF_HAVE_I64 )
/* Convert host endianness to network endianness. 64-bit variant. */
#define HN_HOST2NET64( _val ) ( HN_ENDIAN_SWAP64( _val ) )
#endif /* defined( _SYNDEF_HAVE_I64 ) */
/* Convert network endianness to host endianness. 16-bit variant. */
#define HN_NET2HOST16( _val ) ( HN_ENDIAN_SWAP16( _val ) )
#if defined( _SYNDEF_HAVE_I32 )
/* Convert network endianness to host endianness. 32-bit variant. */
#define HN_NET2HOST32( _val ) ( HN_ENDIAN_SWAP32( _val ) )
#endif /* defined( _SYNDEF_HAVE_I32 ) */
#if defined( _SYNDEF_HAVE_I64 )
/* Convert network endianness to host endianness. 64-bit variant. */
#define HN_NET2HOST64( _val ) ( HN_ENDIAN_SWAP64( _val ) )
#endif /* defined( _SYNDEF_HAVE_I64 ) */
#else /* defined( _SYNDEF_BIGENDIAN ) */
/* Convert host endianness to network endianness. 16-bit variant. */
#define HN_HOST2NET16( _val ) ( _val )
#if defined( _SYNDEF_HAVE_I32 )
/* Convert host endianness to network endianness. 32-bit variant. */
#define HN_HOST2NET32( _val ) ( _val )
#endif /* defined( _SYNDEF_HAVE_I32 ) */
#if defined( _SYNDEF_HAVE_I64 )
/* Convert host endianness to network endianness. 64-bit variant. */
#define HN_HOST2NET64( _val ) ( _val )
#endif /* defined( _SYNDEF_HAVE_I64 ) */
/* Convert network endianness to host endianness. 16-bit variant. */
#define HN_NET2HOST16( _val ) ( _val )
#if defined( _SYNDEF_HAVE_I32 )
/* Convert network endianness to host endianness. 32-bit variant. */
#define HN_NET2HOST32( _val ) ( _val )
#endif /* defined( _SYNDEF_HAVE_I32 ) */
#if defined( _SYNDEF_HAVE_I64 )
/* Convert network endianness to host endianness. 64-bit variant. */
#define HN_NET2HOST64( _val ) ( _val )
#endif /* defined( _SYNDEF_HAVE_I64 ) */
#endif /* defined( _SYNDEF_LILENDIAN ) */

#endif /* INC_API__HN_ENDIAN_H */
