all: thread

CFLAGS= -I./ -std=c++11
LDFLAGS= -lpthread

thread: main.cpp Thread_C.cpp 
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS) 

clean:
	rm thread
