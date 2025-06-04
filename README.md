# picamcapture

This repository holds scripts for automatically capturing evaluation images from an image sensor. Use `setup.sh` to prepare the environment and see `spec_picamcapture.md` for a description of the intended functionality.

The `mkepicam_wrapper/` directory contains a small [pybind11](https://pybind11.readthedocs.io/) wrapper for the C++ `mkepicam` library so that camera control can be performed from Python.


To build the wrapper you need a compiler that supports **C++14**. Run:

```bash
cd mkepicam_wrapper
python setup.py build_ext --inplace
```

Once built, try the sample capture program:

```bash
python ../examples/simple_capture.py
```
