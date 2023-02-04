cmake_minimum_required(VERSION 3.0.0)
project(pp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(dfs dfs.cpp)

add_executable(dij dijkstra.cpp)

add_executable(topo toposort.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
