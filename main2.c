#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"




int main(int argc, char** argv)
{
	
	SEQUENCE S1, S2;
	DISTANCE D[21][21];
	int i, j;
	for (i = 1; i < 21; i++)
	{
		for(j = 1; j < 21; j++)
		{
			S1 = seq_creer(i);
			S1.num = i;
			S2 = seq_creer(j);
			S2.num = j;
			
			D[i][j] = calc_dist2(S1,S2);
			
//			printf("%d & %d : %.1f\n", i, j, D[i][j].dist);
		}
	}
	
//	tri_a_bulle(D);
//	fichier_dist_trie(D);

	FAMILLES F; 
	F = find_famille(D);
	
	
	affiche_familles(F);
	
	return 0;
}
