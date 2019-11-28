#define A 00
#define G 01
#define C 10
#define T 11

struct sequence
{
	int num; // Numero de la sequence
	char base[20];
	int taille; // Pas sûr qu'on en ai besoin
	int famille;
};
typedef struct sequence SEQUENCE;

void seq_stocker (char* seq, int i);

SEQUENCE seq_creer (int i);

SEQUENCE echelonnage1(SEQUENCE S1, SEQUENCE S2);
SEQUENCE echelonnage2(SEQUENCE S1, SEQUENCE S2);

void affiche_seq(SEQUENCE S1, SEQUENCE S2);

int presentation();
int presentation2();
