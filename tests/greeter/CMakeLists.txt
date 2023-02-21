# add executable

add_executable(greeter_test greeter.cpp)

# link gtest and code under test

target_link_libraries(
    greeter_test  # tests
    GTest::gtest_main # gtest
    greeter  # code under test
)

target_compile_features(greeter_test PRIVATE cxx_std_14)

# make tests discoverable by cmake

include(GoogleTest)
gtest_discover_tests(greeter_test)
