if(EXISTS "/home/jesper/dev/cpp/cpp-sorting/build/tst/sorting-demo_tst[1]_tests.cmake")
  include("/home/jesper/dev/cpp/cpp-sorting/build/tst/sorting-demo_tst[1]_tests.cmake")
else()
  add_test(sorting-demo_tst_NOT_BUILT sorting-demo_tst_NOT_BUILT)
endif()
