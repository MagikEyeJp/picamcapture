#!/usr/bin/env python3
"""Simple test program that demonstrates mkepicam_wrapper usage."""

import sys

try:
    from mkepicam_wrapper import find_camera
except ImportError:
    print(
        "mkepicam_wrapper is not built. Run 'python mkepicam_wrapper/setup.py build_ext --inplace' first."
    )
    sys.exit(0)


def main() -> None:
    cam = find_camera()
    if cam is None:
        print("No camera found")
        return
    if not cam.open():
        print("Failed to open camera")
        return
    info = cam.get_camera_info()
    print(f"Camera: {info.name} {info.width}x{info.height}")
    cam.close()
    print("Capture complete")


if __name__ == "__main__":
    main()
