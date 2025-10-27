/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_TYPES_DEF_H
#define INC_API__HN_TYPES_DEF_H

#if !defined( HN_MAKE_CCVERSION )
/**
 * @brief Concatenate a 32-bit integral for compiler versioning.
 * @param maj Major version number (0-255).
 * @param min Minor version number (0-255).
 * @param pat Patch version number (0-65535).
 */
#define HN_MAKE_CCVERSION( maj, min, pat ) \
	( ( ( ( maj ) & 0xFF ) << 24 ) | \
		( ( ( min ) & 0xFF ) << 16 ) | ( ( pat ) & 0xFFFF ) )
#endif /* !defined( HN_MAKE_CCVERSION ) */

#if !defined( HN_CCVERSION )
#if defined( __clang__ )
#if defined( __clang_patchlevel__ )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __clang_major__, \
		__clang_minor__, \
		__clang_patchlevel__ )
#else /* !defined( __clang_patchlevel__ ) */
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __clang_major__, __clang_minor__, 0 )
#endif /* defined( __clang_patchlevel__ ) */
/* Normalize GCC version. */
#elif defined( __GNUC__ )
#if defined( __GNUC_PATCHLEVEL__ )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( \
		__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__ )
#else /* !defined( __GNUC_PATCHLEVEL__ ) */
#define HN_CCVERSION HN_MAKE_CCVERSION( __GNUC__, __GNUC_MINOR__, 0 )
#endif /* defined( __GNUC_PATCHLEVEL__ ) */
#elif defined( __INTEL_COMPILER )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __INTEL_COMPILER << 8, \
		__INTEL_COMPILER, \
		__INTEL_COMPILER_UPDATE )
#elif defined( _MSC_FULL_VER )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( _MSC_FULL_VER / 1000000, \
		( _MSC_FULL_VER % 1000000 ) / 10000, \
		_MSC_FULL_VER % 10000 )
#elif defined( _MSC_VER )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( _MSC_VER / 100, _MSC_VER % 100, 0 )
#elif defined( __TINYC__ )
#define HN_CCVERSION HN_MAKE_CCVERSION( 0, 0, 0 )
#elif defined( __PACIFIC__ )
#define HN_CCVERSION HN_MAKE_CCVERSION( 0, 0, 0 )
#elif defined( __BORLANDC__ )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __BORLANDC__ >> 8, __BORLANDC__ & 0xFF, 0 )
#elif defined( __DMC__ )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __DMC__ >> 8, ( __DMC__ >> 4 ) & 0xF,
	__DMC__ & 0xF )
#elif defined( __SDCC )
#define HN_CCVERSION \
	HN_MAKE_CCVERSION( __SDCC_VERSION_MAJOR, \
		__SDCC_VERSION_MINOR, \
		__SDCC_VERSION_PATCH )
#else /* !defined( __clang__ ) && !defined( __GNUC__ ) && \
	!defined( __INTEL_COMPILER ) && !defined( _MSC_FULL_VER ) && \
	!defined( _MSC_VER ) && !defined( __TINYC__ ) && \
	!defined( __PACIFIC__ ) && !defined( __BORLANDC__ ) && \
	!defined( __DMC__ ) && !defined( __SDCC ) */
#error Hinterlib requires the use of one of the following compilers: \
GCC, Clang, MSVC, TinyCC, Pacific C, Digital Mars C, FCC, PCC, or the \
Small Device C compiler.
#endif /* defined( __clang__ ) || defined( __GNUC__ ) || \
	defined( __INTEL_COMPILER ) || defined( _MSC_FULL_VER ) || \
	defined( _MSC_VER ) || defined( __TINYC__ ) || \
	defined( __PACIFIC__ ) || defined( __BORLANDC__ ) || \
	defined( __DMC__ ) || defined( __SDCC ) */
#endif /* !defined( HN_CCVERSION ) */

#if !defined( HN_CC_CLANG )
#if defined( __clang__ )
#define HN_CC_CLANG
#endif
#endif /* !defined( HN_CC_CLANG ) */

#if !defined( HN_CC_GCC )
#if defined( __GNUC__ ) && !defined( __clang__ )
#define HN_CC_GCC
#endif
#endif /* !defined( HN_CC_GCC ) */

#if !defined( HN_CC_MSVC )
#if defined( _MSC_VER ) && !defined( __INTEL_COMPILER )
#define HN_CC_MSVC
#endif
#endif /* !defined( HN_CC_MSVC ) */

#if !defined( HN_CC_TCC )
#if defined( __TINYC__ )
#define HN_CC_TCC
#endif
#endif /* !defined( HN_CC_TCC ) */

#if !defined( HN_CC_PACIFICC )
#if defined( __PACIFIC__ )
#define HN_CC_PACIFICC
#endif
#endif /* !defined( HN_CC_PACIFICC ) */

#if !defined( HN_CC_DMC )
#if defined( __DMC__ )
#define HN_CC_DMC
#endif
#endif /* !defined( HN_CC_DMC ) */

#if !defined( HN_CC_SDCC )
#if defined( __SDCC )
#define HN_CC_SDCC
#endif
#endif /* !defined( HN_CC_SDCC ) */

#if !defined( HN_PLATFORM_UNIX )
/* Hinterlib counts macOS/iOS as Unices even though compilers don't. */
#if defined( unix ) || defined( __unix ) || defined( __unix__ )
#define HN_PLATFORM_UNIX
#elif defined( __APPLE__ ) && defined( __MACH__ )
#define HN_PLATFORM_UNIX
#endif
#endif /* !defined( HN_PLATFORM_UNIX ) */

#if !defined( HN_PLATFORM_BSD )
/* Apple systems are a false positive, so exclude them. */
#if defined( __unix__ ) || !defined( __APPLE__ )
#include <sys/param.h>
#if defined( BSD )
#define HN_PLATFORM_BSD
#endif
#endif
#endif /* !defined( HN_PLATFORM_BSD ) */

#if !defined( HN_PLATFORM_FREEBSD )
#if defined( __FreeBSD__ )
#define HN_PLATFORM_FREEBSD
#endif
#endif /* !defined( HN_PLATFORM_FREEBSD ) */

#if !defined( HN_PLATFORM_NETBSD )
#if defined( __NetBSD__ )
#define HN_PLATFORM_NETBSD
#endif
#endif /* !defined( HN_PLATFORM_NETBSD ) */

#if !defined( HN_PLATFORM_OPENBSD )
#if defined( __OpenBSD__ )
#define HN_PLATFORM_OPENBSD
#endif
#endif /* !defined( HN_PLATFORM_OPENBSD ) */

#if !defined( HN_PLATFORM_LINUX )
/* Android is a false positive, so exclude it. */
#if defined( __linux__ ) && !defined( __ANDROID__ )
#define HN_PLATFORM_LINUX
#endif
#endif /* !defined( HN_PLATFORM_LINUX ) */

#if !defined( HN_PLATFORM_ANDROID )
#if defined( __ANDROID__ )
#define HN_PLATFORM_ANDROID
#endif
#endif /* !defined( HN_PLATFORM_ANDROID ) */

#if !defined( HN_PLATFORM_IOS )
#if defined( __APPLE__ ) && defined( __MACH__ )
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
#define HN_PLATFORM_IOS
#endif
#endif
#endif /* !defined( HN_PLATFORM_IOS ) */

#if !defined( HN_PLATFORM_MACOS )
#if defined( __APPLE__ ) && defined( __MACH__ )
#include <TargetConditionals.h>
#if TARGET_OS_MAC == 1
#define HN_PLATFORM_MACOS
#endif
#endif
#endif /* !defined( HN_PLATFORM_MACOS ) */

#if !defined( HN_PLATFORM_SOLARIS )
#if defined( sun ) || defined( __sun )
#if defined( __SVR4 ) || defined( __svr4__ )
#define HN_PLATFORM_SOLARIS
#endif
#endif
#endif /* !defined( HN_PLATFORM_SOLARIS ) */

#if !defined( HN_PLATFORM_SUNOS )
#if defined( sun ) || defined( __sun )
#if !defined( __SVR4 ) && !defined( __svr4__ )
#define HN_PLATFORM_SUNOS
#endif
#endif
#endif /* !defined( HN_PLATFORM_SUNOS ) */

#if !defined( HN_PLATFORM_ILLUMOS )
#if defined( __illumos__ )
#define HN_PLATFORM_ILLUMOS
#endif
#endif /* !defined( HN_PLATFORM_ILLUMOS ) */

#if !defined( HN_PLATFORM_WINDOWS )
#if defined( _WIN16 ) || defined( _WIN32 )
#define HN_PLATFORM_WINDOWS
#elif defined( __CYGWIN__ ) || defined( __WINDOWS__ )
#define HN_PLATFORM_WINDOWS
#endif
#endif /* !defined( HN_PLATFORM_WINDOWS ) */

#if !defined( HN_ARCH_AMD64 )
#if defined( __amd64__ ) || defined( _M_AMD64 )
#define HN_ARCH_AMD64
#endif
#endif /* !defined( HN_ARCH_AMD64 ) */

#if !defined( HN_ARCH_ARM32 )
#if defined( __arm__ ) || defined( __thumb__ )
#define HN_ARCH_ARM32
#elif defined( _M_ARM ) || defined( _M_ARMT )
#define HN_ARCH_ARM32
#endif
#endif /* !defined( HN_ARCH_ARM32 ) */

#if !defined( HN_ARCH_ARMV4 )
#if defined( __ARM_ARCH_4T__ ) || defined( __TARGET_ARM_4T )
#define HN_ARCH_ARMV4
#endif
#endif /* !defined( HN_ARCH_ARMV4 ) */

#if !defined( HN_ARCH_ARMV5 )
#if defined( __ARM_ARCH_5__ ) || defined( __ARM_ARCH_5E__ )
#define HN_ARCH_ARMV5
#elif defined( __ARM_ARCH_5T__ ) || defined( __ARM_ARCH_5TE__ )
#define HN_ARCH_ARMV5
#elif defined( __ARM_ARCH_5TEJ__ )
#define HN_ARCH_ARMV5
#endif
#endif /* !defined( HN_ARCH_ARMV5 ) */

#if !defined( HN_ARCH_ARMV6 )
#if defined( __ARM_ARCH_6__ ) || defined( __ARM_ARCH_6J__ )
#define HN_ARCH_ARMV6
#elif defined( __ARM_ARCH_6K__ ) || defined( __ARM_ARCH_6Z__ )
#define HN_ARCH_ARMV6
#elif defined( __ARM_ARCH_6ZK__ ) || defined( __ARM_ARCH_6T2__ )
#define HN_ARCH_ARMV6
#endif
#endif /* !defined( HN_ARCH_ARMV6 ) */

#if !defined( HN_ARCH_ARMV7 )
#if defined( __ARM_ARCH_7__ ) || defined( __ARM_ARCH_7A__ )
#define HN_ARCH_ARMV7
#elif defined( __ARM_ARCH_7R__ ) || defined( __ARM_ARCH_7M__ )
#define HN_ARCH_ARMV7
#elif defined( __ARM_ARCH_7S__ )
#define HN_ARCH_ARMV7
#endif
#endif /* !defined( HN_ARCH_ARMV7 ) */

#if !defined( HN_ARCH_ARM64 )
#if defined( __aarch64__ ) || defined( _M_ARM64 )
#define HN_ARCH_ARM64
#endif
#endif /* !defined( HN_ARCH_ARM64 ) */

#if !defined( HN_ARCH_ARMV8 )
#if defined( __ARM64_ARCH_8__ )
#define HN_ARCH_ARMV8
#endif
#endif /* !defined( HN_ARCH_ARMV8 ) */

#if !defined( HN_ARCH_ARMV9 )
#if defined( __ARM64_ARCH_9__ )
#define HN_ARCH_ARMV9
#endif
#endif /* !defined( HN_ARCH_ARMV9 ) */

#if !defined( HN_ARCH_IA16 )
#if defined( _M_I86 ) && !defined( _M_I386 )
#define HN_ARCH_IA16
#endif
#endif /* !defined( HN_ARCH_IA16 ) */

#if !defined( HN_ARCH_IA32 )
#if defined( __i386__ ) || defined( _M_IX86 )
#define HN_ARCH_IA32
#endif
#endif /* !defined( HN_ARCH_IA32 ) */

#if !defined( HN_ARCH_IA64 )
#if defined( __ia64__ ) || defined( _M_IA64 )
#define HN_ARCH_IA64
#endif
#endif /* !defined( HN_ARCH_IA64 ) */

#if !defined( HN_ARCH_M68K )
#if defined( __m68k__ )
#define HN_ARCH_M68K
#endif
#endif /* !defined( HN_ARCH_M68K ) */

#if !defined( HN_ARCH_PPC32 )
#if ( defined( __ppc__ ) && !defined( __ppc64__ ) ) || defined( _M_PPC )
#define HN_ARCH_PPC32
#endif
#endif /* !defined( HN_ARCH_PPC32 ) */

#if !defined( HN_ARCH_PPC64 )
#if defined( __ppc64__ )
#define HN_ARCH_PPC64
#endif
#endif /* !defined( HN_ARCH_PPC64 ) */

#if !defined( HN_ARCH_RISCV32 )
#if defined( __riscv ) && defined( __riscv_xlen ) && __riscv_xlen == 32
#define HN_ARCH_RISCV32
#endif
#endif /* !defined( HN_ARCH_RISCV32 ) */

#if !defined( HN_ARCH_RISCV64 )
#if defined( __riscv ) && defined( __riscv_xlen ) && __riscv_xlen == 64
#define HN_ARCH_RISCV64
#endif
#endif /* !defined( HN_ARCH_RISCV64 ) */

#if !defined( HN_ARCH_SPARC )
#if defined( __sparc ) || defined( __sparc__ )
#define HN_ARCH_SPARC
#endif
#endif /* !defined( HN_ARCH_SPARC ) */

#if !defined( HN_HAVE_I32 )
#if defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ >= 4
#define HN_HAVE_I32
#elif defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ >= 4
#define HN_HAVE_I32
#endif
#endif /* !defined( HN_HAVE_I32 ) */

#if !defined( HN_HAVE_I64 )
#if defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ >= 8
#define HN_HAVE_I64
#elif defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ >= 8
#define HN_HAVE_I64
#elif defined( __SIZEOF_LONG_LONG__ ) && __SIZEOF_LONG_LONG__ >= 8
#define HN_HAVE_I64
#elif defined( __SIZEOF_POINTER__ ) && __SIZEOF_POINTER__ >= 8
#define HN_HAVE_I64
#endif
#endif /* !defined( HN_HAVE_I64 ) */

#if !defined( HN_HAVE_I128 )
#if defined( __SIZEOF_INT128__ )
#define HN_HAVE_I128
#endif
#endif /* !defined( HN_HAVE_I128 ) */

#if !defined( HN_LILENDIAN )
#if defined( __BYTE_ORDER__ )
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define HN_LILENDIAN
#endif
#endif
#endif /* !defined( HN_LILENDIAN ) */

#if !defined( HN_BIGENDIAN )
#if defined( __BYTE_ORDER__ ) && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define HN_BIGENDIAN
#endif
#endif /* !defined( HN_BIGENDIAN ) */

#if !defined( HN_PDPENDIAN )
#if defined( __BYTE_ORDER__ ) && __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#define HN_PDPENDIAN
#endif
#endif /* !defined( HN_PDPENDIAN ) */

#if !defined( HN_PTRSZ_16 )
#if defined( _BB_PSZ ) && _BB_PSZ == 2
#define HN_PTRSZ_16
#elif defined( __POINTER_WIDTH__ ) && __POINTER_WIDTH__ == 16
#define HN_PTRSZ_16
#endif
#endif /* !defined( HN_PTRSZ_16 ) */

#if !defined( HN_PTRSZ_32 )
#if defined( _BB_PSZ ) && _BB_PSZ == 4
#define HN_PTRSZ_32
#elif defined( __POINTER_WIDTH__ ) && __POINTER_WIDTH__ == 32
#define HN_PTRSZ_32
#endif
#endif /* !defined( HN_PTRSZ_32 ) */

#if !defined( HN_PTRSZ_64 )
#if defined( _BB_PSZ ) && _BB_PSZ == 8
#define HN_PTRSZ_64
#elif defined( __POINTER_WIDTH__ ) && __POINTER_WIDTH__ == 64
#define HN_PTRSZ_64
#endif
#endif /* !defined( HN_PTRSZ_64 ) */

#if !defined( HN_LONGSZ_32 )
#if defined( _BB_LSZ ) && _BB_LSZ == 4
#define HN_LONGSZ_32
#elif defined( __LONG_WIDTH__ ) && __LONG_WIDTH__ == 32
#define HN_LONGSZ_32
#endif
#endif /* !defined( HN_LONGSZ_32 ) */

#if !defined( HN_LONGSZ_64 )
#if defined( _BB_LSZ ) && _BB_LSZ == 8
#define HN_LONGSZ_64
#elif defined( __LONG_WIDTH__ ) && __LONG_WIDTH__ == 64
#define HN_LONGSZ_64
#endif
#endif /* !defined( HN_LONGSZ_64 ) */

/* employ Bitbound to #define GCC/Clang builtins when unavailable */

#if defined( HN_HAVE_I32 )
#if !defined( __INT32_TYPE__ )
#if defined( _BB_ISZ ) && _BB_ISZ == 4
#define __INT32_TYPE__ int
#elif defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ == 4
#define __INT32_TYPE__ int
#elif defined( _BB_LSZ ) && _BB_LSZ == 4
#define __INT32_TYPE__ long int
#elif defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ == 4
#define __INT32_TYPE__ long int
#endif
#endif /* !defined( __INT32_TYPE__ ) */

#if !defined( __UINT32_TYPE__ )
#if defined( _BB_ISZ ) && _BB_ISZ == 4
#define __UINT32_TYPE__ unsigned int
#elif defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ == 4
#define __UINT32_TYPE__ unsigned int
#elif defined( _BB_LSZ ) && _BB_LSZ == 4
#define __UINT32_TYPE__ long unsigned int
#elif defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ == 4
#define __UINT32_TYPE__ long unsigned int
#endif
#endif /* !defined( __UINT32_TYPE__ ) */
#endif /* defined( HN_HAVE_I32 ) */

#if defined( HN_HAVE_I64 )
#if !defined( __INT64_TYPE__ )
#if defined( _BB_ISZ ) && _BB_ISZ == 8
#define __INT64_TYPE__ int
#elif defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ == 8
#define __INT64_TYPE__ int
#elif defined( _BB_LSZ ) && _BB_LSZ == 8
#define __INT64_TYPE__ long int
#elif defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ == 8
#define __INT64_TYPE__ long int
#elif defined( __SIZEOF_LONG_LONG__ ) && __SIZEOF_LONG_LONG__ == 8
#define __INT64_TYPE__ long long int
#endif
#endif /* !defined( __INT64_TYPE__ ) */

#if !defined( __UINT64_TYPE__ )
#if defined( _BB_ISZ ) && _BB_ISZ == 8
#define __UINT64_TYPE__ unsigned int
#elif defined( __SIZEOF_INT__ ) && __SIZEOF_INT__ == 8
#define __UINT64_TYPE__ unsigned int
#elif defined( _BB_LSZ ) && _BB_LSZ == 8
#define __UINT64_TYPE__ long unsigned int
#elif defined( __SIZEOF_LONG__ ) && __SIZEOF_LONG__ == 8
#define __UINT64_TYPE__ long unsigned int
#elif defined( __SIZEOF_LONG_LONG__ ) && __SIZEOF_LONG_LONG__ == 8
#define __UINT64_TYPE__ long long unsigned int
#endif
#endif /* !defined( __UINT64_TYPE__ ) */
#endif /* defined( HN_HAVE_I64 ) */

#endif /* INC_API__HN_TYPES_DEF_H */
