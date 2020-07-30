#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Déclaration des fonctions et leur fonctionnement.

typedef enum Espace espace;
enum Espace
{
	True, False
};

void Lire_Ntel(char *Ntel)
{
	strcpy(Ntel,"");
	char clean_buffer[80] = "";
	int i,signe = 0,savoir = 1;
	do
	{
		signe = 0;
		if(savoir == 1)
			printf("\nEntrez le N° de Tel : ");
		else
			printf("\nEntrez un N° de Tel correct : ");
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
			printf("\nEntrez le nom du client : ");
		else if(savoir == 1 && SAVOIR_si_NouP == 'p')
			printf("\nEntrez le prenom du client : ");
		else
			printf("\nIncorrect(s) ! Reessayez : ");
		gets(NOMouPRENOM);

		for (i = 0; i < strlen(NOMouPRENOM); i++)
		{
			for (int j = 0; j < taille; j++)
			{
				if(NOMouPRENOM[i] == Table[j])
				{
					test += 1;
					break;
				}
			}
		}

		for(i = 0;i < strlen(NOMouPRENOM) - 1; i++)
		{
			if(isdigit(NOMouPRENOM[i]) || NOMouPRENOM[i] == ' ' || test != 0)
			{
				signal = 1;
				break;
			}
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
			printf("Choix inexistant ! Re-entrez : ");
		scanf("%c",choice);
		gets(clean_buffer);
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
    strcpy(Profession, "");
    char Table[] = {',','.','?','/',';',':',';','?','!','*','^','&','(',')','=','>','<'};
    int i, signal, savoir = 1, test, esp = 0;
    espace space = False;
    int taille = sizeof(Table)/sizeof(char);

    do
    {
        signal = 0;
		test = 0;
		esp = 0;
		space = False;
        if(savoir == 0)
            printf("Votre profession : ");
        else
            printf("Profession invalide : Re-entrez : ");
        gets(Profession);

		for (i = 0; i < strlen(Profession); i++)
		{
			for (int j = 0; j < taille; j++)
			{
				if(Profession[i] == Table[j])
				{
					test += 1;
					break;
				}
			}
			if (Profession[i] == ' ' && space == False)
			{
				space = True;
			}
			else if (Profession[i] == ' ' && space == True)
			{
				esp += 1;
			}
			else if (Profession[i] != ' ')
			{
				space = False;
			}
		}

		for(i = 0;i < strlen(Profession) - 1; i++)
		{
			if(isdigit(Profession[i]) || strlen(Profession) > 15 || esp > 1 || test != 0 || space == True || Profession[strlen(Profession) - 1] == ' ')
			{
				signal = 1;
				break;
			}
		}
        savoir++;
    }while(signal == 1 );

    for(i = 0;i < strlen(Profession);i++)
		if(Profession[i] >= 'a' && Profession[i] <= 'z')
			Profession[i] = toupper(Profession[i]);
}

