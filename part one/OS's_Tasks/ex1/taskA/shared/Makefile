cc = gcc
cflag = -Wall -g -o

libhello:
	$(cc) -o libHello.so -shared -fPIC hello_Ariel.c
	
main1:
	$(cc) main1_1.c -L. -l Hello -o hello1
epx:
	export LD_LIBRARY_PATH=.
	echo $LD_LIBRARY
	
main3:
	$(cc) main1_3.c -fPIC -ldl -o hello3

clean:
	rm of *.o