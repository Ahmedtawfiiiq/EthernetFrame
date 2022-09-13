#include "frame_machine.h"
#include "randomgenerator.h"

int main()
{
    RandomGenerator data;
    data.Generate();

    cout << "ethernet frame started" << endl;
    FrameMachine stateMachine;

    while(!stateMachine.isDone()){
        stateMachine.Update();
    }

    return 0;
}
