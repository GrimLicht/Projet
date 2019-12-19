struct familles
{
	int nb_fam; //Nombre de familles
	int S[21];	//Quelle séquence est dans quelle Famille
}; 
typedef struct familles FAMILLES; //Classe les sequences par famille de sequence 
								//en fonction de leures distances d'editions

FAMILLES find_famille(DISTANCE D[21][21]);

void place_famille(FAMILLES F); //place familles dans un fichier par famille

void tri_a_bulle(DISTANCE D[]); //Trie le Tableau de distance

void fichier_dist_trie(DISTANCE D[]); //Affiche le tableau de distance trié

void affiche_familles(FAMILLES F);
