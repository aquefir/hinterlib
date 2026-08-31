/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_INI_H
#define INC_API__HN_INI_H

#include "ct.h"
#include "types/char.h"

hn_chr ** hn_ini_getsectlist( struct hn_ct * );

hn_ptri hn_ini_getsectcount( struct hn_ct * );

#endif /* INC_API__HN_INI_H */
