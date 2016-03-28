cmake_minimum_required (VERSION 2.8) 
project (WeBuildRobotController)
set( CMAKE_MODULE_PATH /usr/local/lib/cmake )
find_package(raspicam REQUIRED)
find_package(OpenCV)
IF  ( OpenCV_FOUND AND raspicam_CV_FOUND)

    add_subdirectory( edgeDetect )
    add_executable( robotctrl main.cpp )

    target_link_libraries (robotctrl ${raspicam_CV_LIBS} edgedetect )

ELSE()
MESSAGE(FATAL_ERROR "OPENCV NOT FOUND IN YOUR SYSTEM")
ENDIF()

