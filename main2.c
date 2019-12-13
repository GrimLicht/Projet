#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"




int main(int argc, char** argv)
{
	
	SEQUENCE S1, S2;
	DISTANCE D[191]; //Nombre total de distance
	int i, j;
	int f = 1;
	for (i=1; i<=19; i++)
	{
		for(j=i+1; j<=20; j++)
		{
			S1 = seq_creer(i);
			S2 = seq_creer(j);
	
//			S1 = echelonnage1(S1,S2);
//			S2 = echelonnage2(S1,S2);
			
			D[f] = calc_dist2(S1,S2);
			
			printf("%d & %d : %.1f\n",S1.num, S2.num, D[f].dist);
			f++;
		}
	}
	
	tri_a_bulle(D);
	fichier_dist_trie(D);
	FAMILLE F[6]; //On 5 Famille  # A METTRE EN DYNAMIC #
//	int c,k;
//	c = 1;
//	k = 1;
	i = 0;
/*	while(i < 191) //Nombre total de distance
	{	
		i = k;
		F[c] = find_famille(D);
		k = k + ((F[c].nb_seq)/2);
		c++;
	}*/
	
	F = find_famille(D);
	printf("###\nPremière famille :\n");
	printf("Nombre de Sequences dans la famille : %d\n", F->nb_seq);
	
	for (i = 0; i < 6; i++)
	{
		for (int j = 0; j < 25; j++)
		{
		printf("Distance entre %d et %d : %.3f", F[i].S[j].Seq1, F[i].S[j].Seq2, F[i].S[j].dist);
		}
	}
	
	
	place_famille(F);
	
	return 0;
}
