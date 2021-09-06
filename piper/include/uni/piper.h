/****************************************************************************\
 *                          Hinterlib™ stdio piper                          *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#ifndef INC_API__UNI_PIPER_H
#define INC_API__UNI_PIPER_H

#include <uni/types/int.h>

enum
{
	UNI_PIPER_SUCCESS,
	UNI_PIPER_EOF,
	UNI_PIPER_ERROR
};

int uni_piper_read( void *, ptri, ptri * );
int uni_piper_write( void *, ptri, ptri * );

#if !defined( UNI_PIPER_NOHEAP )
int uni_piper_readall( void *, ptri * );
int uni_piper_writeall( void *, ptri * );
#endif /* !defined( UNI_PIPER_NOHEAP ) */

#endif /* INC_API__UNI_PIPER_H */
