#ifndef ERREURS_H_INCLUDED
#define ERREURS_H_INCLUDED

void Lire_Ntel(char *Ntel);
void Lire_Nom_ou_Prenom(char *NOMouPRENOM,char SAVOIR_si_NouP);
int Nomber_account();
void Lire_Date(char *d);
int lire_entier(int nb);
void Lire_Profession(char *Profession);
void verification(const char *text,char *choice);
void Lire_Id(char *Id);
void Generer_ID(char *ID);
int search_ID(char *ID);
void Compte_ID(char *ID);
void Creer_Solde(float *solde);
float Pull_Bank();
void Push_Bank(float solde);
void Lire_Compte_ID(char *Id);
void Generer_Solde(float *solde, char Savoir_R_ou_V);


#endif // ERREURS_H_INCLUDED
