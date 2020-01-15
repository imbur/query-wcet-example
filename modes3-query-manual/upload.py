#!/usr/bin/python3

import os
import subprocess

subprocess.Popen('python3 /home/marci/git/essence/util-scripts/uf2conv.py "qemu/modes3-query-manual"', cwd = os.path.dirname(os.path.realpath(__file__)), shell = True )
