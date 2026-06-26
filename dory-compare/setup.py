#!/usr/bin/python3

# Dory Compare

from setuptools import setup

# Setup stage
setup( packages=[],
    name         = "dory-compare",
    version      = "6.7.0",
    description  = "Context menu comparison extension for Dory file manager",
    author       = "Linux Mint",
    author_email = "root@linuxmint.com",
    url          = "https://github.com/linuxmint/dory-extensions",
    license      = "GPL3",

    # See debian/control for install-depends - this is useless here, except as reference.
    # install_requires (and only works with python modules.  It's equally as bad to have
    # some deps here, then draw them into debian/control using {python3:Depends} and add
    # them to our non-python depends.

    # install_requires = ['gir1.2-dory-3.0 >=3.8',
    #                     'python-dory >=3.8',
    #                     'meld'],
    data_files   = [
        ('/usr/share/dory-python/extensions', ['src/dory-compare.py']),
        ('/usr/share/dory-compare', ['src/dory-compare-preferences.py', 'src/utils.py']),
        ('/usr/bin', ['src/dory-compare-preferences'])
    ]
)
