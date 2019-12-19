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
	

FAMILLES init_famille(FAMILLES F)
{
	int i;
	for (i=1;i<21;i++)
	{
		F.S[i] = 0;
	}
	return F;
}

FAMILLES find_famille(DISTANCE D[21][21])
{
	FAMILLES F;
	F = init_famille(F);
	F.nb_fam  = 0; //num de la famille
	
	int save[21]; //nb de fois où seq i est apparue pour dist_min
	
	int pas_complet = 1; //est ce que chaque seq a une famille
	
	float dist_min; //plus petite distance
	
	int i, j;
	
	int most;
	
	
	printf("##############\n");

	

	while (pas_complet)
	{	
		F.nb_fam++;
		pas_complet = 0;
		dist_min = 30;
		most = 0;
		
		for (int z = 0; z < 21; z++)
		{
			save[z] = 0;
		}
	
		for (i=1; i<21; i++)
		{
			if (F.S[i] == 0) //si la sequence 1 n'a pas de famille
			{
				
				for (j=i+1; j<21; j++)
				{
					if(F.S[j] == 0) //si la sequence j n'a pas de fam.
					{
						if (dist_min > D[i][j].dist)
							{dist_min = D[i][j].dist;}//actualise d_min
					}
				}
				
			}
		}
		printf("dist_min = %.1f\n",dist_min);
		
		for (i=1;i<21;i++)
		{
			if (F.S[i] == 0)
			{
				for (j=i+1; j<21; j++)
				{
					if (F.S[j] == 0)
					{
						if (dist_min == D[i][j].dist)
						{
							printf("seq [%d]-[%d]\n",i,j);
							save[i]++;
							save[j]++;
						}
						
					}
				}
				
			}
		}
		
		j = 0;
		for (i=1; i<21; i++){
			if(F.S[i] == 0 && (most < save[i]))
			{
				most = save[i];
				j = i;
			}
		}
		
		F.S[j] = F.nb_fam;//ajout de la seq la plus frequente pour dist_min

		for (i=1; i<21; i++)
		{
			printf("seq[%d] -> famille %d\n",i,F.S[i]);
			if (F.S[i] == 0 && i!=j)
			{
				printf("   			D[%d][%d] = %.1f\n",i,j,D[i][j].dist);
				if(D[i][j].dist == dist_min)
				{
					F.S[i] = F.nb_fam;
					printf("			F.S[%d] = %d\n",i,F.S[i]);
				}
			}
		}
		printf("F.S[%d] = %d\n",j,F.S[j]);
		printf("##############\n");
		
		for (i=1; i<21; i++)
		{
			if(F.S[i] == 0)
			{
				pas_complet = 1;
				break;
			}
		}
		printf(" \n");
		
	} //fin while(pas_complet)
	
	
	return F; 
}
	
void affiche_familles(FAMILLES F)
{
	int i, j;
	for(i=1; i <= F.nb_fam; i++)
	{
		printf("Famille numéro %d\n",i); 
		printf("groupe sequences : ");
		
		for (j=1; j<21; j++)
		{
			if (F.S[j]==i)
			{
				printf("[%d]   ",j);
			}
			
		}
		
		printf("\n\n");
	}
	
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
	
	
//A CORRIGER
/* void place_famille(FAMILLE F[]) //A CORRIGER
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

} */
