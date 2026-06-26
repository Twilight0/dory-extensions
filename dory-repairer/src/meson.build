libdory_filename_repairer_sources = [
    'filename-repairer.c',
    'dory-filename-repairer.c',
]

dory_filename_repairer_sources = [
    'encoding-dialog.c',
    'repair-dialog.c',
    'repairer.c',
]


libdory_filename_repairer = library('dory-filename-repairer',
    libdory_filename_repairer_sources,
    include_directories: rootInclude,
    dependencies: [
        libdory,
        gtk3,
    ],
    install: true,
    install_dir: libdory_extension_dir,
)

dory_filename_repairer = executable('dory-filename-repairer',
    dory_filename_repairer_sources,
    include_directories: rootInclude,
    dependencies: [
        gtk3,
    ],
    install: true,
)

install_data(
    'encoding-dialog.ui',
    'repair-dialog.ui',
    install_dir: join_paths(get_option('datadir'), meson.project_name())
)
