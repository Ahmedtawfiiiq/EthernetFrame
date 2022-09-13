#include <iostream>
#include "acoolstatemachine.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    cout << "Hello State Machine" << endl;
    ACoolStateMachine stateMachine;

    // game loop goes here..
    while(!stateMachine.HasDone()){
        stateMachine.Update();
    }

    return 0;
}
