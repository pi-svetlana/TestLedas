set(target tests)

add_executable(${target}
        tests.cc
)

target_link_libraries(${target}
        PRIVATE
        intersect
        GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${target})