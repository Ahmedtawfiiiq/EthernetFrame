#include "randomGenerator.h"

randomGenerator* randomGenerator::getInstance(){
    static randomGenerator instance;
    return &instance;
}

// to fill payload with random data
vector<uint16> randomGenerator::generate(){
    vector<uint16> payloadData; // // 40 bytes -> 80 hexa digit
    for(uint16 i = 0; i < 8; i++){
        for(uint16 j = 0; j < 10; j++){
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            srand(seed);
            payloadData.push_back(rand()%MAX_NUMBER + 1);
        }
    }
    return payloadData;
}
