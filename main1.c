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
	
	char seq[20];
	seq_stocker(seq, 12);
	
	for (int j = 1; j < 21; j++)
	{
		printf("%c", seq[j]);
	}
	printf("\n");
	
	exit(0);
}
