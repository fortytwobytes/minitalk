CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: server.c
	$(CC) server.c -o server

client: client.c
	$(CC) client.c -o client


clean:
	$(RM) server client

fclean: clean
