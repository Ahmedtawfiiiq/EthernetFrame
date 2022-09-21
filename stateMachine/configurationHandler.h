#pragma once

#include <vector>
#include <fstream>

using namespace std;

typedef unsigned short uint16;

// singleton class
class ConfigurationHandler
{
public:
    vector<string> data;
    fstream file;
    string buffer = "";
private:
    ConfigurationHandler() = default;
public:
    void inFile(string);
    void store(string);
    void outFile(string);
    void openFile(string);
    void closeFile();

    static ConfigurationHandler& getInstance(){static ConfigurationHandler instance; return instance;}
    // delete copy constructor -> className newInstanceName(oldInstanceName);
    ConfigurationHandler(const ConfigurationHandler&) = delete;
    // delete copy assignment operator -> className newInstanceName = oldInstanceName;
    ConfigurationHandler& operator=(const ConfigurationHandler&) = delete;
    // delete move constructor
    ConfigurationHandler(ConfigurationHandler&&) = delete;
    // delete move assignment operator
    ConfigurationHandler& operator=(ConfigurationHandler&&) = delete;
};
