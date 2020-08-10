#include "erreurs.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void interface_0()
{
	system("color 9");
      printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    wprintf(L"|  Dirig%1c par       :       Stephane Fedim                                                      |\n", 130);
      printf("*                                                                                               *\n");
      printf("|  Auteur           :       DETERGENT MADAR                                                     |\n");
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
	interface_0();
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t*********************************************************************\t\n");
	printf("\t\t\t    KALATA BANK\t\t\t\n");
	printf("\t*********************************************************************\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"A. G%1crer les clients.    B. G%1crer les comptes.    C. G%1crer les op%1crations.    D. Quitter.\n\n",130, 130, 130, 130);
	printf("Entrez votre choix : ");
	verification("ABCD",choice);
}

void interface_2(char *choice)
{
	system("cls");
	system("color 1B");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     VEUILLEZ GERER VOS OPERATIONS\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"1. FAIRE UN RETRAIT.     2. FAIRE UN VIREMENT.    3. ACCUEIL.\n\n");
	printf("Entrez votre choix : ");
	verification("123",choice);
}

void interface_3()
{
	system("cls");
	system("color A0");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     VEUILLEZ AJOUTER DES CLIENTS ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_4()
{
	system("cls");
	system("color D0");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t        VEUILLEZ MODIFIER UN CLIENT ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_5()
{
	system("cls");
	system("color BD");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t        VEUILLEZ SUPPRIMER UN CLIENT ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_6(char *choice)
{
	system("cls");
	system("color 0E");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     VEUILLEZ GERER VOS CLIENTS\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"1. AJOUTER    2. MODIFIER.   3. SUPPRIMER.    4. AFFICHER LES CLIENTS.    5. RECHERCHE.     6. ACCUEIL.\n\n");
	printf("Entrez votre choix : ");
	verification("123456",choice);
}

void interface_7()
{
	system("cls");
	system("color 1F");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     LISTE DES CLIENTS\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_8()
{
	system("cls");
	system("color F9");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     EFFECTUER LA RECHERCHE D'UN CLIENT ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_9()
{
	system("cls");
	system("color 2F");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     LISTE DES COMPTES\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_10()
{
	system("cls");
	system("color E1");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     CREER UN NOUVEAU COMPTE ICI\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_11()
{
	system("cls");
	system("color 4B");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     CONSULTEZ VOTRE COMPTE\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
}

void interface_12(char *choice)
{
	system("cls");
	system("color 0B");
	printf("\t---------------------------------------------------------------------\t\n");
	printf("\t\t\t     VEUILLEZ GERER VOS COMPTES\t\t\t\n");
	printf("\t---------------------------------------------------------------------\t\n\n");
	printf("Que voulez-vous faire ?\n\n");
	wprintf(L"1. AJOUTER UN COMPTE.    2. FERMER UN COMPTE.    3. CONSULTER.    4. AFFICHER LES COMPTES.    5. ACCUEIL.\n\n");
	printf("Entrez votre choix : ");
	verification("12345",choice);
}

