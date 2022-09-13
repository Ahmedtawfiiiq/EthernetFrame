#pragma once
#include "statemachine.h"
#include "randomgenerator.h"
#include <ctime>

// our frame machine
class FrameMachine:public StateMachine<FrameMachine>{
public:

    RandomGenerator data;
    // ethernet frame configurations
    vector<uint8> pre  = {0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa, 0xa};
    vector<uint8> sop  = {0xa, 0xb};
    vector<uint8> dest = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x4, 0x0, 0x5, 0x0, 0x6, 0x0};
    vector<uint8> src  = {0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x3, 0x0, 0x2, 0x0, 0x1, 0x0};
    vector<uint8> type = {0x0, 0x8, 0x0, 0x0};
    vector<uint8> dpay = data.Generate(); // 40 bytes
    vector<uint8> ifgs = {0x0, 0x7};

    // Ethernet frame has 8 states [1:preamble
    //                              2:sop
    //                              3:destination address
    //                              4:source address
    //                              5:length/type
    //                              6:payload
    //                              7:fcs
    //                              8:ifg]
    State<FrameMachine> *preamble;
    State<FrameMachine> *start_of_packet;
    State<FrameMachine> *destination_address;
    State<FrameMachine> *source_address;
    State<FrameMachine> *length_type;
    State<FrameMachine> *payload;
    State<FrameMachine> *fcs;
    State<FrameMachine> *ifg;

    clock_t frame_start = clock();
    clock_t burst_period;  // burst = 400 micro seconds

    bool done = false;

public:
    FrameMachine();
    ~FrameMachine();
    void Update(); // call update function of parent class
    void Done(){done = true;}
    bool isDone(){return done;}
    void out_data(vector<uint8>);
};
