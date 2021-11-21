#include <stdio.h>

void menuFonction(void)
 {
      int menu;
// clean ecran 
system("cls");	
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
			printf("Creation de compte\n");
			//creationCompte();
			break;
		case 2:
			printf("Creation de plusiers comptes\n");
			//creationCompte();    //if the user hopes to create an other account ... we recall creationCompte function ...
			break;
		case 3:
			printf("Operations\n");
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
