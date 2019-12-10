struct famille
{
	int nb_seq; //Nombre de sequence dans la famille
	struct famille* suiv;
	int S[25];	//Quelle distance est dans la Famille
}; 
typedef struct famille FAMILLE; //Classe les sequences par famille de sequence 
								//en fonction de leures distances d'editions


FAMILLE find_famille(DISTANCE D[]); //Trouve les familles

void place_famille(FAMILLE []); //place familles dans un fichier par famille

void tri_a_bulle(DISTANCE D[]); //Trie le Tableau de distance

void fichier_dist_trie(DISTANCE D[]); //Affiche le tableau de distance trié
