#!/bin/bash
# Setup script for the picamcapture environment
# Installs system packages and Python dependencies.

set -e

# Update package lists
sudo apt-get update

# Install system packages required for camera control and Python
sudo apt-get install -y python3 python3-venv python3-pip libcamera-tools git

# Create Python virtual environment if it does not exist
if [ ! -d ".venv" ]; then
    python3 -m venv .venv
fi

# Activate the virtual environment
source .venv/bin/activate

# Upgrade pip and install common Python packages
pip install --upgrade pip
pip install opencv-python pillow

echo "Setup complete"

