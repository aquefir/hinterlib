/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_TYPES_BASE_H
#define INC_API__HN_TYPES_BASE_H

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

#if __has_attribute( may_alias )
#if !defined( HN_TYPELESS )
/* Prevents the compiler from doing type analysis based optimisations on the
 * type, treating it as octet-addressable cast-friendly data. */
#define HN_TYPELESS __attribute__( ( may_alias ) )
#endif /* !defined( HN_TYPELESS ) */
#endif /* __has_attribute( may_alias ) */

#if __has_attribute( noreturn )
#if !defined( HN_NORETURN )
#define HN_NORETURN __attribute__( ( noreturn ) )
#endif /* !defined( HN_NORETURN ) */
#endif /* __has_attribute( noreturn ) */

#if __has_attribute( nothrow )
#if !defined( HN_NOTHROW )
#define HN_NOTHROW __attribute__( ( nothrow ) )
#endif /* !defined( HN_NOTHROW ) */
#endif /* __has_attribute( nothrow ) */

#if __has_attribute( pure )
#if !defined( HN_PURE )
#define HN_PURE __attribute__( ( pure ) )
#endif /* !defined( HN_PURE ) */
#endif /* __has_attribute( pure ) */

#if __has_attribute( aligned )
#if !defined( HN_ALIGN )
/* Set the alignment of an object, denominated in octets. */
#define HN_ALIGN( _n ) __attribute__( ( aligned( _n ) ) )
#endif /* !defined( HN_ALIGN ) */
#endif /* __has_attribute( align ) */

#if __has_attribute( deprecated )
#if !defined( HN_DEPRECATED )
/* Mark an API identifier as deprecated. */
#define HN_DEPRECATED __attribute__( ( deprecated ) )
#endif /* !defined( HN_DEPRECATED ) */
#endif /* __has_attribute( deprecated ) */

#if __has_attribute( vector_size )
#if !defined( HN_VECSIZE )
#define HN_VECSIZE( _n ) __attribute__( ( vector_size( _n ) ) )
#endif /* !defined( HN_VECSIZE ) */
#endif /* __has_attribute( vector_size ) */

#endif /* defined( __has_attribute ) */

/* fallback #defines in case attributes are not supported */

#if !defined( HN_PACKED )
#define HN_PACKED
#endif /* !defined( HN_PACKED ) */

#if !defined( HN_TYPELESS )
#define HN_TYPELESS
#endif /* !defined( HN_TYPELESS ) */

#if !defined( HN_NORETURN )
#define HN_NORETURN
#endif /* !defined( HN_NORETURN ) */

#if !defined( HN_NOTHROW )
#define HN_NOTHROW
#endif /* !defined( HN_NOTHROW ) */

#if !defined( HN_PURE )
#define HN_PURE
#endif /* !defined( HN_PURE ) */

#if !defined( HN_ALIGN )
#define HN_ALIGN( _n )
#endif /* !defined( HN_ALIGN ) */

#if !defined( HN_DEPRECATED )
#define HN_DEPRECATED
#endif /* !defined( HN_DEPRECATED ) */

#if !defined( HN_VECSIZE )
#define HN_VECSIZE( _n )
#endif /* !defined( HN_VECSIZE ) */

#if !defined( HN_API )
#if defined( __cplusplus )
#define HN_API extern "C"
#else
#define HN_API extern
#endif /* defined( __cplusplus ) */
#endif /* !defined( HN_API ) */

enum
{
	/* Denotes the size of a pointer at runtime, denominated in octets. */
	HN_SIZEOF_PTR = sizeof( __UINTPTR_TYPE__ ),
	/* Denotes he "null pointer" constant: zero. */
	HN_NULL = 0
};

/* A boolean type. */
enum hn_bl
{
	/* Constant for false. */
	HN_FALSE = 0,
	/* Constant for true. */
	HN_TRUE = 1
};

/* An unsigned integer sized the same as a machine address, for pointers. */
typedef __UINTPTR_TYPE__ hn_ptri HN_TYPELESS;
/* A signed integer sized the same as a machine pointer, for offsets. */
typedef __INTPTR_TYPE__ hn_offs HN_TYPELESS;
/* A boolean type. */
typedef enum hn_bl hn_bl;

#if !defined( _CFGOPT_NOSHORTHAND )

#if !defined( NULL )
#if defined( __cplusplus )
/* Denotes he "null pointer" constant: zero. */
#define NULL nullptr
#else
/* Denotes he "null pointer" constant: zero. */
#define NULL 0
#endif
#endif /* !defined( NULL ) */

#if !defined( FALSE )
#if defined( __cplusplus )
/* Constant for false. */
#define FALSE false
#else
/* Constant for false. */
#define FALSE 0
#endif
#endif /* !defined( FALSE ) */

#if !defined( TRUE )
#if defined( __cplusplus )
/* Constant for true. */
#define TRUE true
#else
/* Constant for true. */
#define TRUE (!(FALSE))
#endif
#endif /* !defined( TRUE ) */

/* An unsigned integer sized the same as a machine address, for pointers. */
typedef __UINTPTR_TYPE__ ptri HN_TYPELESS;
/* A signed integer sized the same as a machine pointer, for offsets. */
typedef __INTPTR_TYPE__ offs HN_TYPELESS;
/* A boolean type. */
typedef enum hn_bl bl;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_BASE_H */
