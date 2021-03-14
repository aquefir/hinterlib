/****************************************************************************\
 *                         unilib base declarations                         *
 *                                                                          *
 *                      Copyright © 2019-2020 Aquefir                       *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_TYPES_OPT_COMMON_H
#define INC_API__UNI_TYPES_OPT_COMMON_H

#define UNI_OPTION( TYPE ) struct opt_##TYPE
#define UNI_OPTIONP( TYPE ) struct optp_##TYPE
#define UNI_DECL_OPT( TYPE ) \
	UNI_OPTION( TYPE ) \
	{ \
		TYPE val; \
		unsigned char is; \
	}; \
	struct _dummy
#define UNI_DECL_OPT_S( TYPE ) \
	UNI_OPTION( TYPE ) \
	{ \
		struct TYPE val; \
		unsigned char is; \
	}; \
	struct _dummy
#define UNI_DECL_OPT_P( TYPE ) \
	UNI_OPTIONP( TYPE ) \
	{ \
		TYPE * val; \
		unsigned char is; \
	}; \
	struct _dummy
#define UNI_DECL_OPT_SP( TYPE ) \
	UNI_OPTIONP( TYPE ) \
	{ \
		struct TYPE * val; \
		unsigned char is; \
	}; \
	struct _dummy

#endif /* INC_API__UNI_TYPES_OPT_COMMON_H */
