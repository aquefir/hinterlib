/****************************************************************************\
 *                             Hinterlib arrays                             *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_ARR_H
#define INC_API__UNI_ARR_H

#include <uni/types/mathprim.h>
#include <uni/types/int.h>
#include <uni/types/opt/range.h>

struct uni_arr;

struct uni_slist_node;

struct uni_slist_node
{
	void * data;
	struct uni_slist_node * next;
};

struct uni_slist
{
	struct uni_slist_node * head;
	struct uni_slist_node * tail;
};

struct uni_dlist_node;

struct uni_dlist_node
{
	void * data;
	struct uni_dlist_node * prev;
	struct uni_dlist_node * next;
};

struct uni_dlist
{
	struct uni_dlist_node * head;
	struct uni_dlist_node * tail;
};

struct uni_htbl
{
	void * vals;
	const char ** keys;
	ptri sz;
	ptri cap;
};

/* circular buffer, useful for LIFO-style queues. */
struct uni_circbuf
{
	/* start of the physical buffer in memory. */
	void * buf_start;
	/* end of the physical buffer in memory. */
	void * buf_end;
	/* head (dynamic start) of the buffer. */
	void * head;
	/* tail (dynamic end) of the buffer. */
	void * tail;
	/* size of each element of the buffer, denominated in octets. */
	ptri elemsz;
};

struct uni_flatbuf
{
	/* raw buffer data. */
	void * buf;
	/* the current existing size of the buffer, denominated in elements. */
	ptri sz;
	/* the current capacity of the buffer, denominated in elements. */
	ptri cap;
	/* the size of one (1) element, denominated in octets. */
	ptri elemsz;
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

#endif /* INC_API__UNI_ARR_H */
