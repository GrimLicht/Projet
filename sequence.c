#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"


// Calcule pour D1
int calc_dist1(SEQUENCE a, SEQUENCE b)
{
	
// Si les 2 sequences n'ont pas la meme taille on rajoute '-' pour compléter la plus petite sequence
	if ( a.taille != b.taille) 
	{
		if (a.taille < b.taille) {
			while (a.taille < b.taille) {
				a.base[a.taille] = '-';
				a.taille = a.taille + 1;
			}
		}
		if (a.taille > b.taille) {
			while (a.taille > b.taille) {
				b.base[b.taille] = '-';
				b.taille = b.taille + 1;
			}
		}
	}
	
	

	
	float cmp = 0;
	int i;
	for(i=0;i<a.taille;i++)
	{
		if ((a.base[i] == 'A')&&(b.base[i] == 'A')) { cmp = cmp + 0;}
		if ((a.base[i] == 'A')&&(b.base[i] == 'T')) { cmp = cmp + 2;}
		if ((a.base[i] == 'A')&&(b.base[i] == 'C')) { cmp = cmp + 2;}
		if ((a.base[i] == 'A')&&(b.base[i] == 'G')) { cmp = cmp + 1;}
		if ((a.base[i] == 'A')&&(b.base[i] == '-')) { cmp = cmp + 1.5;}
		if ((a.base[i] == 'T')&&(b.base[i] == 'T')) { cmp = cmp + 0;}
		if ((a.base[i] == 'T')&&(b.base[i] == 'C')) { cmp = cmp + 1;}
		if ((a.base[i] == 'T')&&(b.base[i] == 'G')) { cmp = cmp + 2;}
		if ((a.base[i] == 'T')&&(b.base[i] == '-')) { cmp = cmp + 1.5;}
		if ((a.base[i] == 'C')&&(b.base[i] == 'C')) { cmp = cmp + 0;}
		if ((a.base[i] == 'C')&&(b.base[i] == 'G')) { cmp = cmp + 2;}
		if ((a.base[i] == 'C')&&(b.base[i] == '-')) { cmp = cmp + 1.5;}
		if ((a.base[i] == 'G')&&(b.base[i] == 'G')) { cmp = cmp + 0;}
		if ((a.base[i] == 'G')&&(b.base[i] == '-')) { cmp = cmp + 1.5;}
	}
	return 0;
}

