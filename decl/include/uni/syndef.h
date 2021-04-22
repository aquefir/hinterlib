/****************************************************************************\
 *                       Hinterlib™ base declarations                       *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_SYNDEF_H
#define INC_API__UNI_SYNDEF_H

#if defined( CFG_DARWIN )
#define UNI_IS_DARWIN( ) 1
#else /* !defined( CFG_DARWIN ) */
#define UNI_IS_DARWIN( ) 0
#endif /* defined( CFG_DARWIN ) */

#if defined( CFG_LINUX )
#define UNI_IS_LINUX( ) 1
#else /* !defined( CFG_LINUX ) */
#define UNI_IS_LINUX( ) 0
#endif /* defined( CFG_LINUX ) */

#if defined( CFG_WINDOWS )
#define UNI_IS_WINDOWS( ) 1
#else /* !defined( CFG_WINDOWS ) */
#define UNI_IS_WINDOWS( ) 0
#endif /* defined( CFG_WINDOWS ) */

#if defined( CFG_GBA )
#define UNI_IS_GBA( ) 1
#else /* !defined( CFG_GBA ) */
#define UNI_IS_GBA( ) 0
#endif /* defined( CFG_GBA ) */

#if defined( CFG_IBMPC )
#define UNI_IS_IBMPC( ) 1
#else /* !defined( CFG_IBMPC ) */
#define UNI_IS_IBMPC( ) 0
#endif /* defined( CFG_IBMPC ) */

#if defined( CFG_DOS )
#define UNI_IS_DOS( ) 1
#else /* !defined( CFG_DOS ) */
#define UNI_IS_DOS( ) 0
#endif /* defined( CFG_DOS ) */

#define UNI_UARCH_UNK 0 /* Unknown */
#define UNI_UARCH_I86 1 /* Intel 8086 */
#define UNI_UARCH_I186 2 /* Intel iAPX 186 */
#define UNI_UARCH_I286 3 /* Intel i286 */
#define UNI_UARCH_IA32 4 /* Intel IA-32 (i386+) */
#define UNI_UARCH_AMD64 5 /* AMD 64 (Intel 64 / x86-64) */
#define UNI_UARCH_ARMV4T 6 /* ARMv4 + Thumb-1 */

#if defined( CFG_I86 )
#define UNI_UARCH( ) UNI_UARCH_I86
#elif defined( CFG_I186 )
#define UNI_UARCH( ) UNI_UARCH_I186
#elif defined( CFG_I286 )
#define UNI_UARCH( ) UNI_UARCH_I286
#elif defined( CFG_IA32 )
#define UNI_UARCH( ) UNI_UARCH_IA32
#elif defined( CFG_AMD64 )
#define UNI_UARCH( ) UNI_UARCH_AMD64
#elif defined( CFG_ARMV4T )
#define UNI_UARCH( ) UNI_UARCH_ARMV4T
#else
#define UNI_UARCH( ) UNI_UARCH_UNK
#endif /* defined( CFG_* ) */

#if defined( CFG_WORDSZ_16 )
#define UNI_SIZEOF_WORD( ) 2
#elif defined( CFG_WORDSZ_32 )
#define UNI_SIZEOF_WORD( ) 4
#elif defined( CFG_WORDSZ_64 )
#define UNI_SIZEOF_WORD( ) 8
#else
#error Syndefs from Slick did not define CFG_WORDSZ_*! This is probably \
a configuration error.
#endif

#if defined( CFG_HAVE_I32 )
#define UNI_HAS_I32( ) 1
#if defined( CFG_HAVE_I64 )
#define UNI_HAS_I64( ) 1
#else
#define UNI_HAS_I64( ) 0
#endif /* defined( CFG_HAVE_I64 ) */
#if defined( CFG_LONGSZ_32 )
#define UNI_SIZEOF_LONG( ) 4
#elif defined( CFG_LONGSZ_64 )
#define UNI_SIZEOF_LONG( ) 8
#endif /* defined( CFG_LONGSZ_* ) */
#else
#define UNI_HAS_I32( ) 0
#define UNI_HAS_I64( ) 0
#endif /* defined( CFG_HAVE_I32 ) */

#if defined( CFG_HAVE_FP )
#define UNI_HAS_FP( ) 1
#if defined( CFG_FP_HARD )
#define UNI_HAS_HWFP( ) 1
#else /* !defined( CFG_FP_HARD ) */
#define UNI_HAS_HWFP( ) 0
#endif /* defined( CFG_FP_HARD ) */
#else /* !defined( CFG_HAVE_FP ) */
#define UNI_HAS_FP( ) 0
#endif /* defined( CFG_HAVE_FP ) */

#endif /* INC_API__UNI_SYNDEF_H */
