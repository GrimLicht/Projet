struct distance
{
	float dist;
	int Seq1;
	int Seq2;
	struct distance* suiv;
};
typedef struct distance DISTANCE;

DISTANCE dist_find_min(); //trouve la distance min entre 2 sequences

DISTANCE calc_dist1(SEQUENCE a,SEQUENCE b);//renvoie la valeur de la distance

void affiche_dist(DISTANCE D);

float Dist2 (char* a, char* b, int i, int j, float save[20][21]);
