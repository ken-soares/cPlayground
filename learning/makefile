CC=gcc
EXEC=prog
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ)

%.o: %.c
	$(CC) -o $@ -c $^

clean:
	rm $(EXEC) $(OBJ)
