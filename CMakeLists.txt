cmake_minimum_required(VERSION 3.16)

# Set Name of project and language
project(portrait_generator LANGUAGES CXX)
# Set cmake version
#cmake_minimum_required(VERSION 3.0)
# set build type to Debug/Release
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(OpenGL REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets OpenGLWidgets)
qt_standard_project_setup()


# Create executable using the specified src
add_executable(${PROJECT_NAME} main.cpp camera.cpp camera.h controller_camera.h controller_camera.cpp face_detector.cpp face_detector.h i_camera.h i_face_detector.h i_img_editor.h img_editor.h img_editor.cpp portrait.h portrait.cpp view_camera.h view_camera.cpp view_camera.ui widget.h widget.cpp widget.ui)




#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)



#


target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::OpenGLWidgets)#♠ ${OPENGL_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

FILE(COPY haarcascade_frontalface_default.xml DESTINATION "${CMAKE_BINARY_DIR}")

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
	$<$<CXX_COMPILER_ID:MSVC>: /W3>
)
