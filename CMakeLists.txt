# Set Name of project and language
project(portrait_generator LANGUAGES CXX)
# Set cmake version
cmake_minimum_required(VERSION 3.0)
# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
# Create executable using the specified src
add_executable(${PROJECT_NAME} main.cpp camera.cpp camera.h face_detector.cpp face_detector.h i_camera.h i_face_detector.h i_img_editor.h portrait.h portrait.cpp img_editor.h img_editor.cpp)

#Include OpenCV
find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
	$<$<CXX_COMPILER_ID:MSVC>: /W3>
)
