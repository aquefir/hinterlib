/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_ERR_H
#define INC_API__HN_ERR_H

#include "conio.h"
#include "types/base.h"
#include "types/char.h"

/* TODO: Document this! */
#if defined( _CFGOPT_NOSTDIO )
/* fake out */
#define hn_wriln_e( x, y )
#endif /* !defined( _CFGOPT_NOSTDIO ) */

#if !defined( HN_CHK_DIE )
/* Assert an expression, otherwise die. */
#define HN_CHK_DIE( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			hn_die( ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_DIE ) */

#if !defined( HN_CHK_RET )
/* Assert an expression, otherwise return void. */
#define HN_CHK_RET( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			return; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_RET ) */

#if !defined( HN_CHK_PRET )
/* Assert an expression, otherwise print and return void. */
#define HN_CHK_PRET( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			return; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PRET ) */

#if !defined( HN_CHK_RETV )
/* Assert an expression, otherwise return a value. */
#define HN_CHK_RETV( _hn_expr, _hn_failval ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			return ( _hn_failval ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_RETV ) */

#if !defined( HN_CHK_PRETV )
/* Assert an expression, otherwise print and return a value. */
#define HN_CHK_PRETV( _hn_expr, _hn_failval, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			return ( _hn_failval ); \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PRETV ) */

#if !defined( HN_CHK_BREAK )
/* Assert an expression, otherwise break. */
#define HN_CHK_BREAK( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			break; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_BREAK ) */

#if !defined( HN_CHK_PBREAK )
/* Assert an expression, otherwise print and break. */
#define HN_CHK_PBREAK( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			break; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PBREAK ) */

#if !defined( HN_CHK_CONT )
/* Assert an expression, otherwise continue. */
#define HN_CHK_CONT( _hn_expr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			continue; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_CONT ) */

#if !defined( HN_CHK_PCONT )
/* Assert an expression, otherwise print and continue. */
#define HN_CHK_PCONT( _hn_expr, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			continue; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PCONT ) */

#if !defined( HN_CHK_GOTO )
/* Assert an expression, otherwise goto a label. */
#define HN_CHK_GOTO( _hn_expr, _hn_label ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			goto _hn_label; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_GOTO ) */

#if !defined( HN_CHK_PGOTO )
/* Assert an expression, otherwise print and goto a label. */
#define HN_CHK_PGOTO( _hn_expr, _hn_label, _hn_failstr ) \
	do \
	{ \
		if( _hn_expr ) \
		{ \
		} \
		else \
		{ \
			hn_wriln_e( "%s", ( _hn_failstr ) ); \
			goto _hn_label; \
		} \
	} while( 0 )
#endif /* !defined( HN_CHK_PGOTO ) */

enum hn_err_id
{
	/* Success */
	HN_ERR_ID_SUCCESS = 0,
	/* Operation not permitted */
	HN_ERR_ID_EPERM = 1,
	/* No such file or directory */
	HN_ERR_ID_ENOENT = 2,
	/* No such process */
	HN_ERR_ID_ESRCH = 3,
	/* Interrupted system call */
	HN_ERR_ID_EINTR = 4,
	/* I/O error */
	HN_ERR_ID_EIO = 5,
	/* No such device or address */
	HN_ERR_ID_ENXIO = 6,
	/* Argument list too long */
	HN_ERR_ID_E2BIG = 7,
	/* Exec format error */
	HN_ERR_ID_ENOEXEC = 8,
	/* Bad file number */
	HN_ERR_ID_EBADF = 9,
	/* No child processes */
	HN_ERR_ID_ECHILD = 10,
	/* Try again */
	HN_ERR_ID_EAGAIN = 11,
	/* Out of memory */
	HN_ERR_ID_ENOMEM = 12,
	/* Permission denied */
	HN_ERR_ID_EACCES = 13,
	/* Bad address */
	HN_ERR_ID_EFAULT = 14,
	/* Block device required */
	HN_ERR_ID_ENOTBLK = 15,
	/* Device or resource busy */
	HN_ERR_ID_EBUSY = 16,
	/* File exists */
	HN_ERR_ID_EEXIST = 17,
	/* Cross-device link */
	HN_ERR_ID_EXDEV = 18,
	/* No such device */
	HN_ERR_ID_ENODEV = 19,
	/* Not a directory */
	HN_ERR_ID_ENOTDIR = 20,
	/* Is a directory */
	HN_ERR_ID_EISDIR = 21,
	/* Invalid argument */
	HN_ERR_ID_EINVAL = 22,
	/* File table overflow */
	HN_ERR_ID_ENFILE = 23,
	/* Too many open files */
	HN_ERR_ID_EMFILE = 24,
	/* Not a typewriter */
	HN_ERR_ID_ENOTTY = 25,
	/* Text file busy */
	HN_ERR_ID_ETXTBSY = 26,
	/* File too large */
	HN_ERR_ID_EFBIG = 27,
	/* No space left on device */
	HN_ERR_ID_ENOSPC = 28,
	/* Illegal seek */
	HN_ERR_ID_ESPIPE = 29,
	/* Read-only file system */
	HN_ERR_ID_EROFS = 30,
	/* Too many links */
	HN_ERR_ID_EMLINK = 31,
	/* Broken pipe */
	HN_ERR_ID_EPIPE = 32,
	/* Math argument out of domain of func */
	HN_ERR_ID_EDOM = 33,
	/* Math result not representable */
	HN_ERR_ID_ERANGE = 34,
	/* Resource deadlock would occur */
	HN_ERR_ID_EDEADLK = 35,
	/* File name too long */
	HN_ERR_ID_ENAMETOOLONG = 36,
	/* No record locks available */
	HN_ERR_ID_ENOLCK = 37,
	/* Function not implemented */
	HN_ERR_ID_ENOSYS = 38,
	/* Directory not empty */
	HN_ERR_ID_ENOTEMPTY = 39,
	/* Too many symbolic links encountered */
	HN_ERR_ID_ELOOP = 40,
	/* No message of desired type */
	HN_ERR_ID_ENOMSG = 42,
	/* Identifier removed */
	HN_ERR_ID_EIDRM = 43,
	/* Channel number out of range */
	HN_ERR_ID_ECHRNG = 44,
	/* Level 2 not synchronized */
	HN_ERR_ID_EL2NSYNC = 45,
	/* Level 3 halted */
	HN_ERR_ID_EL3HLT = 46,
	/* Level 3 reset */
	HN_ERR_ID_EL3RST = 47,
	/* Link number out of range */
	HN_ERR_ID_ELNRNG = 48,
	/* Protocol driver not attached */
	HN_ERR_ID_EUNATCH = 49,
	/* No CSI structure available */
	HN_ERR_ID_ENOCSI = 50,
	/* Level 2 halted */
	HN_ERR_ID_EL2HLT = 51,
	/* Invalid exchange */
	HN_ERR_ID_EBADE = 52,
	/* Invalid request descriptor */
	HN_ERR_ID_EBADR = 53,
	/* Exchange full */
	HN_ERR_ID_EXFULL = 54,
	/* No anode */
	HN_ERR_ID_ENOANO = 55,
	/* Invalid request code */
	HN_ERR_ID_EBADRQC = 56,
	/* Invalid slot */
	HN_ERR_ID_EBADSLT = 57,

	/* Bad font file format */
	HN_ERR_ID_EBFONT = 59,
	/* Device not a stream */
	HN_ERR_ID_ENOSTR = 60,
	/* No data available */
	HN_ERR_ID_ENODATA = 61,
	/* Timer expired */
	HN_ERR_ID_ETIME = 62,
	/* Out of streams resources */
	HN_ERR_ID_ENOSR = 63,
	/* Machine is not on the network */
	HN_ERR_ID_ENONET = 64,
	/* Package not installed */
	HN_ERR_ID_ENOPKG = 65,
	/* Object is remote */
	HN_ERR_ID_EREMOTE = 66,
	/* Link has been severed */
	HN_ERR_ID_ENOLINK = 67,
	/* Advertise error */
	HN_ERR_ID_EADV = 68,
	/* Srmount error */
	HN_ERR_ID_ESRMNT = 69,
	/* Communication error on send */
	HN_ERR_ID_ECOMM = 70,
	/* Protocol error */
	HN_ERR_ID_EPROTO = 71,
	/* Multihop attempted */
	HN_ERR_ID_EMULTIHOP = 72,
	/* RFS specific error */
	HN_ERR_ID_EDOTDOT = 73,
	/* Not a data message */
	HN_ERR_ID_EBADMSG = 74,
	/* Value too large for defined data type */
	HN_ERR_ID_EOVERFLOW = 75,
	/* Name not unique on network */
	HN_ERR_ID_ENOTUNIQ = 76,
	/* File descriptor in bad state */
	HN_ERR_ID_EBADFD = 77,
	/* Remote address changed */
	HN_ERR_ID_EREMCHG = 78,
	/* Can not access a needed shared library */
	HN_ERR_ID_ELIBACC = 79,
	/* Accessing a corrupted shared library */
	HN_ERR_ID_ELIBBAD = 80,
	/* .lib section in a.out corrupted */
	HN_ERR_ID_ELIBSCN = 81,
	/* Attempting to link in too many shared libraries */
	HN_ERR_ID_ELIBMAX = 82,
	/* Cannot exec a shared library directly */
	HN_ERR_ID_ELIBEXEC = 83,
	/* Illegal byte sequence */
	HN_ERR_ID_EILSEQ = 84,
	/* Interrupted system call should be restarted */
	HN_ERR_ID_ERESTART = 85,
	/* Streams pipe error */
	HN_ERR_ID_ESTRPIPE = 86,
	/* Too many users */
	HN_ERR_ID_EUSERS = 87,
	/* Socket operation on non-socket */
	HN_ERR_ID_ENOTSOCK = 88,
	/* Destination address required */
	HN_ERR_ID_EDESTADDRREQ = 89,
	/* Message too long */
	HN_ERR_ID_EMSGSIZE = 90,
	/* Protocol wrong type for socket */
	HN_ERR_ID_EPROTOTYPE = 91,
	/* Protocol not available */
	HN_ERR_ID_ENOPROTOOPT = 92,
	/* Protocol not supported */
	HN_ERR_ID_EPROTONOSUPPORT = 93,
	/* Socket type not supported */
	HN_ERR_ID_ESOCKTNOSUPPORT = 94,
	/* Operation not supported on transport endpoint */
	HN_ERR_ID_EOPNOTSUPP = 95,
	/* Protocol family not supported */
	HN_ERR_ID_EPFNOSUPPORT = 96,
	/* Address family not supported by protocol */
	HN_ERR_ID_EAFNOSUPPORT = 97,
	/* Address already in use */
	HN_ERR_ID_EADDRINUSE = 98,
	/* Cannot assign requested address */
	HN_ERR_ID_EADDRNOTAVAIL = 99,
	/* Network is down */
	HN_ERR_ID_ENETDOWN = 100,
	/* Network is unreachable */
	HN_ERR_ID_ENETUNREACH = 101,
	/* Network dropped connection because of reset */
	HN_ERR_ID_ENETRESET = 102,
	/* Software caused connection abort */
	HN_ERR_ID_ECONNABORTED = 103,
	/* Connection reset by peer */
	HN_ERR_ID_ECONNRESET = 104,
	/* No buffer space available */
	HN_ERR_ID_ENOBUFS = 105,
	/* Transport endpoint is already connected */
	HN_ERR_ID_EISCONN = 106,
	/* Transport endpoint is not connected */
	HN_ERR_ID_ENOTCONN = 107,
	/* Cannot send after transport endpoint shutdown */
	HN_ERR_ID_ESHUTDOWN = 108,
	/* Too many references: cannot splice */
	HN_ERR_ID_ETOOMANYREFS = 109,
	/* Connection timed out */
	HN_ERR_ID_ETIMEDOUT = 110,
	/* Connection refused */
	HN_ERR_ID_ECONNREFUSED = 111,
	/* Host is down */
	HN_ERR_ID_EHOSTDOWN = 112,
	/* No route to host */
	HN_ERR_ID_EHOSTUNREACH = 113,
	/* Operation already in progress */
	HN_ERR_ID_EALREADY = 114,
	/* Operation now in progress */
	HN_ERR_ID_EINPROGRESS = 115,
	/* Stale NFS file handle */
	HN_ERR_ID_ESTALE = 116,
	/* Structure needs cleaning */
	HN_ERR_ID_EUCLEAN = 117,
	/* Not a XENIX named type file */
	HN_ERR_ID_ENOTNAM = 118,
	/* No XENIX semaphores available */
	HN_ERR_ID_ENAVAIL = 119,
	/* Is a named type file */
	HN_ERR_ID_EISNAM = 120,
	/* Remote I/O error */
	HN_ERR_ID_EREMOTEIO = 121,
	/* Quota exceeded */
	HN_ERR_ID_EDQUOT = 122,

	/* No medium found */
	HN_ERR_ID_ENOMEDIUM = 123,
	/* Wrong medium type */
	HN_ERR_ID_EMEDIUMTYPE = 124,
	/* Operation Canceled */
	HN_ERR_ID_ECANCELED = 125,
	/* Required key not available */
	HN_ERR_ID_ENOKEY = 126,
	/* Key has expired */
	HN_ERR_ID_EKEYEXPIRED = 127,
	/* Key has been revoked */
	HN_ERR_ID_EKEYREVOKED = 128,
	/* Key was rejected by service */
	HN_ERR_ID_EKEYREJECTED = 129,

	/* for robust mutexes */

	/* Owner died */
	HN_ERR_ID_EOWNERDEAD = 130,
	/* State not recoverable */
	HN_ERR_ID_ENOTRECOVERABLE = 131,

	/* Operation not possible due to RF-kill */
	HN_ERR_ID_ERFKILL = 132,
	/* Maximum conventional error ID, exclusive */
	HN_MAX_ERR_ID = 133,
	/* Extended error ID in use, see `.xid` */
	HN_ERR_ID_XTENDED = 255
};

/* supplemental for `enum hn_err_id` since there are duplicates */
enum
{
	/* Resource deadlock would occur */
	HN_ERR_ID_EDEADLOCK = HN_ERR_ID_EDEADLK,
	/* Operation would block */
	HN_ERR_ID_EWOULDBLOCK = HN_ERR_ID_EAGAIN
};

struct hn_err
{
	/* Distinguish between errors and mere information. */
	hn_ubf fatal : 1;
	/* See `enum hn_err_id`. Matched to Linux `<errno.h>`. */
	hn_ubf id : 8;
	hn_ubf : 7;
	/* For downstream to define and build string tables for. */
	hn_ubf xid : 16;
} HN_TYPELESS HN_PACKED;

extern const hn_chr * const hn_err_id_strings[HN_MAX_ERR_ID];

/**
 *
 * @brief Terminate program execution immediately.
 * @note Internally this routine uses libc's abort() routine where
 *       available, falling back to its own implementation otherwise.
 */
HN_API HN_NORETURN void hn_die( void );

#if defined( _CFGOPT_NOSTDIO )
/* Remove it before anyone finds out */
#undef hn_wriln_e
#endif /* !defined( _CFGOPT_NOSTDIO ) */

#endif /* INC_API__HN_ERR_H */
