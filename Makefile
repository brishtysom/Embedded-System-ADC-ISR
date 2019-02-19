#Makefile 

CFLAGS= -g

clean: 
	rm -f *.o a.out

all: ADC

ADC : midterm2.o	
	gcc -o a.out midterm2.o ./lib/libmidterm2.a -lm -lcrypto

midterm2.o : midterm2.c
	gcc $(CFLAGS) -I./include -c midterm2.c