if(EXISTS "/Users/yura_kulakovskyi/Documents/C++/AP/PR10/PR10_3/cmake-build-debug/PR10_2_tests[1]_tests.cmake")
  include("/Users/yura_kulakovskyi/Documents/C++/AP/PR10/PR10_3/cmake-build-debug/PR10_2_tests[1]_tests.cmake")
else()
  add_test(PR10_2_tests_NOT_BUILT PR10_2_tests_NOT_BUILT)
endif()
