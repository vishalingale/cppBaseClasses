all: Thread_C

CFLAGS= -I./ -std=c++11 -Wall -Werror 
LDFLAGS= -lpthread

Thread_C: test.cpp Thread_C.cpp 
	g++ -o $@ $^ $(CFLAGS) $(LDFLAGS) 

clean:
	rm Thread_C
