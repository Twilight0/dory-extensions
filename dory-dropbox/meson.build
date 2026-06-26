project('dory-dropbox',
    'c',
    version: '6.7.0',
    meson_version: '>=0.56.0'
)

project_url = 'https://github.com/linuxmint/dory-extensions'


cc = meson.get_compiler('c')

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
# Project configuration

project_datadir = get_option('datadir') / meson.project_name()

config.set_quoted('GETTEXT_PACKAGE', 'dory-extensions')
config.set_quoted('PACKAGE_STRING', meson.project_name() )
config.set_quoted('EMBLEMDIR',      get_option('prefix') / project_datadir / 'emblems')
config.set_quoted('DORYICONDIR',    get_option('datadir') / 'dory-dropbox' / 'icons')

c_args = []
c_args += cc.get_supported_arguments('-Wno-deprecated-declarations')

if [ 'debug', 'relwithdebinfo'].contains(get_option('buildtype'))
    c_args += [ '-DND_DEBUG', ]
else
    c_args += [ '-DG_DISABLE_ASSERT', '-DG_DISABLE_CHECKS', ]
endif

add_project_arguments(c_args, language: 'c')

################################################################################
# Generic stuff


add_project_arguments('-DHAVE_CONFIG_H', language: 'c')
configure_file(
    output: 'config.h',
    configuration: config,
)

rootInclude = include_directories('.')

subdir('data')
subdir('src')

install_data('COPYING',
    install_dir: get_option('datadir') / 'licenses' / meson.project_name(),
)
