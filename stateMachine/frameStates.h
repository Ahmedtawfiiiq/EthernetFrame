#pragma once

#include "state.h"

// preamble state -> start state
class preambleState:public state<class frameMachine>{
public:
    void enter(){cout << "enter preamble state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit from preamble state" << endl;}
    ~preambleState(){cout << endl << "preamble state destroyed" << endl;}
};

// sop state
class sopState:public state<class frameMachine>{
public:
    void enter(){cout << "enter sop state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << "exit from sop state" << endl;}
    ~sopState(){cout << "sop state destroyed" << endl;}
};

// destination address state
class destinationAddressState:public state<class frameMachine>{
public:
    void enter(){cout << "enter destination address state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit destination address state" << endl;}
    ~destinationAddressState(){cout << "destination address state destroyed" << endl;}
};

// source address state
class sourceAddressState:public state<class frameMachine>{
public:
    void enter(){cout << "enter source address state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << "exit from source address state" << endl;}
    ~sourceAddressState(){cout << "source address state destroyed" << endl;}
};

// length/type state
class lengthTypeState:public state<class frameMachine>{
public:
    void enter(){cout << "enter length/type state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit from length/type state" << endl;}
    ~lengthTypeState(){cout << "length/type state destroyed" << endl;}
};

// payload state
class payloadState:public state<class frameMachine>{
public:
    void enter(){cout << "enter payload state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit from payload state" << endl;}
    ~payloadState(){cout << "payload state destroyed" << endl;}
};

// fcs state
class fcsState:public state<class frameMachine>{
public:
    void enter(){cout << "enter fcs state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit from fcs state" << endl;}
    ~fcsState(){cout << "fcs state destroyed" << endl;}
};

// ifg state
class ifgState:public state<class frameMachine>{
public:
    void enter(){cout << "enter ifg state" << endl;}
    void execute(frameMachine*);
    void exit(){cout << endl << "exit from ifg state" << endl;}
    ~ifgState(){cout << "ifg state destroyed" << endl;}
};
