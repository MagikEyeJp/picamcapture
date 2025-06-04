"""Python wrapper for the mkepicam C++ library using pybind11."""

from importlib import import_module

try:
    _mod = import_module('mkepicam_pybind')
except ImportError as e:
    raise ImportError(
        'mkepicam_pybind module not found. Run setup.py to build it.') from e

Camera = _mod.Camera
CameraInfo = _mod.CameraInfo
find_camera = _mod.find_camera

__all__ = ['Camera', 'CameraInfo', 'find_camera']
