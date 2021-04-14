/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_VECF_H
#define INC_API__UNI_TYPES_VECF_H

#include <uni/types/float.h>

typedef f32 f32v2 __attribute__( ( vector_size( 8 ) ) );
typedef f32 f32v4 __attribute__( ( vector_size( 16 ) ) );
typedef f32 f32v8 __attribute__( ( vector_size( 32 ) ) );
typedef f32 f32v16 __attribute__( ( vector_size( 64 ) ) );

typedef f64 f64v2 __attribute__( ( vector_size( 16 ) ) );
typedef f64 f64v4 __attribute__( ( vector_size( 32 ) ) );
typedef f64 f64v8 __attribute__( ( vector_size( 64 ) ) );

typedef volatile f32v2 vf32v2;
typedef volatile f32v4 vf32v4;
typedef volatile f32v8 vf32v8;
typedef volatile f32v16 vf32v16;

typedef volatile f64v2 vf64v2;
typedef volatile f64v4 vf64v4;
typedef volatile f64v8 vf64v8;

#endif /* INC_API__UNI_TYPES_VECF_H */
