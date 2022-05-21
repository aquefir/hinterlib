/****************************************************************************\
 *                             Hinterlib arrays                             *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_ARR_H
#define INC_API__UNI_ARR_H

#include <uni/decl.h>
#include <uni/err.h>
#include <uni/memory.h>
#include <uni/types/mathprim.h>
#include <uni/types/int.h>
#include <uni/types/opt/range.h>

/*
 * # FIFOs
 * uni_q_* := 1ll, 2ll, circ, flat, bst
 * uni_deq_* := 2ll, circ, bst
 * uni_pq_* := flat, bst
 * uni_depq_* := bst
 * # LIFOs
 * uni_stk_* := circ, flat
 *
 * uni_bl_* := flat
 *
 * # Other
 * uni_htbl_* := *
 * uni_dyna_* := flat
 * uni_bl64_* := *
 *
 */

UNI_DEPRECATED struct uni_arr;

struct uni_dyna
{
	void * data;
	ptri elemsz;
	ptri sz;
	ptri cap;
};

struct uni_dyna2
{
	void * data;
	ptri cellsz;
	ptri rowsz;
	ptri rowct;
	ptri rowcap;
};

/**
 * TITLE:       Read Dynamic Array
 * DESCRIPTION: Gives a read-only view of the data in a 1D dynamic array,
 *              doing bounds-checking on the offset and an (admittedly
 *              optional) desired element count.
 *
 * PARAMETER: The array to read from.
 * PARAMETER: The starting index of the array.
 * PARAMETER: The number of elements desired (may be zero).
 *
 * RETURNS: The adjusted pointer to the data in the array.
 */
static inline void * uni_dyna_read( struct uni_dyna a, ptri i, ptri n )
{
	if( i + n >= a.sz )
	{
		uni_die( );

		/* UNREACHABLE */
		return NULL;
	}

	return (void *)((ptri)a.data + (i * a.elemsz));
}

static inline void uni_dyna_write( struct uni_dyna a, ptri i, void * d, ptri n )
{
	if( i + n >= a.sz )
	{
		uni_die( );

		/* UNREACHABLE */
		return NULL;
	}

	{
		void * const dst = (void*)((ptri)(a.data) + (i * a.elemsz));
		const ptri count = n * a.elemsz;

		uni_memcpy( dst, (const void*)d, count );
	}
}

UNI_C_API struct uni_dyna uni_dyna_insert( struct uni_dyna, ptri, void *, ptri );

UNI_C_API struct uni_dyna uni_dyna_delete( struct uni_dyna, rptri );

UNI_C_API struct uni_dyna uni_dyna_dblcap( struct uni_dyna );

UNI_C_API void * uni_dyna2_read( struct uni_dyna2, ptri, ptri, ptri );

UNI_C_API struct uni_dyna2 uni_dyna2_write( struct uni_dyna2, ptri, ptri, void *, ptri );

UNI_C_API struct uni_dyna2 uni_dyna2_insertrow( struct uni_dyna2, ptri, void * );

UNI_C_API struct uni_dyna2 uni_dyna2_deleterow( struct uni_dyna2, rptri );

struct uni_1ll_node;

/* node of a singly linked list. */
struct uni_1ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the next node in this singly linked list. */
	struct uni_1ll_node * next;
};

struct uni_c1ll_node;

/* node of a circular singly linked list. */
struct uni_c1ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the next node in this circular singly linked list. */
	struct uni_c1ll_node * next;
};

struct uni_sc1ll_node;

/* node of a sentinel-bearing circular singly linked list. */
struct uni_sc1ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the next node in this sentinel-bearing circular singly linked list.
	 */
	struct uni_sc1ll_node * next;
};

struct uni_2ll_node;

/* node of a doubly linked list. */
struct uni_2ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the previous node in this doubly linked list. */
	struct uni_2ll_node * prev;
	/* the next node in this doubly linked list. */
	struct uni_2ll_node * next;
};

struct uni_c2ll_node;

/* node of a circular doubly linked list. */
struct uni_c2ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the previous node in this circular doubly linked list. */
	struct uni_c2ll_node * prev;
	/* the next node in this circular doubly linked list. */
	struct uni_c2ll_node * next;
};

struct uni_sc2ll_node;

/* node of a sentinel-bearing circular doubly linked list. */
struct uni_sc2ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the previous node in this sentinel-bearing circular doubly linked
	 * list. */
	struct uni_sc2ll_node * prev;
	/* the next node in this sentinel-bearing circular doubly linked list.
	 */
	struct uni_sc2ll_node * next;
};

struct uni_3ll_node;

/* node of a triply linked list. */
struct uni_3ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this triply linked list. */
	struct uni_3ll_node * prima;
	/* the secondary neighbour node in this triply linked list. */
	struct uni_3ll_node * secunda;
	/* the tertiary neighbour node in this triply linked list. */
	struct uni_3ll_node * tertia;
};

struct uni_c3ll_node;

/* node of a circular triply linked list. */
struct uni_c3ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this circular triply linked list. */
	struct uni_c3ll_node * prima;
	/* the secondary neighbour node in this circular triply linked list. */
	struct uni_c3ll_node * secunda;
	/* the tertiary neighbour node in this circular triply linked list. */
	struct uni_c3ll_node * tertia;
};

struct uni_sc3ll_node;

/* node of a sentinel-bearing circular triply linked list. */
struct uni_sc3ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this sentinel-bearing circular triply
	 * linked list. */
	struct uni_sc3ll_node * prima;
	/* the secondary neighbour node in this sentinel-bearing circular
	 * triply linked list. */
	struct uni_sc3ll_node * secunda;
	/* the tertiary neighbour node in this sentinel-bearing circular triply
	 * linked list. */
	struct uni_sc3ll_node * tertia;
};

struct uni_4ll_node;

/* node of a quadruply linked list. */
struct uni_4ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this quadruply linked list. */
	struct uni_4ll_node * prima;
	/* the secondary neighbour node in this quadruply linked list. */
	struct uni_4ll_node * secunda;
	/* the tertiary neighbour node in this quadruply linked list. */
	struct uni_4ll_node * tertia;
	/* the quaternary neighbour node in this quadruply linked list. */
	struct uni_4ll_node * quarta;
};

struct uni_c4ll_node;

/* node of a circular quadruply linked list. */
struct uni_c4ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this circular quadruply linked list.
	 */
	struct uni_c4ll_node * prima;
	/* the secondary neighbour node in this circular quadruply linked list.
	 */
	struct uni_c4ll_node * secunda;
	/* the tertiary neighbour node in this circular quadruply linked list.
	 */
	struct uni_c4ll_node * tertia;
	/* the quaternary neighbour node in this circular quadruply linked
	 * list. */
	struct uni_4ll_node * quarta;
};

struct uni_sc4ll_node;

/* node of a sentinel-bearing circular quadruply linked list. */
struct uni_sc4ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this sentinel-bearing circular
	 * quadruply linked list. */
	struct uni_sc4ll_node * prima;
	/* the secondary neighbour node in this sentinel-bearing circular
	 * quadruply linked list. */
	struct uni_sc4ll_node * secunda;
	/* the tertiary neighbour node in this sentinel-bearing circular
	 * quadruply linked list. */
	struct uni_sc4ll_node * tertia;
	/* the quaternary neighbour node in this sentinel-bearing circular
	 * quadruply linked list. */
	struct uni_sc4ll_node * quarta;
};

struct uni_5ll_node;

/* node of a quintuply linked list. */
struct uni_5ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this quintuply linked list. */
	struct uni_5ll_node * prima;
	/* the secondary neighbour node in this quintuply linked list. */
	struct uni_5ll_node * secunda;
	/* the tertiary neighbour node in this quintuply linked list. */
	struct uni_5ll_node * tertia;
	/* the quaternary neighbour node in this quintuply linked list. */
	struct uni_5ll_node * quarta;
	/* the quinary neighbour node in this quintuply linked list. */
	struct uni_5ll_node * quinta;
};

struct uni_c5ll_node;

/* node of a circular quintuply linked list. */
struct uni_c5ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this circular quintuply linked list.
	 */
	struct uni_c5ll_node * prima;
	/* the secondary neighbour node in this circular quintuply linked list.
	 */
	struct uni_c5ll_node * secunda;
	/* the tertiary neighbour node in this circular quintuply linked list.
	 */
	struct uni_c5ll_node * tertia;
	/* the quaternary neighbour node in this circular quintuply linked
	 * list. */
	struct uni_5ll_node * quarta;
	/* the quinary neighbour node in this circular quintuply linked list.
	 */
	struct uni_5ll_node * quinta;
};

struct uni_sc5ll_node;

/* node of a sentinel-bearing circular quintuply linked list. */
struct uni_sc5ll_node
{
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
	/* the primary neighbour node in this sentinel-bearing circular
	 * quintuply linked list. */
	struct uni_sc5ll_node * prima;
	/* the secondary neighbour node in this sentinel-bearing circular
	 * quintuply linked list. */
	struct uni_sc5ll_node * secunda;
	/* the tertiary neighbour node in this sentinel-bearing circular
	 * quintuply linked list. */
	struct uni_sc5ll_node * tertia;
	/* the quaternary neighbour node in this sentinel-bearing circular
	 * quintuply linked list. */
	struct uni_sc5ll_node * quarta;
	/* the quinary neighbour node in this sentinel-bearing circular
	 * quintuply linked list. */
	struct uni_sc5ll_node * quinta;
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

/* circular buffer, useful for FIFO-style queues. */
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

/* flat buffer, useful for vectors and LIFO-style stacks. */
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

struct uni_rb_node;

/* node of a red-black tree. */
struct uni_rb_node
{
	/* left child of this red-black node. */
	struct uni_rb_node * lchild;
	/* right child of this red-black node. */
	struct uni_rb_node * rchild;
	/* pseudo-pointer to the data of this red-black node.
	 * the lowest bit contains the colour of the node: 1 == RED.
	 *
	 * IMPORTANT: clear the lowest bit of this before casting it to a
	 * pointer type! */
	ptri data;
};

typedef unsigned ( *PFN_uni_rb_cmp )( struct uni_rb_node, struct uni_rb_node );

struct uni_prb_node;

/* node of a parental red-black tree. */
struct uni_prb_node
{
	/* left child of this parental red-black node. */
	struct uni_prb_node * lchild;
	/* right child of this parental red-black node. */
	struct uni_prb_node * rchild;
	/* parent of this parental red-black node. */
	struct uni_prb_node * parent;
	/* pseudo-pointer to the data of this parental red-black node.
	 * the lowest bit contains the colour of the node: 1 == RED.
	 *
	 * IMPORTANT: clear the lowest bit of this before casting it to a
	 * pointer type! */
	ptri data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_prb_cmp )(
	struct uni_prb_node, struct uni_prb_node );

struct uni_rrb_node;

/* node of a relaxed radix-balanced tree. */
struct uni_rrb_node
{
	/* children of this relaxed radix-balanced node. */
	struct uni_rrb_node * children[32];
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_rrb_cmp )(
	struct uni_rrb_node, struct uni_rrb_node );

struct uni_prrb_node;

/* node of a parental relaxed radix-balanced tree. */
struct uni_prrb_node
{
	/* children of this parental relaxed radix-balanced node. */
	struct uni_prrb_node * children[32];
	/* parent of this parental relaxed radix-balanced node. */
	struct uni_prrb_node * parent;
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_prrb_cmp )(
	struct uni_prrb_node, struct uni_prrb_node );

struct uni_avl_node;

/* node of an AVL tree. */
struct uni_avl_node
{
	/* left child of this AVL node. */
	struct uni_avl_node * lchild;
	/* right child of this AVL node. */
	struct uni_avl_node * rchild;
	/* pseudo-pointer to the data of this AVL node.
	 * the lowest 2 bits contain the balance factor, in one's complement,
	 * i.e. 0b00 == 0, 0b01 == 1, 0b10 == -0, and 0b11 == -1.
	 *
	 * IMPORTANT: clear the lowest 2 bits of this before casting it to a
	 * pointer type! */
	ptri data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_avl_cmp )(
	struct uni_avl_node, struct uni_avl_node );

struct uni_pavl_node;

/* node of a parental AVL tree. */
struct uni_pavl_node
{
	/* left child of this parental AVL node. */
	struct uni_pavl_node * lchild;
	/* right child of this parental AVL node. */
	struct uni_pavl_node * rchild;
	/* parent of this parental AVL node. */
	struct uni_pavl_node * parent;
	/* pseudo-pointer to the data of this parental AVL node.
	 * the lowest 2 bits contain the balance factor, in one's complement,
	 * i.e. 0b00 == 0, 0b01 == 1, 0b10 == -0, and 0b11 == -1.
	 *
	 * IMPORTANT: clear the lowest 2 bits of this before casting it to a
	 * pointer type! */
	ptri data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_pavl_cmp )(
	struct uni_pavl_node, struct uni_pavl_node );

struct uni_splay_node;

/* node of a splay tree. */
struct uni_splay_node
{
	/* left child of this splay node. */
	struct uni_splay_node * lchild;
	/* right child of this splay node. */
	struct uni_splay_node * rchild;
	/* parent of this splay node. */
	struct uni_splay_node * parent;
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_splay_cmp )(
	struct uni_splay_node, struct uni_splay_node );

struct uni_treap_node;

/* node of a treap. */
struct uni_treap_node
{
	/* left child of this treap node. */
	struct uni_treap_node * lchild;
	/* right child of this treap node. */
	struct uni_treap_node * rchild;
	/* parent of this treap node. */
	struct uni_treap_node * parent;
	/* pointer to the node's data. */
	void * data;
	/* size of the node's data, denominated in octets. */
	ptri sz;
};

typedef unsigned ( *PFN_uni_treap_cmp )(
	struct uni_treap_node, struct uni_treap_node );

UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_init( u32 );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_initsz( u32, u32 );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_dup( struct uni_arr * );
UNI_C_API UNI_DEPRECATED void * uni_arr_make( struct uni_arr * );
UNI_C_API UNI_DEPRECATED void * uni_arr_mkslice( struct uni_arr *, rptri );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_conc(
	struct uni_arr *, ... );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_concv( struct uni_arr ** );
UNI_C_API UNI_DEPRECATED struct uni_arr * uni_arr_slice(
	struct uni_arr *, rptri );
UNI_C_API UNI_DEPRECATED void uni_arr_fini( struct uni_arr * );

UNI_C_API UNI_DEPRECATED ptri uni_arr_getsz( struct uni_arr * );
UNI_C_API UNI_DEPRECATED u32 uni_arr_getelemsz( struct uni_arr * );

UNI_C_API UNI_DEPRECATED int uni_arr_app( struct uni_arr *, void * );
UNI_C_API UNI_DEPRECATED int uni_arr_prep( struct uni_arr *, void * );
UNI_C_API UNI_DEPRECATED int uni_arr_ins( struct uni_arr *, ptri, void * );
UNI_C_API UNI_DEPRECATED void uni_arr_ovr( struct uni_arr *, ptri, void * );

#endif /* INC_API__UNI_ARR_H */
