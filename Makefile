partie1: main1
	./main1 
	
main1: main1.o distance.o sequence.o
	gcc -Wall -o main1 main1.o sequence.o
	
main1.o: main1.c sequence.h distance.h
	gcc -Wall -c main1.c 
	
sequence.o: sequence.h sequence.c
	gcc -Wall -c sequence.c

distance.o:
	gcc -Wall -c distance.c
	
	
	
partie2: main2
	./main2 
	
main2: main2.o 
	gcc -Wall -o main2 main2.o
	
main2.o: main2.c
	gcc -Wall -c main2.c 
	
	
partie3: main3
	./main3 
	
main3: main3.o 
	gcc -Wall -o main3 main3.o
	
main3.o: main3.c
	gcc -Wall -c main3.c 
	
archive:

	
clean:
	rm -f main1.o
	rm -f main1
	rm -f distance.o
	rm -f sequence.o
	rm -f main2.o
	rm -f main2
