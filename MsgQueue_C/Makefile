all: Sender Receiver

CFLAGS= -I./ -std=c++11 -Wall -Werror 
LDFLAGS= -lpthread -lrt

Receiver: test_receiver.cpp MsgQueue_C.cpp 
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS) 

Sender: test_sender.cpp MsgQueue_C.cpp
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS) 

clean:
	rm Sender Receiver
