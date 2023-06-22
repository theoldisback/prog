#ifndef LDC_H
#define LDC_H
#include "JOB.h"

typedef struct cellule_L {
    JOB job;
    struct cellule_L* suivant;
    struct cellule_L* precedent;
} cellule_L;

typedef struct {
    cellule_L* debut;
    cellule_L* fin;
} LDC;

LDC ajouter_JOB(LDC L, JOB J);
void afficher_liste(cellule_L* p);
LDC supprimer_JOB(LDC L);

#endif
