cmake_minimum_required(VERSION 3.16.0)

project(median-element)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(MEDIAN_EXE median)
set(MEDIAN_LIB medianlib)

include_directories(include)

enable_testing()
add_subdirectory(test)

# Add compile options for the static lib and the executable but not for the unit tests
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_library(
    ${MEDIAN_LIB}
    STATIC
    src/Median.cpp
)

add_executable(
    ${MEDIAN_EXE}
    main.cpp
)

# Link the Median lib to the main executable
target_link_libraries(${MEDIAN_EXE} PRIVATE ${MEDIAN_LIB})

add_custom_command(
    TARGET ${MEDIAN_EXE}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${MEDIAN_EXE}> ${CMAKE_BINARY_DIR}
)
