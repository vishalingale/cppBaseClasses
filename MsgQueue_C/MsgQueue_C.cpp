#include <MsgQueue_C.h>

using namespace std;

MsgQueue_C::MsgQueue_C(string name, Type_C type)
{
    _queue_name         = name;
    _attr.mq_flags      = 0;
    _attr.mq_maxmsg     = 10;
    _attr.mq_msgsize    = MAX_MSG_SIZE;
    _attr.mq_curmsgs    = 0;
    _type               = type;

    if(type == RECEIVER){
        _mq = mq_open(name.c_str(), O_CREAT | O_RDONLY,0644, &_attr);
        if(_mq == -1){
            cout << "Failed initilization of message queue   : "<<errno <<endl;
        }
        else{
            cout << "Message queue created for : "<<name << endl;
        }
    }
    else{
        _mq = mq_open(name.c_str(), O_CREAT | O_WRONLY,0644,&_attr);
        if(_mq == -1){
            cout << "Failed initilization of message queue   : "<<errno <<endl;
        }
        else{
            cout << "Message queue created for : "<<name << endl;
        }
    }
}


MsgQueue_C::~MsgQueue_C()
{
    mq_close(_mq);
    if(_type == RECEIVER)
        mq_unlink(_queue_name.c_str());
}


bool MsgQueue_C::BlockForMessage(string &str)
{
    char buffer[MAX_MSG_SIZE+1];
    memset(buffer, 0x00, MAX_MSG_SIZE+1);
    int bytes_read = mq_receive(_mq,buffer,MAX_MSG_SIZE+1, NULL);
    if(bytes_read >= 0) {
        str = buffer;
        return true;
    } else {
        cout << "[RECEIVER] : Error : "<<errno<<endl;
        return false;
    }
}

bool MsgQueue_C::SendMessage(string str)
{
    if(str.size() > MAX_MSG_SIZE){
        cout << "[SERVER] : Message size bigger than MAX_SIZE : "<<MAX_MSG_SIZE<<endl;
        return false;
    }
    char buffer[MAX_MSG_SIZE];
    memset(buffer , 0 , MAX_MSG_SIZE);
    snprintf(buffer,sizeof(buffer), "%s", str.c_str());

    cout << "[SERVER] : Sending message : "<<buffer<<endl;
    int ret = mq_send(_mq,buffer,sizeof(buffer), 0);

    if(ret == -1){
        cout << "mq_send :Error : "<<errno << endl;
        return false;
    }
    else{
        cout << "mq_send :Successfull"<<endl;
        return true;
    }
    return false;
}


