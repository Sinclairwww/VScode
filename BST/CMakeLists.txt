cmake_minimum_required(VERSION 3.0.0)
project(BST VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(BST common.h module.h module.c main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
