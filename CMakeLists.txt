cmake_minimum_required(VERSION 3.14)
project(PR10_3)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)

include_directories(/opt/homebrew/opt/ncurses/include)
link_directories(/opt/homebrew/opt/ncurses/lib)

add_executable(PR10_3
        src/main.cpp
        src/functions.cpp
)

target_link_libraries(PR10_3)

add_executable(PR10_3_tests
        tests/test_h.cpp
        src/functions.cpp
)

target_link_libraries(PR10_3_tests gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(PR10_3_tests)
