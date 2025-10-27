/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#include <hn/memops.h>
#include <string.h>

void hn_memset( hn_u8 oct, hn_ptri buf_sz, void * buf )
{
	memset( buf, oct, buf_sz );
}

void hn_memcpy( void * dst, hn_ptri sz, void * src )
{
	memcpy( dst, src, sz );
}

hn_bl hn_memequ( void * buf_a, hn_ptri bufs_sz, void * buf_b )
{
	return (memcmp( buf_a, buf_b, bufs_sz ) == 0) ? HN_TRUE :
	       HN_FALSE;
}
