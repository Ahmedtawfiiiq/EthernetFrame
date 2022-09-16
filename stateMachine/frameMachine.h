#pragma once
#include "stateMachine.h"
#include "randomGenerator.h"

#include <fstream>

// our frame machine
class frameMachine:public stateMachine<frameMachine>{
public:
    // ethernet frame configurations
    vector<uint16> pre  = {0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa};
    vector<uint16> sop  = {0xa, 0xb};
    vector<uint16> dest = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x4, 0x0, 0x5, 0x0, 0x6, 0x0};
    vector<uint16> src  = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x3, 0x0, 0x2, 0x0, 0x1, 0x0};
    vector<uint16> type = {0x0, 0x8, 0x0, 0x0};
    vector<uint16> dPay = randomGenerator::getInstance()->generate(); // 40 bytes
    vector<uint16> ifgs = {0x0, 0x7};

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

    ofstream file;

public:
    frameMachine();
    ~frameMachine();
    void update(); // call update function of parent class
    void done(){doneFlag = true;}
    bool isDone(){return doneFlag;}
    void outData(vector<uint16>);
    void openFile(string);
    void closeFile();
    void outFile(vector<uint16>);
};
