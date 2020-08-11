#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "interface.h"
#include "erreurs.h"

int main()
{
    char choice, choice1;
    do
    {
        interface_1(&choice);
        switch(choice)
        {
        case 'A' :
                do
                {
                    interface_6(&choice1);
                    switch(choice1)
                    {
                case '1' :
                    Ajouter();
                    break;
                case '2' :
                    Modifier();
                    break;
                case '3' :
                    Supprimer();
                    break;
                case '4' :
                    Affiche_Clients();
                    break;
                case '5' :
                    Recherche();
                    break;
                default :
                    printf("\n");
                    system("pause");
                    break;
                    }
                }while(choice1 != '6');
            break;
        case 'B' :
                do
                {
                    interface_12(&choice1);
                    switch(choice1)
                    {
                case '1' :
                    New_Account();
                    break;
                case '2' :
                    break;
                case '3' :
                    Consultation();
                    break;
                case '4' :
                    Affiche_Compte();
                    break;
                default :
                    printf("\n");
                    system("pause");
                    break;
                    }
                }while(choice1 != '5');

            break;
        case 'C' :
                do
                {
                    interface_2(&choice1);
                    switch(choice1)
                    {
                    case '1' :
                        Retrait();
                        break;
                    case '2' :
                        Virement();
                        break;
                    default :
                        printf("\n");
                        system("pause");
                        break;
                    }
                }while(choice1 != '3');
            break;
        default :
            wprintf(L"\nMerci... %1c bient%1ct.\n\n", 183, 147);
            system("pause");
            break;
        }
    }while(choice != 'D');
    return 0;
}
