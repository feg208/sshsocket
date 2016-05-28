#!/usr/bin/env python
"""
This is the build script for sshsocket. The dependencies are boost.python
and libssh2
"""
import distutils.core as dcore
import distutils.extension as dext
import glob
import sys

DEBUG = True

if sys.platform == 'win32':
    raise SystemExit('Windows is unsupported')

include_dirs = ['./includes']
libraries = [
    'boost_python-%d.%d' % (sys.version_info.major, sys.version_info.minor),
    'ssh2'
]
library_dirs = []
extra_compile_args = ['-fPIC', '-std=gnu++11', '-Wall']
extra_compile_args += ['-g', '-ggdb'] if DEBUG else []
files = glob.glob('srcs/*.cc')

dcore.setup(
    name='sshsocket',
    version='1.0',
    description='An idiosyncratic exposure of libssh2 to python',
    license='GPLv2',
    author='Frederick Grim',
    author_email='frederick.grim@gmail.com',
    ext_modules=[
        dext.Extension(
            'sshsocket', files,
            language='c++',
            extra_link_args=['-fPIC', '-pie'],
            extra_compile_args=extra_compile_args,
            library_dirs=library_dirs,
            libraries=libraries,
            include_dirs=include_dirs,
            depends=[]
        )
    ]
)
