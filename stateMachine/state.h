// Specifies that the compiler includes the header file only once,
// when compiling a source code file.
#pragma once

// abstract class for states -> used to create our states
template <class T> class State{
public:
    // virtual functions to be overridden in child classes
    virtual ~State(){}; // destructor
    virtual void enter() = 0;   // pure virtual function
    virtual void execute(T*) = 0; // pure virtual function
    virtual void exit() = 0;    // pure virtual function
};

