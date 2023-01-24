cmake_minimum_required(VERSION 3.22)

project(sorting-demo)

aux_source_directory(src SRCS)

add_executable(${PROJECT_NAME}_run ${SRCS})
target_include_directories(${PROJECT_NAME}_run PUBLIC include)
