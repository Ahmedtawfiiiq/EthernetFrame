#include "eventgenerator.h"

Eventgenerator* Eventgenerator::GetInstance(){
    static Eventgenerator s_instance;
    return &s_instance;
}

int Eventgenerator::Generate(int eventNum){
    if(m_counter == 0){
        m_counter = rand()%MAX_COUNTER + 1;
        if(eventNum > 1)
            return rand()%eventNum+1;
        return 1;
    }
    else{
        m_counter--;
    }
    return 0;
}
