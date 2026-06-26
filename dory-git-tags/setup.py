#!/usr/bin/python3

# dory-git-tags - Git integration for Dory file manager

from setuptools import setup

setup( packages=[],
    name         = "dory-git-tags",
    version      = "1.0.0",
    description  = "Git integration extension for Dory file manager",
    author       = "Twilight",
    author_email = "",
    url          = "https://github.com/Twilight0/dory-extensions",
    license      = "GPL3",

    data_files   = [
        ('/usr/share/dory-python/extensions', ['dory-extension/dory_git_tags.py'])
    ]
)
