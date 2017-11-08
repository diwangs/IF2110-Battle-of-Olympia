#ifndef _PETA_H_
#define _PETA_H_

//#include "unit.h"
#include "point.h"
#include "peta.h"

#define BRS_MAX 100
#define KOL_MAX 100

typedef struct PetakPeta {
    Point coordinate;
    char type;    // T, C, V, atau N
    int owner;          // 0 jika tidak ada pemilik, else 1 atau 2
//    Unit unit;
} PetakPeta;

typedef struct Peta {
    PetakPeta m[BRS_MAX][KOL_MAX];
    int n_brs;
    int n_kol;
} Peta;

extern Peta PETA;

void MakePetakPeta(Point coor, char type, PetakPeta *petak);
// void MakePetakPeta(Point coor, char type, Unit *unit, PetakPeta *petak);
/* Membuat sebuah PetakPeta */

void MakePeta(int nb, int nk, Peta *peta);

/* ****************************************************************************** */
void PrintPetaNormal(Peta peta);

#endif
