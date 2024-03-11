cmake_minimum_required(VERSION 3.20)
project(LeetCode)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Compile source files from src/car/200/easy, src/car/200/mid, and src/car/200/hard
# Assuming all source files are in the format 'mid/*.cpp', 'easy/*.cpp', and 'hard/*.cpp'

file(GLOB_RECURSE SRC_FILES "${PROJECT_SOURCE_DIR}/src/**/*.cpp")

# Add template files
file(GLOB TEMPLATE_CPP "${PROJECT_SOURCE_DIR}/include/*.cpp")

foreach(SOURCE_FILE ${SRC_FILES})
    # Get a filename without extension (NAME_WE will return the filename without extension)
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    
    # Define the executable for each source file
    add_executable(${FILE_NAME} ${SOURCE_FILE} ${TEMPLATE_CPP})
endforeach()
