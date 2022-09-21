#include "frameStates.h"
#include "frameMachine.h"
#include "configurationHandler.h"

#define MICROSECONDS 1000000

void PreambleState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::preamble]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::preamble]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::startOfPacket]);
}

void SopState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::startOfPacket]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::startOfPacket]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::destinationAddress]);
}

void DestinationAddressState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::destinationAddress]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::destinationAddress]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::sourceAddress]);
}

void SourceAddressState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::lengthType]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::sourceAddress]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::lengthType]);
}

void LengthTypeState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::payload]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::lengthType]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::payload]);
}

void PayloadState::execute(FrameMachine *frameMachinePtr){
    // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::fcs]);
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::payload]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::fcs]);
}

void FcsState::execute(FrameMachine *frameMachinePtr){
    // compute crc
    ConfigurationHandler::getInstance().store(ConfigurationHandler::getInstance().data[FrameMachine::fcs]);
    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::ifg]);
}

void IfgState::execute(FrameMachine *frameMachinePtr){
    // out ifgs till 30 ifgs are sent or till burst period ended
    uint16 i = 0;
    static uint16 numberOfFrames = 1; // max 3 frames -> 1 burst
    while(true){
        frameMachinePtr -> burstPeriod = clock() - frameMachinePtr -> frameStart;

        // if period ended -> true
        // if period not ended -> false
        bool periodEnded = (frameMachinePtr -> burstPeriod/(float)CLOCKS_PER_SEC*MICROSECONDS) > (float)stoi(ConfigurationHandler::getInstance().data[FrameMachine::burstTime]);
        if(i < (uint16)stoi(ConfigurationHandler::getInstance().data[FrameMachine::ifg])  && !periodEnded){
            // frameMachinePtr -> outFile(ConfigurationHandler::getInstance().data[frameMachine::ifg]);
            ConfigurationHandler::getInstance().store(frameMachinePtr -> FrameMachine::ifgs);
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
                if(numberOfFrames == (uint16)stoi(ConfigurationHandler::getInstance().data[FrameMachine::burstSize])){
                    frameMachinePtr -> done();
                    numberOfFrames = 1;
                    cout << "exit reason -> max frames per burst" << endl;
                }
                else{
                    frameMachinePtr -> changeState(frameMachinePtr -> states[FrameMachine::preamble]);
                    numberOfFrames++;
                }
            }
            break;
        }
    }
}
