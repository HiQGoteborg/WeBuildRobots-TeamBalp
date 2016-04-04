cmake_minimum_required(VERSION 2.8)
set( ARDUINO_1_5 True )
#set(CMAKE_TOOLCHAIN_FILE /home/balp/src/git/arduino-cmake/cmake/ArduinoToolchain.cmake)
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")
file(DOWNLOAD
 "https://raw.githubusercontent.com/octoblu/cmake-external-project-utils/master/external-project-utils.cmake"
 "${CMAKE_MODULE_PATH}/external-project-utils.cmake"
)

include(external-project-utils)

if(NOT DEFINED BOARDPORT)
	set(BOARDPORT "/dev/ttyACM0")
endif()

project(WeBuildRobots)

if(ARDUINO_FOUND)
    set( RedBot_RECURSE True)

    generate_arduino_firmware(webuildrobots
	HDRS timer.h communication.h
	SRCS main.cpp webuild.cpp communication.cpp
	PORT ${BOARDPORT}
	BOARD uno
    )
else()
    enable_testing()
    getExternalProject("gtest" "https://googletest.googlecode.com/files/gtest-1.7.0.zip")
    getExternalProject("gmock" "https://googlemock.googlecode.com/files/gmock-1.7.0.zip")
    include_directories(${CMAKE_SOURCE_DIR} arduino-mock/)
    add_subdirectory(arduino-mock)

    add_executable(timer_test
        timer.h
        test/timer_test.cpp
        test/main.cpp
        )
    target_link_libraries(timer_test arduino-mock pthread )
    linkExternalProject(timer_test "gtest")
    linkExternalProject(timer_test "gmock")
    add_test(AllTestsForTimer timer_test  --gtest_color=on --gtest_output=xml)

    add_executable(communication_test
        communication.h
        communication.cpp
        test/communication_test.cpp
        test/main.cpp
        )
    target_link_libraries(communication_test arduino-mock pthread )
    linkExternalProject(communication_test "gtest")
    linkExternalProject(communication_test "gmock")
    add_test(AllTestsForTimer communication_test  --gtest_color=on --gtest_output=xml)

endif()
