
#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*Declaration des variables et initialisation */
		int Jeu ;
		char J1[20], J2[20] ;
		char AffP[6][7] ;
		int Puiss[6][7]={0};
		int L, Ligne, Colone, Last ;
		int Victoire, Lastplay, Choix, A, B, C, D, E, F, G, H;
		int Mor[3][3]={0};
		char Aff[9]={'1','2','3','4','5','6','7','8','9'};
		char Sortie ;

	
		for(L = 0 ; L < 6 ; L++)
		{
			for(C = 0 ; C < 7 ; C++)
			{
				AffP[L][C] = 'O' ;
			}
		}

		Last = 2  ;
		Victoire = 0;
		Lastplay = 2 ;


	printf("		Jeux Puissance 4 \n\n");
printf(" voulez-vous jouer ?  \n Entrer 1 si oui ou 0 sinon \n");

	scanf("%d",&Jeu);

	switch(Jeu)
	{
	

///////////////////////Debut puissance 4 /////////////////////////////////////

	case(1) : /*Affichage des messages et acquisition des noms */
		
		puts("			Bienvenue au Puissance 4 ");
		puts(" ");
	/*Saisie des noms des joueurs */
		puts ("Joueur1, Veuillez decliner votre identite :");
		fflush(stdin);
		scanf("%s",J1);
		puts(" ");
		puts ("Joueur2, Veuillez decliner votrez identite :") ;
		fflush(stdin);
		scanf("%s",J2);
		puts(" ");
	/*Attribution des R ou des J */
		printf("%s, Vous aurez les R\n\n",J1) ;
		printf("%s, Vous aurez les J\n\n",J2) ;
		do
		{
	/*Affichage du tableau */
			printf("		   0     1     2     3     4     5     6  \n");
		printf("		___________________________________________\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[5][0] ,AffP[5][1],AffP[5][2],AffP[5][3],AffP[5][4],AffP[5][5],AffP[5][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[4][0] ,AffP[4][1],AffP[4][2],AffP[4][3],AffP[4][4],AffP[4][5],AffP[4][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[3][0] ,AffP[3][1],AffP[3][2],AffP[3][3],AffP[3][4],AffP[3][5],AffP[3][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[2][0] ,AffP[2][1],AffP[2][2],AffP[2][3],AffP[2][4],AffP[2][5],AffP[2][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[1][0] ,AffP[1][1],AffP[1][2],AffP[1][3],AffP[1][4],AffP[1][5],AffP[1][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[0][0] ,AffP[0][1],AffP[0][2],AffP[0][3],AffP[0][4],AffP[0][5],AffP[0][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");

	/*Test permetant de gerer le tour a tour des joueurs*/
		if(Last == 2)
		{
			printf("	%s, Choisissez une colone\n", J1);
			scanf("%d",&Colone);
	/*Differents cas d'invalidité de la colone */
			while(Colone > 6 )
			{
				printf("Votre Colone est invalide veuillez faire un autre choix\n");
				scanf("%d",&Colone);
			}
 
			while (	AffP[5][Colone] == 'R' ||AffP[5][Colone] == 'J' )
			{
				puts ("La colone choisie est complete veuillez effectuer un autre choix ");
				scanf("%d",&Colone);
				while(Colone > 6 )
				{
					printf("Votre Colone est invalide veuillez faire un autre choix\n");
					scanf("%d",&Colone);
				}
			}
	/*Remplissage du tableau en faisant comme si le jeton tombait*/
			for(L = 0 ; L < 6 ; L++)
			{
				if(Puiss[L][Colone] == 0 )
				{
					Puiss[L][Colone] = 1 ;
					AffP[L][Colone]= 'R';
					Ligne = L ;
					L = 6 ;
				}
			}
	/*Test pour l'alignement vertical*/
			if(Ligne >= 3)
			{
				if(Puiss[Ligne-1][Colone]== 1 )
				{
					if(Puiss[Ligne-2][Colone]==1)
					{
						if(Puiss[Ligne-3][Colone]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
	/*Tests pour l'alignement horizontal : il y en a 4 car il y a 4 possiblilité de position du pion dans l'alignement*/
			if(Colone <= 3)
			{
				if(Puiss[Ligne][Colone+1]== 1 )
				{
					if(Puiss[Ligne][Colone+2]==1)
					{
						if(Puiss[Ligne][Colone+3]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne][Colone-1]== 1 )
				{
					if(Puiss[Ligne][Colone+1]==1)
					{
						if(Puiss[Ligne][Colone+2]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Colone <= 5 && Colone >= 2)
			{
				if(Puiss[Ligne][Colone-2]== 1 )
				{
					if(Puiss[Ligne][Colone-1]==1)
					{
						if(Puiss[Ligne][Colone+1]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Colone >= 3)
			{
				if(Puiss[Ligne][Colone -3]== 1 )
				{
					if(Puiss[Ligne][Colone-2]==1)
					{
						if(Puiss[Ligne][Colone -1]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

	/*Tests pour la diagonale montante, il y a encore 4 test pour les meme raisons que precedement */
			if(Ligne <= 2 && Colone <= 3)
			{
				if(Puiss[Ligne+1][Colone+1]== 1 )
				{
					if(Puiss[Ligne+2][Colone+2]==1)
					{
						if(Puiss[Ligne+3][Colone+3]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Ligne >= 1 && Ligne <= 3 && Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne-1][Colone-1]== 1 )
				{
					if(Puiss[Ligne+1][Colone+1]==1)
					{
						if(Puiss[Ligne+2][Colone+2]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Ligne >= 2 && Ligne <= 4 && Colone >= 2 && Colone <= 5)
			{
				if(Puiss[Ligne-2][Colone-2]== 1 )
				{
					if(Puiss[Ligne-1][Colone-1]==1)
					{
						if(Puiss[Ligne+1][Colone+1]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}

			if(Ligne >= 3 && Colone >= 3)
			{
				if(Puiss[Ligne-3][Colone-3]== 1 )
				{
					if(Puiss[Ligne-2][Colone-2]==1)
					{
						if(Puiss[Ligne-1][Colone-1]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
	/*Tests pour la diagonale descendente*/
			if(Ligne >= 3 && Colone <= 3 )
			{
				if(Puiss[Ligne-1][Colone+1]== 1 )
				{
					if(Puiss[Ligne-2][Colone+2]==1)
					{
						if(Puiss[Ligne-3][Colone+3]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
			if(Ligne >= 2 && Ligne <= 4 && Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne-2][Colone+2]== 1 )
				{
					if(Puiss[Ligne+1][Colone-1]==1)
					{
						if(Puiss[Ligne-1][Colone+1]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
			if(Ligne >= 1 && Ligne <= 3 && Colone <= 5 && Colone >= 2)
			{
				if(Puiss[Ligne+1][Colone-1]== 1 )
				{
					if(Puiss[Ligne-1][Colone+1]==1)
					{
						if(Puiss[Ligne+2][Colone-2]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
			if( Ligne <= 2 && Colone >= 3)
			{
				if(Puiss[Ligne+2][Colone-2]== 1 )
				{
					if(Puiss[Ligne+1][Colone-1]==1)
					{
						if(Puiss[Ligne+3][Colone-3]==1)
						{
							Victoire = 1 ;
						}
					}
				}
			}
			Last = 1 ;
			if(Puiss [5][0] != 0 && Puiss [5][1] != 0 && Puiss [5][2] != 0 && Puiss [5][3] != 0 && Puiss [5][4] != 0 && Puiss [5][5] != 0 && Puiss [5][6] != 0 )
			{
				Victoire = 3 ;
			}
		}
		else
	/*Les commentaires sont les memes que precedement puisque ce qui se produit pour un joueur peu aussi ce produire pour l'autre */
		{
			printf("	%s, Choisissez une colone\n", J2);
			scanf("%d",&Colone);
			while(Colone > 6 )
			{
				printf("Votre Colone est invalide veuillez faire un autre choix\n");
				scanf("%d",&Colone);
			}
 
			while (	AffP[5][Colone] == 'R' ||AffP[5][Colone] == 'J' )
			{
				puts ("La colone choisie est complete veuillez effectuer un autre choix ");
				scanf("%d",&Colone);
				while(Colone > 6 )
				{
					printf("Votre Colone est invalide veuillez faire un autre choix\n");
					scanf("%d",&Colone);
				}
			}

			for(L = 0 ; L < 6 ; L++)
			{
				if(Puiss[L][Colone] == 0 )
				{
					Puiss[L][Colone] = 2 ;
					AffP[L][Colone] = 'J' ;
					Ligne = L ;
					L = 6 ;
				}
			}
	/*Test pour l'alignement vertical*/
			if(Ligne >= 3)
			{
				if(Puiss[Ligne-1][Colone]== 2 )
				{
					if(Puiss[Ligne-2][Colone]==2)
					{
						if(Puiss[Ligne-3][Colone]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
	/*Tests pour l'alignement horizontal : il y en a 4 car il y a 4 possiblilité de position du pion dans l'alignement*/
			if(Colone <= 3)
			{
				if(Puiss[Ligne][Colone+1]== 2 )
				{
					if(Puiss[Ligne][Colone+2]==2)
					{
						if(Puiss[Ligne][Colone+3]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

			if(Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne][Colone-1]== 2 )
				{
					if(Puiss[Ligne][Colone+1]==2)
					{
						if(Puiss[Ligne][Colone+2]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

			if(Colone <= 5 && Colone >= 2)
			{
				if(Puiss[Ligne][Colone-2]==2 )
				{
					if(Puiss[Ligne][Colone-1]==2)
					{
						if(Puiss[Ligne][Colone+1]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

			if(Colone >= 3)
			{
				if(Puiss[Ligne][Colone -3]== 2 )
				{
					if(Puiss[Ligne][Colone-2]==2)
					{
						if(Puiss[Ligne][Colone -1]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

	/*Tests pour la diagonale montante, il y a encore 4 test pour les meme raisons que precedement */
			if(Ligne <= 2 && Colone <= 3)
			{
				if(Puiss[Ligne+1][Colone+1]== 2 )
				{
					if(Puiss[Ligne+2][Colone+2]==2)
					{
						if(Puiss[Ligne+3][Colone+3]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

			if(Ligne >= 1 && Ligne <= 3 && Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne-1][Colone-1]== 2 )
				{
					if(Puiss[Ligne+1][Colone+1]==2)
					{
						if(Puiss[Ligne+2][Colone+2]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}

			if(Ligne >= 2 && Ligne <= 4 && Colone >= 2 && Colone <= 5)
			{
				if(Puiss[Ligne-2][Colone-2]== 2 )
				{
					if(Puiss[Ligne-1][Colone-1]==2)
					{
						if(Puiss[Ligne+1][Colone+1]==2)
						{
							Victoire = 2 ;						}
					}
				}
			}

			if(Ligne >= 3 && Colone >= 3)
			{
				if(Puiss[Ligne-3][Colone-3]== 2 )
				{
					if(Puiss[Ligne-2][Colone-2]==2)
					{
						if(Puiss[Ligne-1][Colone-1]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
	/*Tests pour la diagonale descendente*/
			if(Ligne >= 3 && Colone <= 3 )
			{
				if(Puiss[Ligne-1][Colone+1]== 2 )
				{
					if(Puiss[Ligne-2][Colone+2]==2)
					{
						if(Puiss[Ligne-3][Colone+3]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
			if(Ligne >= 2 && Ligne <= 4 && Colone <= 4 && Colone >= 1)
			{
				if(Puiss[Ligne-2][Colone+2]== 2 )
				{
					if(Puiss[Ligne+1][Colone-1]==2)
					{
						if(Puiss[Ligne-1][Colone+1]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
			if(Ligne >= 1 && Ligne <= 3 && Colone <= 5 && Colone >= 2)
			{
				if(Puiss[Ligne+1][Colone-1]== 2 )
				{
					if(Puiss[Ligne-1][Colone+1]==2)
					{
						if(Puiss[Ligne+2][Colone-2]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
			if( Ligne <= 2 && Colone >= 3)
			{
				if(Puiss[Ligne+2][Colone-2]== 2 )
				{
					if(Puiss[Ligne+1][Colone-1]==2)
					{
						if(Puiss[Ligne+3][Colone-3]==2)
						{
							Victoire = 2 ;
						}
					}
				}
			}
			Last = 2 ;
			if(Puiss [5][0] != 0 && Puiss [5][1] != 0 && Puiss [5][2] != 0 && Puiss [5][3] != 0 && Puiss [5][4] != 0 && Puiss [5][5] != 0 && Puiss [5][6] != 0 )
			{
				Victoire = 3 ;
			}
		}
	/*Sortie de la boucle car soit l'un des 2 joueurs a gagné soit le tableau est complet */
		}while(Victoire !=1 && Victoire != 2 && Victoire != 3);
	/*Affichage du tableau final*/
		printf("		   0     1     2     3     4     5     6  \n");
		printf("		 _________________________________________\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[5][0] ,AffP[5][1],AffP[5][2],AffP[5][3],AffP[5][4],AffP[5][5],AffP[5][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[4][0] ,AffP[4][1],AffP[4][2],AffP[4][3],AffP[4][4],AffP[4][5],AffP[4][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[3][0] ,AffP[3][1],AffP[3][2],AffP[3][3],AffP[3][4],AffP[3][5],AffP[3][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[2][0] ,AffP[2][1],AffP[2][2],AffP[2][3],AffP[2][4],AffP[2][5],AffP[2][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[1][0] ,AffP[1][1],AffP[1][2],AffP[1][3],AffP[1][4],AffP[1][5],AffP[1][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		printf("		|     |     |     |     |     |     |     |\n");
		printf("		|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",AffP[0][0] ,AffP[0][1],AffP[0][2],AffP[0][3],AffP[0][4],AffP[0][5],AffP[0][6]);
		printf("		|_____|_____|_____|_____|_____|_____|_____|\n");
		
		/*Tests permetant de conaitre le vaincqueur et de le declarer */
		switch (Victoire)
		{
		case (1) : 	printf ("\a\a\a\n");
			printf("			%s a gagne BRAVO!!!!!\n\n",J1);
			break ;
		case (2):	printf ("\a\a\a\n");
			printf("			%s a gagne BRAVO!!!!!\n\n",J1);
			break;
		case(3): printf ("			Match Nul !!!\n\n");
			break;
		}
/*Fin du Puissance4*/ 
		break ;
	default : printf("			Aurevoir !!! \n");
	}
	puts("Pressez Entree pour quitter");
	fflush(stdin);
	scanf("%c",&Sortie) ;

	return 0;	
}

