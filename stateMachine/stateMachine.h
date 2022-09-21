#pragma once

#include "state.h"
#include <iostream>

using namespace std;

// abstract class for states for FSM (finite state machines)
// used to create our machines
template <class T>
class StateMachine
{
private:
    T *framePtr;               // pointer to our created machine
    State<T> *currentStatePtr; // pointer to current state
    bool firstRun = true;      // flag indicate start state
public:
    StateMachine() { cout << "frame machine created" << endl; }    // FSM constructor
    ~StateMachine() { cout << "frame machine destroyed" << endl; } // FSM destructor
    void init(T *, State<T> *);                                    // FSM initializer
    void changeState(State<T> *);                                  // FSM state changer
    void update();                                                 // FSM state executor
};

// inline functions are used to access private attributes
// and due to small size of those functions
template <class T>
inline void StateMachine<T>::init(T *frameMachinePtr, State<T> *initialState)
{
    currentStatePtr = initialState;
    framePtr = frameMachinePtr;
    cout << "frame machine inilalized" << endl;
}

template <class T>
inline void StateMachine<T>::changeState(State<T> *newState)
{
    currentStatePtr->exit();
    currentStatePtr = newState; // change state pointer to new state
    currentStatePtr->enter();
}

template <class T>
inline void StateMachine<T>::update()
{
    if (firstRun)
    {
        firstRun = false;
        currentStatePtr->enter();
    }
    currentStatePtr->execute(framePtr);
}
