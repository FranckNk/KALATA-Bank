#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// D�claration des fonctions et leur fonctionnement.

typedef enum Espace espace;
enum Espace
{
	True, False
};

int search_ID(char *ID)
{
    FILE *Clients = fopen("Clients.txt", "r");
    char text[200] = "";
    if(Clients == NULL)
    {
        printf("Impossible d'ouvrir le fichier pour la recherche de l'ID :( !");
        return 0;
    }
    while(fgets(text, 199, Clients) != NULL)
        if(strstr(text, ID) != 0)
        {
            fclose(Clients);
            return 1;
        }
    fclose(Clients);
    return 0;
}

void Generer_ID(char *ID)
{
    char chaine[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
        ID[i] = chaine[rand() % 32];
}
void Compte_ID(char *ID)
{
    char chaine[] = "ABCD1234567890";
    srand(time(NULL));
    for(int i = 0; i < 5; i++)
        ID[i] = chaine[rand() % 14];
}

float Pull_Bank()
{
    FILE *Banque = fopen("Banque.txt", "r");
    float solde;
    fscanf(Banque,"%f", &solde);
    fclose(Banque);
    return solde;
}

void Push_Bank(float solde)
{
    FILE *Banque = fopen("Banque.txt", "w");
    fprintf(Banque, "%.0f", solde);
    fclose(Banque);
}

void Creer_Solde(float *solde)
{
    int savoir = 0, retourner;
    printf("\nFAITES VOTRE PREMIER VIREMENT !\n\n");
    do
    {
        if(savoir == 0)
            printf(">> ");
        else
            printf("\nMontant invalide ! >> ");
        retourner = scanf("%f", solde);
        savoir++;
    }while(*solde <= 25000 || *solde > 1000000 || retourner != 1);
}
void Generer_Solde(float *solde, char Savoir_R_ou_V)
{
    int savoir = 0, retourner;
    if(Savoir_R_ou_V == 'r')
    do
    {
        printf("\nFAITES VOTRE RETRAIT !\n\n");
        if(savoir == 0)
            printf(">> ");
        else
            printf("\nMontant invalide ! >> ");
        retourner = scanf("%f", solde);
        savoir++;
    }while(*solde < 10000 || *solde > 250000 || retourner != 1);
    if(Savoir_R_ou_V == 'v')
        do
        {
            printf("\nFAITES VOTRE VIREMENT !\n\n");
            if(savoir == 0)
                printf(">> ");
            else
                printf("\nMontant invalide ! >> ");
            retourner = scanf("%f", solde);
            savoir++;
        }while(*solde < 10000 || retourner != 1);
}

void Lire_Compte_ID(char *Id)
{
    char Table[] = "ABCD1234567890";
	char clean_buffer[50] = "";
	int retourne, i, test, savoir = 1;
	do
	{
		test = 0;
		if(savoir == 1)
			printf("\nEntrez l'Id du compte : ");
		else
			printf("\nId_Compte incorrect ! Reessayez : ");
		retourne = scanf("%s",Id);
		gets(clean_buffer);
		for(int i = 0;i < strlen(Id);i++)
            if(Id[i] >= 'a' && Id[i] <= 'z')
                Id[i] = toupper(Id[i]);
		for (i = 0; i < strlen(Id); i++)
		{
			for (int j = 0; j < strlen(Table); j++)
				if(Id[i] == Table[j])
				{
					test ++;
					break;
				}
		}
		savoir++;
	}while(strlen(clean_buffer) != 0 || retourne != 1 || strlen(Id) != 5 || test != 5);
}

void Lire_Id(char *Id)
{
	char clean_buffer[50] = "";
 	char Table[] = {',','.','?','/',';',':',';','?','!','*','^','&','(',')','=','>','<'};
	int retourne, i, test, savoir = 1;
	do
	{
		test = 0;
		if(savoir == 1)
			printf("\nEntrez l'Id du client : ");
		else
			printf("\nL'Id_Client est incorrect ! Reessayez : ");
		retourne = scanf("%s",Id);
		gets(clean_buffer);
		for (i = 0; i < strlen(Id); i++)
			for (int j = 0; j < strlen(Table); j++)
				if(Id[i] == Table[j])
				{
					test = 1;
					break;
				}
		savoir++;
	}while(strlen(clean_buffer) != 0 || retourne != 1 || strlen(Id) != 5 || test == 1);

	for(int i = 0;i < strlen(Id);i++)
		if(Id[i] >= 'a' && Id[i] <= 'z')
			Id[i] = toupper(Id[i]);
}

void Lire_Ntel(char *Ntel)
{
	strcpy(Ntel,"");
	char clean_buffer[80] = "";
	int i,signe = 0,savoir = 1;
	do
	{
		signe = 0;
		if(savoir == 1)
			printf("\nEntrez le N� de Tel : ");
		else
			printf("\nEntrez un N� de Tel correct : ");
		scanf("%s",Ntel);
		gets(clean_buffer);
		for(i = 0;i < strlen(Ntel); i++)
			if(!isdigit(Ntel[i]))
			{
				signe = 1;
				break;
			}
		savoir++;
	}while(strlen(Ntel) != 9 || strlen(clean_buffer) != 0 || signe == 1 || Ntel[0] == '0');
}

void Lire_Nom_ou_Prenom(char *NOMouPRENOM,char SAVOIR_si_NouP)
{
 	int i,signal = 0,savoir = 1, test = 0;
 	char Table[] = {',','.','?','/',';',':',';','?','!','*','^','&','(',')','=','>','<'};
	int taille = sizeof(Table)/sizeof(char);
	do
	{
		signal = 0;
		test = 0;
		if(savoir == 1 && SAVOIR_si_NouP == 'n')
			printf("\nNOM DU CLIENT : ");
		else if(savoir == 1 && SAVOIR_si_NouP == 'p')
			printf("\nPRENOM DU CLIENT : ");
		else
			printf("\nIncorrect(s) ! Reessayez : ");
		gets(NOMouPRENOM);

		for (i = 0; i < strlen(NOMouPRENOM); i++)
			for (int j = 0; j < taille; j++)
				if(NOMouPRENOM[i] == Table[j])
				{
					test += 1;
					break;
				}
		for(i = 0;i < strlen(NOMouPRENOM); i++)
			if(isdigit(NOMouPRENOM[i]) || NOMouPRENOM[i] == ' ' || test != 0)
			{
				signal = 1;
				break;
			}
		savoir++;
	}while(signal == 1);

	for(i = 0;i < strlen(NOMouPRENOM);i++)
		if(NOMouPRENOM[i] >= 'a' && NOMouPRENOM[i] <= 'z')
			NOMouPRENOM[i] = toupper(NOMouPRENOM[i]);
	return;
}

void verification(const char *text,char *choice)
{
	int i,signal = 0,savoir = 1;
	char clean_buffer[50] = "";
	do
	{
		signal = 0;
		if(savoir != 1)
			printf("\nChoix inexistant ! Re-entrez : ");
		scanf("%c",choice);
        gets(clean_buffer);
        if(*choice >= 'a' && *choice <= 'z')
                *choice = toupper(*choice);
		for(i = 0;i < strlen(text);i++)
			if(text[i] == *choice)
			{
				signal = 1;
				break;
			}
		savoir++;
	}while(strlen(clean_buffer) != 0 || signal != 1);
}

void Lire_Profession(char *Profession)
{
    char Table[] = {',','.','?','/',';',':',';','?','!','*','^','&','(',')','=','>','<'};
    int i, signal, savoir = 0, test, esp = 0;
    espace space = False;
    int taille = sizeof(Table)/sizeof(char);

    do
    {
        signal = 0;
		test = 0;
		esp = 0;
		space = False;
        if(savoir == 0)
            printf("\nVotre profession : ");
        else
            printf("\nProfession invalide : Re-entrez : ");
        gets(Profession);

		for (i = 0; i < strlen(Profession); i++)
		{
			for (int j = 0; j < taille; j++)
				if(Profession[i] == Table[j])
				{
					test += 1;
					break;
				}
			if (Profession[i] == ' ' && space == False)
				space = True;
			else if (Profession[i] == ' ' && space == True)
				esp += 1;
			else if (Profession[i] != ' ')
				space = False;
		}

		for(i = 0;i < strlen(Profession) - 1; i++)
			if(isdigit(Profession[i]) || strlen(Profession) > 21 || Profession[0] == ' ' || esp > 1 || test != 0 || space == True || Profession[strlen(Profession) - 1] == ' ')
			{
				signal = 1;
				break;
			}
        savoir++;
    }while(signal == 1 );

    for(i = 0;i < strlen(Profession);i++)
		if(Profession[i] >= 'a' && Profession[i] <= 'z')
			Profession[i] = toupper(Profession[i]);
}

int lire_entier(int nb)
{
	char clean_buffer[50] = "";
	int retourne,savoir = 1;
	do
	{
		if(savoir == 1)
			printf("\n>> ");
		else
			printf("\nIncorrect ! >> ");
		retourne = scanf("%d",&nb);
		gets(clean_buffer);
		savoir++;
	}while(strlen(clean_buffer) != 0 || retourne != 1 || nb < 10 || nb > 50);
	return nb;
}

void Lire_Date(char *d)
{
    char test[9];
    time_t temps = time(NULL);
    strftime(test, sizeof(test), "%x", localtime(&temps));
    strcpy(d, test);
}


