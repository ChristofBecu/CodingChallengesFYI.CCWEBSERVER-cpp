set(SRC_DIR "../src")
set(OUTPUT_DIR "output/tests")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${OUTPUT_DIR})

# Add the libraries to be tested
add_library(
    socket 
    SHARED 
    "${SRC_DIR}/network/sockets/socket.cpp"
)

find_package(GTest REQUIRED)

# if there are any test data files, copy them to the output directory
#file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/test_data" DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/")

add_executable(globalTests
    "${CMAKE_CURRENT_SOURCE_DIR}/globalTests.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/globalTestEnvironment.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/network/sockets/socketTests.cpp"
)

target_link_libraries(globalTests PRIVATE socket GTest::GTest GTest::Main)

add_test(
  NAME globalTests
  COMMAND $<TARGET_FILE:globalTests>
  WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
