#include <stdio.h>
#include <stdlib.h>
#include "peta.h"
#include "point.h"
#include "unit.h"
#include "pcolor/pcolor.h"
#include "listunit.h"
#include "listbuilding.h"
#include "player.h"

void MakePetakPeta(Point coor, PetakPeta *petak){
    petak->coordinate = coor;
    petak->unit = NULL;
    petak->building = NULL;
}

void MakePeta(int nb, int nk, Peta *peta){
    peta->n_brs = nb;
    peta->n_kol = nk;

    for(int i = 0; i < nb; i++)
        for(int j = 0; j< nk; j++){
            peta->m[i][j] = malloc(sizeof(PetakPeta));
            MakePetakPeta(MakePOINT(i, j), peta->m[i][j]);
        }
}

void AddUnitToCoordinate(Unit * u, Point c, Peta *peta){
    peta->m[c.X][c.Y]->unit = u;
}

void AddUnitToPeta(Unit * u, Peta * peta){
    AddUnitToCoordinate(u, u->coordinate, peta);
}

void DeleteUnitFromCoordinate(Point c, Peta *peta){
    peta->m[c.X][c.Y]->unit = NULL;
}

void DeleteUnitFromPeta(Unit * u, Peta * peta){
    DeleteUnitFromCoordinate(u->coordinate, peta);
}

void AddBuildingToCoordinate(Building * b, Point c, Peta *peta){
    peta->m[c.X][c.Y]->building = b;
}

void AddBuildingToPeta(Building * b, Peta * peta){
    AddBuildingToCoordinate(b, b->coordinate, peta);
}

boolean IsPetakOccupied(int brs, int kol)
{
    PetakPeta P = *(PETA.m[brs][kol]);
    return P.unit != NULL;
}

boolean IsInsidePeta(Peta peta, int r, int c){
    return (0 <= r) && (r < peta.n_brs) && (0 <= c) && (c < peta.n_kol);
}

void PrintPetaNormal(Peta peta, Unit * unit){
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
            if(peta.m[i][j]->building != NULL){
                if(peta.m[i][j]->building->owner != NULL)
                    printf("%s", CharToColor(peta.m[i][j]->building->owner->color));
                printf(" %c ", peta.m[i][j]->building->type);
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
            printf(" ");
            if((unit != NULL) && (peta.m[i][j]->unit == NULL) && ((abs(i - unit->coordinate.X) + abs(j - unit->coordinate.Y)) <= unit->movp)){
                printf("%s", WHITE_BACK);
            }
            if(peta.m[i][j]->unit != NULL){
                if(peta.m[i][j]->unit == unit){
                    printf("%s", "\x1B[1m\x1B[4m");
                }
                printf("%s", CharToColor(peta.m[i][j]->unit->owner->color));
                printf("%c", GetUnitType(*peta.m[i][j]->unit));
            } else {
                printf(" ");
            }
            printf("%s", NORMAL);
            printf(" ┃");
        }
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

