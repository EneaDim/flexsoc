#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""
\file help_doc.py
\brief Print the project's HELP banner.
\details
  Minimal script that prints a help message describing how to generate:
    - the .hjson template,
    - the documentation,
    - and the regmap.

  Coloring is automatic when stdout is a TTY. Set NO_COLOR to disable.
"""

import sys
from common import colorize

# --- internals kept tiny on purpose -----------------------------------------

HELP = """
************************************************************

****************            HELP            ****************

************************************************************

- HJSON SETUP
  • Run "make hjson" to create the .hjson template which
    will be used to generate both doc and regmap.

- DOCUMENTATION
  • Run "make doc" to generate the markdown documentation file
    from the .hjson file created before.

- REGMAP
  • Run "make reg" to generate the regmap file for SoC integration
    with a TLUL interconnect–based system.

"""

if __name__ == "__main__":
    sys.stdout.write(colorize(HELP))
