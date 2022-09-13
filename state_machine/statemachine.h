#pragma once

#include "state.h"

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

// abstract class for states for FSM (finite state machines)
// used to create our machines
template <class T> class StateMachine{
public:
    T *m_pOwner;               // pointer to our created machine
    State<T> *m_pCurrentState; // pointer to current state
    bool m_firstRun = true;    // flag indicate start state
public:
    StateMachine(){cout << "State machine created" << endl;}    // FSM constructor
    ~StateMachine(){cout << "State machine destroyed" << endl;} // FSM destructor
    void Init(T *pOwner, State<T> *initialState);               // FSM initializer
    void ChangeState(State<T> *newState);                       // FSM state changer
    void Update();                                              // FSM state executor
};

// inline functions are used to access private attributes
// and due to small size of those functions
template<class T>
inline void StateMachine<T>::Init(T *pOwner, State<T> *initialState){
    m_pCurrentState = initialState;
    m_pOwner = pOwner;
    cout << "State machine ready" << endl;
}

template<class T>
inline void StateMachine<T>::ChangeState(State<T> *newState){
    m_pCurrentState -> Exit(m_pOwner);
    m_pCurrentState = newState;        // change state pointer to new state
    m_pCurrentState -> Enter(m_pOwner);
}

template<class T>
inline void StateMachine<T>::Update(){
    if(m_firstRun){
        m_firstRun = false;
        m_pCurrentState -> Enter(m_pOwner);
    }
    m_pCurrentState -> Execute(m_pOwner);
}

#endif // STATEMACHINE_H
