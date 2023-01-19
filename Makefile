CC = gcc
CFLAGS = -g

default:
	@make -s run
	@make -s clean

run: myalloc.o myio.o
	@$(CC) $(CFLAGS) main.c myalloc.o myio.o -o output
	@./output

myalloc: 
	@$(CC) $(CFLAGS) myalloc.c -o myalloc.o -c

myio:
	@$(CC) $(CFLAGS) myio.c -o myio.o -c

clean:
	@rm *.o output
