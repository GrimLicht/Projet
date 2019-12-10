#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

#define maxi(x,y) ((x)>(y)?(x):(y))
#define mini(x,y)  ((x)<(y)?(x):(y))
#define min(x,y,z) ((x)<(mini(y, z))?(x):(mini(y,z)))

float calc_dist0 (char a, char b)
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
		e += calc_dist0(a.base[i], b.base[i]);
	}
	
	D1.dist = e;
	D1.Seq1 = a.num;
	D1.Seq2 = b.num;
	
	return D1;
}


void affiche_dist(DISTANCE D)
{
	printf("La distance entre %d et %d est %.1f\n", D.Seq1, D.Seq2, D.dist);
}


//Il faut une chaine où tu enregistre les distances


float Dist2 (char* a, char* b, int i, int j, float save[][21])
{
	if ((i == 0) && (j == 0))
	{
		return 0.0;
	}
	
	else if (((i == 0) || (j == 0)) && (i != j))
	{
		return (i*1.5);
	}
	
	
	else if (((i != 0) && (j != 0)) && (save[i][j]!=(-1)))
	{
		return  save[i][j];
	}
	
	else if (((i != 0) && (j != 0)) && (save[i][j] == (-1)))
	{
		save[i][j] = min((Dist2(a, b, i-1, j-1, save) + calc_dist0(a[i], b[j])),
					(Dist2(a, b, i,   j-1, save)      + 1.5),
					(Dist2(a, b, i-1, j,   save)      + 1.5));
					
		return save[i][j];
	}
	else 
	{
		printf("Erreur 3");
		exit(0);
	}
}
