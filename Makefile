CC = gcc

ServerSpell : ServerSpell.o utils.o
	$(CC) -o ServerSpell ServerSpell.o utils.o

ServerSpell.o : ServerSpell.c 
	$(CC) -c -o ServerSpell.o ServerSpell.c

utils.o : utils.c
	$(CC) -c -o utils.o utils.c

clean :
	rm -f *.o ServerSpell