#include <iostream>
#include "Thread_C.h"
#include <unistd.h>

using namespace std;
class CloudUpload_C:public Thread_C
{
    public:
        void EventLoop() override
        {
            while(IsExit())
            {
                cout << "Main wating "<<endl;
                WaitForEvent();
                cout << "Main Unblocked "<<endl;
                string msg = GetMessage();
                cout<< "Message received by Thread "<<msg<<endl;
            }
            cout << "Main Loop Exited"<<endl;
        }
};


class CloudDownload_C:public Thread_C
{
    public:
        void EventLoop() override
        {
            while(IsExit())
            {
                cout << "Main wating "<<endl;
                WaitForEvent();
                cout << "Main Unblocked "<<endl;
                string msg = GetMessage();
                cout<< "Message received by Thread "<<msg<<endl;
            }
        }
};


int main()
{

    CloudUpload_C t1;
    CloudDownload_C t2;
    t1.Start();
    t2.Start();
    int i = 10;
    while(i){
        usleep(1000000);
        t1.SendMessage(string("Msg ")+std::to_string(i));
        t2.SendMessage(string("Msg ")+std::to_string(i));
        i--;
    }
    cout<<"Main Stopping Threads"<<endl;
    t2.Stop();
    t1.Stop();
    return 0;
}
