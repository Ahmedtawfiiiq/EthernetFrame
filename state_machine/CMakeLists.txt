cmake_minimum_required(VERSION 3.5)

project(state_machine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(state_machine main.cpp
state.h
coolstates.h
statemachine.h
eventgenerator.h
acoolstatemachine.h
crc.h
state.cpp
coolstates.cpp
statemachine.cpp
eventgenerator.cpp
acoolstatemachine.cpp
crc.cpp)

install(TARGETS state_machine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
