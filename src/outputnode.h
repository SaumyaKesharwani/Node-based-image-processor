#ifndef OUTPUTNODE_H
#define OUTPUTNODE_H

#include "node.h"
#include <opencv2/opencv.hpp>
#include <string>

class OutputNode : public Node {
public:
    OutputNode(const std::string& name);

    void process() override;

    // Save the processed image to disk.
    void saveImage(const std::string& filePath, const cv::Mat& image);

    void setOutputFormat(const std::string& format);
    void setQuality(int quality);

    // For demonstration, store the last processed image.
    cv::Mat getOutputImage() const { return outputImage; }

private:
    std::string outputFormat;
    int quality;
    cv::Mat outputImage;
};

#endif // OUTPUTNODE_H
