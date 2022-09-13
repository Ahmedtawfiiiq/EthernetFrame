#include "coolstates.h"
#include "acoolstatemachine.h"
#include "eventgenerator.h"

void StartState::Execute(ACoolStateMachine *pOwner){
    cout << "StartState: Executing something cool.." << endl;
    // at the beginning, we are in this start state
    // we are waiting for an event to occur so that we can
    // jump to state1
    if(Eventgenerator::GetInstance() -> Generate(1)){
        // here the event has occured
        pOwner -> ChangeState(pOwner -> m_state1);
    }
}

void State1::Execute(ACoolStateMachine *pOwner){
    cout << "State1: Executing something cool.." << endl;
    // in state1, we are waiting for 2 events
    // one for jumping to state2
    // and another is for jumping to stateN
    int event = Eventgenerator::GetInstance()->Generate(2);
    if(event == 2){
        // here the event has occured
        pOwner -> ChangeState(pOwner -> m_state2);
    }
    else if (event == 1){
        pOwner -> ChangeState(pOwner -> m_stateN);
    }
}

void State2::Execute(ACoolStateMachine *pOwner){
    cout << "State2: Executing something cool.." << endl;
    // at state 2, when the event occur. we jump back
    // to state1
    if(Eventgenerator::GetInstance()->Generate(1)){
        // here the event has occured
        pOwner -> ChangeState(pOwner -> m_state1);
    }
}

void StateN::Execute(ACoolStateMachine *pOwner){
    // and finally, when we reach this state,
    // the program is terminated, and we don't go any where any more
    pOwner -> Done();
    cout << "StateN: Terminated" << endl;

}
