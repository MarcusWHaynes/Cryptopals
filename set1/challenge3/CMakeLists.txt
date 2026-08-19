add_executable(set1_challenge3 src/main.cpp src/single_byte_xor.cpp)
target_link_libraries(set1_challenge3 PRIVATE common_bytes)

add_executable(set1_challenge3_tests tests/test_single_byte_xor.cpp src/single_byte_xor.cpp)
target_link_libraries(set1_challenge3_tests PRIVATE common_bytes Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(set1_challenge3_tests)