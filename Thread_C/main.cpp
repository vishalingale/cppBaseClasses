#include <iostream>
#include "Thread_C.h"
#include <unistd.h>

using namespace std;
class CloudUpload_C:public Thread_C
{
    private: 
        void EventLoop();
};


class CloudDownload_C:public Thread_C
{
    private: 
        void EventLoop() override;
};

void CloudUpload_C::EventLoop()
{
    int i=10;
    while(i)
    {

        cout<<"Inside Cloud Upload Event loop"<<endl;
        i--;
    }
}

void CloudDownload_C::EventLoop()
{
    int i=10;
    while(i)
    {

        cout<<"Inside Cloud Download Event loop"<<endl;
        i--;
    }
}

int main()
{

    CloudUpload_C t1;
    CloudDownload_C t2;

    usleep(5000000);
    return 0;
}
