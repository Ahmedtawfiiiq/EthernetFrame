#pragma once

#include <chrono>
#include <random>

#define MAX_NUMBER 15

using namespace std;

typedef unsigned short uint16;

class randomGenerator
{
public:
    // this class is a singleton -> only one instance can be created
    static randomGenerator *getInstance();
    void cleanUp(vector<uint16> vec){vec.clear();}
    vector<uint16> generate();
};
