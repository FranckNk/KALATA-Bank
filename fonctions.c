#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "erreurs.h"

typedef struct Client
{
    char Id_client[5];
    char Nom[15];
    char Prenom[15];
    char Profession[16];
    char Ntel[10];
    char Date[9];
}Client;

Client MonClient;

typedef struct Compte
{
    char Id_Compte[5];
    char Id_Client[5];
    float Solde;
    char Derniere_Op[10];
}Compte;

void Ajouter()
{
	int nb_clients = Nomber_account();
	FILE *Clients = NULL;
	char option,clean_buffer[50] = "";
	int i = 1;
	system("cls");
	Clients = fopen("Clients.txt","a");
	if(Clients == NULL)
	{
		printf("Impossible d'ouvrir le fichier :(\n");
		return;
	}
	if(nb_clients == -1)
        nb_clients = 0;
	do
	{
		interface_3();
		printf("CLIENT N - %d A AJOUTER :\n",i);
		itoa((1000 + nb_clients), MonClient.Id_client, 10);
		Lire_Nom_ou_Prenom(MonClient.Nom,'n');
		Lire_Nom_ou_Prenom(MonClient.Prenom,'p');
		Lire_Profession(MonClient.Profession);
		Lire_Ntel(MonClient.Ntel);
		Lire_Date(MonClient.Date);
		fprintf(Clients,"%s|%s|%s|%s|%s|%s\n",MonClient.Id_client,MonClient.Nom,MonClient.Prenom,MonClient.Profession, MonClient.Ntel, MonClient.Date);
		wprintf(L"\n\nAjout r%1cussi !!!\n",130 );
		printf("\nEntrez 0 pour quitter ou tout autre pour continuer : ");
		scanf("%c",&option);

		gets(clean_buffer);
		system("cls");
		nb_clients++;
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

	cart = fgetc(Clients);
	rewind(Clients);
	if (cart == EOF)
	{
		printf("\nFichier vide ! Suppression impossible :(.");
	}
	else
	{
		Lire_Id(MonClient.Id_client);
		printf("L'ID du client est : %s", MonClient.Id_client);
		Clients_tmp = fopen("Clients_tmp.txt", "w");
		while(fgets(text,199,Clients) != NULL)
		{
			strcpy(text_1,text);
			token = strtok(text_1,"|");
			printf("\nLe premier token est : %s", token);
			if(strcmp(token,MonClient.Id_client) != 0)
			{
				fputs(text,Clients_tmp);
			}
			else
            {
                wprintf(L"\nClient existant ! Vous %1ctes s%1cr de supprimer ?\n1. OUI\t2. NON\n>> ",136,150);
                char c;
                verification("12", &c);
                if(c = '1')
                {
                    signe++;
                    wprintf(L"\nSuppression r%1cussie :)\n\n", 130);
                }else
                {
                    wprintf(L"\nOp%1cration annul%1ce !", 130,130);
                    fputs(text,Clients_tmp);
                    signe = -1;
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
