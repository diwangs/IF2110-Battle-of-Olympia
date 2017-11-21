#include <stdio.h>
#include "peta.h"
#include "point.h"
#include <stdlib.h>
#include "unit.h"
#include "pcolor/pcolor.h"
#include "listunit.h"
#include "listvillage.h"
#include "player.h"

Peta PETA;

void MakePetakPeta(Point coor, char type, PetakPeta *petak){
    petak->coordinate = coor;
    petak->type = type;
    petak->owner = NULL;
    petak->unit = NULL;
    petak->village = NULL;
}

void SetPetakPetaOwner(PetakPeta * peta, Player * owner){
    peta->owner = owner;
}

void SetPetakPetaType(PetakPeta * peta, char type){
    peta->type = type;
}

void SetPetakPetaOwnerType(PetakPeta * peta, Player * owner, char type){
    SetPetakPetaOwner(peta, owner);
    SetPetakPetaType(peta, type);
}

void SetPointPetaOwner(Point c, Peta * peta, Player * owner){
    peta->m[c.X][c.Y]->owner = owner;
}

void SetPointPetaType(Point c, Peta * peta, char type){
    peta->m[c.X][c.Y]->type = type;
}

void SetPointPetaOwnerType(Point c, Peta * peta, Player * owner, char type){
    SetPointPetaOwner(c, peta, owner);
    SetPointPetaType(c, peta, type);
}

void MakePeta(int nb, int nk, Peta *peta){
    peta->n_brs = nb;
    peta->n_kol = nk;

    for(int i = 0; i < nb; i++)
        for(int j = 0; j< nk; j++){
            peta->m[i][j] = malloc(sizeof(PetakPeta));
            MakePetakPeta(MakePOINT(i, j), 'N', peta->m[i][j]);
        }
}

void AddUnitToCoordinate(Unit * u, Point c, Peta *peta){
    peta->m[c.X][c.Y]->unit = u;
}

void AddVillageToCoordinate(Village * v, Point c, Peta *peta){
    peta->m[c.X][c.Y]->village = v;
    peta->m[c.X][c.Y]->type = 'V';
}

void PrintPetaNormal(Peta peta){
    printf("    ");
    for(int i = 0; i < peta.n_kol; i++)
        printf("%3d ", i);
    printf("\n");

    printf("   ┏");
    for(int i = 0; i < peta.n_kol; i++)
        if(i == peta.n_kol - 1)
            printf("━━━┓");
        else
            printf("━━━┳");

    printf("\n");
    for(int i = 0; i < peta.n_brs; i++){
        // Cetak baris pertama dan bangunan
        printf("   ┃");
        for(int j = 0; j < peta.n_kol; j++){
            if(peta.m[i][j]->type != 'N'){
                printf("%s", CharToColor(peta.m[i][j]->owner->color));
                printf(" %c ", peta.m[i][j]->type);
                printf("%s", NORMAL);
            } else {
                printf("   ");
            }
            printf("┃");
        }
        printf("\n");

        // Cetak nomor baris dan unit
        printf("%2d ┃", i);
        for(int j = 0; j < peta.n_kol; j++){
            if(peta.m[i][j]->unit != NULL){
                printf("%s", CharToColor(peta.m[i][j]->unit->owner->color));
                printf(" %c ", GetUnitType(*peta.m[i][j]->unit)[0]);
                printf("%s", NORMAL);
            } else {
                printf("   ");
            }
            printf("┃");
        }
        printf("\n");
        
        // cetak baris terakhir dan range jika perlu
        printf("   ┃");
        for(int j = 0; j < peta.n_kol; j++)
            printf("   ┃");
        printf("\n");

        // cetak garis bawah
        if(i != peta.n_brs - 1)
            printf("   ┣");
        else
            printf("   ┗");
        
        for(int j = 0; j < peta.n_kol; j++){
            printf("━━━");
            if(i != peta.n_brs - 1){
                if(j == peta.n_kol - 1)
                    printf("┫");
                else
                    printf("╋");
            } else {
                if(j == peta.n_kol - 1)
                    printf("┛");
                else
                    printf("┻");
            }
        }
        printf("\n");
    }
}
