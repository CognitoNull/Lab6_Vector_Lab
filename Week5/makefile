
CC = gcc
CFLAGS = -Wall -Wextra -std=c89
TARGET = minimat
OBJS = main.o interface.o storage.o vector.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c interface.h
	$(CC) $(CFLAGS) -c main.c

interface.o: interface.c interface.h storage.h vector.h
	$(CC) $(CFLAGS) -c interface.c

storage.o: storage.c storage.h vector.h
	$(CC) $(CFLAGS) -c storage.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	rm -f $(TARGET) $(OBJS)
