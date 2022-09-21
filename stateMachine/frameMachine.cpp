#include "frameMachine.h"
#include "frameStates.h"

frameMachine::frameMachine(){
    states[preamble] = new preambleState();
    states[startOfPacket] = new sopState();
    states[destinationAddress] = new destinationAddressState();
    states[sourceAddress] = new sourceAddressState();
    states[lengthType] = new lengthTypeState();
    states[payload] = new payloadState();
    states[fcs] = new fcsState();
    states[ifg] = new ifgState();
    stateMachine<frameMachine>::init(this, states[preamble]);
}

frameMachine::~frameMachine(){
    delete states[preamble];
    delete states[startOfPacket];
    delete states[destinationAddress];
    delete states[sourceAddress];
    delete states[lengthType];
    delete states[payload];
    delete states[fcs];
    delete states[ifg];
}

// execute current state
void frameMachine::update(){
    stateMachine<frameMachine>::update();
}
