#ifndef _BUILDING_H_
#define _BUILDING_H_

#include "point.h"
#include "boolean.h"

typedef struct tPlayer Player;

typedef struct tBuilding {
    Point coordinate;
    int income;         // banyak gold yang diberikan building tiap turn
    Player * owner;       // 0 jika tidak ada, else 1 atau 2
    char * type;
} Building;

/* Constructor */

Building MakeBuilding(Point coordinate, int income, Player * owner, char * type);

/* Getter */

Point GetBuildingCoordinate(Building building);
int GetBuildingIncome(Building building);
int GetBuildingOwner(Building building);
char * GetBuildingType(Building building);

/* Setter */

void SetBuildingCoordinate(Building * building, Point coordinate);
void SetBuildingIncome(Building * building, int income);
void SetBuildingOwner(Building * building, Player * owner);
void SetBuildingType(Building * building, char * type);

/* Misc Functions */

Building CopyBuilding(Building building);
boolean IsEQBuilding(Building b1, Building b2);

#endif