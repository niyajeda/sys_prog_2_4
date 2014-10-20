CC=gcc
CFLAGS="-Wall"

DEPS = brett.h
OBJ = main.o brett.o

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) -g
debug:$(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS) -g
sys_prog_2_4: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
stable: $(OBJ)
	$(CC) -o  $@ $^ $(CFLAGS)
clean:
	rm -vfr *~ debug