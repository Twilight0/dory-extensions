#!/usr/bin/python3
# -*- coding: utf-8 -*-
# dory-pastebin - Dory extension to paste a file to a pastebin service
# Written by:
#    Alessio Treglia <quadrispro@ubuntu.com>
# Copyright (C) 2009-2010, Alessio Treglia
#
# This package is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This package is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this package; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
#

from setuptools import setup

def get_app_path_files():
    return [
        'data/dory-pastebin-configurator.ui',
        'src/dory-pastebin-configurator.py'
    ]

data_files = [
    ('/usr/share/icons/hicolor/scalable/apps', ['data/dory-pastebin.svg']),
    ('/usr/share/icons/hicolor/48x48/apps', ['data/dory-pastebin.png']),
    ('/usr/share/glib-2.0/schemas', ['data/dory-pastebin.gschema.xml']),
    ('/usr/bin', ['src/dory-pastebin-configurator']),
    ('/usr/share/dory-pastebin', get_app_path_files()),
    ('/usr/share/dory-python/extensions', ['src/dory-pastebin.py'])
]

pkg_short_dsc = "Dory extension to send files to a pastebin"
pkg_long_dsc = """dory-pastebin is a Dory extension written in Python, which allows users to upload text-only files to a pastebin service just by right-clicking on them. Users can also add their favorite service just by creatine new presets."""

setup(name='dory-pastebin', packages=[],
      version='6.7.0',
      author='Linux Mint',
      author_email='root@linuxmint.com',
      license='GPL-2',
      url='https://github.com/linuxmint/dory-extensions',
      description=pkg_short_dsc,
      long_description=pkg_long_dsc,
      data_files=data_files
)
