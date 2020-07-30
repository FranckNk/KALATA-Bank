#include <stdio.h>
#include <stdlib.h>
#include "erreurs.h"

typedef struct Client
{
    char Id_client[5];
    char NOM[15];
    char PRENOM[15];
    char Profession[16];
    char Ntel[10];
    int Date[3];
}Client;

typedef struct Compte
{
    char Id_Compte[5];
    char Id_Client[5];
    float Solde;
    char Derniere_Op[10];
}Compte;

