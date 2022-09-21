#include "frameMachine.h"
#include "configurationHandler.h"

int main()
{
    ConfigurationHandler::getInstance().inFile("input.txt");
    ConfigurationHandler::getInstance().openFile("output.txt");

    for(uint16 i = 0; i < stoi(ConfigurationHandler::getInstance().data[FrameMachine::streams]); i++){
        cout << "ethernet frame started" << endl;
        FrameMachine stateMachine;
        while(!stateMachine.isDone()){
            stateMachine.update();
        }
    }

    ConfigurationHandler::getInstance().closeFile();

    return 0;
}
