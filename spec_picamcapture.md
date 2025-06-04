# picamcapture Specification

picamcapture is intended to automate the capture of evaluation images for image sensor testing. The program should control a camera module, capture frames at configurable intervals and resolutions, and store the resulting images on disk for later analysis.

## Features

- Configurable image resolution and format (e.g. JPEG, PNG).
- Adjustable exposure time, gain, and white balance settings.
- Ability to capture a sequence of images at a fixed interval.
- Command line interface for starting a capture session.
- Optional configuration file to store default parameters.
- Logging of capture parameters and camera metadata.
- Python wrapper for the C++ `mkepicam` library via `pybind11`.

## Directory Layout

```
/-- capture.py        # main entry point
|-- config.yaml       # example configuration
|-- captured/         # directory where images are stored
|-- setup.sh          # environment setup script
```

## Dependencies

The project uses Python 3. Typical dependencies include:

- `opencv-python` for camera access and image processing
- `pillow` for image format conversions
- `libcamera-tools` for low level control on systems that support it
- `pybind11` to build the wrapper for the C++ `mkepicam` library

See `setup.sh` for an example installation script.

## mkepicam_wrapper Usage

To build the pybind11 wrapper you need a compiler that supports **C++14**. Run:

```bash
cd mkepicam_wrapper
python setup.py build_ext --inplace
```

You can then use the wrapper from Python:

```python
from mkepicam_wrapper import find_camera
cam = find_camera()
cam.open()
info = cam.get_camera_info()
print(info.name, info.width, info.height)
cam.close()
```


## Usage Example

```bash
# activate the virtual environment first
source .venv/bin/activate

# capture 10 frames at 1920x1080 using default parameters
python capture.py --count 10 --width 1920 --height 1080
```

## Future Work

Additional features such as GUI controls, integration with automated test rigs, and support for multiple camera modules can be added as needed.

