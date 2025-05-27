/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_LOOM_H
#define INC_API__HN_LOOM_H

/**
 * Behold Himem, the Modular Memory Toolkit
 *
 * Otherwise known as The Late Great John James Maynard Keynesnan and
 * His Incalculable Contribution to Economics Through Performance Art
 * and Heavy Metal, Otherwise Called "Nothing is Real" or Simply,
 * "Modern Monetary Theory". Rest in peace Judith Marie
 */

#include "types/base.h"
#include "types/mem.h"

#include "err.h"

/* increment amalgam */
HN_API struct hn_err hn_himem_inc(
	/* reference to amalgam */
	void *,
	/* dynamic typing information for amalgam */
	struct hn_amalgam,
	/* amalgam offset to store the result */
	hn_amoffs * );

/* decrement amalgam */
HN_API struct hn_err hn_himem_dec(
	/* reference to amalgam */
	void *,
	/* dynamic typing information for amalgam */
	struct hn_amalgam,
	/* amalgam offset to store the result */
	hn_amoffs * );

HN_API struct hn_err hn_himem_deepcopy(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* reference to output amalgam */
	void *,
	/* dynamic typing information for output amalgam */
	struct hn_amalgam );

HN_API struct hn_err hn_himem_appendk(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* target dimension level to append knot at */
	enum hn_amaldim,
	/* reference to knot to append to the amalgam */
	void * );

HN_API struct hn_err hn_himem_insertk(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* target dimension level to insert knot at */
	enum hn_amaldim,
	/* offset in target dimension to insert knot at */
	hn_amoffs,
	/* reference to knot to insert into the amalgam */
	void * );

HN_API struct hn_err hn_himem_deletek(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* target dimension level to delete knot from */
	enum hn_amaldim,
	/* offset in target dimension to delete knot from */
	hn_amoffs );

HN_API struct hn_err hn_himem_read8(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to read from */
	hn_ptri,
	/* reference to output data */
	hn_u8 * );

HN_API struct hn_err hn_himem_read16(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to read from */
	hn_ptri,
	/* reference to output data */
	hn_u16 * );

#if defined( HN_HAVE_I32 )
HN_API struct hn_err hn_himem_read32(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to read from */
	hn_ptri,
	/* reference to output data */
	hn_u32 * );
#endif /* defined( HN_HAVE_I32 ) */

#if defined( HN_HAVE_I64 )
HN_API struct hn_err hn_himem_read64(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to read from */
	hn_ptri,
	/* reference to output data */
	hn_u64 * );
#endif /* defined( HN_HAVE_I64 ) */

HN_API struct hn_err hn_himem_readk8(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to output data */
	hn_knot8 );

HN_API struct hn_err hn_himem_readk12(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to output data */
	hn_knot12 );

HN_API struct hn_err hn_himem_readk16(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to output data */
	hn_knot16 );

#if HN_SIZEOF_PTR > 2
HN_API struct hn_err hn_himem_readk20(
	/* reference to input amalgam */
	void *,
	/* dynamic typing information for input amalgam */
	struct hn_amalgam,
	/* knot offset in amalgam to read from, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to output data */
	hn_knot20 );
#endif /* HN_SIZEOF_PTR > 2 */

HN_API struct hn_err hn_himem_write8(
	/* input data */
	u8,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to write to */
	hn_ptri,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );

HN_API struct hn_err hn_himem_write16(
	/* input data */
	u16,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to write to */
	hn_ptri,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );

#if defined( HN_HAVE_I32 )
HN_API struct hn_err hn_himem_write32(
	/* input data */
	u32,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to write to */
	hn_ptri,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );
#endif /* defined( HN_HAVE_I32 ) */

#if defined( HN_HAVE_I64 )
HN_API struct hn_err hn_himem_write64(
	/* input data */
	u64,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* data offset within selected knot to write to */
	hn_ptri,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );
#endif /* defined( HN_HAVE_I64 ) */

HN_API struct hn_err hn_himem_writek8(
	/* input data */
	hn_knot8,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );

HN_API struct hn_err hn_himem_writek12(
	/* input data */
	hn_knot12,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );

HN_API struct hn_err hn_himem_writek16(
	/* input data */
	hn_knot16,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );

#if HN_SIZEOF_PTR > 2
HN_API struct hn_err hn_himem_writek20(
	/* input data */
	hn_knot20,
	/* knot offset in amalgam to write to, interpreted as an array
	 * sized to the number of dimensions inherent to the amalgam */
	hn_amoffs *,
	/* reference to the amalgam to write to */
	void *,
	/* dynamic typing information for the output amalgam */
	struct hn_amalgam );
#endif /* HN_SIZEOF_PTR > 2 */

#endif /* INC_API__HN_LOOM_H */
