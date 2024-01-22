# Set the minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Set the encoding to UTF-8
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# Set the source directory
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Get all the .cpp files recursively
file(GLOB_RECURSE CPP_FILES ${SOURCE_DIR}/*.cpp)

# Iterate over each .cpp file
foreach(CPP_FILE ${CPP_FILES})
    # Get the file name without extension
    get_filename_component(EXECUTABLE_NAME ${CPP_FILE} NAME_WE)

    # Get the relative path of the .cpp file
    file(RELATIVE_PATH RELATIVE_PATH ${SOURCE_DIR} ${CPP_FILE})

    # Get the directory name of the .cpp file
    get_filename_component(DIR_NAME ${RELATIVE_PATH} DIRECTORY)

    # Create the corresponding output directory
    file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${DIR_NAME})

    # Add an executable target for each .cpp file
    add_executable(${EXECUTABLE_NAME} ${CPP_FILE})

    # Set the output directory for the executable
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach()
