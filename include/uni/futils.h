/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC_API__UNI_FUTILS_H
#define INC_API__UNI_FUTILS_H

#include <uni/decl.h>
#include <uni/types/opt/int.h>
#include <uni/types/int.h>

UNI_OPTION( ptri ) uni_filesz( const char * );
int uni_buffile( const char *, u8 *, ptri );
int uni_loadfile( const char *, u8 **, ptri * );

#endif /* INC_API__UNI_FUTILS_H */
