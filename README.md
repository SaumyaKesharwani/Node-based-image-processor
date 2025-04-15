Node-based-image-processor
# Node-Based Image Processor

## Overview 

This project implements a simple node-based image manipulation interface in C++ using only free libraries. The application lets users load an image, process it through a series of connected nodes (such as brightness/contrast adjustment and Gaussian blur), and save the resulting output. The interface uses OpenCV for image processing and basic HighGUI windows for display, ensuring no paid libraries (e.g. Qt) are needed.

## Features

- **Node Framework:** 
  - **Image Input Node:** Loads images and displays metadata.
  - **Brightness/Contrast Node:** Adjusts image brightness and contrast.
  - **Blur Node:** Applies Gaussian blur with a configurable radius.
  - **Output Node:** Saves the processed image to disk.
- **Simple Processing Pipeline:** Nodes can be connected in a chain for sequential processing.
- **Basic GUI:** Uses OpenCV HighGUI to preview the final processed image.
- **Error Handling:** Basic error checking to handle missing images or invalid parameters.

## Requirements

- C++11 or later
- OpenCV (for image processing and display)
- CMake (for building the project)

## Build Instructions

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/node-based-image-processor.git
   cd node-based-image-processor
