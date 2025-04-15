#ifndef BLURNODE_H
#define BLURNODE_H

#include "node.h"
#include <opencv2/opencv.hpp>

class BlurNode : public Node {
public:
    BlurNode(const std::string& name);

    void process() override;
    void setBlurRadius(int radius);

    // Apply Gaussian blur on the given image.
    cv::Mat applyGaussianBlur(const cv::Mat& image);

    // Expose the processed image for further pipeline use.
    cv::Mat getOutputImage() const { return outputImage; }

private:
    int blurRadius;
    cv::Mat outputImage;
};

#endif // BLURNODE_H
