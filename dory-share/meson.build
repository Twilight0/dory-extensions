project('dory-share',
    'c',
    version: '6.7.0',
    meson_version: '>=0.56.0'
)

project_url = 'https://github.com/linuxmint/dory-extensions'


gnome     = import('gnome')
pkgconfig = import('pkgconfig')

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
# Extension dependencies

libcinnamon = dependency('cinnamon-desktop', version: '>=3.0.0')

interfaces_dir = get_option('datadir') / meson.project_name() / 'interfaces'
config.set_quoted('INTERFACES_DIR', get_option('prefix') / interfaces_dir)

################################################################################
# Specific stuff to the extension

gettext_package = 'dory-extensions'
config.set_quoted('GETTEXT_PACKAGE', gettext_package)
config.set_quoted('DORY_SHARE_LOCALEDIR', get_option('prefix') / get_option('localedir'))
config.set_quoted('PKGDATADIR', get_option('prefix')/get_option('datadir')/meson.project_name())

add_project_arguments('-DG_LOG_DOMAIN="Dory-Share"', language: 'c')

add_project_arguments('-DHAVE_CONFIG_H', language: 'c')
configure_file(
    output: 'config.h',
    configuration: config,
)

rootInclude = include_directories('.')

subdir('interfaces')
subdir('src')
