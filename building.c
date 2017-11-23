#include <stdlib.h>
#include "building.h"

/* Constructor */

Building * MakeBuilding(Point coordinate, int income, Player * owner, char type)
{
    Building * b1 = malloc(sizeof(Building));

    SetBuildingCoordinate(b1, coordinate);
    SetBuildingIncome(b1, income);
    SetBuildingOwner(b1, owner);
    SetBuildingType(b1, type);

    return b1;
}

/* Getter */

Point GetBuildingCoordinate(Building building)
{
    return building.coordinate;
}

int GetBuildingIncome(Building building)
{
    return building.income;
}

Player * GetBuildingOwner(Building building)
{
    return building.owner;
}

char GetBuildingType(Building building){
    return building.type;
}

/* Setter */

void SetBuildingCoordinate(Building * building, Point coordinate)
{
    building->coordinate = coordinate;
}

void SetBuildingIncome(Building * building, int income)
{
    building->income = income;
}

void SetBuildingOwner(Building * building, Player * owner)
{
    building->owner = owner;
}

void SetBuildingType(Building * building, char type){
    building->type = type;
}

/* Misc Functions */

Building CopyBuilding(Building building)
{
    Building b1;

    b1 = *MakeBuilding(
        GetBuildingCoordinate(building),
        GetBuildingIncome(building),
        GetBuildingOwner(building),
        GetBuildingType(building)
    );

    return b1;
}

boolean IsEQBuilding(Building b1, Building b2)
{
    return
        GetBuildingOwner(b1) == GetBuildingOwner(b2) &&
        GetBuildingIncome(b1) == GetBuildingIncome(b2) &&
        EQ(GetBuildingCoordinate(b1), GetBuildingCoordinate(b2));
}
