struct distance
{
	int dist;
	char* Seq1;
	char* Seq2;
	struct distance* suiv;
};
typedef struct distance DISTANCE;

DISTANCE dist_find_min(); //trouve la distance min entre 2 sequences

float calc_dist1(SEQUENCE a,SEQUENCE b);//renvoie la valeur de la distance
