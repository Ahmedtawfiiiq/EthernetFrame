#include "frameMachine.h"
#include "frameStates.h"

FrameMachine::FrameMachine(){
    states[preamble] = new PreambleState();
    states[startOfPacket] = new SopState();
    states[destinationAddress] = new DestinationAddressState();
    states[sourceAddress] = new SourceAddressState();
    states[lengthType] = new LengthTypeState();
    states[payload] = new PayloadState();
    states[fcs] = new FcsState();
    states[ifg] = new IfgState();
    StateMachine<FrameMachine>::init(this, states[preamble]);
}

FrameMachine::~FrameMachine(){
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
void FrameMachine::update(){
    StateMachine<FrameMachine>::update();
}
