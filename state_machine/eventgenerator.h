#pragma once
#ifndef EVENTGENERATOR_H
#define EVENTGENERATOR_H

#include <iostream>
#define MAX_COUNTER 5

class Eventgenerator
{
public:
    int m_counter;
    Eventgenerator(){
        // initial value
        m_counter = rand()%MAX_COUNTER + 1;
    }
public:
    // this class is a singleton
    static Eventgenerator *GetInstance();
    void cleanUp(){}
    int Generate(int eventNum);
};

#endif // EVENTGENERATOR_H
