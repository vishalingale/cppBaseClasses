#include <iostream>
#include "MsgQueue_C.h"
#include <unistd.h>

using namespace std;
int main()
{
    MsgQueue_C mq1("/my_queue",10,RECEIVER);
    int i = 40000;
    while(i){
        cout<<"[RECEIVER] : Receiver blocked on message"<<endl;
        mq1.BlockForMessage();
        cout << "[RECEIVER] : Msg recived complete"<<endl;
        i--;
    }
    cout<<"Receiver exiting"<<endl;
    return 0;
}