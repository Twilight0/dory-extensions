dory_fileroller_sources = [
    'fileroller-module.c',
    'dory-fileroller.c',
]

libdory_fileroller = shared_library('dory-fileroller',
    dory_fileroller_sources,
    include_directories: rootInclude,
    dependencies: [
        libdory,
    ],

    install: true,
    install_dir: libdory_extension_dir,
)
