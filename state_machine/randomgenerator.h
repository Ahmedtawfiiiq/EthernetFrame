#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#define MAX_NUMBER 15

using namespace std;

typedef unsigned char uint8;

class RandomGenerator
{
public:
    // this class is a singleton -> only one instance can be created
    static RandomGenerator *GetInstance();
    void cleanUp(vector<uint8> vec){vec.clear();}
    vector<uint8> Generate();
};
