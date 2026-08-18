add_executable(set1_challenge2 src/main.cpp src/fixed_xor.cpp)
target_link_libraries(set1_challenge2 PRIVATE common_bytes)

add_executable(set1_challenge2_tests tests/test_fixed_xor.cpp src/fixed_xor.cpp)
target_link_libraries(set1_challenge2_tests PRIVATE common_bytes Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(set1_challenge2_tests)