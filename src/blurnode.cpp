#include "blurnode.h"
#include "connection.h"      // Needed for accessing inputConnections
#include "imageinput.h"  // Needed for dynamic_pointer_cast to ImageInputNode
#include <stdexcept>

void BlurNode::process() {
    if (inputConnections.empty()) {
        throw std::runtime_error("No input connection for BlurNode.");
    }
    
    // Get the first connection
    std::shared_ptr<Connection> conn = inputConnections.front();
    // Get the node that is the source of the connection
    std::shared_ptr<Node> fromNode = conn->getFromNode();
    
    // Try to cast fromNode to an ImageInputNode
    auto imageInput = std::dynamic_pointer_cast<ImageInputNode>(fromNode);
    if (!imageInput) {
        throw std::runtime_error("Invalid node connected to BlurNode; expecting an ImageInputNode.");
    }
    
    cv::Mat inputImage = imageInput->getImage();
    if (inputImage.empty()) {
        throw std::runtime_error("Input image is empty in BlurNode.");
    }
    
    outputImage = applyGaussianBlur(inputImage);
}

void BlurNode::setBlurRadius(int radius) {
    if (radius < 1 || radius > 20) {
        throw std::invalid_argument("Blur radius must be between 1 and 20.");
    }
    blurRadius = radius;
}

cv::Mat BlurNode::applyGaussianBlur(const cv::Mat& image) {
    cv::Mat blurredImage;
    cv::GaussianBlur(image, blurredImage, cv::Size(blurRadius * 2 + 1, blurRadius * 2 + 1), 0);
    return blurredImage;
}
