#include "outputnode.h"
#include "connection.h"
#include "brightness.h"
#include "blurnode.h"
#include <vector>
#include <stdexcept>
#include <opencv2/imgcodecs.hpp>

void OutputNode::process() {
    if (inputConnections.empty()) {
        throw std::runtime_error("No input connection for OutputNode.");
    }
    
    std::shared_ptr<Connection> conn = inputConnections.front();
    std::shared_ptr<Node> fromNode = conn->getFromNode();
    
    cv::Mat image;
    // Try casting to BrightnessContrastNode first.
    auto bcNode = std::dynamic_pointer_cast<BrightnessContrastNode>(fromNode);
    if (bcNode && !bcNode->getOutputImage().empty()) {
        image = bcNode->getOutputImage();
    } else {
        // If that fails, try casting to BlurNode.
        auto blurNode = std::dynamic_pointer_cast<BlurNode>(fromNode);
        if (blurNode && !blurNode->getOutputImage().empty()) {
            image = blurNode->getOutputImage();
        }
    }
    
    if (image.empty()) {
        throw std::runtime_error("No image available to save in OutputNode.");
    }
    outputImage = image;
    
    // Save the image to disk.
    saveImage("output_image." + outputFormat, image);
}

void OutputNode::saveImage(const std::string& filePath, const cv::Mat& image) {
    if (image.empty()) {
        throw std::runtime_error("No image to save.");
    }
    std::vector<int> params;
    if (outputFormat == "jpg" || outputFormat == "jpeg") {
        params.push_back(cv::IMWRITE_JPEG_QUALITY);
        params.push_back(quality);
    }
    if (!cv::imwrite(filePath, image, params)) {
        throw std::runtime_error("Failed to save image: " + filePath);
    }
}

void OutputNode::setOutputFormat(const std::string& format) {
    outputFormat = format;
}

void OutputNode::setQuality(int quality) {
    if (quality < 0 || quality > 100) {
        throw std::invalid_argument("Quality must be between 0 and 100.");
    }
    this->quality = quality;
}
