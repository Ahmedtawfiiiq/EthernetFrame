#include "configurationHandler.h"

#include <iostream>

void ConfigurationHandler::inFile(string path){

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

void ConfigurationHandler::store(string data){
    for(uint16 i = 0; i < data.size(); i++){
        if(ConfigurationHandler::buffer.size() == 110){
            ConfigurationHandler::outFile(ConfigurationHandler::buffer);
            ConfigurationHandler::buffer = "";
        }
        ConfigurationHandler::buffer += data[i];
    }
}

void ConfigurationHandler::outFile(string vec){
    static uint16 k = 0;
    for(uint16 i = 0; i < vec.size(); i++){
        ConfigurationHandler::file << vec[i];
        k++;
        if(k == 8){
            k = 0;
            ConfigurationHandler::file << "\n";
        }
    }
}

void ConfigurationHandler::openFile(string path){
    ConfigurationHandler::file.open(path, ios::out);
}

void ConfigurationHandler::closeFile(){
    ConfigurationHandler::file.close();
}



