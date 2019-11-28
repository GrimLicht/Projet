#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"


int main()
{
/*	float dist1 = 0;
	SEQUENCE a; SEQUENCE b;
	a.base[1] = 'A'; b.base[1] = 'C';
	dist1 = calc_dist1(a ,b);
	printf("%5f\n", dist1);*/
	
	SEQUENCE S1, S2;
	int i, j;
	
	i = presentation();
	j = presentation2();
	
	S1 = seq_creer(i);
	S2 = seq_creer(j);
	
	S1 = echelonnage1(S1,S2);
	S2 = echelonnage2(S1,S2);
	
	affiche_seq(S1,S2);
	
	DISTANCE D1;
	D1 = calc_dist1(S1, S2);
	affiche_dist(D1);
	
	exit(0);
}
