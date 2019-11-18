struct sequence
{
	char* base;
	int taille;
	int famille;
};
typedef struct sequence SEQUENCE;

int calc_dist1(SEQUENCE a,SEQUENCE b); // Renvoi un entier = valeur de la distance
