cmake_minimum_required(VERSION 3.10)
project(NodeBasedImageProcessor)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Point to the built OpenCV include folder where opencv_modules.hpp exists
include_directories("D:/Downloads/opencv/build/include" src)

# Specify the library directory – adjust if needed
link_directories("D:/Downloads/opencv/build/x64/vc16/lib")

# List all source files needed for the project
add_executable(NodeBasedImageProcessor 
    src/main.cpp 
    src/node.cpp 
    src/connection.cpp 
    src/imageinput.cpp 
    src/blurnode.cpp 
    src/brightness.cpp 
    src/outputnode.cpp
)


# Link against the appropriate OpenCV libraries.
# Adjust the library names if necessary. For example, if you built with opencv_world,
# then you might link to opencv_world480 (or a similar version string).
target_link_libraries(NodeBasedImageProcessor opencv_world4110)

