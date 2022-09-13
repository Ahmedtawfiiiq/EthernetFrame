#pragma once

#include "state.h"

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

// abstract class for states for FSM (finite state machines)
// used to create our machines
template <class T> class StateMachine{
public:
    T *frame_ptr;               // pointer to our created machine
    State<T> *current_state_ptr; // pointer to current state
    bool first_run = true;    // flag indicate start state
public:
    StateMachine(){cout << "frame machine created" << endl;}    // FSM constructor
    ~StateMachine(){cout << "frame machine destroyed" << endl;} // FSM destructor
    void Init(T*, State<T>*);               // FSM initializer
    void ChangeState(State<T>*);                       // FSM state changer
    void Update();                                              // FSM state executor
};

// inline functions are used to access private attributes
// and due to small size of those functions
template<class T>
inline void StateMachine<T>::Init(T *frame_machine_ptr, State<T> *initialState){
    current_state_ptr = initialState;
    frame_ptr = frame_machine_ptr;
    cout << "frame machine inilalized" << endl;
}

template<class T>
inline void StateMachine<T>::ChangeState(State<T> *newState){
    current_state_ptr -> Exit();
    current_state_ptr = newState;        // change state pointer to new state
    current_state_ptr -> Enter();
}

template<class T>
inline void StateMachine<T>::Update(){
    if(first_run){
        first_run = false;
        current_state_ptr -> Enter();
    }
    current_state_ptr -> Execute(frame_ptr);
}

#endif // STATEMACHINE_H
