#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"
#define nb_seq 20

int main(int argc, char** argv)
{
/*	float dist1 = 0;
	SEQUENCE a; SEQUENCE b;
	a.base[1] = 'A'; b.base[1] = 'C';
	dist1 = calc_dist1(a ,b);
	printf("%5f\n", dist1);*/
	
	SEQUENCE* S;
	S = malloc(nb_seq * sizeof(SEQUENCE));
	
	SEQUENCE S1, S2;
	int i, j;
	
	i = presentation(); //Seulement pour les tests pour verifier 
	j = presentation2(); // fichier par fichier
	
	S1 = seq_creer(argv[1], i);
	S2 = seq_creer(argv[1], j);
	
	S1 = echelonnage1(S1,S2);
	S2 = echelonnage2(S1,S2);
	
	affiche_seq(S1,S2);
	
	DISTANCE D1;
	D1 = calc_dist1(S1, S2);
//	D1 = calc_dist2(S1, S2);
	affiche_dist(D1);
	
	
	free(S);
	exit(0);
}
