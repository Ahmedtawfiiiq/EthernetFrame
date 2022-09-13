#include "framestates.h"
#include "frame_machine.h"
#define MICROSECONDS 1000000

void preamble_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr ->pre);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> start_of_packet);
}

void sop_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr ->sop);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> destination_address);
}

void destination_address_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr ->dest);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> source_address);
}

void source_address_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr ->src);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> length_type);
}

void length_type_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr ->type);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> payload);
}

void payload_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> out_data(frame_machine_ptr -> dpay);
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> fcs);
}

void fcs_state::Execute(FrameMachine *frame_machine_ptr){
    // compute crc
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> ifg);
}

void ifg_state::Execute(FrameMachine *frame_machine_ptr){
    // out ifgs till 30 ifgs are sent or till burst period ended
    uint8 i = 0;
    static uint8 number_of_frames = 1; // max 3 frames -> 1 burst
    while(true){
        frame_machine_ptr -> burst_period = clock() - frame_machine_ptr -> frame_start;

        // if period ended -> true
        // if period not ended -> false
        bool period_ended = (frame_machine_ptr -> burst_period/(float)CLOCKS_PER_SEC*MICROSECONDS) > (float)250;
        if(i < 30  && !period_ended){
            frame_machine_ptr -> out_data(frame_machine_ptr -> ifgs);
            i++;
        }
        else{
            // time in micro seconds
            cout << endl << endl << "frame time:" << frame_machine_ptr -> burst_period/(float)CLOCKS_PER_SEC*MICROSECONDS << endl;
            if(period_ended){
                frame_machine_ptr -> Done();
                cout << "exit reason -> time ended" << endl;
            }
            else{
                if(number_of_frames == 3){
                    frame_machine_ptr -> Done();
                    cout << "exit reason -> max bursts" << endl;
                }
                else{
                    frame_machine_ptr -> ChangeState(frame_machine_ptr -> preamble);
                    number_of_frames++;
                }
            }
            break;
        }
    }
}
