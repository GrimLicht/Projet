#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"
#define nb_seq 20

int main()
{
/*	SEQUENCE S1, S2;
	int i, j;
	
	i = presentation(); //Seulement pour les tests pour verifier 
	j = presentation2(); // fichier par fichier
	
	S1 = seq_creer(i);
	S1.num = i;
	S2 = seq_creer(j);
	S2.num = j;
	
	affiche_seq(S1,S2);
	
	DISTANCE D1;
	D1 = calc_dist1(S1, S2);
	affiche_dist(D1);
	
	
	float save[20][21];
	
	int a,b;
	for(a = 1; a <= 19; a++)
	{
		for (b = 1; b <= 20; b++)
		{
			save[a][b] = -1;
		}
	}
	
	printf("D2: %.1f\n",Dist2(S1.base, S2.base, S1.taille, S2.taille, save));
	*/
	
	SEQUENCE S1, S2;
	DISTANCE D[20][21];
	int i, j;
	for (i = 1; i < 20; i++)
	{
		for(j = 2; j < 21; j++)
		{
			S1 = seq_creer(i);
			S1.num = i;
			S2 = seq_creer(j);
			S2.num = j;
			
			D[i][j] = calc_dist2(S1,S2);
			
			printf("%d & %d : %.1f\n", i, j, D[i][j].dist);
		}
	}
	
	
	exit(0);
}
