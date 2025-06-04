enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests gtest gtest_main url_encoder_decoder)
add_test(NAME UnitTests COMMAND unit_tests)