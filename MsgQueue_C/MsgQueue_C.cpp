#include <MsgQueue_C.h>

using namespace std;

MsgQueue_C::MsgQueue_C(string name, int max_size,Type_C type)
{
    _queue_name         = name;
    _max_msg_size       = max_size;
    _max_messages       = 10;
    _attr.mq_flags      = 0;
    _attr.mq_maxmsg     = 10;
    _attr.mq_msgsize    = 1024;
    _attr.mq_curmsgs    = 0;
    _msg_ptr            = (char *)malloc(sizeof(char) * _max_msg_size);
    _type               = type;
    if(_msg_ptr)
        memset(_msg_ptr , 0 , _max_msg_size);

    if(type == RECEIVER){
        _mq = mq_open(name.c_str(), O_CREAT | O_RDONLY , 0644, &_attr);
        if(_mq == -1)
        {
            printf("Name = %s \n",name.c_str());
            cout << "Failed initilization of message queue   : "<<errno <<endl;
        }
        cout << "Message que created for Receiver : "<<name << endl;
    }
    else{
        _mq = mq_open(name.c_str(), O_WRONLY);
        cout << "Message que created for Sender"<<endl;
    }
}


MsgQueue_C::~MsgQueue_C()
{
    if(_msg_ptr){
        free(_msg_ptr);
        _msg_ptr = 0;
    }
    mq_close(_mq);
    if(_type == RECEIVER)
        mq_unlink(_queue_name.c_str());
}


void MsgQueue_C::BlockForMessage()
{
    memset(_msg_ptr, 0x00, _max_msg_size);
    int bytes_read = mq_receive(_mq,_msg_ptr,1024, NULL);
    cout << "Error : "<<errno<< "Bytes read  :" << bytes_read<<endl;
    if(bytes_read >= 0) {
        printf("SERVER: Received message: %s\n", _msg_ptr);
    } else {
        printf("SERVER: None \n");
    }

    fflush(stdout);
}

void MsgQueue_C::GetIncomingMessage()
{

}
void MsgQueue_C::SendMessage(string str)
{
    static int count=0;
    snprintf(_msg_ptr, _max_msg_size, "MESSAGE %d", count++);

    printf("CLIENT: Send message... \n");
    mq_send(_mq, _msg_ptr, _max_msg_size, 0);

    fflush(stdout);

}


