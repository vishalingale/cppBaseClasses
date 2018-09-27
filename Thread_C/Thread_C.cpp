#include <Thread_C.h>

using namespace std;
Thread_C::~Thread_C()
{
    _exit = true;
    cout << "Calling Destructor"<<endl;
    if(_thread.joinable())
        _thread.join();
    cout << "Thread exited"<<endl;
}


Thread_C::Thread_C()
{
    _thread = std::thread(&Thread_C::EventLoop, this);
    cout << "Thread Created"<<endl;
}



void Thread_C::WaitForEvent()
{
    while (!_unblock_thread )
        _cond_variable.wait(_lock);
}


void Thread_C::UnBlockThread()
{
    _unblock_thread     = true;
    _cond_variable.notify_all();
}


