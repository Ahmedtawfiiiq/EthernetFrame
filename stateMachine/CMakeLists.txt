cmake_minimum_required(VERSION 3.5)

project(stateMachine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(stateMachine main.cpp
state.h
stateMachine.h
frameMachine.cpp
frameMachine.h
frameStates.cpp
frameStates.h
configurationHandler.cpp
configurationHandler.h
input.txt
output.txt)

install(TARGETS stateMachine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
