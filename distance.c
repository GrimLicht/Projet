#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

#define maxi(x,y) ((x)>(y)?(x):(y))

float calc_dist0 (char a, char b, int taille)
{
	
	float c = 0.0;
	int u, d;
	
	if(a == 'A')
		u = A;
	if(a == 'C')
		u = C;
	if(a == 'G')
		u = G;
	if(a == 'T')
		u = T;
	
	if(b == 'A')
		d = A;
	if(b == 'C')
		d = C;
	if(b == 'G')
		d = G;
	if(b == 'T')
		d = T;
		
	c = u ^ d;
	
	if (c > 2)
		{c = 2;}
		
	if(((a == '-') || (b == '-')) && (a != b))
		{c = 1.5;}
		
	return c;
}

// Calcul pour D1
DISTANCE calc_dist1 (SEQUENCE a, SEQUENCE b)
{
	DISTANCE D1;
	float e = 0.0;
	int taille = maxi((a.taille), (b.taille));
	
	int i = 0;
	for(i = 1; i <= taille; i++)
	{
		e += calc_dist0(a.base[i], b.base[i], taille);
	}
	
	D1.dist = e;
	D1.Seq1 = a.num;
	D1.Seq2 = b.num;
	
	return D1;
}


void affiche_dist(DISTANCE D)
{
	printf("La distance entre vos 2 séquences est %.1f\n", D.dist);
}


/* Pour D2 il faut un tableau à double entrées pour calculer 
 * La plus petite distance -> programmation dynamique (TD et CM faut voir)
 * -> Algorithme de Needleman-Wunsch
*/
