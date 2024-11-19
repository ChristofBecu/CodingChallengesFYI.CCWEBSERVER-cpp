# src/CMakeLists.txt

# Gather source files
file(GLOB_RECURSE SOURCES "*.cpp")

# Create the main executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Set the output directory for the executable
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR}
)

# Copy www directory to the output location after build
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/www
        ${CMAKE_BINARY_DIR}/${OUTPUT_DIR}
)