#pragma once
#include "stateMachine.h"
#include "randomGenerator.h"

// our frame machine
class frameMachine:public stateMachine<frameMachine>{
public:
    // ethernet frame configurations
    vector<uint8> pre  = {0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa};
    vector<uint8> sop  = {0xa, 0xb};
    vector<uint8> dest = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x4, 0x0, 0x5, 0x0, 0x6, 0x0};
    vector<uint8> src  = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x3, 0x0, 0x2, 0x0, 0x1, 0x0};
    vector<uint8> type = {0x0, 0x8, 0x0, 0x0};
    vector<uint8> dPay = randomGenerator::getInstance()->generate(); // 40 bytes
    vector<uint8> ifgs = {0x0, 0x7};

    // Ethernet frame has 8 states [1:preamble
    //                              2:sop
    //                              3:destination address
    //                              4:source address
    //                              5:length/type
    //                              6:payload
    //                              7:fcs
    //                              8:ifg]
    state<frameMachine> *preamble;
    state<frameMachine> *startOfPacket;
    state<frameMachine> *destinationAddress;
    state<frameMachine> *sourceAddress;
    state<frameMachine> *lengthType;
    state<frameMachine> *payload;
    state<frameMachine> *fcs;
    state<frameMachine> *ifg;

    clock_t frameStart = clock();
    clock_t burstPeriod;  // burst = 400 micro seconds

    bool doneFlag = false;

public:
    frameMachine();
    ~frameMachine();
    void update(); // call update function of parent class
    void done(){doneFlag = true;}
    void outData(vector<uint8>);
    bool isDone(){return doneFlag;}
};
