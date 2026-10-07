include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(rayforge_tests
    test_main.cpp
    test_vec3.cpp
    test_ray.cpp
    test_sphere.cpp
    test_hittable.cpp
)

target_link_libraries(rayforge_tests
    PRIVATE
    GTest::gtest_main
)

target_include_directories(rayforge_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

include(GoogleTest)
gtest_discover_tests(rayforge_tests)
