#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

void seq_stocker (char* seq, int i) //prends en arg le num de la seq, 
{					   			    //renvoie la seq sous forme de tab
	char namefile[24];
	
	FILE* F = NULL;
	//ouvre la sequence selon i
	if (i < 10)
		sprintf(namefile, "sequences_ADN/seq0%d.txt", i);
	else
		sprintf(namefile, "sequences_ADN/seq%d.txt", i);
	
	F = fopen(namefile, "r");
	if(F == NULL)
	{
		printf("Erreur dans l'ouverture du fichier");
		exit(1);
	}
	
	int j = 1;
	while ((seq[j] = fgetc(F)) != EOF)
		j++;
		
	while (j < 20)
	{
		seq[j] = '-';
		j++;
	}
	
//	printf("%d\n", j);
	
	fclose(F);
}

