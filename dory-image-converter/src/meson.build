libdory_image_converter_sources = [
    'image-converter.c',
    'dory-image-converter.c',
    'dory-image-resizer.c',
    'dory-image-rotator.c',
]

libdory_image_converter = library('dory-image-converter',
    libdory_image_converter_sources,
    include_directories: rootInclude,
    dependencies: [
        libdory,
        gtk3,
    ],
    install: true,
    install_dir: libdory_extension_dir,
)
