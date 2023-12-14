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
add_executable(${PROJECT_NAME}
    src/model/main.cpp
    src/model/camera.cpp
    src/model/camera.h
    src/model/face_detector.cpp
    src/model/face_detector.h
    src/model/i_camera.h
    src/model/i_face_detector.h
    src/model/i_img_editor.h
    src/model/img_editor.h
    src/model/img_editor.cpp
    src/model/portrait.h
    src/model/portrait.cpp
    src/ui/controller_camera.h
    src/ui/controller_camera.cpp
    src/ui/controller_editor.h
    src/ui/controller_editor.cpp
    src/ui/view_camera.h
    src/ui/view_camera.cpp
    src/ui/view_camera.ui
    src/ui/view_editor.h
    src/ui/view_editor.cpp
    src/ui/view_editor.ui
    )

target_include_directories(${PROJECT_NAME} PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    ${CMAKE_CURRENT_SOURCE_DIR}/src/model
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ui
    )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::OpenGLWidgets)#♠ ${OPENGL_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)

FILE(COPY resources/haarcascade_frontalface_default.xml DESTINATION "${CMAKE_BINARY_DIR}")

# Define required c++ standard to C++11
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
# Set compile options, enable warnings
target_compile_options(${PROJECT_NAME} PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>: -Wall>
	$<$<CXX_COMPILER_ID:MSVC>: /W3>
)
