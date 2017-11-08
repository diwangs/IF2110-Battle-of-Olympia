#ifndef _PETA_H_
#define _PETA_H_

#include "unit.h"
#include "point.h"

#define BrsMax 100
#define KolMax 100

extern Peta PETA;

typedef struct PetakPeta {
    Point coordinate;
    char type;    // T, C, V, atau N
    int owner;          // 0 jika tidak ada pemilik, else 1 atau 2
    Unit unit;
} PetakPeta;

typedef struct Peta {
    PetakPeta M[BrsMax][KolMax];
    int NBrsEff;
    int NKolEff;
} Peta;

void MakePeta(int NB, int NK, Peta *peta);

/* ****************************************************************************** */
void PrintPetaNormal(Peta peta);

#endif
