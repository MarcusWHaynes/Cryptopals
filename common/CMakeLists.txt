add_library(common_bytes bytes.cpp)
target_include_directories(common_bytes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(common_bytes_tests tests/test_bytes.cpp)
target_link_libraries(common_bytes_tests PRIVATE common_bytes Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(common_bytes_tests)