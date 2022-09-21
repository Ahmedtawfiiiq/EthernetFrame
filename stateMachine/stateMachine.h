#pragma once
#include "state.h"

// abstract class for states for FSM (finite state machines)
// used to create our machines
template <class T> class stateMachine{
private:
    T *framePtr;               // pointer to our created machine
    state<T> *currentStatePtr; // pointer to current state
    bool firstRun = true;    // flag indicate start state
public:
    stateMachine(){cout << "frame machine created" << endl;}    // FSM constructor
    ~stateMachine(){cout << "frame machine destroyed" << endl;} // FSM destructor
    void init(T*, state<T>*);               // FSM initializer
    void changeState(state<T>*);                       // FSM state changer
    void update();                                              // FSM state executor
};

// inline functions are used to access private attributes
// and due to small size of those functions
template<class T>
inline void stateMachine<T>::init(T *frame_machine_ptr, state<T> *initialState){
    currentStatePtr = initialState;
    framePtr = frame_machine_ptr;
    cout << "frame machine inilalized" << endl;
}

template<class T>
inline void stateMachine<T>::changeState(state<T> *newState){
    currentStatePtr -> exit();
    currentStatePtr = newState;        // change state pointer to new state
    currentStatePtr -> enter();
}

template<class T>
inline void stateMachine<T>::update(){
    if(firstRun){
        firstRun = false;
        currentStatePtr -> enter();
    }
    currentStatePtr -> execute(framePtr);
}
