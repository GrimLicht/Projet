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
	
	SEQUENCE S1;
	
	
//	char seq[20];
	
//	seq_stocker(seq, 12);
	S1 = seq_creer(12);
	
	
	for (int j = 1; j < 20; j++)
	{
		printf("%c", S1.base[j]);
	}
	printf("\n");
	
	exit(0);
}
