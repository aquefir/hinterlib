/***************************************************************************\
 *                         Hinterlib/Neopolitan 2.                         *
 *                                                                         *
 *                     Copyright (C) 2019-2023 Aquefir                     *
 *              Released under Artisan Software Licence v1.1.              *
\***************************************************************************/

#ifndef INC_API__HN_BUFFER_H
#define INC_API__HN_BUFFER_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using \
Hinterlib/Neopolitan. Please ensure you are using Slick/Inbound and a \
compatible compiler (either GCC, Clang, or FCC).
#endif /* END sanity check */

#include "types/base.h"
#include "types/int.h"
#include "types/mem.h"

struct hn_cbuf_inf
{
	hn_u32 bits : 7;
	hn_u32 ovr : 1;
};

void hn_cbuf16_psh( hn_twig

#endif /* INC_API__HN_BUFFER_H */
