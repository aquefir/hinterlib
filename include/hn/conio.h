/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_CONIO_H
#define INC_API__HN_CONIO_H

#include "file.h"
#include "types/base.h"
#include "types/char.h"

void hn_wri_o( const hn_chr *, ... );

void hn_wri_e( const hn_chr *, ... );

void hn_wri_f( struct hn_file *, const hn_chr *, ... );

void hn_wriln_o( const hn_chr *, ... );

void hn_wriln_e( const hn_chr *, ... );

void hn_wriln_f( struct hn_file *, const hn_chr *, ... );

hn_ptri hn_readn_i( hn_chr *, hn_ptri );

hn_ptri hn_readn_f( struct hn_file *, hn_chr *, hn_ptri );

hn_ptri hn_readln_i( hn_chr *, hn_ptri );

hn_ptri hn_readln_f( struct hn_file *, hn_chr *, hn_ptri );

#endif /* INC_API__HN_CONIO_H */
