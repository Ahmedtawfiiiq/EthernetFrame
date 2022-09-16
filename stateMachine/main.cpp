#include "frameMachine.h"

int main()
{
    cout << "ethernet frame started" << endl;
    frameMachine stateMachine;

    while(!stateMachine.isDone()){
        stateMachine.update();
    }

    return 0;
}
