cmake_minimum_required(VERSION 3.10)
project(dalive_project)

# Set the executable name and sources
set(EXECUTABLE_NAME dalive)
set(SOURCES src/main.c src/dalive.c src/dalive.h)

# Create the executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Set the output directory for the executable
set_target_properties(${EXECUTABLE_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
