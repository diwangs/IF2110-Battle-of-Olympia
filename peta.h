#ifndef _PETA_H_
#define _PETA_H_

#include "unit.h"
#include "point.h"
#include "building.h"
#include "boolean.h"

#define BRS_MAX 100
#define KOL_MAX 100

typedef struct tPlayer Player;

typedef struct PetakPeta {
    Point coordinate;
    Unit * unit;
    Building * building;
} PetakPeta;

typedef PetakPeta * pPetakPeta;

typedef struct Peta {
    pPetakPeta m[BRS_MAX][KOL_MAX];
    int n_brs;
    int n_kol;
} Peta;

extern Peta PETA;

void MakePetakPeta(Point coor, PetakPeta *petak);
/* Membuat sebuah PetakPeta */

void MakePeta(int nb, int nk, Peta *peta);

void AddUnitToPeta(Unit * u, Peta * peta);
void AddBuildingToPeta(Building * b, Peta * peta);

boolean IsPetakOccupied(int brs, int kol);
boolean IsInsidePeta(Peta peta, int r, int c);

/* ****************************************************************************** */
void PrintPetaNormal(Peta peta, Unit * unit);

#endif
