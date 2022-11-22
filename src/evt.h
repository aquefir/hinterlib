/*****************************************************************************\
 *                                 Hinterlib                                 *
 *                                                                           *
 *                      Copyright (C) 2019-2022 Aquefir                      *
 *                        Released under BSD-2-Clause                        *
\*****************************************************************************/

#ifndef INC__UNI_EVT_H
#define INC__UNI_EVT_H

struct uni_evt
{
#ifdef CFG_LINUX
	int fd;
#endif /* CFG_LINUX */
};

#endif /* INC__UNI_EVT_H */
