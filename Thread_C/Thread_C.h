#include<mutex>
#include<thread>
#include<iostream>
#include<condition_variable>
#ifndef _THREAD_C_HEADER_
#define _THREAD_C_HEADER_
class Thread_C
{
    public:
        Thread_C();
        virtual ~Thread_C();
        void UnBlockThread();
   
    private:
        bool                            _exit;
        bool                            _unblock_thread;
        std::thread                     _thread;
        std::condition_variable         _cond_variable;
        std::unique_lock<std::mutex>    _lock;
    
        void WaitForEvent();
        virtual void EventLoop(){;};

};
#endif
