cmake_minimum_required(VERSION 3.11)

project(datastruct_practice C CXX)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set C++ standard for tests
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type configuration
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Debug flags
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")


# Include directories
include_directories(include)

# Create the library from C source files
add_library(datastruct
    src/queue.c
    # Add other data structure implementations here
)

# Enable testing
enable_testing()

# Download and configure Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0  # Sp
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

# Add tests to be run
add_test(NAME QueueTest COMMAND test_queue)