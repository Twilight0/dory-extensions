
libdory_share = shared_library('dory-share',
    'shares.c',
    'dory-share.c',
    include_directories: rootInclude,
    dependencies: [
        glib,
        libdory,
        libcinnamon,
    ],

    install: true,
    install_dir: libdory_extension_dir,
)


# Install data
install_data(
    'install-samba',
    'check-directory-permissions',
    install_dir: get_option('datadir') / meson.project_name(),
    install_mode: 'rwxr-xr-x'
)

data_conf = configuration_data()
data_conf.set('pkgdatadir',
    get_option('prefix') / get_option('datadir') / meson.project_name()
)

install_data(
    configure_file(
        input : 'org.dory.share.samba_install.policy.in',
        output: 'org.dory.share.samba_install.policy',
        configuration: data_conf,
    ),
    install_dir: get_option('datadir') / 'polkit-1' / 'actions'
)
