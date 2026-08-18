# Main executable for this challenge
add_executable(set1_challenge1
    src/main.cpp
    src/hex_to_base64.cpp
)

# Test executable, linked against Catch2
add_executable(set1_challenge1_tests
    tests/test_hex_to_base64.cpp
    src/hex_to_base64.cpp
)
target_link_libraries(set1_challenge1_tests PRIVATE Catch2::Catch2WithMain)

# Register with CTest so `ctest` picks it up
include(Catch)
catch_discover_tests(set1_challenge1_tests)