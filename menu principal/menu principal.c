#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int choix;
int i = 0;
int j = 0;
float montantX;
int NombreComptes;
char cin[10];

typedef struct
{
	char cin [10];
	char nom [10];
	char prenom[10];
    float solde;
}client;

	client temp;
 	client c[100];

void fedilisation ()
{
                for (i = 1; i < NombreComptes; i++)
                {
                    for (j = 0; j < NombreComptes - i; j++)
                    {
                       if (c[j].solde > c[j + 1].solde) {
                            temp = c[j];
                            c[j] = c[j + 1];
                            c[j + 1] = temp;
                         }
                    }
                }

                for(i = 0; i < 3 ; i++)
                {
                    printf("\n CIN : %s\nle solde de %s AVANT la fedilisation est de %.2f",c[i].cin,c[i].nom,c[i].solde);
                    c[i].solde *= 1.013;
                    printf("\n CIN : %s\nle solde de %s\APRES la fedilisation est de %.2f",c[i].cin,c[i].nom,c[i].solde);

                }

}

 void rechercheAscDescCond ()
{

	printf("***Recherche par Ordre Ascendant Ou Descendant Conditionne***\n\n");
	printf("Merci de rentré le seuil\n");
	scanf("%f",&montantX);

    printf("Merci d'entree l'ordre que vous voulez\n");
    printf("1. Ascendent\n");
    printf("2. Descendant\n");
    scanf("%d",&choix);

                switch(choix)
                {
                case 1 :
	                for (i = 1; i < NombreComptes; i++)
	                {
	                    for (j = 0; j < NombreComptes - i; j++)
	                    {
	                        if (c[j].solde > c[j + 1].solde)
	                        {
	                                temp = c[j];
	                                c[j] = c[j + 1];
	                                c[j + 1] = temp;
	                        }
	                    }
	                }
	                   for (i = 0; i < NombreComptes; i++)
	                    {
	                        if(montantX < c[i].solde)
	                        {
	                           printf("\n%s\t%s\t%f",c[i].cin,c[i].nom,c[i].solde);
	                        }
	                    }
                   break;
                   
                   case 2:
	                    for (i = 1; i < NombreComptes; i++)
	                    {
	                    	for (j = 0; j < NombreComptes - i; j++)
							{
								if (c[j].solde < c[j + 1].solde)
								{
		                            temp = c[j];
		                            c[j] = c[j + 1];
		                            c[j + 1] = temp;
		                        }
                     		}
	                    	
						}

                   for (i = 0; i < NombreComptes; i++)

                    { 
						if(montantX < c[i].solde)
	                    {
	                       printf("\n%s\t%s\t%f",c[i].cin,c[i].nom,c[i].solde);
	                    }
                  	}
                }
}

void rechercheCIN ()
{
    system("cls");
    	printf("***RECHERCHE PAR CIN***\n\n");
		printf ("\n entrer le CIN \n");
		scanf("%s",cin);

		for ( i = 0; i < NombreComptes ;i++)
		{
				if (strcmp(cin, c[i].cin) == 0)
				{
					printf("*LES INFOS DE TITULAIRE DE COMPTE*\n\n NOM : %s\nPRENOM : %s\nCIN : %s\nSOLDE : %.2fDH",c[i].nom,c[i].prenom,c[i].cin,c[i].solde);
				
					system ("PAUSE");
					menuFonction();
				}

		}
		printf("\nCompte introuvable");
		system ("PAUSE");
		rechercheCIN();
}
void rechercheAscDesc ()
	{

			printf("***Recherche par Ordre Ascendant Ou Descendant***\n\n");
		    printf("Merci d'entree l'ordre que vous voulez\n");
		    printf("1. Ascendent\n");
		    printf("2. Descendant\n");
		    scanf("%d",&choix);

                switch(choix)
                {
                case 1 :
                for (i = 1; i < NombreComptes; i++)
                {
                      for (j = 0; j < NombreComptes - i; j++)
                    {
                       	if (c[j].solde > c[j + 1].solde)
						{
                            temp = c[j];
                            c[j] = c[j + 1];
                            c[j + 1] = temp;
                        }
                    }
                }
                for (i = 0; i < NombreComptes; i++)
				{

                      printf("\nNOM : %s\tCIN : %s\tSOLDE : %.2f",c[i].cin,c[i].nom,c[i].solde);
                }
                break;
                
                case 2:
                    for (i = 1; i < NombreComptes; i++)
                    {
                    	for (j = 0; j < NombreComptes - i; j++) 
						{
	                        if (c[j].solde < c[j + 1].solde)
							{
	                            temp = c[j];
	                            c[j] = c[j + 1];
	                            c[j + 1] = temp;
	                        }
                     	}
					}
                   	for (i = 0; i < NombreComptes; i++)
				   	{
                      printf("\n%s\t%s\t%.2f",c[i].cin,c[i].nom,c[i].solde);
                   	}
                }
   }
void affichage ()
{

	printf("Veuillez choisir le type d'affichage des infos client !\n");
	printf("1. Recherche par CIN\n");
	printf("2. Par Ordre Ascendant Ou Descendant\n");
	printf("3. Recherche par Ordre Ascendant Ou Descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n");
	scanf("%d",&choix);

			switch(choix)
			{
				case 1 :
					rechercheCIN();
					break;
				case 2 :
					rechercheAscDesc();

					break;
				case 3 :
					printf("4. Recherche par Ordre Ascendant Ou Descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
					rechercheAscDescCond();
					break;
				default:
					break;
			}
}

void operations()
{

	printf("\n*Verification d'indentite*\n\n");
	printf("entrer un cin\n");
 	scanf("%s",cin);

 		for ( i = 0; i < NombreComptes ;i++)
		{
		 	if (strcmp(cin, c[i].cin) == 0)
		 	{
		 		printf("Voulez-vous faire un Retrait ou DEPOT d'argent ?\n");
				printf("1. --RETRAIT--\n");
				printf("2. --DEPOT--\n");
				scanf("%d",&choix);

				printf("Veuillez entrer un montant");
				scanf("%f",&montantX);

						switch(choix)
						{
							case 1:

									if(montantX <= c[i].solde)
									{
										c[i].solde -= montantX ;
										printf("Vous avez retire %.2f DH , Votre solde est de %.2f DH\n",montantX,c[i].solde);
												printf("1. Voulez-vous revenir au menu principal ?\n");
									    		printf("2. QUITTER !\n");
												scanf("%d",&choix);
													if(choix == 1)
													{
														menuFonction();
													}
													else
													{
													printf("A bientot!");
													}
									}
									else
									{
										printf("Veuillez saisir un montant inferieur ou egale a votre solde");
										operations ();
									}
								break;

							case 2:
									c[i].solde += montantX ;

									printf("Vous avez depose %.2f DH , Votre solde est de %.2f DH\n",montantX,c[i].solde);
												printf("1. Voulez-vous revenir au menu principal ?\n");
									    		printf("2. QUITTER !\n");
												scanf("%d",&choix);
													if(choix == 1)
													{
														menuFonction();
													}
													else
													{
													printf("A bientot!");
													}

								break;
							default:
								operations();
								break;
						}
						break;

			}
		}
		printf("Compte introuvable\n");
}

 void creationPlsrComptes ()
{

	printf("donner le nombre de comptes : \n");
	scanf("%d",&NombreComptes);

		for (i = 0; i < NombreComptes ; i++)
		{
				printf("Veuillez entrer le nom : ");
				scanf("%s",c[i].nom);

				printf("Veuillez entrer le prenom : ");
				scanf("%s",c[i].prenom);

				printf("Veuillez entrer le cin : ");
				scanf("%s",c[i].cin);

				printf("Veuillez entrer un montant : ");
				scanf("%f",&c[i].solde);
		}
		printf("\n\n***INFOS SAISIES***\n\n");
		for(i = 0; i < NombreComptes;i++)
 			{
			    printf("Nom: %s\n",c[i].nom);
			    printf("Prenom: %s\n",c[i].prenom);
			    printf("CIN: %s\n",c[i].cin);
			    printf("Montant: %.2f DH\n\n",c[i].solde);
			}
}

void creationCompte()
  {
		    printf("Veuillez entrer le nom : ");
			scanf("%s",c[NombreComptes].nom);

			printf("Veuillez entrer le prenom : ");
			scanf("%s",c[NombreComptes].prenom);

			printf("Veuillez entrer le cin : ");
			scanf("%s",c[NombreComptes].cin);

			printf("Veuillez entrer un montant : ");
			scanf("%f",&c[NombreComptes].solde);

			NombreComptes++;

 system("cls");
 			for(i = 0; i < NombreComptes;i++)
 			{
	 			printf("\n\n***INFOS SAISIES***\n\n");
			    printf("Nom: %s\n",c[i].nom);
			    printf("Prenom: %s\n",c[i].prenom);
			    printf("CIN: %s\n",c[i].cin);
			    printf("Montant: %.2f DH\n\n",c[i].solde);
			}

  }
void menuFonction()
{
	
system("cls");	// clean ecran : ça efface ce qui était ecrit avant ...
	printf("1. Creation de compte\n");
	printf("2. Creation de plusiers comptes\n");
	printf("3. Operations\n");
	printf("4. Affichage\n");
	printf("5. Fedilisation\n");
	printf("6. QUITTER\n\n");

	printf("Veuillez entrer le num de votre operation\t");
	scanf("%d",&choix);

		switch (choix)
	{
		case 1:
 
	system ("cls");
			printf("Creation de compte\n");
			creationCompte();
			printf("Le compte a ete cree avec succes !\n\n");
			
			system("PAUSE");
			
			menuFonction();
			
			break;
			
			case 2:
	system ("cls");
			int compteur = 1;
				printf("Creation de plusiers comptes\n");
				creationPlsrComptes();

				system("PAUSE");
				
				menuFonction();
			break;

		case 3:
			printf("Operations\n");
			operations();
			
			system("PAUSE");
			
			menuFonction ();
			break;
			
		case 4:
			printf("Affichage\n");
			affichage ();
			break;
	  	case 5:
			printf("Fedilisation\n");
			fedilisation();
			break;
		case 6:
			printf("QUITTER\n");	
			break;
		default:
		   menuFonction();
		    break;
	}
}

int main()
{
   menuFonction() ;
}
