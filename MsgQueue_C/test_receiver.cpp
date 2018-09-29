#include <iostream>
#include "MsgQueue_C.h"
#include <unistd.h>

using namespace std;
int main()
{
    MsgQueue_C mq1("/my_queue",RECEIVER);
    int i = 50;
    while(i){
        cout<<"[RECEIVER] : Receiver blocked on message"<<endl;
        string str;
        mq1.BlockForMessage(str);
        usleep(1000000);
        cout << "[RECEIVER] : Msg recived complete   :  "<<str << endl;
        i--;
    }
    cout<<"Receiver exiting"<<endl;
    return 0;
}
