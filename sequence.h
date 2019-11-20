#define A 00
#define G 01
#define C 10
#define T 11

struct sequence
{
	char base[4];
	int taille;
	int famille;
};
typedef struct sequence SEQUENCE;

void seq_stocker (char* seq, int i);
