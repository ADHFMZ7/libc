CC = gcc
CFLAGS = -g

default:
	@make -s run
	@make -s clean

run: myalloc.o
	@$(CC) $(CFLAGS) main.c myalloc.o -o output
	@./output

myalloc: 
	@$(CC) $(CFLAGS) myalloc.c -o myalloc.o -c


clean:
	@rm *.o output
