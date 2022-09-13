// Specifies that the compiler includes the header file only once,
// when compiling a source code file.
#pragma once

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef unsigned char uint8;

// abstract class for states -> used to create our states
template <class T> class State{
public:
    // virtual functions to be overridden in child classes
    virtual ~State(){}; // destructor
    virtual void Enter() = 0;   // pure virtual function
    virtual void Execute(T*) = 0; // pure virtual function
    virtual void Exit() = 0;    // pure virtual function
};

#endif // STATE_H
