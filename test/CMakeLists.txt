cmake_minimum_required(VERSION 3.16.0)

project(median_test)

Include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(
    ${PROJECT_NAME}
    median_tests.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
target_link_libraries(${PROJECT_NAME} PRIVATE ${MEDIAN_LIB})

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
