CC = gcc
FLAGS = -Wall -g

all:hello_Ariel1 

hello_Ariel1: main1_1.o hello_Ariel.o
	$(CC) $(FLAGS) -o $@ main1_1.o hello_Ariel.o

main1_1.o: main1_1.c hello_Ariel.h
	$(CC) $(FLAGS) -c main1_1.c 

hello_Ariel.o: hello_Ariel.c hello_Ariel.h
	$(CC) $(FLAGS) -c hello_Ariel.c 

lib.so: hello_Ariel.o hello_Ariel.h
	$(CC) -shared -o lib.so hello_Ariel.o

myprogram: hello_Ariel1
	$(CC) $(FLAGS) -o mypragram.exe hello_Ariel1.o

.PHONY: clean all

clean:
	rm -f *.o *.a *.so hello_Ariel1
