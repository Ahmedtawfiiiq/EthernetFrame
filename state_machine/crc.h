#ifndef CRC_H
#define CRC_H

#include <iostream>

using namespace std;

class CRC
{
public:
    string msg;
    string crc;
    string encoded="";
public:
    CRC();
    void do_crc();
};

#endif // CRC_H
