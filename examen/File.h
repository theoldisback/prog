#ifndef FILE_H
#define FILE_H
#include "JOB.h"

typedef struct cellule_F {
    JOB job;
    struct cellule_F* suivant;
    struct cellule_F* precedent;
} cellule_F;

typedef struct {
    cellule_F* debut;
    cellule_F* fin;
} File;

File enfiler_JOB(File F, JOB J);
File enfiler_depuis_Fichier(File F, char* Fichier_TXT);
File defiler(File F, JOB* J);
File organiser(File F);

#endif
