#include <iostream>
#include "MsgQueue_C.h"
#include <unistd.h>

using namespace std;
int main()
{
    MsgQueue_C mq1("/my_queue",1024,SENDER);
    int i = 3;
    while(i){
        string msg = string("This is also this is me : ")+std::to_string(i);
        mq1.SendMessage(msg);
        //cout<<"Receiver blocked on message"<<endl;
        //mq1.BlockForMessage();
        cout << "[Server] : Msg Sending complete : "<<msg<<endl;
        usleep(1000000);
        i--;
    }
    cout<<"Sender exiting"<<endl;
    return 0;

}

