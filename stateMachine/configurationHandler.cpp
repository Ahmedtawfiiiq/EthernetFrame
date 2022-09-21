#include "configurationHandler.h"

#include <chrono>
#include <iostream>
#include <random>
#include <fstream>

void configurationHandler::inFile(string path){

    fstream file;
    string line;

    file.open(path, ios::in);
    if(file.fail()) cout << "file did not open" << endl;
    while(!file.eof()){ // untill we reach end of the file
        getline(file, line);
        if(file.fail()) break;
        data.push_back(line);
    }
    file.close();
}

void configurationHandler::store(string data){
    for(uint16 i = 0; i < data.size(); i++){
        if(configurationHandler::buffer.size() == 110){
            configurationHandler::outFile(configurationHandler::buffer);
            configurationHandler::buffer = "";
        }
        configurationHandler::buffer += data[i];
    }
}

void configurationHandler::outFile(string vec){
    static uint16 k = 0;
    for(uint16 i = 0; i < vec.size(); i++){
        configurationHandler::file << vec[i];
        k++;
        if(k == 8){
            k = 0;
            configurationHandler::file << "\n";
        }
    }
}

void configurationHandler::openFile(string path){
    configurationHandler::file.open(path, ios::out);
}

void configurationHandler::closeFile(){
    configurationHandler::file.close();
}



