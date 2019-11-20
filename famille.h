struct famille
{
	int nb_seq;
	struct famille* suiv;
}


struct distance find_famille(struct distance dist_min);

void place_famille(); //place familles dans un fichier par famille
