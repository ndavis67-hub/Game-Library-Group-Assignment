RM = rm -f 
CC = g++
CFLAGS = -g -Wall -Wextra

default: gamelib

gamelib: main.o library.o 
	$(CC) $(CFLAGS) -o gamelib main.o library.o

library.o: library.cpp library.h
	$(CC) $(CFLAGS) -c library.cpp

#library.h: games.h library.h
#	$(CC) $(CFLAGS) -o gamelib games.h 
main.o: main.cpp library.h game.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) gamelib *.o *~
