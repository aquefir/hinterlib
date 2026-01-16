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

enum hn_strsplit_delimincl
{
	HN_STRSPLIT_DELIM_NONE,
	HN_STRSPLIT_DELIM_SUFFIX,
	HN_STRSPLIT_DELIM_PREFIX,
	HN_STRSPLIT_DELIM_BOTH,
	HN_MAX_STRSPLIT_DELIM
};

struct hn_asciify_opts
{
	hn_ubf method : 2;
	hn_ubf conv_chr : 7;
	hn_ubf : 7;
	hn_ubf : 16;
};

/**
 *
 * @brief Count the number of characters in a `NUL`-terminated string.
 * @param s The string to enumerate.
 * @returns The number of characters, not including the `NUL`.
 */
HN_API hn_ptri hn_strlen( hn_chr * );

/**
 *
 * @brief Count the number of runes in a `NUL`-terminated unistring.
 * @param s The unistring to enumerate.
 * @returns The number of runes, not including the NUL.
 */
HN_API hn_ptri hn_ustrlen( hn_uchr * );

/**
 *
 * @brief Convert a string to a unistring, or alternatively deduce the
 *        amount of space needed to do so.
 * @param s The input `NUL`-terminated ASCII string.
 * @param us The buffer to contain the output unistring, or `NULL` if
 *        one merely wishes to count how many runes would be output in
 *        order to allocate space for the buffer.
 * @returns The number of runes that would be output, not including the
 *          `NUL` terminator.
 */
HN_API hn_ptri hn_str2ustr( hn_chr *, hn_uchr * );

/**
 *
 * @brief Convert a unistring to a string, or alternatively deduce the
 *        amount of space needed to do so.
 * @param s The input `NUL`-terminated Unicode string.
 * @param opts A valid `struct hn_asciify_opts` containing information
 *        on how to deal with non-ASCII runes.
 * @param us The buffer to contain the output string, or `NULL` if
 *        one merely wishes to count how many runes would be output in
 *        order to allocate space for the buffer.
 * @returns The number of runes that would be output, not including the
 *          `NUL` terminator.
 */
HN_API hn_ptri hn_ustr2str( hn_uchr *, struct hn_asciify_opts, hn_chr *
	);

/**
 *
 * @brief Get the length of a `NULL`-terminated string array.
 * @param a The array to get the length of.
 * @returns The length of the array, not including the `NULL`
 *          terminator, denominated in strings.
 */
HN_API hn_ptri hn_strasz( hn_chr ** );

/**
 *
 * @brief Get the length of a `NULL`-terminated unistring array.
 * @param a The array to get the length of.
 * @returns The length of the array, not including the `NULL`
 *          terminator, denominated in unistrings.
 */
HN_API hn_ptri hn_ustrasz( hn_uchr ** );

/**
 *
 * @brief Deep copy a `NULL`-terminated string array.
 * @param src The source string array to copy from.
 * @param dst The destination string array allocation to copy to, or
 *        `NULL` if one merely wishes to know how many octets are needed
 *        to fully contain the string array and its children in a single
 *        allocation.
 * @returns The number of octets written (or to be written if `dst` is
 *          `NULL`) to the output string array.
 */
HN_API hn_ptri hn_stracpy( hn_chr **, hn_chr ** );

/**
 *
 * @brief Deep copy a `NULL`-terminated unistring array.
 * @param src The source unistring array to copy from.
 * @param dst The destination unistring array allocation to copy to, or
 *        `NULL` if one merely wishes to know how many octets are needed
 *        to fully contain the unistring array and its children in a
 *        single allocation, including `NUL` terminators in each string
 *        and a `NULL` terminator for the array.
 * @returns The number of octets written (or to be written if `dst` is
 *          `NULL`) to the output unistring array.
 */
HN_API hn_ptri hn_ustracpy( hn_uchr **, hn_uchr ** );

/**
 *
 * @brief Convert an ASCII string array to a Unicode unistring array.
 * @param str ASCII string to read from.
 * @param ustr Unicode unistring to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including `NUL` terminators in each string and a
 *        `NULL` terminator for the array.
 * @returns The number of octets written (or to be written if `ustr` is
 *          `NULL`) to the output unistring array.
 */
HN_API hn_ptri hn_stra2ustra( hn_chr **, hn_uchr ** );

/**
 *
 * @brief Convert a Unicode unistring array to an ASCII string array.
 * @param ustr Unicode unistring to read from.
 * @param opts A valid `struct hn_asciify_opts` containing details on
 *        how to handle non-ASCII rune coercion.
 * @param str ASCII string to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including `NUL` terminators in each string and a
 *        `NULL` terminator for the array.
 * @returns The number of octets written (or to be written if `ustr` is
 *          `NULL`) to the output unistring array.
 */
HN_API hn_ptri hn_ustra2stra( hn_uchr **, struct hn_asciify_opts,
	hn_chr ** );

/**
 *
 * @brief Split an ASCII string by a delimiter.
 * @param str The string to split.
 * @param delim Delimiter string to search for and split by.
 * @param delim_opt Whether to include the delimiter at the end of each
 *        string, beginning of each string, both, or neither.
 * @param max Maximum number of splits to perform, or zero for unlimited
 *        splitting.
 * @param stra The string array to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including `NUL` terminators in each string and a
 *        `NULL` terminator for the array.
 * @returns The number of splits performed if `stra` is not `NULL`, or
 *          alternatively the number of octets of memory needed to hold
 *          the output string array, including `NUL` terminators in each
 *          string and a `NULL` terminator for the array.
 */
HN_API hn_ptri hn_strsplit( hn_chr *,
	hn_chr *,
	enum hn_strsplit_delimincl,
	hn_ptri,
	hn_chr ** );

/**
 *
 * @brief Split a Unicode unistring by a delimiter.
 * @param ustr The unistring to split.
 * @param delim Delimiter unistring to search for and split by.
 * @param delim_opt Whether to include the delimiter at the end of each
 *        unistring, beginning of each unistring, both, or neither.
 * @param max Maximum number of splits to perform, or zero for unlimited
 *        splitting.
 * @param ustra The unistring array to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including `NUL` terminators in each unistring and
 *        a `NULL` terminator for the array.
 * @returns The number of splits performed if `ustra` is not `NULL`, or
 *          alternatively the number of octets of memory needed to hold
 *          the output unistring array, including `NUL` terminators in
 *          each unistring and a `NULL` terminator for the array.
 */
HN_API hn_ptri hn_ustrsplit( hn_uchr *,
	hn_uchr *,
	enum hn_strsplit_delimincl,
	hn_ptri,
	hn_uchr ** );

/**
 *
 * @brief Join an ASCII string with an optional joinder.
 * @param stra The string array to join.
 * @param joinder The joinder to stick between array members in the
 *        output string.
 * @param str The output string to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including the `NUL` terminator.
 * @returns The number of ASCII characters that were written to `str`,
 *          or would have been written in the case `str` is `NULL`.
 */
HN_API hn_ptri hn_strjoin( hn_chr **, hn_chr *, hn_chr * );

/**
 *
 * @brief Join a Unicode unistring with an optional joinder.
 * @param ustra The unistring array to join.
 * @param joinder The joinder to stick between array members in the
 *        output unistring.
 * @param ustr The output unistring to write to, or `NULL` if one merely
 *        wishes to know how many octets of memory are needed to hold
 *        the output, including the `NUL` terminator.
 * @returns The number of Unicode runes that were written to `ustr`, or
 *          would have been written in the case `ustr` is `NULL`.
 */
HN_API hn_ptri hn_ustrjoin( hn_uchr **, hn_uchr *, hn_uchr * );

#endif /* INC_API__HN_STR_H */
