#include <iostream>
#include "MsgQueue_C.h"
#include <unistd.h>

using namespace std;
int main()
{
    MsgQueue_C mq1("/my_queue",SENDER);
    int i = 50;
    while(i){
        string msg = string("This is so this is me : ")+std::to_string(i);
        mq1.SendMessage(msg);
        cout << "[Server] : Msg Sending complete : "<<msg<<endl;
        i--;
    }
    cout<<"Sender exiting"<<endl;
    return 0;

}

