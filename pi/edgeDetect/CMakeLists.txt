find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

set(EDGESRC EdgeDetector.cpp EdgeDetector.h)

add_library(edgedetect ${EDGESRC})

add_executable(edgedetector main.cpp)

target_link_libraries(edgedetector edgedetect ${OpenCV_LIBS})
