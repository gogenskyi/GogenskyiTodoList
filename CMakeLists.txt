cmake_minimum_required(VERSION 4.3)
project(TodoList)

set(CMAKE_CXX_STANDARD 26)

add_executable(TodoList src/main.cpp
        src/Todo.cpp
        src/Todo.h
        database.txt
        src/database/database.cpp
        src/database/database.h)
target_include_directories(TodoList
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
