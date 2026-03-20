cmake_minimum_required(VERSION 3.00)
project(project_name CXX)
set(CMAKE_CPP_CSTANDARD 11)
include_directories("sources")
file(GLOB MAIN
"main.cpp"
    )
    add_executable(testy ${MAIN})
