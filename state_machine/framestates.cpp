#include "framestates.h"
#include "frame_machine.h"

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
    //
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> fcs);
}

void fcs_state::Execute(FrameMachine *frame_machine_ptr){
    //
    frame_machine_ptr -> ChangeState(frame_machine_ptr -> ifg);
}

void ifg_state::Execute(FrameMachine *frame_machine_ptr){
    frame_machine_ptr -> Done();
}
