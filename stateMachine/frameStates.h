#pragma once

#include "state.h"
#include<iostream>

using namespace std;

// preamble state -> start state
class PreambleState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter preamble state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit from preamble state" << endl;}
    ~PreambleState(){cout << endl << "preamble state destroyed" << endl;}
};

// sop state
class SopState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter sop state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << "exit from sop state" << endl;}
    ~SopState(){cout << "sop state destroyed" << endl;}
};

// destination address state
class DestinationAddressState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter destination address state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit destination address state" << endl;}
    ~DestinationAddressState(){cout << "destination address state destroyed" << endl;}
};

// source address state
class SourceAddressState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter source address state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << "exit from source address state" << endl;}
    ~SourceAddressState(){cout << "source address state destroyed" << endl;}
};

// length/type state
class LengthTypeState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter length/type state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit from length/type state" << endl;}
    ~LengthTypeState(){cout << "length/type state destroyed" << endl;}
};

// payload state
class PayloadState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter payload state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit from payload state" << endl;}
    ~PayloadState(){cout << "payload state destroyed" << endl;}
};

// fcs state
class FcsState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter fcs state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit from fcs state" << endl;}
    ~FcsState(){cout << "fcs state destroyed" << endl;}
};

// ifg state
class IfgState:public State<class FrameMachine>{
public:
    void enter(){cout << "enter ifg state" << endl;}
    void execute(FrameMachine*);
    void exit(){cout << endl << "exit from ifg state" << endl;}
    ~IfgState(){cout << "ifg state destroyed" << endl;}
};
