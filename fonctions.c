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
Compte Generer_Compte(char *chaine);
void Display_Compte(Compte UnCompte, char *Nom, char *Prenom);

void Ajouter()
{
	system("cls");
	FILE *Clients = NULL, *Comptes = NULL;
	char option;
	int i = 1;
	char clean_buffer[10];
	float Solde_Banque;
	Clients = fopen("Clients.txt","a");
	Comptes = fopen("Comptes.txt", "a");
	do
	{
        interface_3();
		wprintf(L"La cr%1cation d'un client conduit %1c la cr%1cation de son compte.\n\n",130, 133, 130);
		printf("\t\tCLIENT N - %d A AJOUTER :\n",i);
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
		wprintf(L"\nAjout r%1cussi !!!\n",130 );
		gets(clean_buffer);
		printf("\n1. CONTINUER.\t2. SORTIR.\n>> ");
		verification("12", &option);
		i++;
	}while(option == '1');
	fclose(Clients);
	printf("\n\n");
	system("pause");
	return;
}

void Supprimer_Compte(char *Id)
{
    FILE *Comptes = fopen("Comptes.txt", "r");
    FILE *Comptes_tmp = fopen("Comptes_tmp.txt", "w");
    char text[200];
    if(Comptes == NULL)
        printf("Impossible d'ouvrir la liste des comptes...\n");
    while(fgets(text, 199, Comptes) != NULL)
        if(strstr(text, Id) == 0)
            fputs(text, Comptes_tmp);
    fclose(Comptes);
    fclose(Comptes_tmp);
    remove("Comptes.txt");
    rename("Comptes_tmp.txt", "Comptes.txt");
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
		printf("\nFichier vide ! Suppression impossible :( !");
	}
	else
	{
	    printf("Comment voulez-vous supprimer ?\n\n1. UN SEUL.    2. TOUT.\n\n>> ");
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
				fputs(text,Clients_tmp);
			else
            {
                wprintf(L"\nClient existant ! Vous %1ctes s%1cr de supprimer ?\n\n1. OUI    2. NON\n\n>> ",136,150);
                char c;
                verification("12", &c);
                if(c == '2')
                {
                    wprintf(L"\nOp%1cration annul%1ce !\n\n", 130,130);
                    fputs(text,Clients_tmp);
                    signe = -1;
                }
                else
                {
                    signe++;
                    Supprimer_Compte(MonClient.Id_client);
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
		printf("\nFichier vide :(.");
	else
	{
	    char Identifiant[6], nom[20], c;
	    wprintf(L"Vous recherchez %1c partir de : \n\n1. ID DU CLIENT.    2. NOM DU CLIENT.    3. SORTIR.\n>> ", 133);
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
void Display_Compte(Compte UnCompte, char *Nom, char *Prenom)
{
    printf("\nID DU COMPTE       :   %s\nNOM DU CLIENT      :   %s\nPRENOM DU CLIENT   :   %s\nSOLDE DE BASE      :   %.0f FCFA\nDERNIERE OPERATION :   %s\n\n", UnCompte.Id_Compte, Nom, Prenom, UnCompte.Solde, UnCompte.Derniere_Op);
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

Compte Generer_Compte(char *chaine)
{
    char text[200], *token;
    Compte Result;
    strcpy(text, chaine);
    token = strtok(text, "|");
    strcpy(Result.Id_Compte, token);
    token = strtok(NULL,"|");
    strcpy(Result.Id_Client, token);
    token = strtok(NULL,"|");
    Result.Solde = (float)atoi(token);
    token = strtok(NULL,"\n");
    strcpy(Result.Derniere_Op, token);
    return Result;
}

void Affiche_Clients()
{
    interface_7();
    FILE *Clients = fopen("Clients.txt", "r");
    char text[200] = "", cart;
    int n = 1;
    if(Clients == NULL)
    {
        printf("Impossible d'ouvrir le fichier... :(  !");
        return;
    }
    cart = fgetc(Clients);
    if(cart == EOF)
        printf("Fichier vide !");
    rewind(Clients);
    while(fgets(text, 200, Clients) != NULL)
    {
        printf("   CLIENT N- :  %d\n", n);
        MonClient = Generer_client(text);
        Display_Client(MonClient);
        n++;
    }
    fclose(Clients);
    system("pause");
}

void Retrait()
{
    FILE *Comptes = fopen("Comptes.txt", "r"), *Comptes_tmp = fopen("Comptes_tmp.txt", "w");
    char text[200] = "", Id_Client[6], Id_Compte[6];
    Compte UnCompte;
    int trouve = 0;
    float Solde_Banque = 0, Solde;
    if(Comptes == NULL)
    {
        printf("\nImpossible d'ouvrir la liste de comptes...!\n\n");
        system("pause");
        return;
    }
    Lire_Compte_ID(Id_Compte);
    Lire_Id(Id_Client);
    while(fgets(text, 199, Comptes) != NULL)
    {
        UnCompte = Generer_Compte(text);
        if(strcmp(Id_Compte, UnCompte.Id_Compte) == 0 && strcmp(Id_Client, UnCompte.Id_Client) == 0)
        {
            int savoir = 0;
            printf("\n           VOTRE SOLDE EST DE : %.0f FCFA\n", UnCompte.Solde);
            do
            {
                savoir = 0;
                Generer_Solde(&Solde, 'r');
                if(Solde > UnCompte.Solde)
                {
                    printf("\nImpossible ! Solde insuffisant...\n");
                    savoir = 1;
                }
                else
                {
                    Solde_Banque = Pull_Bank();
                    if(Solde_Banque < Solde)
                        wprintf(L"D%1csol%1c ! KALATA-Bank ne dispose pas encore cette somme...", 130, 130);
                    else
                    {
                        UnCompte.Solde = UnCompte.Solde - Solde;
                        Push_Bank(Solde_Banque - Solde);
                        strcpy(UnCompte.Derniere_Op, "RETRAIT");
                        fprintf(Comptes_tmp,"%s|%s|%.0f|%s\n", UnCompte.Id_Compte, UnCompte.Id_Client, UnCompte.Solde, UnCompte.Derniere_Op);
                        wprintf(L"\nRetrait %1cffectu%1c avec succ%1cs...\n\n", 130, 130, 138);
                        printf("SOLDE RESTANT : %.0f FCFA\n\n", UnCompte.Solde);
                    }
                }
            }while(savoir == 1);
            trouve = 1;
        }
        else
            fputs(text, Comptes_tmp);
    }
    fclose(Comptes);
    fclose(Comptes_tmp);
    remove("Comptes.txt");
    rename("Comptes_tmp.txt", "Comptes.txt");
    if(trouve == 0)
        printf("\nCompte inexistant...\n\n");
    system("pause");
}

void Virement()
{
    FILE *Comptes = fopen("Comptes.txt", "r"), *Comptes_tmp = fopen("Comptes_tmp.txt", "w");
    char text[200] = "", Id_Client[6], Id_Compte[6];
    Compte UnCompte;
    int trouve = 0;
    float Solde_Banque = 0, Solde;
    if(Comptes == NULL)
    {
        printf("\nImpossible d'ouvrir la liste de comptes...!\n\n");
        system("pause");
        return;
    }
    Lire_Compte_ID(Id_Compte);
    Lire_Id(Id_Client);
    while(fgets(text, 199, Comptes) != NULL)
    {
        UnCompte = Generer_Compte(text);
        if(strcmp(Id_Compte, UnCompte.Id_Compte) == 0 && strcmp(Id_Client, UnCompte.Id_Client) == 0)
        {
            int savoir = 0;
            printf("\n           VOTRE SOLDE EST DE : %.0f FCFA\n", UnCompte.Solde);
            do
            {
                savoir = 0;
                Generer_Solde(&Solde, 'v');
                UnCompte.Solde = UnCompte.Solde + Solde;
                Solde_Banque = Pull_Bank();
                Push_Bank(Solde + Solde_Banque);
                strcpy(UnCompte.Derniere_Op, "VIREMENT");
                fprintf(Comptes_tmp,"%s|%s|%.0f|%s\n", UnCompte.Id_Compte, UnCompte.Id_Client, UnCompte.Solde, UnCompte.Derniere_Op);
                wprintf(L"\nVirement %1cffectu%1c avec succ%1cs...\n\n", 130, 130, 138);
                printf("NOUVEAU SOLDE : %.0f FCFA\n\n", UnCompte.Solde);
            }while(savoir == 1);
            trouve = 1;
        }
        else
            fputs(text, Comptes_tmp);
    }
    fclose(Comptes);
    fclose(Comptes_tmp);
    remove("Comptes.txt");
    rename("Comptes_tmp.txt", "Comptes.txt");
    if(trouve == 0)
        printf("\nCompte inexistant...\n\n");
    system("pause");
}

void search_Compte(char *Id_Client, char *nom, char *prenom)
{
    FILE *Clients = fopen("Clients.txt", "r");
    char text[200] = "", text_1[200], *token;
     if(Clients == NULL)
    {
        printf("Impossible d'ouvrir le fichier... :( ! ");
        return;
    }
    while(fgets(text, 199, Clients) != NULL)
    {
        strcpy(text_1, text);
        token = strtok(text_1,"|");
        if(strcmp(token, Id_Client) == 0)
        {
            token = strtok(NULL,"|");
            strcpy(nom, token);
            token = strtok(NULL,"|");
            strcpy(prenom, token);
            break;
        }
    }
    fclose(Clients);
}

void Affiche_Compte()
{
    FILE *Comptes = fopen("Comptes.txt", "r");
    char text[200] = "", cart, Nom[20], Prenom[20];
    int n = 1;
    Compte MonCompte;
    interface_9();
    if(Comptes == NULL)
    {
        printf("Impossible d'ouvrir le fichier... :( ! ");
        return;
    }
    cart = fgetc(Comptes);
    if(cart == EOF)
        printf("La banque n'a aucun compte !");
    rewind(Comptes);
    while(fgets(text, 200, Comptes) != NULL)
    {
        printf("\t COMPTE N- :   %d\n", n);
        MonCompte = Generer_Compte(text);
        search_Compte(MonCompte.Id_Client, Nom, Prenom);
        Display_Compte(MonCompte, Nom, Prenom);
        n++;
    }
    fclose(Comptes);
    system("pause");
}

void New_Account()
{
    char Id_Client[6] = "";
    Compte UnCompte;
    FILE *Comptes = fopen("Comptes.txt", "a");
    interface_10();
    if(Comptes == NULL)
    {
        printf("Impossible d'ouvrir le fichier... :( ! ");
        return;
    }
    Lire_Id(Id_Client);
    if(search_ID(Id_Client) == 1)
    {
        float Solde_Banque;
        strcpy(UnCompte.Id_Client, Id_Client);
        Compte_ID(UnCompte.Id_Compte);
		strcpy(UnCompte.Derniere_Op, "VIREMENT");
		Creer_Solde(&UnCompte.Solde);
        Solde_Banque = Pull_Bank();
        Push_Bank(Solde_Banque + UnCompte.Solde);
        fprintf(Comptes,"%s|%s|%.0f|%s\n", UnCompte.Id_Compte, UnCompte.Id_Client, UnCompte.Solde, UnCompte.Derniere_Op);
        wprintf(L"Compte cr%1c%1c avec succ%1cs...\n\n", 130, 130, 138);
    }
    else
        printf("\nImpossible ! Client absent...\n\n");
    fclose(Comptes);
    system("pause");
}

void Consultation()
{
    FILE *Comptes = fopen("Comptes.txt", "r");
    char text[200], Id_Compte[6], cart, *token, trouve = 'f', Nom[20], Prenom[20];
    interface_11();
    if(Comptes == NULL)
        printf("\nImpossible d'ouvrir la liste des comptes...\n");
    cart = fgetc(Comptes);
    if(cart == EOF)
    {
        printf("\nAucun compte dans la banque...\n");
        fclose(Comptes);
        system("pause");
        return;
    }
    rewind(Comptes);
    Lire_Compte_ID(Id_Compte);
    while(fgets(text, 199, Comptes) != NULL)
        if(strstr(text, Id_Compte) != 0)
        {
            trouve = 'v';
            float solde = 0;
            char t[6];
            token = strtok(text, "|");
            token = strtok(NULL, "|");
            strcpy(t, token);
            token = strtok(NULL, "|");
            search_Compte(t, Nom, Prenom);
            solde = (float)atoi(token);
            printf("\nNOM DU CLIENT    :  %s\nPRENOM DU CLIENT :  %s\nSOLDE DU COMPTE  :  %.0f FCFA\n\n", Nom, Prenom, solde);
            break;
        }
    fclose(Comptes);
    if(trouve == 'f')
        printf("\nCompte Inexistant...\n\n");
    system("pause");
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
    fclose(Clients_tmp);
    fclose(Clients);
	remove("Clients.txt");
	rename("Clients_tmp.txt", "Clients.txt");
    if(trouve == 0)
        printf("\nClient absent...\n\n");
    else
        wprintf(L"\nModification r%1cussie !!!\n\n",130);
    system("pause");
}
