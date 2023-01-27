cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)

project(sorting-demo)

aux_source_directory(src SRCS)

add_executable(${PROJECT_NAME}_run ${SRCS})
target_include_directories(${PROJECT_NAME}_run PUBLIC include)

add_library(${PROJECT_NAME}_lib STATIC ${SRCS})
target_include_directories(${PROJECT_NAME}_lib PUBLIC include)

add_subdirectory(tst)
