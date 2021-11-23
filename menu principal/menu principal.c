#include <stdio.h>


int choixOperation;
void operation()
{
system("cls");	
	printf("Voulez-vous faire un Retrait ou DEPOT d'argent ?\n");
	printf("1. --RETRAIT--\n");
	printf("2. --DEPOT--\n");
	scanf("%d",&choixOperation);
system ("cls");	
	switch(choixOperation)
	{	
		case 1:
			printf("---RETRAIT---\n");
			//je dois creer une fonction qui va me calculer le nv Mt apres le RETRAIT d'argent ...
			break;
		case 2:
			printf("---DEPOT---\n");
		  	//je dois creer une fonction qui va me calculer le nv Mt apres le DEPOT d'argent ...
			break;
		default:
			operation();
			break;	
	}
}

//creation de compte ... 
int choixMulti, quitterReMenu;
void creationCompte()
  {
    char cin [10], nom [10], prenom[10];
    int montant;
    
    printf("CIN : ");
    scanf("%s",&cin);
    
    printf("Nom : ");
    scanf(" %s",&nom);
    
    printf("Prenom : ");
    scanf(" %s",&prenom);
    
    printf("Montant : ");
    scanf("%d",&montant);
    
 system("cls");
 	printf("vos informations :\n\n");
    printf("Nom: %s\n",nom);
    printf("Prenom: %s\n",prenom);
    printf("CIN: %s\n",cin);
    printf("Montant: %d\n\n",montant);    
    
  }
void menuFonction(void){
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
			scanf("%d",&quitterReMenu);
				if(quitterReMenu == 1)
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
				creationCompte();
				printf("Le compte a ete cree avec succes !\n\n");
			
///After creating the first account, giving the user 3 choices : if he hopes to create an other account, back to the principal menu or just leave ..

				do{
					printf("1. Voulez-vous creer un autre compte ?\n");
					printf("2. Revenir au Menu Principal !\n");
					printf("3. QUITTER !\n");
					scanf("%d",&choixMulti);
			
					if(choixMulti == 1)
					{
						creationCompte();
						printf("Le compte a ete cree avec succes !\n\n");
					}
					else if (choixMulti == 2)
					{
						menuFonction();
					}
					else 
					{
						printf("A bientot!");
					}
				} while(choixMulti == 1);	
			
			break;
//the user will choose if he wonna do un RETRAIT or un DEPOT d'argent ...			
		case 3:
			printf("Operations\n");
			operation();
			if(choixOperation == 1)
			{
				printf("CALL FONCTION RETRAIT");
			}
			else if(choixOperation == 2)
			{
				printf("CALL FONCTION DEPOT");
			}
			else
			{
				operation();
			}
			break;
		case 4:
			printf("Affichage\n");
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
