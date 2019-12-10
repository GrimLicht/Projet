#define A 00
#define G 01
#define C 10
#define T 11

struct sequence
{
	int num; // Numero de la sequence
	char base[20];
	int taille;
};
typedef struct sequence SEQUENCE;

void seq_stocker (char* seq, char* rep, int i);

SEQUENCE seq_creer (char* rep, int i);

SEQUENCE echelonnage1(SEQUENCE S1, SEQUENCE S2);
SEQUENCE echelonnage2(SEQUENCE S1, SEQUENCE S2);

void affiche_seq(SEQUENCE S1, SEQUENCE S2);

int presentation();
int presentation2();
