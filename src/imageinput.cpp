#include "imageinput.h"
#include <opencv2/imgcodecs.hpp>
#include <sstream>

ImageInputNode::ImageInputNode(const std::string& name) : Node(name) {}

void ImageInputNode::loadImage(const std::string& filePath) {
    this->filePath = filePath;
    image = cv::imread(filePath, cv::IMREAD_COLOR);
    if (image.empty()) {
        throw std::runtime_error("Failed to load image: " + filePath);
    }
}

void ImageInputNode::process() {
    // In this simple example, process() ensures the image is loaded.
    if (image.empty()) {
        throw std::runtime_error("No image loaded in ImageInputNode.");
    }
}

cv::Mat ImageInputNode::getImage() const {
    return image;
}

std::string ImageInputNode::getImageMetadata() const {
    if (image.empty()) {
        return "No image loaded.";
    }
    std::ostringstream metadata;
    metadata << "Dimensions: " << image.cols << "x" << image.rows << "\n";
    metadata << "Channels: " << image.channels() << "\n";
    std::vector<uchar> buf;
    cv::imencode(".png", image, buf);
    metadata << "Approx. File Size: " << buf.size() << " bytes\n";
    return metadata.str();
}
