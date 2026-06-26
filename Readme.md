# Dory Extensions

A suite of extensions for the [Dory file manager](https://github.com/Twilight0/dory), forked from Nemo extensions with all `nemo`/`Nemo`/`NEMO` references renamed to `dory`/`Dory`/`DORY`.

## Installation

### Arch Linux (AUR)

Install individual extensions or all at once:

```bash
# Individual
yay -S dory-dropbox-git
yay -S dory-terminal-git

# All extensions
yay -S dory-dropbox-git dory-fileroller-git dory-image-converter-git \
       dory-share-git dory-repairer-git dory-python-git dory-preview-git \
       dory-seahorse-git dory-compare-git dory-terminal-git \
       dory-emblems-git dory-audio-tab-git dory-media-columns-git \
       dory-pastebin-git
```

## Extensions

### Cloud & Sharing
| Extension | Description | Type |
|-----------|-------------|------|
| dory-dropbox | Dropbox integration | Meson/C |
| dory-share | Samba/Windows folder sharing | Meson/C |

### File Management
| Extension | Description | Type |
|-----------|-------------|------|
| dory-fileroller | Archive manager integration (file-roller) | Meson/C |
| dory-image-converter | Image resizing/rotating from context menu | Meson/C |
| dory-repairer | Filename encoding repair | Meson/C |
| dory-compare | Side-by-side file comparison | Python |

### Preview & Info
| Extension | Description | Type |
|-----------|-------------|------|
| dory-preview | Full file preview (HTML, documents) | Meson/C |
| dory-seahorse | PGP/GPG encryption management | Meson/C |
| dory-audio-tab | Audio metadata properties tab | Python |
| dory-media-columns | Audio/video metadata in list view | Python |

### UI Enhancements
| Extension | Description | Type |
|-----------|-------------|------|
| dory-terminal | Integrated terminal (F4) | Python |
| dory-emblems | Custom emblem icons for files | Python |
| dory-pastebin | Upload files to pastebin services | Python |

### Python Framework
| Extension | Description | Type |
|-----------|-------------|------|
| dory-python | Python extension bindings for Dory | Meson/C |

## Dependencies

Most extensions require `dory-python` to be installed first, as they use the Python extension framework it provides.

C-based extensions link against `libdory-extension` and are installed to `/usr/lib/dory/extensions-3.0/`.

Python extensions are installed to `/usr/share/dory-python/extensions/`.

## Status

- dory-wallpaper: built in to Dory
- dory-dropbox: functional
- dory-fileroller: functional
- dory-seahorse: functional
- dory-share: functional
- dory-pastebin: functional
- dory-compare: functional
- dory-python: functional
- dory-terminal: functional
- dory-repairer: functional
- dory-image-converter: functional
- dory-audio-tab: functional
- dory-media-columns: functional
- dory-emblems: functional
- dory-preview: functional
