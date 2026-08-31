/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_CHECKED_H
#define INC_API__HN_CHECKED_H

#if defined(__has_builtin)
#if __has_builtin( __builtin_add_overflow )
#if !defined(HN_CHECKED_ADD)
#define HN_CHECKED_ADD( _a, _b, _c ) \
	__builtin_add_overflow( ( _a ), ( _b ), ( _c ) )
#endif /* !defined( HN_CHECKED_ADD ) */

#if !defined(HN_CHECKED_SUB)
#define HN_CHECKED_SUB( _a, _b, _c ) \
	__builtin_sub_overflow( ( _a ), ( _b ), ( _c ) )
#endif /* !defined( HN_CHECKED_SUB ) */

#if !defined(HN_CHECKED_MUL)
#define HN_CHECKED_MUL( _a, _b, _c ) \
	__builtin_mul_overflow( ( _a ), ( _b ), ( _c ) )
#endif /* !defined( HN_CHECKED_MUL ) */
#endif /* __has_builtin( __builtin_add_overflow ) */
#endif /* defined( __has_builtin ) */

#endif /* INC_API__HN_CHECKED_H */
