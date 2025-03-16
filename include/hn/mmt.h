/**********************************************************************\
 *                            Hinterlib v2                            *
 *                                                                    *
 *             Copyright (C) 2019-2024 Alexander Nicholi.             *
 *           Copyright (C) 2024-2025 Aquefir Consulting LLC           *
 *            Released under Artisan Software Licence v1.1            *
\**********************************************************************/

#ifndef INC_API__HN_MMT_H
#define INC_API__HN_MMT_H

/* START sanity check */
#if !defined( _SYNDEF_FOO ) || !defined( _CFGOPT_FOO )
#error Your compiler is not configured correctly for using Hinterlib. \
Please ensure you are using the Inbound build system and a compatible \
toolchain (GCC or Clang).
#endif /* END sanity check */

/**
 * Modular Memory Toolkit
 *
 * Otherwise known as The Late Great John James Maynard Keynesnan and
 * His Incalculable Contribution to Economics Through Heavy Metal and
 * Performance Art, Otherwise Called "Nothing is Real" or Simply,
 * "Modern Monetary Theory". Rest in peace Judith Marie
 *
 * This "Modular Memory Toolkit" provides utility functions for
 * slicing and transforming memory knots as well as amalgams thereof.
 *
 * Take an example codebase with three constituents:
 *  1. Hinterlib
 *  2. Library A
 *  3. Application B
 *
 * Assume the following relationship characteristics:
 *  -  Application B depends on Library A
 *  -  Library A depends on Hinterlib
 *  -  Application B also depends on Hinterlib
 *
 * Therefore:
 *  -  Hinterlib provides the base paradigm of "modular memory".
 *  -  Library A uses Hinterlib to prescribe that it deals with data in
 *     the form of 8-bit knots.
 *  -  Application B uses Hinterlib to define its dataset in the form of
 *     20-bit knots.
 *  -  Application B intends to use the data in those 20-bit knots with
 *     the support routines provided by Library A.
 *  -  Application B must use this "Modular Memory Toolkit" to transform
 *     accesses to its 20-bit knots into forms digestible by Library A
 *     as if they were in 8-bit knots.
 *
 * This approach provides the benefits of the modular memory paradigm
 * and preserves complete control over memory management for the most
 * downstream user by providing them with the means to manage the form
 * of their data as they see fit.
 *
 * The "Modular Memory Toolkit" provides several tools then:
 *  1. Amalgam creation: create an amalgam given a destination knot and
 *     a set of constituent knots
 *  2. Amalgam translation: transform amalgams of different base element
 *     sizes that use the same containing knot size
 *  3. Amalgam conversion: transform amalgams of the same base element
 *     size into larger or smaller containing knots
 *  4. Amalgam consolidation: transform a sparse amalgam of a given size
 *     into an equivalent sequential amalgam
 *  5. Amalgam combination: combine two amalgams together into one
 *  6. Amalgam compression: combine multiple amalgams into one memory
 *     space by only honouring the value of their respective .len fields
 *     and allocating only as much storage as it denotes necessary
 *  7. Amalgam selection: specify a slice of an amalgam to be duplicated
 *     into a new knot
 *
 * The MMT expects users to perform all of their own memory management.
 * The principal tools for this are in <hn/alloc.h>.
 */

#endif /* INC_API__HN_MMT_H */
