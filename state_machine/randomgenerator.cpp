#include "randomgenerator.h"

RandomGenerator* RandomGenerator::GetInstance(){
    static RandomGenerator s_instance;
    return &s_instance;
}

// to fill payload with random data
vector<uint8> RandomGenerator::Generate(){
    vector<uint8> payload_data; // // 40 bytes -> 80 hexa digit
    for(uint8 i = 0; i < 8; i++){
        for(uint8 j = 0; j < 10; j++){
            unsigned seed = chrono::system_clock::now().time_since_epoch().count();
            srand(seed);
            payload_data.push_back(rand()%MAX_NUMBER + 1);
        }
    }
    return payload_data;
}
