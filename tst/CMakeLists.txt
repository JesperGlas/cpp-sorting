cmake_minimum_required(VERSION 3.20)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG b796f7d44681514f58a683a3a71ff17c94edb0c1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME}_tst tst_main.cpp tst_LinkedList.cpp)
target_link_libraries(${PROJECT_NAME}_tst PUBLIC ${PROJECT_NAME}_lib gtest)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}_tst)
