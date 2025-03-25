/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_FILE_H
#define INC_API__HN_FILE_H

#include "types/base.h"
#include "types/char.h"
#include "types/int.h"

enum
{
	/* Maximum number of octets (not characters!) in a file path.
	 * This is 64 KiB - 1 to hold the NUL terminus in 64 KiB. */
	HN_PATHMAX = 65535
};

/* Specify the origin of a file handle seek operation. */
enum hn_forigin
{
	HN_SEEK_SET,
	HN_SEEK_CUR,
	HN_SEEK_END,
	HN_MAX_SEEK
};

/* Opaque structure containing file handle positioning information. */
struct hn_fpos;

/* Opaque structure containing file handle data. */
struct hn_file;

/* File handle operating mode, a la ANSI C stdio's mode string. */
struct hn_fmode
{
	/* Base mode: 0 = r, 1 = w, 2 = a, 3 = x. */
	hn_ubf approach : 2;
	/* The + in the libc mode string. */
	hn_ubf update : 1;
	hn_ubf : 13;
	hn_ubf : 16;
} HN_PACKED;

#if !defined( _CFGOPT_NOSTDIO )
/* Return the file handle for standard input, or `stdin`. */
HN_API struct hn_file * hn_fstdin( void );

/* Return the file handle for standard output, or `stdout`. */
HN_API struct hn_file * hn_fstdout( void );

/* Return the file handle for standard error, or `stderr`. */
HN_API struct hn_file * hn_fstderr( void );
#endif /* !defined( _CFGOPT_NOSTDIO ) */

/**
 *
 * @brief Open a file for I/O.
 * @param path Path to the file to open.
 * @param mode Operating mode to place the file handle into.
 * @returns A file handle if succesful, or `NULL` upon failure.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API struct hn_file * hn_fopen( const hn_chr *, struct hn_fmode );

/**
 *
 * @brief Repen a file for I/O.
 * @param path Path to the file to open, or `NULL` to leave the path
 *        unchanged from when it was previously opened.
 * @param mode Operating mode to place the file handle into.
 * @param f The already open file handle to be reopened.
 * @returns A file handle if succesful, or `NULL` upon failure.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 * @note If this routine is successful, the old file handle passed in
 *       by parameter is no longer valid and should be discarded. It
 *       should also not be flushed or closed by the caller.
 */
HN_API struct hn_file * hn_freopen(
	const hn_chr *, struct hn_fmode, struct hn_file * );

/**
 *
 * @brief Close a file handle.
 * @param f File handle to close.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fclose( struct hn_file * );

/**
 *
 * @brief Flush any pending data to be streamed to a file handle.
 * @param f File handle to flush.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fflush( struct hn_file * );

/**
 *
 * @brief Change the internal buffer used for a file handle's I/O.
 * @param f File handle to change the internal buffer of.
 * @param buf New internal buffer for the file handle to use. If this is
 *        a `NULL` pointer, buffering is turned off.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 * @note To properly allocate a sufficiently sized internal buffer,
 *       first call `hn_fgetbufsz()`.
 */
HN_API hn_bl hn_fsetbuf( struct hn_file *, hn_u8 * );

/* Returns the size of an internal stdio buffer, denominated in octets.
 */
HN_API hn_ptri hn_fgetbufsz( void );

/**
 *
 * @brief Read some octets from a file handle.
 * @param buf The buffer to read the octets into.
 * @param buf_sz The size of the buffer, denominated in octets.
 * @param f The file handle to read from.
 * @returns The number of octets read, which may range from 0 to
 *          `buf_sz`.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `buf_sz` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
HN_API hn_ptri hn_fread( hn_u8 *, hn_ptri, struct hn_file * );

/**
 *
 * @brief Write some octets to a file handle.
 * @param buf The buffer containing the octets to write.
 * @param buf_sz The size of the buffer, denominated in octets.
 * @param f The file handle to write to.
 * @returns The number of octets written, which may range from 0 to
 *          `buf_sz`.
 * @note Check EOF and error conditions whenever this routine returns
 *       less than `buf_sz` using `hn_feof()` and `hn_ferror()`,
 *       respectively.
 */
HN_API hn_ptri hn_fwrite( hn_u8 *, hn_ptri, struct hn_file * );

/**
 *
 * @brief Get the current position of a file handle.
 * @param f The file handle to interrogate.
 * @returns A valid `struct hn_fpos`, or `NULL` on failure.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API struct hn_fpos * hn_fgetpos( struct hn_file * );

/**
 *
 * @brief Set the current position of a file handle.
 * @param pos File position information to apply to the file handle.
 * @param f The file handle to modify.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fsetpos( struct hn_fpos *, struct hn_file * );

/**
 *
 * @brief Change the current I/O position of a file handle.
 * @param f The file handle to modify.
 * @param offs The number of octets to move.
 * @param orig The origin specifying what the offset is relative to.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fseek16( struct hn_file *, hn_s16, enum hn_forigin );

#if defined( _SYNDEF_HAVE_I32 )

/**
 *
 * @brief Change the current I/O position of a file handle.
 * @param f The file handle to modify.
 * @param offs The number of octets to move.
 * @param orig The origin specifying what the offset is relative to.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fseek32( struct hn_file *, hn_s32, enum hn_forigin );

#endif /* defined( _SYNDEF_HAVE_I32 ) */

#if defined( _SYNDEF_HAVE_I64 )

/**
 *
 * @brief Change the current I/O position of a file handle.
 * @param f The file handle to modify.
 * @param offs The number of octets to move.
 * @param orig The origin specifying what the offset is relative to.
 * @returns `HN_FALSE` if successful, `HN_TRUE` if not.
 * @note `hn_ferror()` may have useful information if this routine
 *       fails.
 */
HN_API hn_bl hn_fseek64( struct hn_file *, hn_s64, enum hn_forigin );

#endif /* defined( _SYNDEF_HAVE_I64 ) */

/* Clear any error conditions set upon a file handle. */
HN_API void hn_fclearerr( struct hn_file * );

/* Check if a file handle has its EOF condition set. */
HN_API hn_bl hn_feof( struct hn_file * );

/* Check if a file handle has its error condition set. */
HN_API hn_bl hn_ferror( struct hn_file * );

#endif /* INC_API__HN_FILE_H */
