from setuptools import setup, Extension
import pybind11
import os

include_dirs = [pybind11.get_include(), os.path.join('..', 'mkepicam')]

# MKEPICAM_LIB 環境変数で mkepicam の静的ライブラリを指定する。
lib_path = os.environ.get('MKEPICAM_LIB')
if not lib_path:
    raise OSError(
        'MKEPICAM_LIB 環境変数が設定されていません。libmkepicam.a のパスを指定してください。'
    )

ext_modules = [
    Extension(
        'mkepicam_pybind',
        ['mkepicam_pybind.cpp'],
        include_dirs=include_dirs,
        language='c++',
        extra_compile_args=['-std=c++14'],
        # 静的ライブラリをリンクする
        extra_objects=[lib_path]
    )
]

setup(
    name='mkepicam_pybind',
    version='0.1',
    ext_modules=ext_modules,
    zip_safe=False,
)
