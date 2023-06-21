#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED


typedef struct
{
    int num;
       char adresse[30];
}Colis;

typedef struct
{
    char imm[30];
    char nom[30];
    int nbr;
    Colis col[100];
}Vehicule;


void SaisirVehicule(Vehicule *V);
int ChercherVehicule(Vehicule Automobiles[],int n, char imm[]);
void RemplirParc (Vehicule Automobiles[],int n);
void AfficherParc(Vehicule Automobiles[],int n);
Colis SaisirColis();
void AjouterColis(Vehicule Automobiles[],int n,Colis col ,char imm[])
void ChercherColis(Colis T_Colis[],int  nbColis,char dest[],int * pPos)
void Supprimer1Colis(Colis T_Colis[],int *pNbColis,int Pos);
void AnnulerLivraisonsColis(Vehicule Automobiles[],int n, char dest[])


#endif // FONCTION_H_INCLUDED
