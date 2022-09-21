#pragma once

#include <vector>
#include <fstream>

using namespace std;

typedef unsigned short uint16;

// singleton class
class configurationHandler
{
public:
    vector<string> data;
    fstream file;
    string buffer = "";
private:
    configurationHandler() = default;
public:
    void inFile(string);
    void store(string);
    void outFile(string);
    void openFile(string);
    void closeFile();

    static configurationHandler& getInstance(){static configurationHandler instance; return instance;}
    // delete copy constructor -> className newInstanceName(oldInstanceName);
    configurationHandler(const configurationHandler&) = delete;
    // delete copy assignment operator -> className newInstanceName = oldInstanceName;
    configurationHandler& operator=(const configurationHandler&) = delete;
    // delete move constructor
    configurationHandler(configurationHandler&&) = delete;
    // delete move assignment operator
    configurationHandler& operator=(configurationHandler&&) = delete;
};
