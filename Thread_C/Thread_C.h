#include<mutex>
#include<thread>
#include<string>
#include<queue>
#include<iostream>
#include<condition_variable>
#ifndef _THREAD_C_HEADER_
#define _THREAD_C_HEADER_


using namespace std;
class Thread_C
{
    public:
    	//< Constructor 
        Thread_C();

	//< Destructor
        ~Thread_C();

	//< Unblock The thread in case of externally trigged event
        void UnBlockThread();

	//< Block the thread until an event is received
        void WaitForEvent();

	//< Function which will run in the thread
	//< This should be overridden by the inherited class
        virtual void EventLoop(){cout  << "Inside base Thread"<<endl;};

	//< Send a message to the Thread
	//< The message will be put in a queue
	//< Inherited class can override this function	
	virtual void SendMessage(string str);

    //< Get the message from queue
    string GetMessage();

	//< The the execution of thread
	void Start();

	//< Stop the execution of thread
	void Stop();

    //< Return false if thread needs to exit
    bool IsExit();
    private:
        bool                            _exit;
        bool                            _unblock_thread;
        std::mutex                      _mtx;
        std::thread                     _thread;
   	    std::queue<string>		        _msg_queue; 
        std::condition_variable         _cond_variable;
        std::unique_lock<std::mutex>    _lock;

	/* Member function */
	
};
#endif
