cmake_minimum_required(VERSION 3.5)
project(lab5_task3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    main.cpp
    callchain.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})