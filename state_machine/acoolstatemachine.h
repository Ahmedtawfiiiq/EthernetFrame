#pragma once
#ifndef ACOOLSTATEMACHINE_H
#define ACOOLSTATEMACHINE_H

#include "statemachine.h"

// our created machine
class ACoolStateMachine:public StateMachine<ACoolStateMachine>{
public:
    bool m_done;
    // our machine has 4 states
    State<ACoolStateMachine> *m_startState;
    State<ACoolStateMachine> *m_state1;
    State<ACoolStateMachine> *m_state2;
    State<ACoolStateMachine> *m_stateN;
public:
    ACoolStateMachine();
    ~ACoolStateMachine();
    void Update(); // call update function of parent class
    void Done(){m_done = true;}
    bool HasDone(){return m_done;}
    // friend class StartState;
    // friend class State1;
    // friend class State2;
    // friend class StateN;
};

#endif // ACOOLSTATEMACHINE_H
