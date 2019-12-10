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
DISTANCE tab_D(SEQUENCE a,SEQUENCE b);	   //renvoie le tableau des distances


DISTANCE calc_dist2(SEQUENCE a,SEQUENCE b);
float Dist2(char* a, char* b, int i, int j, float save[][21]);

void affiche_dist(DISTANCE D);
void affiche_tab_dist(DISTANCE** D);


void fichier_dist(DISTANCE D);
