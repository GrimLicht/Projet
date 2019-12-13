#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "sequence.h"
#include "distance.h"
#include "famille.h"

void tri_a_bulle(DISTANCE D[]) 
{
	int en_desordre = 1; 
	while (en_desordre)
	{
		en_desordre = 0;			// Supposons le tableau ordonné 
		for (int j = 1; j < 190; j++)
		{
			if(D[j].dist > D[j+1].dist)		// Si les 2 éléments sont mal triés 
			{ 
 				DISTANCE tmp = D[j+1];
 				D[j+1] = D[j];
 				D[j] = tmp;

									//Le tableau n'est toujours pas trié
				en_desordre = 1;
 			}
		}
	}
}
	
void fichier_dist_trie(DISTANCE D[])
{
	
	FILE* fichier;

    fichier = fopen("Fichier_Distance_Trié", "a");

    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        for( int i = 1 ; i<191 ;i++)
        {
			fprintf(fichier,"%d - %d : %.1f\n", D[i].Seq1, D[i].Seq2, D[i].dist);
		}
    
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier Fichier_Distance_Trié.txt");
    }

	
	fclose(fichier);
}
	
int* init_tab(int tab[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		tab[i] = 0;
	}
	
	return tab;
}

FAMILLE* find_famille(DISTANCE D[]) 
{ //idée : retourne un tab de famille et fait toutes les familles
	FAMILLE F[10]; 	
	F.nb_seq  = 0;
	int save[21];
	int tmp_cnt[21];
	tmp_cnt[0] = 0; // compteur du nb d'apparence de la seq i
	int j, k, range, old, def, tmp;
	j = 0;
	k = 1;
	tmp = 0;
	def = 0; //à chaque distance on va prendre 
	//la seq la plus représentée (def fois)
	range = 1; //les distances sont les memes
	//entre les indices range et old
	old = 1;
	int tab[21];
	int i = 1;
	
	for (int z = 0; z < 21; z++)
	{
		save[z] = -1;
	}
	
	tmp_cnt = init_tab(tmp_cnt, 21);
	

	while (i < 191)
	{	
		tmp_cnt[D[i].Seq1]++;
		tmp_cnt[D[i].Seq2]++;
		while (D[i].dist == D[i+1].dist) //augmente dans un tableau la 
		{//case qui représente la séquence tant que les dist sont les meme
			tmp_cnt[D[i+1].Seq1]++;
			tmp_cnt[D[i+1].Seq2]++;
			i++;			
		}
		range = i;
		i++;
		
		for (j = 1; j < 21; j++) // Cherche la seq la plus présente
		{
			if (tmp_cnt[j] > tmp_cnt[j-1])
			{
				tmp = j;
			}
		}
		
		j = 1;
		
		while (old <= range)
		{
			//après avoir trouvé la seq+présente 
			if ((D[old].Seq1 == tmp) && (tab[D[old].Seq1] == -1)) //si la dist actuelle est avec la seq+pré
			{//on ajoute l'autre séq dans la famille
				save[tmp] = 1;
				F.S[k] = D[old].Seq2;
				k++;
				F.nb_seq++;
				tab[D[old].Seq1] = 1;
			}
			if ((D[old].Seq2 == tmp) && (tab[D[old].Seq2] == -1))
			{
				save[tmp] = 1;
				F.S[k] = D[old].Seq1;
				k++;
				F.nb_seq++;
				tab[D[old].Seq2] = 1;
			}
			old++;
		}
	}
	return F; 
}
	
	
int copier_fichier(char const * const source, char const * const destination) 
{ 
    FILE* fSource; 
    FILE* fDestination; 
    char buffer[512]; 
    int NbLus; 
  
    if ((fSource = fopen(source, "r")) == NULL) 
    { 
        return 3; //Si le fichier est vide
    } 
  
    if ((fDestination = fopen(destination, "w")) == NULL) 
    { 
        fclose(fSource); 
        return 3; 
    } 
  
    while ((NbLus = fread(buffer, 1, 512, fSource)) != 0) 
		{
			fwrite(buffer, 1, NbLus, fDestination); 
		}
		
    fclose(fDestination); 
    fclose(fSource); 
  
    return 0; 
}
	
	
		
void place_famille(FAMILLE F[])
{
	//Idée : tu me crés le dossier et on ecrit directement dedans le sequences
	int k;
	char Famille[11]; char Source[24]; char Destination[21];//Car une adresse de dossier 
														 //est sur 33 bits
	for (int cpt = 1; cpt <= 39; cpt++)
	{
		sprintf(Famille,"Famille %d/",cpt); 
		mkdir(Famille,0777); //Crée le cptème dossier famille 
		
		for( int i = 0; i<20; i++)
		{
			k = F[cpt].S[i]; // On prends la ième sequence de la cptème famille
			if(k<10)
			{
				sprintf(Source,"sequences_ADN/seq0%d.txt",k);
				sprintf(Destination,"Famille %d/seq0%d.txt",cpt,k);
			}
			if(k>=10)
			{
				sprintf(Source,"sequences_ADN/seq%d.txt",k);
				sprintf(Destination,"Famille %d/seq%d.txt",cpt,k);
			}
			copier_fichier(Source,Destination);
		//printf("%d\n",k);
		}
	}

}
