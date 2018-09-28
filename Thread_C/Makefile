all: Thread_C

CFLAGS= -I./ -std=c++11 -Wall -Werror 
LDFLAGS= -lpthread

Thread_C: main.cpp Thread_C.cpp 
	g++ -o Thread_C main.cpp Thread_C.cpp $(CFLAGS) $(LDFLAGS) 

clean:
	rm Thread_C
