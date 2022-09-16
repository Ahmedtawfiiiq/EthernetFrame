#include "frameMachine.h"
#include "frameStates.h"

frameMachine::frameMachine(){
    preamble = new preambleState();
    startOfPacket = new sopState();
    destinationAddress = new destinationAddressState();
    sourceAddress = new sourceAddressState();
    lengthType = new lengthTypeState();
    payload = new payloadState();
    fcs = new fcsState();
    ifg = new ifgState();
    stateMachine<frameMachine>::init(this, preamble);
}

frameMachine::~frameMachine(){
    delete preamble;
    delete startOfPacket;
    delete destinationAddress;
    delete sourceAddress;
    delete lengthType;
    delete payload;
    delete fcs;
    delete ifg;
}

// execute current state
void frameMachine::update(){
    stateMachine<frameMachine>::update();
}

void frameMachine::outData(vector<uint16> vec){
    static uint16 k = 0;
    for(uint16 i = 0; i < vec.size(); i++){
        printf("%x", vec[i]);
        k++;
        if(k == 8){
            k = 0;
            cout << endl;
        }
    }
}

void frameMachine::openFile(string path){
    frameMachine::file.open(path, ios::out);
}

void frameMachine::closeFile(){
    frameMachine::file.close();
}

void frameMachine::outFile(vector<uint16> vec){
    static uint16 k = 0;
    for(uint16 i = 0; i < vec.size(); i++){
        frameMachine::file << hex << vec[i];
        k++;
        if(k == 8){
            k = 0;
            frameMachine::file << "\n";
        }
    }
}
