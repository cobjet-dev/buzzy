# -*- coding: utf-8 -*-
# ----------------------------------------------------------------------
# Copyright © 2012, RedJack, LLC.
# All rights reserved.
#
# Please see the COPYING file in this distribution for license details.
# ----------------------------------------------------------------------

__all__ = (
    "os",
    "pkgdb",
    "version",
)

import os as _os
pkgdb = _os.getcwd()

import buzzy.version
version = buzzy.version.version

os = None
