#!/usr/bin/python3

from setuptools import setup

# Create data files

# Setup stage
setup( packages=[],
    name         = "dory-audio-tab",
    version      = "6.7.0",
    description  = "View audio tag information from the file manager's properties tab",
    author       = "Linux Mint",
    author_email = "root@linuxmint.com",
    url          = "https://github.com/linuxmint/dory-extensions",
    license      = "GPL3",

    # See debian/control for install-depends - this is useless here, except as reference.
    # install_requires (and only works with python modules.  It's equally as bad to have
    # some deps here, then draw them into debian/control using {python3:Depends} and add
    # them to our non-python depends.

    # install_requires = [
    #     'gir1.2-dory-3.0',
    #     'gir1.2-gtk-3.0',
    #     'gir1.2-glib-2.0',
    #     'python-dory',
    #     'python3-mutagen'
    # ]

    data_files   = [
        ('/usr/share/dory-python/extensions', ['dory-extension/dory-audio-tab.py']),
        ('/usr/share/dory-audio-tab',         ['dory-extension/dory-audio-tab.glade'])
    ]
)
