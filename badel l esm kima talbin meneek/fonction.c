#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"fonction.h"



void SaisirVehicule(Vehicule *V)
{
    printf(" Donner immatriculation \n");
    fflush(stdin);
    gets((*V).imm);
    printf(" Donner nom \n");
    fflush(stdin);
    gets((*V).nom);
    (*V).nbr=0;
}


int ChercherVehicule(Vehicule Automobiles[],int n, char imm[])
{
    int i=0 ;
    int  pos=-1;
    while((i<n)&&(strcmp(imm,Automobiles[i].imm)!=0))
    {
        i++;
    }
    if(strcmp(imm,Automobiles[i].imm)==0)
    {
        pos=i;
    }
    return pos;
}



void RemplirParc (Vehicule Automobiles[],int n)
{
    int pos,i;
    Vehicule V;
    for(i=0; i<n; i++)
    {
        do
        {
            SaisirVehicule(&V);
            pos=ChercherVehicule(Automobiles,n,V.imm);
        }
        while(pos!=-1);
        Automobiles[i]=V;
    }
}




void AfficherParc(Vehicule Automobiles[],int n)
{

    int i,j;
    if(n==0)
    {
        printf("Aucune vehicule \n");
    }
    else
    {
        for(i=0; i<n; i++)
        {
            printf("Immatriculation : %s",Automobiles[i].imm);
            printf("Nom : %s",Automobiles[i].nom);
            printf("Nombre de colis  : %d",Automobiles[i].nbr);
            for(j=0; j<Automobiles[i].nbr; j++)
            {
                printf("Numero : %d",Automobiles[i].col[j].num);
                printf("Adresse : %s",Automobiles[i].col[j].adresse);
            }
        }
    }
}





Colis SaisirColis()
{
    Colis col;
    printf(" Donner numero \n");
    scanf("%d",&col.num)
    printf(" Donner adresse \n");
    fflush(stdin);
    gets(col.adresse);
    return col;
}


void AjouterColis(Vehicule Automobiles[],int n,Colis col,char imm[])
{
    int pos;
    pos=ChercherVehicule(Automobiles,n,imm);
    if(pos!=-1)
    {
        Automobiles[pos].nbr += 1;
        SaisirColis(col);
        Automobiles[pos].col[ Automobiles[pos].nbr] = col;
    }
    else
    {
        printf("\n Vehicule introuvable ! \n");
    }

}

void ChercherColis(Colis T_Colis[],int  nbColis,char dest[],int * pPos)
{
    int i=0 ;
    *pPos=-1;
    while((i<nbColis)&&(strcmp(T_Colis[i].adresse,dest)!=0))
    {
        i++;
    }
    if(strcmp(T_Colis[i].adresse,dest)==0)
    {
        *pPos=i;
    }
}



void Supprimer1Colis(Colis T_Colis[],int *pNbColis,int Pos)
{
    int i;
    if(Pos!=-1)
    {
        for(i=Pos; i<(*pNbColis)-1; i++)
        {
            T_Colis[i]=T_Colis[i+1];
        }
        (*pNbColis)--;
    }
}




void AnnulerLivraisonsColis(Vehicule Automobiles[],int n, char dest[])
{
    int i,pPos;

    for(i=0;i<n;i++)
    {
        ChercherColis(Automobiles[i].col,Automobiles[i].nbr,dest,&pPos);
        Supprimer1Colis(Automobiles[i].col,Automobiles[i].nbr,pPos);
    }
}
