partie1: main1
	./main1 sequences_ADN/
	
main1: main1.o distance.o sequence.o
	gcc -Wall -o main1 main1.o
	
main1.o: main1.c sequence.h distance.h
	gcc -Wall -c main1.c 
	
sequence.o:
	gcc -Wall -c sequence.c

distance.o:
	gcc -Wall -c distance.c
	
	
	
partie2: main2
	./main2 sequences_ADN/
	
main2: main2.o 
	gcc -Wall -o main2 main2.o
	
main2.o: main2.c
	gcc -Wall -c main2.c 
	
	
partie2: main3
	./main3 sequences_ADN/
	
main3: main3.o 
	gcc -Wall -o main3 main3.o
	
main3.o: main3.c
	gcc -Wall -c main3.c 
	
archive:

	
clean:
	rm -f main1.o
	rm -f main1
	rm -f main2.o
	rm -f main2
