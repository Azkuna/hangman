CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
SRC = src/main.c
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