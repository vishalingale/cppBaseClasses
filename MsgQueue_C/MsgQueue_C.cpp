#include <MsgQueue_C.h>

using namespace std;

MsgQueue_C::MsgQueue_C(string name, int max_size,Type_C type)
{
    _queue_name         = name;
    _max_msg_size       = 1024;
    _max_messages       = 20;
    _attr.mq_flags      = 0;
    _attr.mq_maxmsg     = 10;
    _attr.mq_msgsize    = 1024;
    _attr.mq_curmsgs    = 0;
    _msg_ptr            = (char *)malloc(sizeof(char) * 1024+1);
    _type               = type;
    if(_msg_ptr)
        memset(_msg_ptr , 0 , _max_msg_size);


    if(type == RECEIVER){
        _mq = mq_open(name.c_str(), O_CREAT | O_RDONLY,0644, &_attr);
        if(_mq == -1)
        {
            printf("Name = %s \n",name.c_str());
            cout << "Failed initilization of message queue   : "<<errno <<endl;
        }
        cout << "Message que created for Receiver : "<<name << endl;
    }
    else{
        _mq = mq_open(name.c_str(), O_CREAT | O_WRONLY,0644,&_attr);
        cout << "Message que created for Sender"<<endl;
        if(_mq == -1)
        {
            printf("Name = %s \n",name.c_str());
            cout << "Failed initilization Sender message queue   : "<<errno <<endl;
        }
    }
}

    
MsgQueue_C::~MsgQueue_C()
{
    if(_msg_ptr){
        free(_msg_ptr);
        _msg_ptr = NULL;
    }
    mq_close(_mq);
    if(_type == RECEIVER)
        mq_unlink(_queue_name.c_str());
}


void MsgQueue_C::BlockForMessage()
{
    char buffer[1025];
    memset(buffer, 0x00, 1025);
    int bytes_read = mq_receive(_mq,buffer,1025, NULL);
    cout << "Error : "<<errno<< "Bytes read  :" << bytes_read<<endl;
    if(bytes_read >= 0) {
        printf("[RECEIVER]: Received message: %s\n", buffer);
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
    char buffer[50];
    memset(buffer , 0 , 50);
    snprintf(buffer,sizeof(buffer), "%s", str.c_str());

    printf("CLIENT: Send message... %d \n",str.size());
    int ret = mq_send(_mq,buffer,sizeof(buffer), 0);

    /* send the message */
   //const char *str2 = "mani12345678923423423";
   //int ret = mq_send(_mq, str2, strlen(str2), 0); // no need to include the null character
    if(ret == -1)
        cout << "mq_send Error : "<<errno << endl;
    else
        cout << "mq_send :Successfull"<<endl;


    fflush(stdout);

}


