# -*- coding: utf-8 -*-
# ----------------------------------------------------------------------
# Copyright © 2012, RedJack, LLC.
# All rights reserved.
#
# Please see the COPYING file in this distribution for license details.
# ----------------------------------------------------------------------


from __future__ import absolute_import

import buzzy.yaml

class Autotools(buzzy.yaml.Fields):
    def fields(self):
        yield "type"

    def create_packages(self, recipe):
        raise NotImplementedError
