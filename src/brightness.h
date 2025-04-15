#ifndef BRIGHTNESSCONTRASTNODE_H
#define BRIGHTNESSCONTRASTNODE_H

#include "node.h"
#include <opencv2/opencv.hpp>

class BrightnessContrastNode : public Node {
public:
    BrightnessContrastNode(const std::string& name);

    void process() override;
    void setBrightness(int brightness);
    void setContrast(double contrast);

    // Apply brightness and contrast adjustment to the given image.
    cv::Mat adjustBrightnessContrast(const cv::Mat& image);

    // Expose the processed image.
    cv::Mat getOutputImage() const { return outputImage; }

private:
    int brightness;
    double contrast;
    cv::Mat outputImage;
};

#endif // BRIGHTNESSCONTRASTNODE_H
