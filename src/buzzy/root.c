/* -*- coding: utf-8 -*-
 * ----------------------------------------------------------------------
 * Copyright © 2013-2014, RedJack, LLC.
 * All rights reserved.
 *
 * Please see the COPYING file in this distribution for license details.
 * ----------------------------------------------------------------------
 */

#include <libcork/cli.h>

#include "buzzy/commands.h"

static struct cork_command  *subcommands[] = {
    &buzzy_build,
    &buzzy_doc,
    &buzzy_get,
    &buzzy_info,
    &buzzy_install,
    &buzzy_raw,
    &buzzy_test,
    &buzzy_uninstall,
    &buzzy_update,
    &buzzy_vercmp,
    NULL
};

CORK_LOCAL struct cork_command  buzzy_root =
    cork_command_set("buzzy", NULL, NULL, subcommands);
