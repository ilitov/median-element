cmake_minimum_required(VERSION 3.16.0)

project(median_test)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES_LIST}
    median_tests.cpp
)

Include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gtest_main)
