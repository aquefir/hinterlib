/*****************************************************************************\
 *                          Hinterlib/Neopolitan 2.                          *
 *                                                                           *
 *                      Copyright (C) 2019-2023 Aquefir                      *
 *               Released under Artisan Software Licence v1.1.               *
\*****************************************************************************/

#ifndef INC_API__HN_TYPES_BASE_H
#define INC_API__HN_TYPES_BASE_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#if !defined( HN_PACKED )
/* Force the structure to be tightly packed into as few octets as possible. */
#define HN_PACKED __attribute__( ( packed ) )
#endif /* !defined( HN_PACKED ) */

#if !defined( HN_ALIGN )
/* Set the alignment of an object, denominated in octets. */
#define HN_ALIGN( _x ) __attribute__( ( aligned( _x ) ) )
#endif /* !defined( HN_ALIGN ) */

#if !defined( HN_DEPRECATED )
/* Mark an API identifier as deprecated. */
#define HN_DEPRECATED __attribute__( ( deprecated ) )
#endif /* !defined( HN_DEPRECATED ) */

#if !defined( HN_VECSIZE )
#define HN_VECSIZE(_n) __attribute__( ( vector_size( _n ) ) )
#endif /* !defined( HN_VECSIZE ) */

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
	HN_TRUE = !HN_FALSE,
};

/* An unsigned integer sized the same as a machine address, for pointers. */
typedef __UINTPTR_TYPE__ hn_ptri;
/* A signed integer sized the same as a machine pointer, for offsets. */
typedef __INTPTR_TYPE__ hn_offs;
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
typedef __UINTPTR_TYPE__ ptri;
/* A signed integer sized the same as a machine pointer, for offsets. */
typedef __INTPTR_TYPE__ offs;
/* A boolean type. */
typedef enum hn_bl bl;

#endif /* !defined( _CFGOPT_NOSHORTHAND ) */

#endif /* INC_API__HN_TYPES_BASE_H */
