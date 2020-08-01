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
		fprintf(Clients,"%5s | %14s | %14s | %15s | %9s | %8s\n",MonClient.Id_client,MonClient.Nom,MonClient.Prenom,MonClient.Profession, MonClient.Ntel, MonClient.Date);
		wprintf(L"\n\nAjout r%1cussi !!!\n",130 );
		printf("\nEntrez 0 pour quitter ou tout autre pour continuer : ");
		scanf("%c",&option);
		gets(clean_buffer);
		system("cls");
		nb_clients++;
		i++;
	}while(option != '0');
	system("cls");
	fclose(Clients);
	return;

}

