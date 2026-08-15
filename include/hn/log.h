/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_LOG_H
#define INC_API__HN_LOG_H

#if !defined(_CFGOPT_NOSTDIO)
#include "file.h"
#include "types/char.h"

enum
{
	HN_LOG_PREFIX_SZ = 16
};

struct hn_log
{
	/* File handle the log items are sent to using standard I/O. */
	struct hn_file * f;
	/* Text prefixed to log items sent at the level of "info". */
	hn_chr prefix_info[HN_LOG_PREFIX_SZ];
	/* Text prefixed to log items sent at the level of "warning". */
	hn_chr prefix_warn[HN_LOG_PREFIX_SZ];
	/* Text prefixed to log items sent at the level "error". */
	hn_chr prefix_err[HN_LOG_PREFIX_SZ];
	/* Tracks the indentation level for grouping and ungrouping. */
	hn_ubf indent_lvl : 3;
	/* Whether to allow the high bit to be set, as it is with UTF-8.
	 */
	hn_ubf allow_msb : 1;
	/* Whether to show log items sent at the level of "info". */
	hn_ubf show_info : 1;
	/* Whether to show items sent at the level of "warning". */
	hn_ubf show_warn : 1;
	/* Whether to colour output using ANSI escape sequences. */
	hn_ubf ansi_col : 1;
	hn_ubf : 9;
}
HN_PACKED;

/**
 *
 * @brief Group the logger's output for contextualisation.
 * @param log The logger context to modify.
 * @returns `HN_FALSE` if successful; `HN_TRUE` if the maximum number of
 *          indent levels has already been reached (7) or if the logger
 *          context pointer provided is NULL.
 */
HN_API hn_bl hn_log_grp( struct hn_log * );

/**
 *
 * @brief Ungroup the logger's output for contextualisation.
 * @param log The logger context to modify.
 * @returns `HN_FALSE` if successful; `HN_TRUE` if the number of indent
 *          indent levels is already at zero (0) or if the logger
 *          context pointer provided is NULL.
 */
HN_API hn_bl hn_log_ungrp( struct hn_log * );

/**
 *
 * @brief Write a line to log at the "info" urgency level.
 * @param log The logger context to use.
 * @param fmt The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
HN_API void hn_log_info(
	struct hn_log *,
	const chr *,
	...
	);

/**
 *
 * @brief Write a line to log at the "warning" urgency level.
 * @param log The logger context to use.
 * @param fmt The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
HN_API void hn_log_warn(
	struct hn_log *,
	const chr *,
	...
	);

/**
 *
 * @brief Write a line to log at the "error" urgency level.
 * @param log The logger context to use.
 * @param fmt The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
HN_API void hn_log_err(
	struct hn_log *,
	const chr *,
	...
	);
#endif /* !defined( _CFGOPT_NOSTDIO ) */

#endif /* INC_API__HN_LOG_H */
