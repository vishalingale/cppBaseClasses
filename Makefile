all: lib/libBasicModules.so


CFLAGS=-IThread_C/. -IMsgQueue_C/. -shared -fPIC -std=c++11 -Werror 
LDFLAGS=-lpthread -lrt
lib/libBasicModules.so: Thread_C/Thread_C.cpp MsgQueue_C/MsgQueue_C.cpp
	g++ $(CFLAGS) -o $@ $(LDFLAGS) $^

clean:
	rm lib/libBasicModules.so
