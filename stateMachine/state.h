// Specifies that the compiler includes the header file only once,
// when compiling a source code file.
#pragma once

#include <iostream>

using namespace std;

typedef unsigned short uint16;

// abstract class for states -> used to create our states
template <class T> class state{
public:
    // virtual functions to be overridden in child classes
    virtual ~state(){}; // destructor
    virtual void enter() = 0;   // pure virtual function
    virtual void execute(T*) = 0; // pure virtual function
    virtual void exit() = 0;    // pure virtual function
};

