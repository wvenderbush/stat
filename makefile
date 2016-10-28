GCC = gcc -g

all: stat.c
	$(GCC) stat.c -o prog

clean:
	rm *.o
	rm *~

run: all
	./prog

debug: all
	gdb prog
