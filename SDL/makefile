CC=gcc
EXEC=prog
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) -lSDL2main -lSDL2

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm $(EXEC) $(OBJ)
