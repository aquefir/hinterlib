/****************************************************************************\
 *                 Mersenne-Twister Algorithm 19937, 32-bit                 *
 *                                                                          *
 *                      Copyright © 2019-2021 Aquefir.                      *
 *                       Released under BSD-2-Clause.                       *
\****************************************************************************/

#include <tes/battery.h>

#include <mt19937/random.h>

TES_OPEN( );

struct mt_prng * rng = mt_prng_init( );

TES_CLOSE( );
