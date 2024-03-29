/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_TYPES_BOUND_H
#define INC_API__UNI_TYPES_BOUND_H

#include "int.h"

struct _uni_b8d2
{
	u8 x, y;
};

struct _uni_b16d2
{
	u16 x, y;
};

struct _uni_b32d2
{
	u32 x, y;
};

#if UNI_HAS_I64( )
struct _uni_b64d2
{
	u64 x, y;
};
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
struct _uni_b128d2
{
	u128 x, y;
};
#endif /* UNI_HAS_I128( ) */

struct _uni_b8d3
{
	u8 x, y, z;
};

struct _uni_b16d3
{
	u16 x, y, z;
};

struct _uni_b32d3
{
	u32 x, y, z;
};

#if UNI_HAS_I64( )
struct _uni_b64d3
{
	u64 x, y, z;
};
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
struct _uni_b128d3
{
	u128 x, y, z;
};
#endif /* UNI_HAS_I128( ) */

struct _uni_b8d4
{
	u8 x, y, z, a;
};

struct _uni_b16d4
{
	u16 x, y, z, a;
};

struct _uni_b32d4
{
	u32 x, y, z, a;
};

#if UNI_HAS_I64( )
struct _uni_b64d4
{
	u64 x, y, z, a;
};
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
struct _uni_b128d4
{
	u128 x, y, z, a;
};
#endif /* UNI_HAS_I128( ) */

struct _uni_b8d5
{
	u8 x, y, z, a, b;
};

struct _uni_b16d5
{
	u16 x, y, z, a, b;
};

struct _uni_b32d5
{
	u32 x, y, z, a, b;
};

#if UNI_HAS_I64( )
struct _uni_b64d5
{
	u64 x, y, z, a, b;
};
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
struct _uni_b128d5
{
	u128 x, y, z, a, b;
};
#endif /* UNI_HAS_I128( ) */

struct _uni_b8d6
{
	u8 x, y, z, a, b, c;
};

struct _uni_b16d6
{
	u16 x, y, z, a, b, c;
};

struct _uni_b32d6
{
	u32 x, y, z, a, b, c;
};

#if UNI_HAS_I64( )
struct _uni_b64d6
{
	u64 x, y, z, a, b, c;
};
#endif /* UNI_HAS_I64( ) */

#if UNI_HAS_I128( )
struct _uni_b128d6
{
	u128 x, y, z, a, b, c;
};
#endif /* UNI_HAS_I128( ) */

typedef struct _uni_b8d2 b8d2;
typedef volatile struct _uni_b8d2 vb8d2;
typedef struct _uni_b16d2 b16d2;
typedef volatile struct _uni_b16d2 vb16d2;
typedef struct _uni_b32d2 b32d2;
typedef volatile struct _uni_b32d2 vb32d2;
#if UNI_HAS_I64( )
typedef struct _uni_b64d2 b64d2;
typedef volatile struct _uni_b64d2 vb64d2;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef struct _uni_b128d2 b128d2;
typedef volatile struct _uni_b128d2 vb128d2;
#endif /* UNI_HAS_I128( ) */

typedef struct _uni_b8d3 b8d3;
typedef volatile struct _uni_b8d3 vb8d3;
typedef struct _uni_b16d3 b16d3;
typedef volatile struct _uni_b16d3 vb16d3;
typedef struct _uni_b32d3 b32d3;
typedef volatile struct _uni_b32d3 vb32d3;
#if UNI_HAS_I64( )
typedef struct _uni_b64d3 b64d3;
typedef volatile struct _uni_b64d3 vb64d3;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef struct _uni_b128d3 b128d3;
typedef volatile struct _uni_b128d3 vb128d3;
#endif /* UNI_HAS_I128( ) */

typedef struct _uni_b8d4 b8d4;
typedef volatile struct _uni_b8d4 vb8d4;
typedef struct _uni_b16d4 b16d4;
typedef volatile struct _uni_b16d4 vb16d4;
typedef struct _uni_b32d4 b32d4;
typedef volatile struct _uni_b32d4 vb32d4;
#if UNI_HAS_I64( )
typedef struct _uni_b64d4 b64d4;
typedef volatile struct _uni_b64d4 vb64d4;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef struct _uni_b128d4 b128d4;
typedef volatile struct _uni_b128d4 vb128d4;
#endif /* UNI_HAS_I128( ) */

typedef struct _uni_b8d5 b8d5;
typedef volatile struct _uni_b8d5 vb8d5;
typedef struct _uni_b16d5 b16d5;
typedef volatile struct _uni_b16d5 vb16d5;
typedef struct _uni_b32d5 b32d5;
typedef volatile struct _uni_b32d5 vb32d5;
#if UNI_HAS_I64( )
typedef struct _uni_b64d5 b64d5;
typedef volatile struct _uni_b64d5 vb64d5;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef struct _uni_b128d5 b128d5;
typedef volatile struct _uni_b128d5 vb128d5;
#endif /* UNI_HAS_I128( ) */

typedef struct _uni_b8d6 b8d6;
typedef volatile struct _uni_b8d6 vb8d6;
typedef struct _uni_b16d6 b16d6;
typedef volatile struct _uni_b16d6 vb16d6;
typedef struct _uni_b32d6 b32d6;
typedef volatile struct _uni_b32d6 vb32d6;
#if UNI_HAS_I64( )
typedef struct _uni_b64d6 b64d6;
typedef volatile struct _uni_b64d6 vb64d6;
#endif /* UNI_HAS_I64( ) */
#if UNI_HAS_I128( )
typedef struct _uni_b128d6 b128d6;
typedef volatile struct _uni_b128d6 vb128d6;
#endif /* UNI_HAS_I128( ) */

#endif /* INC_API__UNI_TYPES_BOUND_H */
