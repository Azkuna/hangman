CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Iinclude
SRC = src/main.c src/hangman.c
OBJ = $(SRC:.c=.o)
EXEC = hangman

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean