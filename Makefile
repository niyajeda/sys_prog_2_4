CC=gcc
CFLAGS="-Wall"

debug:clean
	$(CC) $(CFLAGS) -g -o sys_prog_2_4 main.c
stable:clean
	$(CC) $(CFLAGS) -o sys_prog_2_4 main.c
clean:
	rm -vfr *~ sys_prog_2_4
