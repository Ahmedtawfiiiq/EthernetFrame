#pragma once
#include "stateMachine.h"

#include <vector>
#include <fstream>

// our frame machine
class frameMachine:public stateMachine<frameMachine>{
public:
    // Ethernet frame has 8 states
    enum configuration{
        preamble           = 0,
        startOfPacket      = 1,
        destinationAddress = 2,
        sourceAddress      = 3,
        lengthType         = 4,
        payload            = 5,
        fcs                = 6,
        ifg                = 7,
        burstTime          = 8,
        burstSize          = 9,
        streams            = 10
    };
public:
    // ethernet frame configurations
    state<frameMachine>* states[8];
    string ifgs = "07";
    string buffer = "";

    clock_t frameStart = clock();
    clock_t burstPeriod;

    bool doneFlag = false;

public:
    frameMachine();
    ~frameMachine();
    void update(); // call update function of parent class
    void done(){doneFlag = true;}
    bool isDone(){return doneFlag;}
};
