CC = gcc
CFLAGS = -g -Wall

count-words: count-words.c
	$(CC) $(CFLAGS) -o count-words count-words.c

clean:
	rm -f count-words