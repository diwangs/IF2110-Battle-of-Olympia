#include "template.h"
#include "point.h"

Point P1 = MakePOINT(1,1);
Unit king = MakeUnit(
	10, 10, 
    1, 1, 
    'm', 1, 
    NULL, 1, 
    0, 'king', NULL);

Unit archer = MakeUnit(
	10, 10, 
    1, 1, 
    'r', 1, 
    NULL, 1, 
    0, 'archer', NULL);

Unit swordsman = MakeUnit(
	10, 10, 
    1, 1, 
    'm', 1, 
   	NULL, 1, 
    0, 'swordsman', NULL);

Unit mage = MakeUnit(
	10, 10, 
    1, 1, 
    'r', 1, 
    NULL, 1, 
    0, 'mage', NULL);

Unit CreateUnitKing(Player * P, int brs, int kol)
{
	Unit u;
	u = CopyUnit(king);
	Point p1;
	p1 = MakePOINT(brs, kol);
	SetUnitCoordinate(&u, p1);
	SetUnitOwner(&u, P);

	return u;
}

Unit CreateUnitArcher(Player * P, int brs, int kol)
{
	Unit u;
	u = CopyUnit(archer);
	Point p1;
	p1 = MakePOINT(brs, kol);
	SetUnitCoordinate(&u, p1);
	SetUnitOwner(&u, P);

	return u;
}

Unit CreateUnitSwordsman(Player * P, int brs, int kol)
{
	Unit u;
	u = CopyUnit(swordsman);
	Point p1;
	p1 = MakePOINT(brs, kol);
	SetUnitCoordinate(&u, p1);
	SetUnitOwner(&u, P);

	return u;
}

Unit CreateUnitMage(Player * P, int brs, int kol)
{
	Unit u;
	u = CopyUnit(mage);
	Point p1;
	p1 = MakePOINT(brs, kol);
	SetUnitCoordinate(&u, p1);
	SetUnitOwner(&u, P);

	return u;
}