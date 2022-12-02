/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_MEMORY_H
#define INC_API__UNI_MEMORY_H

#include <uni/types/int.h>

void * uni_alloc( ptri );
void * uni_alloc0( ptri );
void * uni_alloca( ptri );
#if 0
void * uni_allocb( ptri );
#endif /* 0 */
void * uni_realloc( void *, ptri );
#if 0
void * uni_realloc0( void *, ptri );
void * uni_reallocb( void *, ptri );
#endif /* 0 */
void * uni_tryalloc( ptri );
void * uni_tryalloc0( ptri );
#if 0
void * uni_tryalloca( ptri );
void * uni_tryallocb( ptri );
#endif /* 0 */
void * uni_tryrealloc( void *, ptri );
#if 0
void * uni_tryrealloc0( void *, ptri );
void * uni_tryreallocb( void *, ptri );
#endif /* 0 */
void uni_free( void * );

void uni_memset( void *, u8, ptri );
void uni_memcpy( void *, const void *, ptri );
int uni_memcmp( const void *, const void *, ptri );

#endif /* INC_API__UNI_MEMORY_H */
