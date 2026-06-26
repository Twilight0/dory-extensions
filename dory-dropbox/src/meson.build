dory_dropbox_sources = [
    'dropbox-client-util.c',
    'dropbox-client.c',
    'dropbox-command-client.c',
    'dropbox.c',
    'dory-dropbox-hooks.c',
    'dory-dropbox.c',
]

libdory_dropbox = shared_library('dory-dropbox',
    dory_dropbox_sources,
    include_directories: rootInclude,
    dependencies: [
        glib,
        libdory,
    ],
    install: true,
    install_dir: libdory_extension_dir,
)
