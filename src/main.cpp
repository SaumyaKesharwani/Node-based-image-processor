#include <iostream>
#include <memory>
#include "imageinput.h"
#include "blurnode.h"
#include "brightness.h"
#include "outputnode.h"
#include "connection.h"

int main() {
    try {
        // Create nodes
        auto inputNode = std::make_shared<ImageInputNode>("Input");
        auto bcNode = std::make_shared<BrightnessContrastNode>("BrightnessContrast");
        auto blurNode = std::make_shared<BlurNode>("Blur");
        auto outputNode = std::make_shared<OutputNode>("Output");

        // Example: build a simple processing chain: Input -> BrightnessContrast -> Blur -> Output

        // Create connections
        auto conn1 = std::make_shared<Connection>(inputNode, bcNode);
        bcNode->addInputConnection(conn1);
        inputNode->addOutputConnection(conn1);

        auto conn2 = std::make_shared<Connection>(bcNode, blurNode);
        blurNode->addInputConnection(conn2);
        bcNode->addOutputConnection(conn2);

        auto conn3 = std::make_shared<Connection>(blurNode, outputNode);
        outputNode->addInputConnection(conn3);
        blurNode->addOutputConnection(conn3);

        // Load an image (adjust the path as needed)
        std::string imagePath;
        std::cout << "Enter the path to the image file: ";
        std::getline(std::cin, imagePath);
        inputNode->loadImage(imagePath);

        // Set Brightness/Contrast parameters
        bcNode->setBrightness(20);      // Example: increase brightness by 20
        bcNode->setContrast(1.2);         // Example: slightly increase contrast

        // Set Blur parameter
        blurNode->setBlurRadius(5);       // Example: blur radius of 5

        // Process each node in order.
        inputNode->process();
        bcNode->process();
        blurNode->process();
        outputNode->process();

        // Display the final output image using OpenCV
        cv::Mat finalImage = outputNode->getOutputImage();
        cv::namedWindow("Final Processed Image", cv::WINDOW_AUTOSIZE);
        cv::imshow("Final Processed Image", finalImage);
        std::cout << "Image processed and saved as output_image." << outputNode->getName() << "\n";
        cv::waitKey(0);

    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return -1;
    }
    return 0;
}
