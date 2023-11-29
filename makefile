CC = g++
CFLAGS = -std=c++11

all: main

main: main.o Account.o Saving.o Checking.o
	$(CC) $(CFLAGS) -o Longhorn main.o Account.o Saving.o Checking.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Account.o: Account.cpp Account.h
	$(CC) $(CFLAGS) -c Account.cpp

Saving.o: Saving.cpp Saving.h Account.h
	$(CC) $(CFLAGS) -c Saving.cpp

Checking.o: Checking.cpp Checking.h Account.h
	$(CC) $(CFLAGS) -c Checking.cpp

clean:
	rm -rf *.o Longhorn

