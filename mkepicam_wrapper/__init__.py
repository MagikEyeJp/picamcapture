"""Python wrapper for the mkepicam C++ library using pybind11."""

from importlib import import_module

try:
    _mod = import_module('.mkepicam_pybind', package=__name__)
except ImportError as e:
    raise ImportError(
        'mkepicam_pybind モジュールが見つかりません。まだビルドされていない可能性があります。setup.py を実行してビルドしてください。README も参照してください。') from e
except OSError as e:
    raise OSError(
        'libmkepicam.so が見つからない、または libmkepicam.a がリンクされていない可能性があります。README も参照してください。') from e

Camera = _mod.Camera
CameraInfo = _mod.CameraInfo
find_camera = _mod.find_camera

__all__ = ['Camera', 'CameraInfo', 'find_camera']
