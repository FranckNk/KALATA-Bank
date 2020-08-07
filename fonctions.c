#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "erreurs.h"
#include "interface.h"

typedef struct Client
{
    char Id_client[6];
    char Nom[15];
    char Prenom[15];
    char Profession[16];
    char Ntel[10];
    char Date[9];
}Client;

Client MonClient;

typedef struct Compte
{
    char Id_Compte[6];
    char Id_Client[6];
    float Solde;
    char Derniere_Op[9];
}Compte;

Compte MonCompte;

void Display_Client(Client UnClient);
Client Generer_client(char *chaine);

void Ajouter()
{
	FILE *Clients = NULL, *Comptes = NULL;
	char option,clean_buffer[50] = "";
	int i = 1;
	float Solde_Banque;
	system("cls");
    interface_3();
	Clients = fopen("Clients.txt","a");
	Comptes = fopen("Comptes.txt", "a");
	if(Clients == NULL)
	{
		printf("Impossible d'ouvrir le fichier :(\n");
		return;
	}

	do
	{
		wprintf(L"La cr%1cation d'un client conduit %1c la cr%1cation de son compte.\n",130, 133, 130);
		printf("CLIENT N - %d A AJOUTER :\n",i);
		Generer_ID(MonClient.Id_client);
		Lire_Nom_ou_Prenom(MonClient.Nom,'n');
		Lire_Nom_ou_Prenom(MonClient.Prenom,'p');
		Lire_Profession(MonClient.Profession);
		Lire_Ntel(MonClient.Ntel);
		Lire_Date(MonClient.Date);
		Creer_Solde(&MonCompte.Solde);
		fprintf(Clients,"%s|%s|%s|%s|%s|%s\n",MonClient.Id_client,MonClient.Nom,MonClient.Prenom,MonClient.Profession, MonClient.Ntel, MonClient.Date);
		Compte_ID(MonCompte.Id_Compte);
		strcpy(MonCompte.Id_Client, MonClient.Id_client);
		strcpy(MonCompte.Derniere_Op, "VIREMENT");
        Solde_Banque = Pull_Bank();
        Push_Bank(Solde_Banque + MonCompte.Solde);
        fprintf(Comptes,"%s|%s|%.0f|%s\n", MonCompte.Id_Compte, MonCompte.Id_Client, MonCompte.Solde, MonCompte.Derniere_Op);
		wprintf(L"\n\nAjout r%1cussi !!!\n",130 );
		printf("\nEntrez 0 pour quitter ou tout autre pour continuer : ");
		scanf("%c",&option);
		gets(clean_buffer);
		system("cls");
		i++;
	}while(option != '0');
	system("cls");
	system("color E0");
	fclose(Clients);
	return;
}

//Cette fonction permet de supprimer un client dans le fichier "Clients.txt"
void Supprimer()
{
    interface_5();
	char text[200] = "",text_1[200] = "";
	char *token,cart;
	int signe = 0;
	FILE *Clients_tmp = NULL;
	FILE *Clients = NULL;
	Clients = fopen("Clients.txt", "r");
    Clients_tmp = fopen("Clients_tmp.txt", "w");

	cart = fgetc(Clients);
	rewind(Clients);
	if (cart == EOF)
	{
		printf("\nFichier vide ! Suppression impossible :(.");
	}
	else
	{
	    printf("Comment voulez-vous supprimer ?\n1. UN SEUL.\t2. TOUT.\n\n>> ");
	    verification("12", &cart);
	    if(cart == '2')
        {
            fclose(Clients_tmp);
            fclose(Clients);
            remove("Clients.txt");
            rename("Clients_tmp.txt", "Clients.txt");
            wprintf(L"Suppr%1cssion r%1cussie...", 130, 130);
            system("pause");
            return;
        }
		Lire_Id(MonClient.Id_client);
		while(fgets(text,199,Clients) != NULL)
		{
			strcpy(text_1,text);
			token = strtok(text_1,"|");
			if(strcmp(token,MonClient.Id_client) != 0)
			{
				fputs(text,Clients_tmp);
			}
			else
            {
                wprintf(L"\nClient existant ! Vous %1ctes s%1cr de supprimer ?\n1. OUI\t2. NON\n>> ",136,150);
                char c;
                verification("12", &c);
                if(c == '2')
                {
                    wprintf(L"\nOp%1cration annul%1ce !", 130,130);
                    fputs(text,Clients_tmp);
                    signe = -1;
                }
                else
                {
                    signe++;
                    wprintf(L"\nSuppression r%1cussie :)\n\n", 130);
                }
            }

		}
		if(signe == 0)
			printf("\nClient inexistant :(.\n\n");

		fclose(Clients_tmp);
	}
	fclose(Clients);
	remove("Clients.txt");
	rename("Clients_tmp.txt", "Clients.txt");
	system("pause");
}

void Recherche()
{
    interface_8();
	char text[200] = "";
	char cart;
	int signe = 0;
	FILE *Clients = NULL;
	Clients = fopen("Clients.txt", "r");

	cart = fgetc(Clients);
	rewind(Clients);
	if (cart == EOF)
	{
		printf("\nFichier vide :(.");
	}
	else
	{
	    char Identifiant[5], nom[15], c;
	    wprintf(L"Vous recherchez %1c partir de : \n1. ID.\t2. NOM. \t3. Sortir.\n>> ", 133);
	    verification("123", &c);
	    if(c == '1')
            Lire_Id(Identifiant);
        if(c == '2')
            Lire_Nom_ou_Prenom(nom, 'n');
        if(c == '3')
        {
            fclose(Clients);
            return;
        }

		while(fgets(text,199,Clients) != NULL)
		{
            Client N = Generer_client(text);
            if(c == '1')
                if(strcmp(Identifiant, N.Id_client) == 0)
                {
                    Display_Client(N);
                    signe++;
                }
            if(c == '2')
                if(strcmp(nom, N.Nom) == 0)
                {
                    Display_Client(N);
                    signe++;
                }
		}

		if(signe == 0)
			printf("\nClient inexistant :(.\n\n");
	}
	fclose(Clients);
	system("pause");
}

void Display_Client(Client UnClient)
{
    printf("\nID           :   %s\nNOM          :   %s\nPRENOM       :   %s\nPROFESSION   :   %s\nTELEPHONE    :   %s\nOPENING DATE :   %s\n\n",UnClient.Id_client,UnClient.Nom,UnClient.Prenom,UnClient.Profession, UnClient.Ntel, UnClient.Date);
    printf("--------------------------------------\n\n");
}

Client Generer_client(char* chaine)
{
    char text[200], *token;
    Client Result;
    strcpy(text,chaine);
    token = strtok(text,"|");
    strcpy(Result.Id_client, token);
    token = strtok(NULL,"|");
    strcpy(Result.Nom, token);
    token = strtok(NULL,"|");
    strcpy(Result.Prenom, token);
    token = strtok(NULL,"|");
    strcpy(Result.Profession, token);
    token = strtok(NULL,"|");
    strcpy(Result.Ntel, token);
    token = strtok(NULL,"\n");
    strcpy(Result.Date, token);
    return Result;
}

void Affiche_Clients()
{
    interface_7();
    FILE *Clients = fopen("Clients.txt", "r");
    char text[200] = "", cart;
    if(Clients == NULL)
    {
        printf("Impossible d'ouvrir le fichier... :(");
        return;
    }
    cart = fgetc(Clients);
    if(cart == EOF)
        printf("Fichier vide !");
    rewind(Clients);
    while(fgets(text, 200, Clients) != NULL)
    {
        MonClient = Generer_client(text);
        Display_Client(MonClient);
    }
    fclose(Clients);
}

void Modifier()
{
    interface_4();
    char text[200] = "", cart, Id_tmp[6] = "";
    int trouve = 0;
    Client N;
    FILE *Clients = fopen("Clients.txt", "r");

    cart = fgetc(Clients);
    if(cart == EOF)
    {
        printf("\nFichier vide...\n");
        fclose(Clients);
        system("pause");
        return;
    }
    FILE *Clients_tmp = fopen("Clients_tmp.txt", "w");
    rewind(Clients);
    Lire_Id(Id_tmp);

    while(fgets(text, 199, Clients) != NULL)
    {
        N = Generer_client(text);
        if(strcmp(Id_tmp, N.Id_client) == 0)
        {
            printf("\nVoulez vous modifier le nom ?\n1. OUI\t2. NON\n\n>> ");
            verification("12", &cart);
            if(cart == '1')
                Lire_Nom_ou_Prenom(N.Nom, 'n');
            wprintf(L"\nVoulez vous modifier le pr%1cnom ?\n1. OUI\t2. NON\n\n>> ", 130);
            verification("12", &cart);
            if(cart == '1')
                Lire_Nom_ou_Prenom(N.Prenom, 'P');
            wprintf(L"\nVoulez vous modifier la profession ?\n1. OUI\t2. NON\n\n>> ", 130);
            verification("12", &cart);
            if(cart == '1')
                Lire_Profession(N.Profession);
            wprintf(L"\nVoulez vous modifier le num%1cro de t%1cl%1cphone ?\n1. OUI\t2. NON\n\n>> ", 130, 130, 130);
            verification("12", &cart);
            if(cart == '1')
                Lire_Ntel(N.Ntel );
            fprintf(Clients_tmp,"%s|%s|%s|%s|%s|%s\n",N.Id_client,N.Nom,N.Prenom,N.Profession, N.Ntel, N.Date);
            trouve++;
        }
        else
            fputs(text, Clients_tmp);
    }
    if(trouve == 0)
        printf("\nClient absent...\n\n");
    else
        wprintf(L"\nModification r%1cussie !!!\n\n",130);

    fclose(Clients_tmp);
    fclose(Clients);
	remove("Clients.txt");
	rename("Clients_tmp.txt", "Clients.txt");
    system("pause");
}


