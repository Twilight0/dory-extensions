#!/usr/bin/python3
# -*- coding: utf-8 -*-
#    dory-git-tags --- Git integration extension for Dory file manager
#    Copyright (C) 2026  Twilight
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

import os
import subprocess
import threading
from urllib import parse

from gi.repository import GObject, Gio, GLib, Dory

from gettext import gettext as _

APP = 'dory-extensions'

# Git status codes -> emblem mapping
# X Y status meaning
# M  [index status]
#   M [worktree status]
# MM both modified
# A  added
# D  deleted
# R  renamed
# C  copied
# U  unmerged
# ?  untracked
# !  ignored

GIT_EMBLEMS = {
    'M':  'emblem-important',       # modified (index)
    'm':  'emblem-readonly',        # modified (worktree only)
    'MM': 'emblem-important',       # modified both
    'A':  'emblem-new',             # added
    'D':  'emblem-urgent',          # deleted
    'R':  'emblem-favorite',        # renamed
    'C':  'emblem-generic',         # copied
    'U':  'emblem-danger',          # unmerged (conflict)
    'UU': 'emblem-danger',          # both modified (conflict)
    '??': 'emblem-synchronizing',   # untracked
    '!!': None,                     # ignored
}

# Cache: directory path -> { relative_path: status_code }
_status_cache = {}
_cache_lock = threading.Lock()


def _find_git_root(path):
    """Find the git root for a given path."""
    try:
        result = subprocess.run(
            ['git', '-C', path, 'rev-parse', '--show-toplevel'],
            capture_output=True, text=True, timeout=5
        )
        if result.returncode == 0:
            return result.stdout.strip()
    except (subprocess.TimeoutExpired, FileNotFoundError):
        pass
    return None


def _read_git_status(git_root):
    """Run git status --porcelain and return a dict of path -> status."""
    try:
        result = subprocess.run(
            ['git', '-C', git_root, 'status', '--porcelain', '-z'],
            capture_output=True, timeout=10
        )
        if result.returncode != 0:
            return {}

        status = {}
        output = result.stdout
        # Split on null bytes, filter empty entries
        entries = [e for e in output.split(b'\x00') if e]
        for entry in entries:
            decoded = entry.decode('utf-8', errors='replace')
            if len(decoded) < 2:
                continue
            # Format: XY path (space between status and path)
            xy = decoded[:2]
            filepath = decoded[3:] if len(decoded) > 3 else decoded[2:]
            filepath = filepath.strip()

            # Skip submodule headers
            if filepath.startswith('diff --git'):
                break

            status[filepath] = xy

        return status
    except (subprocess.TimeoutExpired, FileNotFoundError):
        return {}


def _get_status_for_file(filepath):
    """Get cached git status for a file. Refresh cache if needed."""
    directory = os.path.dirname(filepath)
    git_root = _find_git_root(directory)

    if git_root is None:
        return None

    with _cache_lock:
        if git_root not in _status_cache:
            _status_cache[git_root] = {
                'status': _read_git_status(git_root),
                'root': git_root
            }

    cache_entry = _status_cache[git_root]
    root = cache_entry['root']

    # Make path relative to git root
    try:
        rel_path = os.path.relpath(filepath, root)
    except ValueError:
        return None

    # Also check with trailing slash removed for directories
    rel_path_stripped = rel_path.rstrip('/')

    with _cache_lock:
        status = cache_entry['status']

    return status.get(rel_path_stripped, status.get(rel_path))


def _get_status_summary(directory):
    """Get a summary of git statuses in a directory."""
    git_root = _find_git_root(directory)
    if git_root is None:
        return None

    with _cache_lock:
        if git_root not in _status_cache:
            _status_cache[git_root] = {
                'status': _read_git_status(git_root),
                'root': git_root
            }
        return dict(_status_cache[git_root]['status'])


def _refresh_cache(git_root):
    """Force refresh the cache for a git root."""
    with _cache_lock:
        _status_cache[git_root] = {
            'status': _read_git_status(git_root),
            'root': git_root
        }


def _run_git_async(directory, args, callback=None):
    """Run a git command asynchronously."""
    def _thread():
        try:
            result = subprocess.run(
                ['git', '-C', directory] + args,
                capture_output=True, text=True, timeout=30
            )
            if callback:
                GLib.idle_add(callback, result.returncode, result.stdout, result.stderr)
        except (subprocess.TimeoutExpired, FileNotFoundError) as e:
            if callback:
                GLib.idle_add(callback, -1, '', str(e))
    threading.Thread(target=_thread, daemon=True).start()


class DoryGitTagsExtension(GObject.GObject, Dory.InfoProvider, Dory.MenuProvider, Dory.NameAndDescProvider):
    """Git integration extension for Dory file manager."""

    def __init__(self):
        pass

    def update_file_info(self, file):
        if file.get_uri_scheme() != 'file':
            return

        filepath = parse.unquote(file.get_uri()[7:])
        status = _get_status_for_file(filepath)

        if status is None:
            return

        # Map status codes to emblems
        for code, emblem in GIT_EMBLEMS.items():
            if status.startswith(code) and emblem is not None:
                file.add_emblem(emblem)
                return

    def get_file_items(self, window, files):
        if not files:
            return []

        # Get paths
        paths = []
        for f in files:
            if f.get_uri_scheme() != 'file':
                continue
            paths.append(parse.unquote(f.get_uri()[7:]))

        if not paths:
            return []

        # Check if we're in a git repo
        git_root = _find_git_root(paths[0])
        if git_root is None:
            return []

        locale_locale = __import__('locale')
        locale_locale.setlocale(locale_locale.LC_ALL, '')
        from gettext import bindtextdomain, textdomain
        bindtextdomain(APP, '/usr/share/locale')
        textdomain(APP)

        items = []

        # Git Add (for untracked or modified files)
        item_add = Dory.MenuItem(
            name="DoryGitTags::GitAdd",
            label=_('Git Add'),
            tip=_('Stage file(s) for commit')
        )
        item_add.connect('activate', self._on_git_add, paths)
        items.append(item_add)

        # Git Diff
        item_diff = Dory.MenuItem(
            name="DoryGitTags::GitDiff",
            label=_('Git Diff'),
            tip=_('Show changes in selected file(s)')
        )
        item_diff.connect('activate', self._on_git_diff, paths)
        items.append(item_diff)

        # Git Log
        item_log = Dory.MenuItem(
            name="DoryGitTags::GitLog",
            label=_('Git Log'),
            tip=_('Show commit history for file(s)')
        )
        item_log.connect('activate', self._on_git_log, paths)
        items.append(item_log)

        # Git Reset (for staged files)
        item_reset = Dory.MenuItem(
            name="DoryGitTags::GitReset",
            label=_('Git Reset'),
            tip=_('Unstage file(s)')
        )
        item_reset.connect('activate', self._on_git_reset, paths)
        items.append(item_reset)

        return items

    def get_background_items(self, window, item):
        if item is None:
            return []

        if item.get_uri_scheme() != 'file':
            return []

        directory = parse.unquote(item.get_uri()[7:])

        git_root = _find_git_root(directory)
        if git_root is None:
            return []

        locale_locale = __import__('locale')
        locale_locale.setlocale(locale_locale.LC_ALL, '')
        from gettext import bindtextdomain, textdomain
        bindtextdomain(APP, '/usr/share/locale')
        textdomain(APP)

        items = []

        # Git Commit
        item_commit = Dory.MenuItem(
            name="DoryGitTags::GitCommit",
            label=_('Git Commit'),
            tip=_('Commit staged changes')
        )
        item_commit.connect('activate', self._on_git_commit, directory)
        items.append(item_commit)

        # Git Push
        item_push = Dory.MenuItem(
            name="DoryGitTags::GitPush",
            label=_('Git Push'),
            tip=_('Push commits to remote')
        )
        item_push.connect('activate', self._on_git_push, directory)
        items.append(item_push)

        # Git Pull
        item_pull = Dory.MenuItem(
            name="DoryGitTags::GitPull",
            label=_('Git Pull'),
            tip=_('Pull changes from remote')
        )
        item_pull.connect('activate', self._on_git_pull, directory)
        items.append(item_pull)

        # Git Status
        item_status = Dory.MenuItem(
            name="DoryGitTags::GitStatus",
            label=_('Git Status'),
            tip=_('Show working tree status')
        )
        item_status.connect('activate', self._on_git_status, directory)
        items.append(item_status)

        # Refresh emblems
        item_refresh = Dory.MenuItem(
            name="DoryGitTags::RefreshEmblems",
            label=_('Refresh Git Status'),
            tip=_('Refresh git status emblems')
        )
        item_refresh.connect('activate', self._on_refresh, directory)
        items.append(item_refresh)

        return items

    def _on_git_add(self, menu, paths):
        directory = os.path.dirname(paths[0])
        _run_git_async(directory, ['add'] + paths, self._on_command_complete)

    def _on_git_diff(self, menu, paths):
        directory = os.path.dirname(paths[0])
        _run_git_async(directory, ['diff'] + paths, self._on_diff_complete)

    def _on_git_log(self, menu, paths):
        directory = os.path.dirname(paths[0])
        _run_git_async(directory, ['log', '--oneline', '-20', '--'] + paths, self._on_log_complete)

    def _on_git_reset(self, menu, paths):
        directory = os.path.dirname(paths[0])
        _run_git_async(directory, ['reset', 'HEAD', '--'] + paths, self._on_command_complete)

    def _on_git_commit(self, menu, directory):
        _run_git_async(directory, ['commit'], self._on_command_complete)

    def _on_git_push(self, menu, directory):
        _run_git_async(directory, ['push'], self._on_command_complete)

    def _on_git_pull(self, menu, directory):
        _run_git_async(directory, ['pull'], self._on_command_complete)

    def _on_git_status(self, menu, directory):
        _run_git_async(directory, ['status'], self._on_status_complete)

    def _on_refresh(self, menu, directory):
        git_root = _find_git_root(directory)
        if git_root:
            _refresh_cache(git_root)

    def _on_command_complete(self, returncode, stdout, stderr):
        pass

    def _on_diff_complete(self, returncode, stdout, stderr):
        if stdout:
            print(stdout)

    def _on_log_complete(self, returncode, stdout, stderr):
        if stdout:
            print(stdout)

    def _on_status_complete(self, returncode, stdout, stderr):
        if stdout:
            print(stdout)

    def get_name_and_desc(self):
        description = _("Git integration: status emblems, add, diff, commit, push, pull")
        return [(f"dory-git-tags:::{description}")]
