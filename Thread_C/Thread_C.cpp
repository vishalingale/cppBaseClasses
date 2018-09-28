#include <Thread_C.h>

using namespace std;
Thread_C::~Thread_C()
{
    cout <<"Thread Destructed"<<endl;
}


Thread_C::Thread_C():
_exit(false),
_unblock_thread(false),
_lock(_mtx)
{
    cout << "Thread Created"<<endl;
}

void Thread_C::Stop()
{
    _exit = true;
    UnBlockThread();
    if(_thread.joinable()){
        _thread.join();
    }
    cout << "Thread exited"<<endl;
}
void Thread_C::Start()
{
    _thread = std::thread(&Thread_C::EventLoop, this);
}
void Thread_C::WaitForEvent()
{
    cout<<"Calling While Loop"<<endl;
    while (!_unblock_thread ){
        cout<<"Locking"<<endl;
        _cond_variable.wait(_lock);
    }
    _unblock_thread = false;
    cout << "Unblocked"<<endl;
}

std::string Thread_C::GetMessage()
{
    cout << "Get message called"<<endl;
    if(!_msg_queue.empty()){
        std::string str = _msg_queue.front(); 
        cout << "Message popped " << str<<endl;
        _msg_queue.pop();
        return str;
    }
    else{
        cout<<"No message present"<<endl;
        return nullptr;
    }
}
bool Thread_C::IsExit()
{
    return _exit;
}
void Thread_C::SendMessage(string str)
{
    _msg_queue.push(str);
    cout<<"Adding message "<<str<<endl;
    UnBlockThread();
}
void Thread_C::UnBlockThread()
{
    cout << "Unblocking Thread"<<endl;
    _unblock_thread     = true;
    _cond_variable.notify_all();
}


