sources = [
    'dory-python.c',
    'dory-python.h',
    'dory-python-object.c',
    'dory-python-object.h'
]

mod = shared_module('dory-python',
    sources  : sources,
    include_directories: [top_inc],
    dependencies: deps,
    install_dir: dory.get_variable(pkgconfig: 'extensiondir'),
    install: true
)

