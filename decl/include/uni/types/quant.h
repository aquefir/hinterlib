/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_QUANT_H
#define INC_API__UNI_TYPES_QUANT_H

#include "float.h"

struct _uni_q32d2
{
	f32 x, y;
};

struct _uni_q64d2
{
	f64 x, y;
};

struct _uni_q32d3
{
	f32 x, y, z;
};

struct _uni_q64d3
{
	f64 x, y, z;
};

struct _uni_q32d4
{
	f32 x, y, z, a;
};

struct _uni_q64d4
{
	f64 x, y, z, a;
};

struct _uni_q32d5
{
	f32 x, y, z, a, b;
};

struct _uni_q64d5
{
	f64 x, y, z, a, b;
};

struct _uni_q32d6
{
	f32 x, y, z, a, b, c;
};

struct _uni_q64d6
{
	f64 x, y, z, a, b, c;
};

typedef struct _uni_q32d2 q32d2;
typedef volatile struct _uni_q32d2 vq32d2;
typedef struct _uni_q64d2 q64d2;
typedef volatile struct _uni_q64d2 vq64d2;

typedef struct _uni_q32d3 q32d3;
typedef volatile struct _uni_q32d3 vq32d3;
typedef struct _uni_q64d3 q64d3;
typedef volatile struct _uni_q64d3 vq64d3;

typedef struct _uni_q32d4 q32d4;
typedef volatile struct _uni_q32d4 vq32d4;
typedef struct _uni_q64d4 q64d4;
typedef volatile struct _uni_q64d4 vq64d4;

typedef struct _uni_q32d5 q32d5;
typedef volatile struct _uni_q32d5 vq32d5;
typedef struct _uni_q64d5 q64d5;
typedef volatile struct _uni_q64d5 vq64d5;

typedef struct _uni_q32d6 q32d6;
typedef volatile struct _uni_q32d6 vq32d6;
typedef struct _uni_q64d6 q64d6;
typedef volatile struct _uni_q64d6 vq64d6;

#endif /* INC_API__UNI_TYPES_QUANT_H */
