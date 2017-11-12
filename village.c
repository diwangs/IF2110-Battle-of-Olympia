#include "village.h"

/* Constructor */

Village MakeVillage(Point coordinate, int income, int owner)
{
	Village v1;

	SetVillageCoordinate(&v1, coordinate);
	SetVillageIncome(&v1, income);
	SetVillageOwner(&v1, owner);

	return v1;
}

/* Getter */

Point GetVillageCoordinate(Village village)
{
	return village.coordinate;
}

int GetVillageIncome(Village village)
{
	return village.income;
}

int GetVillageOwner(Village village)
{
	return village.owner;
}

/* Setter */

void SetVillageCoordinate(Village * village, Point coordinate)
{
	village->coordinate = coordinate;
}

void SetVillageIncome(Village * village, int income)
{
	village->income = income;
}

void SetVillageOwner(Village * village, int owner)
{
	village->owner = owner;
}

/* Misc Functions */

Village CopyVillage(Village village)
{
	Village v1;

	v1 = MakeVillage(
		GetVillageCoordinate(village),
		GetVillageIncome(village),
		GetVillageOwner(village)
	);

	return v1;
}

boolean IsEQVillage(Village v1, Village v2)
{
	return
		GetVillageOwner(v1) == GetVillageOwner(v2) &&
		GetVillageIncome(v1) == GetVillageIncome(v2) &&
		EQ(GetVillageCoordinate(v1), GetVillageCoordinate(v2));
}