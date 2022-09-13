#include "frame_machine.h"
#include "framestates.h"

FrameMachine::FrameMachine(){
    preamble = new preamble_state();
    start_of_packet = new sop_state();
    destination_address = new destination_address_state();
    source_address = new source_address_state();
    length_type = new length_type_state();
    payload = new payload_state();
    fcs = new fcs_state();
    ifg = new ifg_state();
    StateMachine<FrameMachine>::Init(this, preamble);
}

FrameMachine::~FrameMachine(){
    delete preamble;
    delete start_of_packet;
    delete destination_address;
    delete source_address;
    delete length_type;
    delete payload;
    delete fcs;
    delete ifg;
}

// execute current state
void FrameMachine::Update(){
    StateMachine<FrameMachine>::Update();
}

void FrameMachine::out_data(vector<uint8> vec){
    static uint8 k = 0;
    for(uint8 i = 0; i < vec.size(); i++){
        printf("%x", vec[i]);
        k++;
        if(k == 4){
            k = 0;
            cout << endl;
        }
    }
}
