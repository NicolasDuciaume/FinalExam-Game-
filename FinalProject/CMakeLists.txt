cmake_minimum_required(VERSION 2.8)

project ( FP )

file(GLOB_RECURSE FP_SOURCES "src/*.cpp")
file(GLOB_RECURSE FP_HEADERS "src/*.h")

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

set (FP_INCLUDE_DIRS "")
foreach (_headerFile ${FP_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND FP_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES FP_INCLUDE_DIRS)

add_executable (FPExe ${FP_SOURCES})
target_include_directories(FPExe PRIVATE ${FP_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
target_link_libraries( FPExe ${OpenCV_LIBS} )
