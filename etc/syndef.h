/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC__SYNDEF_H
#define INC__SYNDEF_H

/**
 * Do not include this file in any project source code! It is only
 * meant to augment clangd for editor intelligence.
 */

/* Define unconditional ones. */
#define _SYNDEF_HAVE_FP
#define _SYNDEF_FP_SOFT
#define _SYNDEF_HAVE_I32
#define _SYNDEF_HAVE_I64
#define _SYNDEF_LLVM
#define _SYNDEF_FOO
#define _CFGOPT_FOO
#define __VSCODE_INTELLISENSE__

/* Define operating system being targeted. */

#ifdef __ANDROID__
#define _SYNDEF_ANDROID
#else
#ifdef __linux__
#ifdef __x86_64__
#define _SYNDEF_LINUX64
#endif
#ifdef __arm__
#define _SYNDEF_LINUXARM
#endif
#ifdef __aarch64__
#define _SYNDEF_LINUXA64
#endif
#ifdef __i386__
#define _SYNDEF_LINUX32
#endif
#endif
#endif

#if defined(__APPLE__) && defined(__MACH__)
#ifdef __aarch64__
#define _SYNDEF_DARWINM1
#else
#define _SYNDEF_DARWIN86
#endif
#endif

#ifdef _WIN32_WINNT
#ifdef _WIN64
#ifdef __x86_64__
#define _SYNDEF_WINNT64
#endif
#ifdef __aarch64__
#define _SYNDEF_WINNTA64
#endif
#else
#ifdef _WIN32
#define _SYNDEF_WINNT32
#endif
#endif
#else
#ifdef _WIN32
#define _SYNDEF_WIN95
#endif
#ifdef _WIN16
#define _SYNDEF_WIN311
#endif
#endif

#ifdef __aarch64__
#define _SYNDEF_AARCH64
#endif
#ifdef __arm__
#define _SYNDEF_AARCH32
#endif
#ifdef __x86_64__
#define _SYNDEF_AMD64
#endif
#ifdef __i386__
#define _SYNDEF_IA32
#endif

/* Define the endianness. */

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define _SYNDEF_LILENDIAN
#else
#define _SYNDEF_BIGENDIAN
#endif

/* Deduce floating-point support. */

#ifdef __aarch64__
#define _SYNDEF_WORDSZ_64
#ifdef __ARM_NEON__
#define _SYNDEF_FP_HARD
#endif
#endif
#ifdef __arm__
#define _SYNDEF_WORDSZ_32
#ifdef __ARM_NEON__
#define _SYNDEF_FP_HARD
#endif
#endif

#ifdef __x86_64__
#define _SYNDEF_FP_HARD
#define _SYNDEF_WORDSZ_64
#endif

/* Define the pointer size. */

#if __POINTER_WIDTH__ == 64
#define _SYNDEF_PTRSZ_64
#elif __POINTER_WIDTH__ == 32
#define _SYNDEF_PTRSZ_32
#elif __POINTER_WIDTH__ == 16
#define _SYNDEF_PTRSZ_16
#endif /* __POINTER_WIDTH__ */

/* Define the size of "long". */
#if __LONG_WIDTH__ == 64
#define _SYNDEF_LONGSZ_64
#elif __LONG_WIDTH__ == 32
#define _SYNDEF_LONGSZ_32
#endif

#endif /* INC__SYNDEF_H */
