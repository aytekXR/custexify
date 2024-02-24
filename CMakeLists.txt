cmake_minimum_required(VERSION 3.10)
project(custexify VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find packages
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(PORTAUDIO REQUIRED portaudio-2.0)
pkg_check_modules(ALSA REQUIRED alsa)

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS} ${PORTAUDIO_INCLUDE_DIRS} ${ALSA_INCLUDE_DIRS} include/)

# Add executable
add_executable(custexify main.cpp src/CameraCapture.cpp src/MicrophoneCapture.cpp src/SpeakerOutput.cpp)

# Link libraries to the executable
target_link_libraries(custexify ${OpenCV_LIBS} ${PORTAUDIO_LIBRARIES} ${ALSA_LIBRARIES})

# Add include directories to the build.
target_include_directories(custexify PUBLIC "${PROJECT_BINARY_DIR}")
