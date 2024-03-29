/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_UTF8_H
#define INC_API__UNI_UTF8_H

#include <uni/types/int.h>

struct uni_u8pos
{
	ptri pos;
	u8 mid;
};

int uni_u8dec( char *, char32 * );
int uni_u8enc( char32, char * );
s32 uni_u8decsz( char );
u32 uni_u8encsz( char32 );

struct uni_u8pos uni_u8by2cp( const char *, ptri );
ptri uni_u8cp2by( const char *, ptri );
int uni_validu8( const char * );

#endif /* INC_API__UNI_UTF8_H */
