cmake_minimum_required(VERSION 3.11)

project(datastruct_practice C CXX)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set C++ standard for tests
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type configuration
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Debug flags
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Include directories
include_directories(include)

# Create the library from C source files
add_library(datastruct
    src/queue.c
    src/stack.c
    src/linked_list.c
    src/tree.c
)

# Enable testing
enable_testing()

# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG main
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Create test targets
add_executable(test_queue tests/test_queue.cpp)
target_link_libraries(test_queue 
  datastruct 
  gtest
  gtest_main
  pthread
)
add_test(NAME QueueTest COMMAND test_queue)

add_executable(test_stack tests/test_stack.cpp)
target_link_libraries(test_stack 
  datastruct 
  gtest
  gtest_main
  pthread
)
add_test(NAME StackTest COMMAND test_stack)

add_executable(test_linked_list tests/test_linked_list.cpp)
target_link_libraries(test_linked_list 
  datastruct 
  gtest
  gtest_main
  pthread
)
add_test(NAME LinkedListTest COMMAND test_linked_list)

add_executable(test_tree tests/test_tree.cpp)
target_link_libraries(test_tree 
  datastruct 
  gtest
  gtest_main
  pthread
)
add_test(NAME TreeTest COMMAND test_tree)

# Copy header files to include directory
file(COPY ${CMAKE_SOURCE_DIR}/include/datastruct DESTINATION ${CMAKE_BINARY_DIR}/include)

# Add executable targets here as you create them
# Example:
# add_executable(my_program src/main.cpp)