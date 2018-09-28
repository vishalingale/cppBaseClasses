#include <mutex>
#include <string>
#include <queue>
#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#ifndef _MSG_QUEUE_C_HEADER_
#define _MSG_QUEUE_C_HEADER_

typedef enum TYPE_C
{
    RECEIVER,
    SENDER
}Type_C;
using namespace std;
class MsgQueue_C
{
    public:
        //< Constructor
        MsgQueue_C(){};
        MsgQueue_C(string name, int max_size, Type_C type);

        //< Destructor
        ~MsgQueue_C();

        void GetIncomingMessage();
        void BlockForMessage();
        void SendMessage(string str);


    private:
        mqd_t                      _mq;
        char                        *_msg_ptr;
        struct mq_attr             _attr;
        mutex                      _mtx;
        string                     _name;
        int                         _max_msg_size;
        int                         _max_messages;
        Type_C                      _type;
        string                      _queue_name;
};
#endif
