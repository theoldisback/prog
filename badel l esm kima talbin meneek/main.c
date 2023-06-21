#include <stdio.h>
#include <stdlib.h>
#include"fonction.h"

int main()
{
    int choix;
    Vehicule Automobiles[50];
    int n;


    do
    {
        do
        {
            printf("\n  Choisir a partir de ce menu : \n");
            printf("\n 1: Afficher les vehicules du parc automobile  ");
            printf("\n 2: Ajouter un colis a un vehicule ");
            printf("\n 3: Annuler la livraison des colis d'une destination invalide ");
            printf("\n 4: Afficher le pourcentage de transport d'un chauffeur donne ");
            printf("0. Quitter . \n");
            scanf("%d",&choix);
        }
        while((choix<0)||(choix>4));

              printf("Donner n \n");
            scanf("%d",&n);


        switch(choix)
        {
        case 1 : AfficherParc(Automobiles,n)

            break;

        case 2 :


            break;

        case 3 :

            break;

        case 4 :

            break;

        }
    }
    while(choix!=0);

    if(choix==0)
    {
        printf("Vous avez quitter !! \n");
    }

    return 0;
}
