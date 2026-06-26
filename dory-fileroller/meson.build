project('dory-fileroller',
    'c',
    version: '6.7.0',
    meson_version: '>=0.56.0'
)

project_url = 'https://github.com/linuxmint/dory-extensions'


gnome       = import('gnome')
pkgconfig   = import('pkgconfig')

config = configuration_data()

################################################################################
# Find libdory-extensions

libdory = dependency('libdory-extension', version: '>=2.0.0')
libdory_extension_dir = libdory.get_variable(pkgconfig: 'extensiondir')
libdory_extension_ver = libdory.version().split('.')

config.set('DORY_VERSION_MAJOR', libdory_extension_ver[0])
config.set('DORY_VERSION_MINOR', libdory_extension_ver[1])
config.set('DORY_VERSION_MICRO', libdory_extension_ver[2])

glib = dependency('glib-2.0', version: '>=2.14.0')

################################################################################
# Generic stuff

config.set_quoted('GETTEXT_PACKAGE', 'dory-extensions')
config.set_quoted('GNOMELOCALEDIR', get_option('prefix')/get_option('datadir')/'locale')

add_project_arguments('-DHAVE_CONFIG_H', language: 'c')
configure_file(
    output: 'config.h',
    configuration: config,
)

rootInclude = include_directories('.')

subdir('src')
