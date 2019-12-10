#include <stdlib.h>
#include <stdio.h>
#include "sequence.h"
#include "distance.h"

void seq_stocker (char* seq, int i)
{	//prends en arg le num de la seq, 
	//renvoie la seq sous forme de tab
	
	char namefile[24];
	
	FILE* F = NULL;

	if (i < 10) //ouvre la sequence selon i
		sprintf(namefile, "sequences_ADN/seq0%d.txt", i);
	else
		sprintf(namefile, "sequences_ADN/seq%d.txt", i);
	
	F = fopen(namefile, "r");
	
	if(F == NULL)
	{
		printf("Erreur dans l'ouverture du fichier\n");
		exit(1);
	}
	
	int j = 1;
	while ((seq[j] = fgetc(F)) != EOF)
	{
		j++;
	}
	fclose(F);
}

int seq_taille (char* seq, int i)
{
	int t = 1;
	while ((seq[t] >= 'A') && (seq[t] <= 'T'))
		{t++;}
	return (t - 1); 
}

SEQUENCE seq_creer (int i) //prends en argument la sequence à 
{							   //rentrer dans la variable SEQUENCE

	SEQUENCE S;
	S.num = i;
	
	char seq[20];
	seq_stocker(seq, i);
	
	S.taille = seq_taille(seq,i);

	for (int i = 1; i <= S.taille; i++)
		{S.base[i] = seq[i];}
	
	return S;
}

SEQUENCE echelonnage1(SEQUENCE S1, SEQUENCE S2){
	int i;
	if (S1.taille < S2.taille){
		for(i = S1.taille + 1; i <= S2.taille; i++){
			S1.base[i] = '-';
		}
	}
	return S1;
}
SEQUENCE echelonnage2(SEQUENCE S1, SEQUENCE S2){
	int i;
	if (S2.taille < S1.taille){
		for(i = S2.taille + 1; i <= S1.taille; i++){
			S2.base[i] = '-';
		}
	}
	return S2;
}




void affiche_seq(SEQUENCE S1, SEQUENCE S2){
	int j;
	printf("## ");
	for (j = 1; j <= S1.taille; j++)
	{
		printf("%c", S1.base[j]);
	}
	printf(" ##");
	printf("  Taille : %d",S1.taille);
	printf("\n");
	
	printf("## ");
	for (j = 1; j <= S2.taille; j++)
	{
		printf("%c", S2.base[j]);
	}
	printf(" ##");
	printf("  Taille : %d",S2.taille);
	printf("\n");
}

int presentation()
{
	int i;
	printf("Quelle est la première séquence à comparer : ");
	scanf("%d",&i);
	return i;
}

int presentation2()
{
	int j;
	printf("Quelle est la seconde séquence à comparer : ");
	scanf("%d",&j);
	return j;
}
