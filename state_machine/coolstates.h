#pragma once
#ifndef COOLSTATES_H
#define COOLSTATES_H

#include "state.h"

// start state
class StartState:public State<class ACoolStateMachine>{
public:
    ~StartState(){cout << "Start State Destroyed" << endl;}
    void Enter(ACoolStateMachine *pOwner){
        cout << "Enter Start State" << endl;
    }
    void Execute(ACoolStateMachine *pOwner);
    void Exit(ACoolStateMachine *pOwner){
        cout << "Exit from Start State" << endl;
    }
};

// first state
class State1:public State<class ACoolStateMachine>{
public:
    ~State1(){cout << "State1 Destroyed" << endl;}
    void Enter(ACoolStateMachine *pOwner){
        cout << "Enter State1" << endl;
    }
    void Execute(ACoolStateMachine *pOwner);
    void Exit(ACoolStateMachine *pOwner){
        cout << "Exit from State1" << endl;
    }
};

// second state
class State2:public State<class ACoolStateMachine>{
public:
    ~State2(){cout << "State2 Destroyed" << endl;}
    void Enter(ACoolStateMachine *pOwner){
        cout << "Enter State2" << endl;
    }
    void Execute(ACoolStateMachine *pOwner);
    void Exit(ACoolStateMachine *pOwner){
        cout << "Exit from State2" << endl;
    }
};

// N state
class StateN:public State<class ACoolStateMachine>{
public:
    ~StateN(){cout << "StateN Destroyed" << endl;}
    void Enter(ACoolStateMachine *pOwner){
        cout << "Enter StateN" << endl;
    }
    void Execute(ACoolStateMachine *pOwner);
    void Exit(ACoolStateMachine *pOwner){
        cout << "Exit from StateN" << endl;
    }
};

#endif // COOLSTATES_H
