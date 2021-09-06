/****************************************************************************\
 *                          Hinterlib™ stdio piper                          *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include "piper.h"

#include <stdio.h>
#include <uni/err.h>

int uni_piper_read( void * data, ptri data_sz, ptri * data_rsz )
{
	if( data == NULL )
	{
		uni_die( );
	}

	{
		size_t r = fread( data, 1, data_sz, stdin );

		if( r < data_sz )
		{
			if( feof( stdin ) )
			{
				if( data_rsz )
				{
					*data_rsz = r;
				}
			}
		}

		return r < data_sz
			? ( feof( stdin ) ? UNI_PIPER_EOF : UNI_PIPER_ERROR )
			: UNI_PIPER_SUCCESS;
	}
}
