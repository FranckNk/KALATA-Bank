#include "erreurs.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void interface_0()
{
      printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    wprintf(L"|  Dirig%1c par       :       Stephane Fedim                                                           |\n", 130);
      printf("*                                                                                               *\n");
      printf("|  Auteurs          :        Madar, Joseph                                                      |\n");
      printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
      printf("\n");
}
/*
void interface_13()
{
      printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
      printf("* +_________   + ________    +   ________     +  _____________  + ___________   + ______________  *\n");
      printf("| |   ____  \\   |  ___   \\      /         \\     |             |  |          |    |              | | \n");
      printf("* |  |   +|  |  |  |+  \\  \\    |   ______  |    |____     ____|  |   |------|  + |____     _____| *\n");
      printf("| |  |____/  |  |  |    |  |   |  |     |  |   +     |   |       |   |   +            |   | +     |\n");
      printf("* |   _____ /   |  |____|  |  +|  | +   |  |         |   |    +  |   |___             |   |     + *\n");
      printf("* |  |+        +|          /   |  |     |  | +       |   |       |       |       +    |   |       *\n");
      printf("* |  |          |  |-----  \\   |  |     |  |      +  |   |       |    ___|            |   |       *\n");
      printf("* |  |     +    |  |    +\\  \\  |  |   + |  |    +    |   |+      |   |    +        +  |   |       *\n");
      printf("* |  |          |  |     |  |  |  |_____|  |    __   |   |       |   |                |   |    +  *\n");
      printf("* |  | +        |  |     |  |  |           |   |  \\__/   |       |   |-------|    +   |   |       *\n");
      printf("* |__|          |__| +   |__|   \\_________/+    \\_______/   +    |___________|        |___|    +  *\n");
      printf("*   +    +                     +               +                            +         +           *\n");
      printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
      printf("\n");
}
*/

void interface_1(char *choice)
{
	system("cls");
	system("color 37");
	interface_0();
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tKALATA BANK\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"1. G%1crer les clients\t2. G%1crer les comptes\t3. G%1crer les op%1crations \t4. Quitter\n\n",130, 130, 130, 130);
	printf("Entrez votre choix : ");
	verification("1234",choice);
}

void interface_3()
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tVEUILLEZ AJOUTER DES CLIENTS ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");

}
void interface_4()
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tVEUILLEZ MODIFIER UN CLIENT ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}
void interface_5()
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tVEUILLEZ SUPPRIMER UN CLIENT ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}
void interface_6(char *choice)
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tVEUILLEZ GERER VOS CLIENTS\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"1. Liste d'admis\n2. Liste d'attente\n3. Rechercher \n4. Statistiques \n5. Affiche m%1crite\n6. Supprimer %1cg%1cs\n7. Sortir\n\n",130, 131, 130);
	printf("Entrez votre choix : ");
	verification("1234567",choice);
}
void interface_7()
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tLISTE DES CLIENTS\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_8()
{
	system("cls");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\tEFFECTUER LA RECHERCHE ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}
