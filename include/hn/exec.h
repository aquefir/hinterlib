/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_EXEC_H
#define INC_API__HN_EXEC_H

#include "types/base.h"
#include "types/char.h"

/**
 *
 * @brief Obtain the absolute path to the executable program file making
 *        the call.
 * @param buf buffer to contain the result, which must be exactly
 *        `HN_PATHMAX` + 1 octets in size (i.e. 64KiB).
 * @returns `HN_FALSE` on success, `HN_TRUE` on failure.
 */
hn_bl hn_execpath( hn_chr[HN_PATHMAX + 1] );

/**
 *
 * @brief Obtain the current "working directory" of the program.
 * @param buf buffer to contain the result, which must be exactly
 *        `HN_PATHMAX` + 1 octets in size (i.e. 64KiB).
 * @returns `HN_FALSE` on success, `HN_TRUE` on failure.
 */
hn_bl hn_getcwd( hn_chr[HN_PATHMAX + 1] );

/**
 *
 * @brief Set the current "working directory" of the running program.
 * @param path path to set the current "working directory" to. It may be
 *        a relative or an absolute path.
 * @returns `HN_FALSE` on success, `HN_TRUE` on failure.
 */
hn_bl hn_setcwd( hn_chr * );

/**
 *
 * @brief Get an "environment variable" value by key name.
 * @param key the name of the "environment variable" to look up.
 * @param val buffer to store the "environment variable" value into.
 * @param val_sz size of the `val` buffer, denominated in octets. The
 *        routine will store at most this many octets minus one, and
 *        terminate the output string with a `NUL` character.
 * @returns `HN_FALSE` on success, `HN_TRUE` on failure.
 */
hn_bl hn_getenv( hn_chr *, hn_chr *, hn_ptri );

/**
 *
 * @brief Set an "environment variable" value by key name.
 * @param key the name of the "environment variable" to look up.
 * @param val the value ot set the "environment variable" to.
 * @param ovr whether to overwrite an already existing key or not:
 *        `HN_FALSE` will cause the routine to return `HN_TRUE`
 *        indicating failure if `key` already exists, while `HN_TRUE`
 *        will go ahead with the overwrite.
 * @returns `HN_FALSE` on success, `HN_TRUE` on failure.
 * @note "environment variables" set by this method may not persist in
 *       the wider environment of the user's system. This routine can
 *       only guarantee the value set will persist for the lifetime of
 *       the current program's run, and only in the execution context of
 *       that program.
 */
hn_bl hn_setenv( hn_chr *, hn_chr *, hn_bl );

#endif /* INC_API__HN_EXEC_H */
