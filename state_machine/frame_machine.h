#pragma once
#include "statemachine.h"

// our frame machine
class FrameMachine:public StateMachine<FrameMachine>{
public:
    // ethernet frame configurations
    // stream duration = 1000 micro seconds -> let 10 seconds
    // burst period = 100 micro seconds -> let 1 second
    // frames per burst = 3 frames
    // 1000 micro seconds (1 milli seconds) -> 30 frames -> let in 10 seconds

    vector<uint8> pre  = {0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa};
    vector<uint8> sop  = {0xab};
    vector<uint8> dest = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60};
    vector<uint8> src  = {0x10, 0x20, 0x30, 0x30, 0x20, 0x10};
    vector<uint8> type = {0x08, 0x00};

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

    bool done = false;

public:
    FrameMachine();
    ~FrameMachine();
    void Update(); // call update function of parent class
    void Done(){done = true;}
    bool isDone(){return done;}
    void out_data(vector<uint8>);
};
