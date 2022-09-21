#include "frameMachine.h"
#include "configurationHandler.h"

int main()
{
    configurationHandler::getInstance().inFile("input.txt");
    configurationHandler::getInstance().openFile("output.txt");

    for(uint16 i = 0; i < stoi(configurationHandler::getInstance().data[frameMachine::streams]); i++){
        cout << "ethernet frame started" << endl;
        frameMachine stateMachine;
        while(!stateMachine.isDone()){
            stateMachine.update();
        }
    }

    configurationHandler::getInstance().closeFile();

    return 0;
}
