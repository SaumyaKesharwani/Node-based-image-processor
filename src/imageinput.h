#ifndef IMAGEINPUTNODE_H
#define IMAGEINPUTNODE_H

#include "node.h"
#include <opencv2/opencv.hpp>
#include <string>

class ImageInputNode : public Node {
public:
    ImageInputNode(const std::string& name);

    // Load an image from disk
    void loadImage(const std::string& filePath);
    
    // For processing, simply assign the image (no further changes)
    void process() override;

    // Getters to retrieve the loaded image and its metadata.
    cv::Mat getImage() const;
    std::string getImageMetadata() const;

private:
    cv::Mat image;
    std::string filePath;
};

#endif // IMAGEINPUTNODE_H
