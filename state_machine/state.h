// Specifies that the compiler includes the header file only once,
// when compiling a source code file.
#pragma once

#ifndef STATE_H
#define STATE_H

#include <iostream>

using namespace std;

// abstract class for states -> used to create our states
template <class T> class State{
public:
    // virtual functions to be overridden in child classes
    virtual ~State(){}; // destructor
    virtual void Enter(T *pOwner) = 0;   // pure virtual function
    virtual void Execute(T *pOwner) = 0; // pure virtual function
    virtual void Exit(T *pOwner) = 0;    // pure virtual function
};

#endif // STATE_H
