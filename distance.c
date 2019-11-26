#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

// Calcule pour D1
float calc_dist1 (SEQUENCE a, SEQUENCE b)
{
	float c = 0.0;
	int u, d;
	
	
	if(a.base[2] == 'A')
		u = A;
	if(a.base[2] == 'C')
		u = C;
	if(a.base[2] == 'G')
		u = G;
	if(a.base[2] == 'T')
		u = T;
		
	if(b.base[2] == 'A')
		d = A;
	if(b.base[2] == 'C')
		d = C;
	if(b.base[2] == 'G')
		d = G;
	if(b.base[2] == 'T')
		d = T;
		
	c = u ^ d;
	
	if (c > 2)
		c = 2;
	
	return c;
}


/* Pour D2 il faut un tableau à double entrées pour calculer 
 * La plus petite distance -> programmation dynamique (TD et CM faut voir)
 * -> Algorithme de Needleman-Wunsch
*/
