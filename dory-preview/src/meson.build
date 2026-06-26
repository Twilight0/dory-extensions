gnome = import('gnome')

dory_preview_sources = [
  'main.c',
]

deps = [
  clutter_dep,
  clutter_gst_dep,
  clutter_gtk_dep,
  xreader_document_dep,
  xreader_view_dep,
  freetype_dep,
  gdk_pixbuf_dep,
  cjs_dep,
  glib_dep,
  gstreamer_dep,
  gstreamer_pbutils_dep,
  gstreamer_tag_dep,
  gtk_dep,
  gtksourceview_dep,
  introspection_dep,
  musicbrainz_dep,
  webkit_dep,
]

# This actually doesn't do anything,
# but main.c includes config.h, so we need to have some value in it
conf_h = configuration_data()
conf_h.set_quoted(
  'PACKAGE_NAME',
  'dory-preview',
)

configure_file(
  output: 'config.h',
  configuration: conf_h,
)

# Include the just generated config.h
include_dirs = [
  include_directories('.'),
]

# Compile libdory-preview and its introspection data
subdir('libdory-preview')

dory_preview_resources = gnome.compile_resources(
    'dory-preview-resources',
    'org.dory.Preview.gresource.xml',
    c_name: 'dory_preview',
)

dory_preview_sources += dory_preview_resources

executable(
  'dory-preview-start',
  dory_preview_sources,
  # link against the just built libdory-preview
  dependencies: libdory_preview_shared_link,
  install: true,
  install_dir: libexecdir,
)

conf = configuration_data()

conf.set(
  'pkgdatadir',
  join_paths(datadir, 'dory-preview'),
)
conf.set(
  'pkglibdir',
  join_paths(libdir, 'dory-preview'),
)
conf.set(
  'libexecdir',
  libexecdir,
)

dory_preview_bin = configure_file(
  input: 'dory-preview.in',
  output: 'dory-preview',
  configuration: conf,
)

install_data(
  dory_preview_bin,
  install_mode: 'rwxr-xr-x',
  install_dir: bindir,
)

# Install the Javascript components without installing path.js.in as well
install_subdir(
  'js',
  install_dir: join_paths(datadir, 'dory-preview'),
  exclude_files: 'util/path.js.in',
)

js_conf = configuration_data()

js_conf.set(
  'localedir',
  join_paths(datadir, 'locale'),
)

js_conf.set(
  'pkgdatadir',
  join_paths(datadir, 'dory-preview'),
)

configure_file(
  input: 'js/util/path.js.in',
  output: 'path.js',
  configuration: js_conf,
  install_dir: join_paths(datadir, 'dory-preview', 'js', 'util'),
)
