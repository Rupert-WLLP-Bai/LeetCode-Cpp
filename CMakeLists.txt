cmake_minimum_required(VERSION 3.20)
project(LeetCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置为 Release 模式，启用优化
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0")

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Compile source files from src/car/200/easy, src/car/200/mid, and src/car/200/hard
# Assuming all source files are in the format 'mid/*.cpp', 'easy/*.cpp', and 'hard/*.cpp'

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

# Add template files
file(GLOB TEMPLATE_CPP "${PROJECT_SOURCE_DIR}/include/*.cpp")

foreach(SOURCE_FILE ${SRC_FILES})
    # Get the directory path of the source file
    get_filename_component(DIR_PATH ${SOURCE_FILE} DIRECTORY)

    # Split the directory path into components (parent directories)
    string(REPLACE "${PROJECT_SOURCE_DIR}/src/" "" RELATIVE_PATH ${DIR_PATH})
    string(REPLACE "/" "-" DIR_NAME_PART ${RELATIVE_PATH})

    # Get the filename without extension
    get_filename_component(FILE_NAME_WE ${SOURCE_FILE} NAME_WE)

    # Construct the executable name using the directory structure and file name
    set(EXECUTABLE_NAME "${DIR_NAME_PART}-${FILE_NAME_WE}")

    # Define the executable for each source file
    add_executable(${EXECUTABLE_NAME} ${SOURCE_FILE} ${TEMPLATE_CPP})

endforeach()
