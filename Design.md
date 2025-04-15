
---

## Updated DESIGN.md

```markdown
# Design Document

## Architecture Overview

The Node-Based Image Processor is built with a modular design that separates the processing operations into nodes. Each node represents a single operation (such as loading an image, adjusting brightness/contrast, applying a blur, or saving the output) and can be connected to form a simple processing pipeline.

### Key Components

- **Node Base Class:**  
  Defines a common interface for all nodes, including a pure virtual `process()` method and connection management functions.

- **Connection Class:**  
  Represents a directed link between two nodes. This enables data (images) to flow from one node (output) to another node (input).

- **Specific Node Classes:**  
  - *ImageInputNode:* Loads images and provides metadata.
  - *BrightnessContrastNode:* Adjusts image brightness and contrast.
  - *BlurNode:* Applies a Gaussian blur with configurable parameters.
  - *OutputNode:* Saves the processed image to disk with configurable quality and format.

## Key Decisions

1. **Simplicity & Free Dependencies:**  
   Only OpenCV is used for image processing and simple GUI functions. This keeps the code free from paid libraries (like Qt) while still meeting the assignment requirements.

2. **Modular Node Design:**  
   Each node has its own processing logic. This modular design makes it easier to extend the system by adding new nodes without altering the core architecture.

3. **Sequential Processing:**  
   The processing pipeline runs nodes in sequence. Although advanced features like circular dependency detection are not implemented here, the structure supports future enhancements.

4. **Basic User Interface:**  
   Instead of using a full-featured GUI framework, OpenCV HighGUI functions are used to display the final output image and for simple user input via the console.

## Future Improvements

- **Enhanced GUI:**  
  A graphical node editor (using a library such as Dear ImGui) could be implemented for real-time interactive connections between nodes.

- **Error Handling Enhancements:**  
  Further improvements in detecting and handling invalid connections or missing inputs.

- **Advanced Nodes:**  
  Additional processing nodes (such as color channel splitters, thresholding, or edge detection) can be added following the modular pattern established.

## Conclusion

This design satisfies the assignment's requirements while keeping dependencies minimal (using only OpenCV) and the implementation straightforward. It provides a solid foundation for further expansion and refinement.
