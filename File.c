#include <stdio.h>
#include <stdlib.h>
#include "FILE.h"

LDC ldc;
LDC ldcJournal;

LDC ajouter_JOB(LDC L, JOB J) {
    cellule_L* nouvelle_cellule = (cellule_L*)malloc(sizeof(cellule_L));
    nouvelle_cellule->job = J;
    nouvelle_cellule->suivant = NULL;
    nouvelle_cellule->precedent = NULL;

    if (L.debut == NULL) {
        L.debut = L.fin = nouvelle_cellule;
    } else {
        cellule_L* courant = L.debut;
        cellule_L* precedent = NULL;

        while (courant != NULL && J.priorite >= courant->job.priorite) {
            precedent = courant;
            courant = courant->suivant;
        }

        if (precedent == NULL) {
            nouvelle_cellule->suivant = L.debut;
            L.debut->precedent = nouvelle_cellule;
            L.debut = nouvelle_cellule;
        } else if (courant == NULL) {
            L.fin->suivant = nouvelle_cellule;
            nouvelle_cellule->precedent = L.fin;
            L.fin = nouvelle_cellule;
        } else {
            precedent->suivant = nouvelle_cellule;
            nouvelle_cellule->precedent = precedent;
            nouvelle_cellule->suivant = courant;
            courant->precedent = nouvelle_cellule;
        }
    }

    return L;
}

void afficher_liste(cellule_L* p) {
    if (p == NULL) {
        printf("\n");
        return;
    }

    afficher_liste(p->suivant);
    printf("ID: %d, Taille: %d, Priorite: %d\n", p->job.id, p->job.taille, p->job.priorite);
}

LDC supprimer_JOB(LDC L) {
    if (L.debut == NULL) {
        printf("La liste est vide.\n");
        return L;
    }

    cellule_L* temp = L.debut;
    L.debut = L.debut->suivant;
    if (L.debut != NULL) {
        L.debut->precedent = NULL;
    } else {
        L.fin = NULL;
    }

    free(temp);
    return L;
}

File organiser(File F) {
    if (F.debut == NULL || F.debut->suivant == NULL) {
        return F;
    }

    ldc.debut = ldc.fin = NULL;

    cellule_F* courant = F.debut;
    while (courant != NULL) {
        ldc = ajouter_JOB(ldc, courant->job);
        courant = courant->suivant;
    }

    printf("Liste I : ");
    afficher_liste(ldc.debut);

    while (ldc.debut != NULL) {
        F = supprimer_JOB(F);
        ldc = supprimer_JOB(ldc);
    }

    return F;
}

File demarrer_impression(File F, char* Journal) {
    FILE* fichier = fopen(Journal, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return F;
    }

    while (F.debut != NULL) {
        JOB J;
        F = defiler(F, &J);
        fwrite(&J, sizeof(JOB), 1, fichier);
    }

    fclose(fichier);
    return F;
}

void afficher_Journal(char* Journal) {
    FILE* fichier = fopen(Journal, "rb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    JOB J;
    printf("Contenu du fichier binaire : \n");
    while (fread(&J, sizeof(JOB), 1, fichier) == 1) {
        printf("ID: %d, Taille: %d, Priorite: %d\n", J.id, J.taille, J.priorite);
        ldcJournal = ajouter_JOB(ldcJournal, J);
    }

    fclose(fichier);
}
