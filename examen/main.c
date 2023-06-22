#include <stdio.h>
#include <stdlib.h>
#include "File.h"

int main() {
    File file;
    file.debut = file.fin = NULL;
    char fichier_txt[] = "jobs.txt";
    char journal[] = "impression.bin";

    int choix;
    do {
        printf("=== Gestion de la file d'attente des travaux d'impression ===\n");
        printf("1. Enfiler les jobs d'impression depuis le fichier.\n");
        printf("2. R�organiser les jobs suivant l'ordre croissant de leur priorite.\n");
        printf("3. D�marrer les travaux d'impression.\n");
        printf("4. Afficher le journal d'impression.\n");
        printf("0. Quitter.\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                file = enfiler_depuis_Fichier(file, fichier_txt);
                printf("Les jobs ont �t� ajout�s � la file d'attente.\n");
                break;
            case 2:
                file = organiser(file);
                printf("Les jobs ont �t� r�organis�s selon leur priorit�.\n");
                break;
            case 3:
                file = demarrer_impression(file, journal);
                printf("Les travaux d'impression ont d�marr�.\n");
                break;
            case 4:
                afficher_Journal(journal);
                break;
            case 0:
                printf("Programme termin�.\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}
