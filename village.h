#ifndef _VILLAGE_H_
#define _VILLAGE_H_

#include "point.h"
#include "boolean.h"

typedef struct tPlayer Player;

typedef struct tVillage {
    Point coordinate;
    int income;         // banyak gold yang diberikan village tiap turn
    Player * owner;          // 0 jika tidak ada, else 1 atau 2
} Village;

/* Constructor */

Village MakeVillage(Point coordinate, int income, Player * owner);

/* Getter */

Point GetVillageCoordinate(Village village);
int GetVillageIncome(Village village);
Player * GetVillageOwner(Village village);

/* Setter */

void SetVillageCoordinate(Village * village, Point coordinate);
void SetVillageIncome(Village * village, int income);
void SetVillageOwner(Village * village, Player * owner);

/* Misc Functions */

Village CopyVillage(Village village);
boolean IsEQVillage(Village v1, Village v2);

#endif
