struct distance
{
	int dist;
	char* Seq1;
	char* Seq2;
	struct distance* suiv;
}

struct distance dist_find_min();

struct distance find_famille(struct distance dist_min);

void place_famille(); //place familles dans un fichier par famille
