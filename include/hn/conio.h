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

/**
 *
 * @brief Write formatted string to `stdout`.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wri_o( const hn_chr *, ... );

/**
 *
 * @brief Write formatted string to `stderr`.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wri_e( const hn_chr *, ... );

/**
 *
 * @brief Write formatted string to a file.
 * @param f The open file handle to write to.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wri_f( struct hn_file *, const hn_chr *, ... );

/**
 *
 * @brief Write formatted string to `stdout`, appending a newline.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wriln_o( const hn_chr *, ... );

/**
 *
 * @brief Write formatted string to `stderr`, appending a newline.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wriln_e( const hn_chr *, ... );

/**
 *
 * @brief Write formatted string to a file, appending a newline.
 * @param f The open file handle to write to.
 * @param s The format string, using the ANSI C format specification.
 *        See https://en.cppreference.com/w/c/io/fprintf for details.
 * @param ... The parameters specified in the format sring, if any.
 */
void hn_wriln_f( struct hn_file *, const hn_chr *, ... );

/**
 *
 * @brief Read text string from `stdin` into a buffer.
 * @param buf The buffer to contain the output read in. Must be at least
 *        `count` octets large.
 * @param count The number of octets to read from `stdin`.
 * @returns The number of octets actually read into `buf`, which may be
 *          anywhere from 0 to `count`.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `count` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
hn_ptri hn_readn_i( hn_chr *, hn_ptri );

/**
 *
 * @brief Read text string from a file into a buffer.
 * @param f the open file handle to read from.
 * @param buf The buffer to contain the output read in. Must be at least
 *        `count` octets large.
 * @param count The number of octets to read from the file.
 * @returns The number of octets actually read into `buf`, which may be
 *          anywhere from 0 to `count`.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `count` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
hn_ptri hn_readn_f( struct hn_file *, hn_chr *, hn_ptri );

/**
 *
 * @brief Read line of text from `stdin` into a buffer.
 * @param buf The buffer to contain the output read in. Must be at least
 *        `count` octets large.
 * @param count The maximum number of octets to read from `stdin`.
 * @returns The number of octets actually read into `buf`, which may be
 *          anywhere from 0 to `count`.
 * @note This routine reads text continuously and stops if either a
 *       newline is encountered or `count` octets are read, whichever
 *       comes first.
 * @note The newline read in will not be discarded by this routine, so
 *       it, along with EOF and error checking as in the `hn_readn_*()`
 *       routines suffice to fully inform consumers about the program
 *       state.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `count` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
hn_ptri hn_readln_i( hn_chr *, hn_ptri );

/**
 *
 * @brief Read line of text from a file into a buffer.
 * @param f the open file handle to read from.
 * @param buf The buffer to contain the output read in. Must be at least
 *        `count` octets large.
 * @param count The maximum number of octets to read from the file.
 * @returns The number of octets actually read into `buf`, which may be
 *          anywhere from 0 to `count`.
 * @note This routine reads text continuously and stops if either a
 *       newline is encountered or `count` octets are read, whichever
 *       comes first.
 * @note The newline read in will not be discarded by this routine, so
 *       it, along with EOF and error checking as in the `hn_readn_*()`
 *       routines suffice to fully inform consumers about the program
 *       state.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `count` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
hn_ptri hn_readln_f( struct hn_file *, hn_chr *, hn_ptri );

#endif /* INC_API__HN_CONIO_H */
