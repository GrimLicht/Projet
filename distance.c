#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

// Calcule pour D1
float calc_dist1 (SEQUENCE a, SEQUENCE b)
{
	float c = 0.0;
	c = a.base[1] ^ b.base[1];
	
	if (c > 2)
		c = 2;
	
	return c;
}


/* Pour D2 il faut un tableau à double entrées pour calculer 
 * La plus petite distance -> programmation dynamique (TD et CM faut voir)
 * -> Algorithme de Needleman-Wunsch
*/
