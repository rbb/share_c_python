#!/usr/bin/env python3
# encoding: utf-8

#from distutils.core import setup, Extension
from setuptools import setup, Extension
import numpy

setup(
    ext_modules=[
        Extension(
            name="hello",  # as it would be imported
                               # may include packages/namespaces separated by `.`

            sources=["hello.cpp"], # all sources are compiled into a single binary file
            include_dirs=[numpy.get_include()],
        ),
    ]
)

"""
def configuration(parent_package='', top_path=None):
      import numpy
      from numpy.setuptools.misc_util import Configuration
      from numpy.setuptools.misc_util import get_info

      #Necessary for the half-float d-type.
      info = get_info('npymath')

      config = Configuration('',
                             parent_package,
                             top_path)
      config.add_extension('hello',
                           ['hello.cpp'],
                           extra_info=info)

      return config

if __name__ == "__main__":
      from numpy.setuptools.core import setup
      setup(configuration=configuration)
"""

"""
setup_args = dict(
    ext_modules = [
        Extension(
            'mypackage.mymodule',
            ['lib/mymodule.c', 'lib/mypackage.c', 'lib/myalloc.c'],
            include_dirs = ['lib'],
            py_limited_api = True
        )
    ]
)
setup(**setup_args)
"""
