#!/usr/bin/python3

# Dory Terminal

from setuptools import setup

# Setup stage
setup( packages=[],
    name         = "dory-terminal",
    version      = "6.7.0",
    description  = "Embedded VTE terminal for Dory file manager",
    author       = "Linux Mint",
    author_email = "root@linuxmint.com",
    url          = "https://github.com/linuxmint/dory-extensions",
    license      = "GPL3",

    # See debian/control for install-depends - this is useless here, except as reference.
    # install_requires (and only works with python modules.  It's equally as bad to have
    # some deps here, then draw them into debian/control using {python3:Depends} and add
    # them to our non-python depends.

    # install_requires = ['python-dory (>= 1.0)',
    #                     'gir1.2-dory-3.0',
    #                     'gir1.2-vte-2.91',
    #                     'gir1.2-gtk-3.0 (>= 3.8.4~)',
    #                     'gir1.2-glib-2.0 (>= 1.38.0~)',
    #                     'gir1.2-xapp-1.0 (>= 3.8.0)'],

    data_files = [
        ('/usr/share/dory-python/extensions', ['src/dory_terminal.py']),
        ('/usr/bin',                          ['src/dory-terminal-prefs']),
        ('/usr/share/dory-terminal',          ['src/dory-terminal-prefs.py',
                                               'pixmap/logo_120x120.png']),
        ('/usr/share/glib-2.0/schemas',       ['src/org.dory.extensions.dory-terminal.gschema.xml'])
    ]
)
