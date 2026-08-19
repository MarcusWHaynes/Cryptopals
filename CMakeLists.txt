cmake_minimum_required(VERSION 3.16)
project(cryptopals_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pull in a testing framework once, shared by all challenges
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

enable_testing()

# Register each set/challenge as it's built
add_subdirectory(common)
add_subdirectory(set1/challenge1)
add_subdirectory(set1/challenge2)
add_subdirectory(set1/challenge3)

# Main executable for this challenge
