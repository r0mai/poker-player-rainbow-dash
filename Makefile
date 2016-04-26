
CC=g++

CFLAGS=-c -std=c++11

all: player

player: main.o player.o json.o Hand.o Card.o
	$(CC) main.o Card.o Hand.o player.o json.o -o player

main.o:
	$(CC) $(CFLAGS) main.cpp

player.o:
	$(CC) $(CFLAGS) player.cpp

Hand.o:
	$(CC) $(CFLAGS) Hand.cpp

Card.o:
	$(CC) $(CFLAGS) Card.cpp

json.o:
	$(CC) $(CFLAGS) json.cpp

clean:
	rm -rf *.o player

test: player
	 @cat tests/input1.json | ./player bet_request
	 @cat tests/input2.json | ./player bet_request
