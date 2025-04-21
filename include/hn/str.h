/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_STR_H
#define INC_API__HN_STR_H

#include "types/base.h"
#include "types/char.h"

enum hn_asciify_method
{
	HN_ASCIIFY_METHOD_QUIT,
	HN_ASCIIFY_METHOD_DROP,
	HN_ASCIIFY_METHOD_CONV,
	HN_MAX_ASCIIFY_METHOD
};

struct hn_asciify_opts
{
	hn_ubf method : 2;
	hn_ubf conv_chr : 7;
	hn_ubf : 7;
	hn_ubf : 16;
};

HN_API hn_ptri hn_strlen( hn_chr * );

HN_API hn_ptri hn_ustrlen( hn_uchr * );

HN_API hn_ptri hn_str2ustr( hn_chr *, hn_uchr * );

HN_API hn_ptri hn_ustr2str(
	hn_uchr *, struct hn_asciify_opts, hn_chr * );

HN_API hn_ptri hn_strasz( hn_chr ** );

HN_API hn_ptri hn_ustrasz( hn_uchr ** );

HN_API hn_ptri hn_stracpy( hn_chr **, hn_chr ** );

HN_API hn_ptri hn_ustracpy( hn_uchr **, hn_uchr ** );

HN_API hn_ptri hn_stra2ustra( hn_chr **, hn_uchr ** );

HN_API hn_ptri hn_ustra2stra(
	hn_uchr **, struct hn_asciify_opts, hn_chr ** );

HN_API hn_ptri hn_strsplit( hn_chr *, hn_chr *, hn_ptri, hn_chr ** );

HN_API hn_ptri hn_ustrsplit(
	hn_uchr *, hn_uchr *, hn_ptri, hn_uchr ** );

HN_API hn_ptri hn_strjoin( hn_chr **, hn_chr *, hn_chr * );

HN_API hn_ptri hn_ustrjoin( hn_uchr **, hn_uchr *, hn_uchr * );

#endif /* INC_API__HN_STR_H */
