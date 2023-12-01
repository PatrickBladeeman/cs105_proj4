CC = g++
CFLAGS = -std=c++11

all: main

main: main.o Account.o Savings.o Checking.o
	$(CC) $(CFLAGS) -o main main.o Account.o Savings.o Checking.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Account.o: Account.cpp Account.h
	$(CC) $(CFLAGS) -c Account.cpp

Savings.o: Savings.cpp Savings.h Account.h
	$(CC) $(CFLAGS) -c Savings.cpp

Checking.o: Checking.cpp Checking.h Account.h
	$(CC) $(CFLAGS) -c Checking.cpp

clean:
	rm -rf *.o main

