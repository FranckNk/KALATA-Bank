#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include "interface.h"
#include "erreurs.h"

int main()
{
    system("color E0");
    char c;
    printf("L'adresse est : %p\n", &c);

    printf("Hello world!\n");
    return 0;
}
