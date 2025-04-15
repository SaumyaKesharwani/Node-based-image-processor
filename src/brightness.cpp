#include "brightness.h"
#include "connection.h"       // To work with inputConnections
#include "imageinput.h"   // To cast to ImageInputNode and use getImage()
#include <stdexcept>

void BrightnessContrastNode::process() {
    if (inputConnections.empty()) {
        throw std::runtime_error("No input connection for BrightnessContrastNode.");
    }
    
    std::shared_ptr<Connection> conn = inputConnections.front();
    std::shared_ptr<Node> fromNode = conn->getFromNode();
    
    auto imageInput = std::dynamic_pointer_cast<ImageInputNode>(fromNode);
    if (!imageInput) {
        throw std::runtime_error("Invalid node connected to BrightnessContrastNode; expecting an ImageInputNode.");
    }
    
    cv::Mat inputImage = imageInput->getImage();
    if (inputImage.empty()) {
        throw std::runtime_error("Input image is empty in BrightnessContrastNode.");
    }
    
    outputImage = adjustBrightnessContrast(inputImage);
}

void BrightnessContrastNode::setBrightness(int brightness) {
    if (brightness < -100 || brightness > 100) {
        throw std::invalid_argument("Brightness must be between -100 and 100.");
    }
    this->brightness = brightness;
}

void BrightnessContrastNode::setContrast(double contrast) {
    if (contrast < 0 || contrast > 3) {
        throw std::invalid_argument("Contrast must be between 0 and 3.");
    }
    this->contrast = contrast;
}

cv::Mat BrightnessContrastNode::adjustBrightnessContrast(const cv::Mat& image) {
    cv::Mat adjustedImage;
    image.convertTo(adjustedImage, -1, contrast, brightness);
    return adjustedImage;
}
