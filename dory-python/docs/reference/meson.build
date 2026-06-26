
docConf = configuration_data()
docConf.set('VERSION', meson.project_version())

configure_file(
  input : 'entities.docbook.in',
  output: 'entities.docbook',
  configuration: docConf
)


content_files = [
    'entities.docbook.in'
]

gnome.gtkdoc('dory-python',
  main_xml: 'dory-python-ref.xml',
  src_dir: 'src',
  content_files: content_files,
  install: true,
  install_dir: 'dory-python'
)
