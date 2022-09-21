#pragma once

#include <vector>

#define MAX_NUMBER 15

using namespace std;

typedef unsigned short uint16;

class randomGenerator
{
public:
    // this class is a singleton -> only one instance can be created

    /*
     * static methods does not depend on object of class
     * we don't need to create an object to use them
     * static methods belong to the class not to a certain object
     */
    static randomGenerator* getInstance(); // return type is a static pointer to a singleton object
    void cleanUp(vector<uint16> vec){vec.clear();}
    vector<uint16> generate();
};
