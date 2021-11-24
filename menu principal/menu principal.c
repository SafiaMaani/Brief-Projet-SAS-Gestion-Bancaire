#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

int choix,i = 0,n = 0;
char cin[10];

typedef struct
{
	char cin [10];
	char nom [10];
	char prenom[10];
    float solde;
}client;

 client c[100];
 
void rechercheCIN ()
{
		for ( i = 0; i < n ;i++)
		{
			printf ("entrer le CIN");
			scanf("%s",cin);
			
				if (strcmp(cin, c[i].cin) == 0)
				{
					printf("***LES INFOS DE TITULAIRE DE COMPTE***\n\n NOM : %s\nPRENOM : %s\nCIN : %s\nSOLDE : %.2fDH",c[i].nom,c[i].prenom,c[i].cin,c[i].solde);	
				}
				else
				{
					printf("Compte introuvable");
				}	
		}	
}

void affichage ()
{
	printf("Veuillez choisir le type d'affichage des infos client !\n");
	printf("1. Recherche par CIN\n");
	printf("2. Par Ordre Ascendant\n");
	printf("3. Recherche par Ordre Descendant\n");
	printf("4. Recherche par Ordre Ascendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n");
	printf("5. Recherche par Ordre descendant (les comptes bancaires ayant un montant supérieur à un chiffre introduit)\n");
	scanf("%d",&choix);
	
			switch(choix) 
			{
				case 1 :
					printf("Recherche par CIN\n");
					rechercheCIN();
					break;
				case 2 :
					printf("Recherche par Ordre Ascendant\n");
					break;
				case 3 :
					printf("3. Recherche par Ordre Descendant\n");
					break;
				case 4 :
					printf("4. Recherche par Ordre Ascendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
					break;
				case 5 :
					printf("4. Recherche par Ordre descendant (les comptes bancaires ayant un montant superieur a un chiffre introduit)\n");
					break;
				default:
					break;						
			}
}

void operations()
{
	float montantX;
	int  found = 0; // au lieu d'utiliser les booleans
	
			
	printf("\n**Verification d'indentite**\n\n"); 
	printf("entrer un cin\n");
 	scanf("%s",cin);
 	
 		for ( i = 0; i < n ;i++)
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
		printf("Compte introuvable");
			sleep(5);
			menuFonction();
}
// creation plusieur comptes 
void creationPlsrComptes ()
{
	int nb;
	int j;
	printf("donner le nombre de comptes : \n");
	scanf("%d",&nb);
	for (j = 0; j < nb+n ; j++)
	{
			printf("Veuillez entrer le nom : ");
			scanf("%s",c[j].nom);
			
			printf("Veuillez entrer le prenom : ");
			scanf("%s",c[j].prenom);
			
			printf("Veuillez entrer le cin : ");
			scanf("%s",c[j].cin);
			
			printf("Veuillez entrer un montant : ");
			scanf("%f",&c[j].solde);
	}	
	n = n + nb;
		for(j = 0; j < nb+n;j++)
 			{
	 			printf("vos informations :\n\n");
			    printf("Nom: %s\n",c[j].nom);
			    printf("Prenom: %s\n",c[j].prenom);
			    printf("CIN: %s\n",c[j].cin);
			    printf("Montant: %.2f DH\n\n",c[j].solde);			
			} 
}
//creation de compte ... 
void creationCompte()
  {
		    printf("Veuillez entrer le nom : ");
			scanf("%s",c[i].nom);
			
			printf("Veuillez entrer le prenom : ");
			scanf("%s",c[i].prenom);
			
			printf("Veuillez entrer le cin : ");
			scanf("%s",c[i].cin);
			
			printf("Veuillez entrer un montant : ");
			scanf("%f",&c[i].solde);
    		
    		//n++;
 system("cls");
 			for(i = 0; i < n;i++)
 			{
	 			printf("vos informations :\n\n");
			    printf("Nom: %s\n",c[i].nom);
			    printf("Prenom: %s\n",c[i].prenom);
			    printf("CIN: %s\n",c[i].cin);
			    printf("Montant: %.2f DH\n\n",c[i].solde);			
			} 
  }
void menuFonction()
{
      int menu;
    
system("cls");	// clean ecran : ça efface ce qui était ecrit avant ...
	printf("1. Creation de compte\n");
	printf("2. Creation de plusiers comptes\n");
	printf("3. Operations\n");
	printf("4. Affichage\n");
	printf("5. Fedilisation\n");
	printf("6. QUITTER\n\n");

	printf("Veuillez entrer le num de votre operation\t");
	scanf("%d",&menu);
	
		switch (menu)
	{
		case 1:
 system ("cls");

			printf("Creation de compte\n");
			creationCompte();
			printf("Le compte a ete cree avec succes !\n\n");
			
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
			case 2:			
			system ("cls");
				printf("Creation de plusiers comptes\n");
				creationPlsrComptes();
				menuFonction();
			break;
//the user will choose if he wonna do un RETRAIT or un DEPOT d'argent ...			
		case 3:
			printf("Operations\n");
			operations();
			break;
		case 4:
			printf("Affichage\n");
			affichage ();
			break;
	  	case 5:
			printf("Fedilisation\n");
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
