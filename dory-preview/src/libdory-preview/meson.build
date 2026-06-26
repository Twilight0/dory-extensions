libdory_preview_c = [
  'dory-preview-cover-art.c',
  'dory-preview-file-loader.c',
  'dory-preview-font-loader.c',
  'dory-preview-font-widget.c',
  'dory-preview-pdf-loader.c',
  'dory-preview-sound-player.c',
  'dory-preview-text-loader.c',
  'dory-preview-utils.c',
]

libdory_preview_headers = [
  'dory-preview-cover-art.h',
  'dory-preview-file-loader.h',
  'dory-preview-font-loader.h',
  'dory-preview-font-widget.h',
  'dory-preview-pdf-loader.h',
  'dory-preview-sound-player.h',
  'dory-preview-text-loader.h',
  'dory-preview-utils.h',
]

libdory_preview_enum = gnome.mkenums(
  'libdory_preview_enum',
  c_template: 'dory-preview-enum-types.c.in',
  h_template: 'dory-preview-enum-types.h.in',
  sources: libdory_preview_headers,
)

libdory_preview = shared_library(
  'dory-preview-1.0',
  dependencies: deps,
  sources: [
    libdory_preview_c,
    libdory_preview_enum,
    libdory_preview_headers,
  ],
  install: true,
  install_dir: join_paths(libdir, 'dory-preview'),
  include_directories: include_dirs,
)

# We use that later on to link the dory-preview-start executable against libdory_preview
libdory_preview_shared_link = declare_dependency(
  link_with: libdory_preview,
  dependencies: deps,
)

gnome.generate_gir(
  libdory_preview,
  sources: [
    libdory_preview_c,
    libdory_preview_enum,
    libdory_preview_headers,
  ],
  nsversion: '1.0',
  namespace: 'DoryPreview',
  symbol_prefix: 'dory_preview',
  identifier_prefix: 'DoryPreview',
  includes: [
    'Clutter-1.0',
    'GstPbutils-1.0',
    'GstTag-1.0',
    'GdkPixbuf-2.0',
    'Gtk-3.0',
    'GtkSource-4',
    'XreaderDocument-1.5',
  ],
  install: true,
  install_dir_gir: join_paths(datadir, 'dory-preview', 'gir-1.0'),
  install_dir_typelib: join_paths(libdir, 'dory-preview', 'girepository-1.0'),
)
