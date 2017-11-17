#ifndef _PETA_H_
#define _PETA_H_

#include "unit.h"
#include "point.h"

#define BRS_MAX 100
#define KOL_MAX 100

typedef struct tPlayer Player;

typedef struct PetakPeta {
    Point coordinate;
    char type;    // T, C, V, atau N
    Player * owner;
    Unit * unit;
} PetakPeta;

typedef PetakPeta * pPetakPeta;

typedef struct Peta {
    pPetakPeta m[BRS_MAX][KOL_MAX];
    int n_brs;
    int n_kol;
} Peta;

extern Peta PETA;

void MakePetakPeta(Point coor, char type, PetakPeta *petak);
// void MakePetakPeta(Point coor, char type, Unit *unit, PetakPeta *petak);
/* Membuat sebuah PetakPeta */

void SetPetakPetaOwner(PetakPeta * peta, Player * owner);
void SetPetakPetaType(PetakPeta * peta, char type);
void SetPetakPetaOwnerType(PetakPeta * peta, Player * owner, char type);

void MakePeta(int nb, int nk, Peta *peta);

void AddUnitToCoordinate(Unit * u, Point p, Peta *peta);

/* ****************************************************************************** */
void PrintPetaNormal(Peta peta);

#endif
