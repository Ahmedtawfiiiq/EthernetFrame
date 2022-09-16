#include "frameStates.h"
#include "frameMachine.h"

#define MICROSECONDS 1000000

void preambleState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr ->pre);
    frameMachinePtr -> changeState(frameMachinePtr -> startOfPacket);
}

void sopState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr ->sop);
    frameMachinePtr -> changeState(frameMachinePtr -> destinationAddress);
}

void destinationAddressState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr ->dest);
    frameMachinePtr -> changeState(frameMachinePtr -> sourceAddress);
}

void sourceAddressState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr ->src);
    frameMachinePtr -> changeState(frameMachinePtr -> lengthType);
}

void lengthTypeState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr ->type);
    frameMachinePtr -> changeState(frameMachinePtr -> payload);
}

void payloadState::execute(frameMachine *frameMachinePtr){
    frameMachinePtr -> outData(frameMachinePtr -> dPay);
    frameMachinePtr -> changeState(frameMachinePtr -> fcs);
}

void fcsState::execute(frameMachine *frameMachinePtr){
    // compute crc
    frameMachinePtr -> changeState(frameMachinePtr -> ifg);
}

void ifgState::execute(frameMachine *frameMachinePtr){
    // out ifgs till 30 ifgs are sent or till burst period ended
    uint8 i = 0;
    static uint8 numberOfFrames = 1; // max 3 frames -> 1 burst
    while(true){
        frameMachinePtr -> burstPeriod = clock() - frameMachinePtr -> frameStart;

        // if period ended -> true
        // if period not ended -> false
        bool periodEnded = (frameMachinePtr -> burstPeriod/(float)CLOCKS_PER_SEC*MICROSECONDS) > (float)250;
        if(i < 30  && !periodEnded){
            frameMachinePtr -> outData(frameMachinePtr -> ifgs);
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
                if(numberOfFrames == 3){
                    frameMachinePtr -> done();
                    cout << "exit reason -> max frames per burst" << endl;
                }
                else{
                    frameMachinePtr -> changeState(frameMachinePtr -> destinationAddress);
                    numberOfFrames++;
                }
            }
            break;
        }
    }
}
