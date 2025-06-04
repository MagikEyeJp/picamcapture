from setuptools import setup, Extension
import pybind11
import os

include_dirs = [pybind11.get_include(), os.path.join('..', 'mkepicam')]

ext_modules = [
    Extension(
        'mkepicam_pybind',
        ['mkepicam_pybind.cpp'],
        include_dirs=include_dirs,
        language='c++',
        extra_compile_args=['-std=c++11'],
        libraries=['mkepicam']
    )
]

setup(
    name='mkepicam_pybind',
    version='0.1',
    ext_modules=ext_modules,
    zip_safe=False,
)
