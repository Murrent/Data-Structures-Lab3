cmake_minimum_required(VERSION 3.17)
project(Lab3_BinaryTree C)

set(CMAKE_C_STANDARD 11)
set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)


add_subdirectory(${src}/binarytree)
add_subdirectory(${src}/load_files)

add_executable(operationTest ${src}/operationTest.c)

target_link_libraries(operationTest binarytree load_files)