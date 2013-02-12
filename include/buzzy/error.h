/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the LICENSE.txt file in this distribution for license
 * details.
 * ----------------------------------------------------------------------
 */

#ifndef BUZZY_ERROR_H
#define BUZZY_ERROR_H

#include <libcork/core.h>


/*-----------------------------------------------------------------------
 * Error handling
 */

/* hash of "buzzy.h" */
#define BZ_ERROR  0xb8a66a70

enum bz_error {
    BZ_INVALID_VERSION
};

#define bz_set_error(code, ...) (cork_error_set(BZ_ERROR, code, __VA_ARGS__))
#define bz_invalid_version(...) \
    bz_set_error(BZ_INVALID_VERSION, __VA_ARGS__)


#endif /* BUZZY_ERROR_H */