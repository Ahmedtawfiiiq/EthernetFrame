#include "acoolstatemachine.h"
#include "coolstates.h"

// our machine constructor
// it creates 4 different state instances
// and initialize our machine with start state
ACoolStateMachine::ACoolStateMachine(){
    m_startState = new StartState();
    m_state1 = new State1();
    m_state2 = new State2();
    m_stateN = new StateN();
    StateMachine<ACoolStateMachine>::Init(this, m_startState);
}

// our machine destructor
// it destroys all created states of the machine
// call all destructors of states
ACoolStateMachine::~ACoolStateMachine(){
    delete m_startState;
    delete m_state1;
    delete m_state2;
    delete m_stateN;
}

// execute current state
void ACoolStateMachine::Update(){
    StateMachine<ACoolStateMachine>::Update();
}
