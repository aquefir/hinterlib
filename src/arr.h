/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC__UNI_ARR_H
#define INC__UNI_ARR_H

#include <uni/decl.h>
#include <uni/err.h>
#include <uni/memory.h>
#include <uni/types/int.h>
#include <uni/types/opt/range.h>

struct uni_arr
{
	u8 * data;
	ptri sz, cap;
	u32 elemsz;
};

struct uni_arr * uni_arr_init( u32 );
struct uni_arr * uni_arr_initsz( u32, u32 );
struct uni_arr * uni_arr_dup( struct uni_arr * );
void * uni_arr_make( struct uni_arr * );
void * uni_arr_mkslice( struct uni_arr *, rptri );
struct uni_arr * uni_arr_conc( struct uni_arr *, ... );
struct uni_arr * uni_arr_concv( struct uni_arr ** );
struct uni_arr * uni_arr_slice( struct uni_arr *, rptri );
void uni_arr_fini( struct uni_arr * );

ptri uni_arr_getsz( struct uni_arr * );
u32 uni_arr_getelemsz( struct uni_arr * );

int uni_arr_app( struct uni_arr *, void * );
int uni_arr_prep( struct uni_arr *, void * );
int uni_arr_ins( struct uni_arr *, ptri, void * );
void uni_arr_ovr( struct uni_arr *, ptri, void * );

#endif /* INC__UNI_ARR_H */
