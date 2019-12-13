#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"
#define nb_seq 20

int main()
{
	
	SEQUENCE* S;
	S = malloc(nb_seq * sizeof(SEQUENCE));
	
	SEQUENCE S1, S2;
	int i, j;
	
	i = presentation(); //Seulement pour les tests pour verifier 
	j = presentation2(); // fichier par fichier
	
	S1 = seq_creer(i);
	S2 = seq_creer(j);
	
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
	
	
	free(S);
	exit(0);
}
