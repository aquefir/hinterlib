/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_LOG_H
#define INC_API__HN_LOG_H

#include "file.h"
#include "types/char.h"
#include "types/int.h"

struct hn_log
{
	/* File handle the log items are sent to using standard I/O. */
	struct hn_file * f;
	/* Text prefixed to log items sent at the level of "info". */
	hn_chr prefix_info[16];
	/* Text prefixed to log items sent at the level of "warning". */
	hn_chr prefix_warn[16];
	/* Text prefixed to log items sent at the level "error". */
	hn_chr prefix_err[16];
	/* Tracks the indentation level for grouping and ungrouping. */
	hn_u32 indent_lvl : 3;
	/* Whether to allow the high bit to be set, as it is with UTF-8.
	 */
	hn_u32 allow_msb : 1;
	/* Whether to show log items sent at the level of "info". */
	hn_u32 show_info : 1;
	/* Whether to show items sent at the level of "warning". */
	hn_u32 show_warn : 1;
	/* Whether to colour output using ANSI escape sequences. */
	hn_u32 ansi_col : 1;
} HN_PACKED;

hn_bl hn_log_grp( struct hn_log * );

hn_bl hn_log_ungrp( struct hn_log * );

void hn_log_info( struct hn_log *, const chr *, ... );

void hn_log_warn( struct hn_log *, const chr *, ... );

void hn_log_err( struct hn_log *, const chr *, ... );

#endif /* INC_API__HN_LOG_H */
