#include <iostream>
#include "MsgQueue_C.h"
#include <unistd.h>

using namespace std;
int main()
{
    MsgQueue_C mq1("/my_queue",10,SENDER);
    int i = 10;
    while(i){
        mq1.SendMessage(string("this is me"));
        //cout<<"Receiver blocked on message"<<endl;
        //mq1.BlockForMessage();
        cout << "[Server] : Msg Sending complete"<<endl;
        usleep(1000000);
        i--;
    }
    cout<<"Receiver exiting"<<endl;
    return 0;

}

