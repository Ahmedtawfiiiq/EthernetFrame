#include "frame_machine.h"
#include <unistd.h> // used only for linux machines

int main()
{
    cout << "ethernet frame started" << endl;
    FrameMachine stateMachine;

    while(!stateMachine.isDone()){
        stateMachine.Update();
    }

    return 0;
}
