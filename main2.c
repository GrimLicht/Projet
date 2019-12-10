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
	FAMILLE F[39]; //On  38 Famille #### A METTRE EN DYNAMIC ####
	int c,k;
	c = 1;
	k = 1;
	i = 0;
	while(i < 191) //Nombre total de distance
	{	
		i = k;
		F[c] = find_famille(D,i);
		k = k + ((F[c].nb_seq)/2);
		c++;
	}
	//printf ("Dans la famille 1: %d - %d - %d - %d - %d - %d - %d\n",F[1].S[0],F[1].S[1],F[1].S[2],F[1].S[3],F[1].S[4],F[1].S[5],F[1].S[6],F[1].S[15]);
	//printf ("Dans la famille 2: %d - %d - %d - %d\n",F[39].S[0],F[39].S[1],F[39].S[2],F[39].S[3]);
	
	place_famille(F);
	
	return 0;
}
