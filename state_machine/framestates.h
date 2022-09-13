#pragma once

#include "state.h"

// preamble state -> start state
class preamble_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter preamble state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit from preamble state" << endl;}
    ~preamble_state(){cout << endl << "preamble state destroyed" << endl;}
};

// sop state
class sop_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter sop state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << "exit from sop state" << endl;}
    ~sop_state(){cout << "sop state destroyed" << endl;}
};

// destination address state
class destination_address_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter destination address state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit destination address state" << endl;}
    ~destination_address_state(){cout << "destination address state destroyed" << endl;}
};

// source address state
class source_address_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter source address state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << "exit from source address state" << endl;}
    ~source_address_state(){cout << "source address state destroyed" << endl;}
};

// length/type state
class length_type_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter length/type state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit from length/type state" << endl;}
    ~length_type_state(){cout << "length/type state destroyed" << endl;}
};

// payload state
class payload_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter payload state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit from payload state" << endl;}
    ~payload_state(){cout << "payload state destroyed" << endl;}
};

// fcs state
class fcs_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter fcs state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit from fcs state" << endl;}
    ~fcs_state(){cout << "fcs state destroyed" << endl;}
};

// ifg state
class ifg_state:public State<class FrameMachine>{
public:
    void Enter(){cout << "enter ifg state" << endl;}
    void Execute(FrameMachine*);
    void Exit(){cout << endl << "exit from ifg state" << endl;}
    ~ifg_state(){cout << "ifg state destroyed" << endl;}
};
