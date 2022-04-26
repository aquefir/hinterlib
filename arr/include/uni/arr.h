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
#include <uni/decl.h>

UNI_DEPRECATED struct uni_arr;

struct uni_slist_node;

/* node of a singly linked list. */
struct uni_slist_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the next node in this singly linked list. */
	struct uni_slist_node * next;
};

/* singly linked list. */
struct uni_slist
{
	/* head (first element) of the singly linked list. */
	struct uni_slist_node * head;
	/* tail (last element) of the singly linked list. */
	struct uni_slist_node * tail;
};

struct uni_dlist_node;

/* node of a doubly linked list. */
struct uni_dlist_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the previous node in this doubly linked list. */
	struct uni_dlist_node * prev;
	/* the next node in this doubly linked list. */
	struct uni_dlist_node * next;
};

/* doubly linked list. */
struct uni_dlist
{
	/* head (first element) of this doubly linked list. */
	struct uni_dlist_node * head;
	/* tail (last element) of this singly linked list. */
	struct uni_dlist_node * tail;
};

/* hash table. */
struct uni_htbl
{
	/* array of pointers to the hash table's values. */
	void ** vals;
	/* array of sizes of the hash table's values, denominated in octets. */
	ptri * szs;
	/* array of NUL-terminated strings keying the hash table's values. */
	const char ** keys;
	/* number of elements currently allocated in this hash table. */
	ptri sz;
	/* number of elements this hash table can hold without reallocation. */
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

/* flat buffer, useful for  vectors and FIFO-style stacks. */
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

UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_init( u32 );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_initsz( u32, u32 );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_dup( struct uni_arr * );
UNI_C_API UNI_DEPRECATED void * uni_arr_make( struct uni_arr * );
UNI_C_API UNI_DEPRECATED void * uni_arr_mkslice( struct uni_arr *, rptri );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_conc( struct uni_arr *, ... );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_concv( struct uni_arr ** );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_slice( struct uni_arr *, rptri );
UNI_C_API UNI_DEPRECATED void uni_arr_fini( struct uni_arr * );

UNI_C_API UNI_DEPRECATED ptri uni_arr_getsz( struct uni_arr * );
UNI_C_API UNI_DEPRECATED u32 uni_arr_getelemsz( struct uni_arr * );

UNI_C_API UNI_DEPRECATED int uni_arr_app( struct uni_arr *, void * );
UNI_C_API UNI_DEPRECATED int uni_arr_prep( struct uni_arr *, void * );
UNI_C_API UNI_DEPRECATED int uni_arr_ins( struct uni_arr *, ptri, void * );
UNI_C_API UNI_DEPRECATED void uni_arr_ovr( struct uni_arr *, ptri, void * );

#endif /* INC_API__UNI_ARR_H */
