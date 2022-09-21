#include "frameStates.h"
#include "frameMachine.h"
#include "configurationHandler.h"

#define MICROSECONDS 1000000

void preambleState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::preamble]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::preamble]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::startOfPacket]);
}

void sopState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::startOfPacket]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::startOfPacket]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::destinationAddress]);
}

void destinationAddressState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::destinationAddress]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::destinationAddress]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::sourceAddress]);
}

void sourceAddressState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::lengthType]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::sourceAddress]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::lengthType]);
}

void lengthTypeState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::payload]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::lengthType]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::payload]);
}

void payloadState::execute(frameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::fcs]);
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::payload]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::fcs]);
}

void fcsState::execute(frameMachine *frameMachinePtr){
    // compute crc
    configurationHandler::getInstance().store(configurationHandler::getInstance().data[frameMachine::fcs]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::ifg]);
}

void ifgState::execute(frameMachine *frameMachinePtr){
    // out ifgs till 30 ifgs are sent or till burst period ended
    uint16 i = 0;
    static uint16 numberOfFrames = 1; // max 3 frames -> 1 burst
    while(true){
        frameMachinePtr -> burstPeriod = clock() - frameMachinePtr -> frameStart;

        // if period ended -> true
        // if period not ended -> false
        bool periodEnded = (frameMachinePtr -> burstPeriod/(float)CLOCKS_PER_SEC*MICROSECONDS) > (float)stoi(configurationHandler::getInstance().data[frameMachine::burstTime]);
        if(i < (uint16)stoi(configurationHandler::getInstance().data[frameMachine::ifg])  && !periodEnded){
            // frameMachinePtr -> outFile(configurationHandler::getInstance().data[frameMachine::ifg]);
            configurationHandler::getInstance().store(frameMachinePtr -> frameMachine::ifgs);
            i++;
        }
        else{
            // time in micro seconds
            cout << endl << endl << "frame time:" << frameMachinePtr -> burstPeriod/(float)CLOCKS_PER_SEC*MICROSECONDS << endl;
            if(periodEnded){
                frameMachinePtr -> done();
                cout << "exit reason -> time ended" << endl;
            }
            else{
                if(numberOfFrames == (uint16)stoi(configurationHandler::getInstance().data[frameMachine::burstSize])){
                    frameMachinePtr -> done();
                    numberOfFrames = 1;
                    cout << "exit reason -> max frames per burst" << endl;
                }
                else{
                    frameMachinePtr -> changeState(frameMachinePtr -> states[frameMachine::preamble]);
                    numberOfFrames++;
                }
            }
            break;
        }
    }
}
