#include "load.h"
#include "listbuilding.h"
#include "listunit.h"
#include "mesinkarload.h"
#include "mesinkataload.h"
#include "point.h"

int kata_to_int(LKata K)
{
	int res = 0;
	for(int i = 0; i < K.length; i++)
	{
		res *= 10;
		res += K.TabKata[i] -'0';
	}

	return res;
}

void load_unit(infotypeunit u, Player* p)
{
	SetUnitMaxHealth(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitHealth(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitAttack(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitMaxMovePoint(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitMovePoint(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitAttackType(u, CKata.TabKata[0]);
	ADVKATA();
	SetUnitCanAttack(u, kata_to_int(CKata));
	ADVKATA();
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	SetUnitCoordinate(u, MakePOINT(pos_x, pos_y));
	ADVKATA();
	SetUnitPrice(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitIsDead(u, kata_to_int(CKata));
	ADVKATA();
	SetUnitType(u, CKata.TabKata[0]);
	ADVKATA();
	SetUnitOwner(u, p);
	ADVKATA();
}

void load_building(infotypebuilding b, Player* p)
{
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	SetBuildingCoordinate(b, MakePOINT(pos_x, pos_y));
	ADVKATA();
	SetBuildingIncome(b, kata_to_int(CKata));
	ADVKATA();
	SetBuildingOwner(b, p);
	ADVKATA();
	SetBuildingType(b, CKata.TabKata[0]);
	ADVKATA();
}

void load_player(Player* p)
{
	CreateEmptyListUnit(&(p->list_unit));
	CreateEmptyListBuilding(&(p->list_building));

	if(!EndData)
	{
		p->gold = kata_to_int(CKata);
		ADVKATA();
		p->income = kata_to_int(CKata);
		ADVKATA();
		p->upkeep = kata_to_int(CKata);
		ADVKATA();
		p->color = CKata.TabKata[0];
	}

	CreateEmptyListUnit(&(p->list_unit));
	ADVKATA();

	while(!EndData)
	{
		Unit unit;
		load_unit(&unit, p);
		InsVLastListUnit(&(p->list_unit), &unit);
	}

	ADVKATA();

	while(!EndData)
	{
		Building building;
		load_building(&building, p);
		InsVLastListBuilding(&(p->list_building), &building);
	}

	ADVKATA();
}

void load_map(Player* p1, Player* p2, Peta* p)
{
	(*p).n_brs = kata_to_int(CKata);
	ADVKATA();
	(*p).n_kol = kata_to_int(CKata);
	ADVKATA();

	address_unit u = FirstUnit(p1->list_unit);
	while(u != NULL)
	{
		AddUnitToPeta(InfoUnit(u), p);
		u = NextUnit(u);
	}

	u = FirstUnit(p2->list_unit);
	while(u != NULL)
	{
		AddUnitToPeta(InfoUnit(u), p);
		u = NextUnit(u);
	}

	address_building b = FirstBuilding(p1->list_building);
	while(b != NULL)
	{
		AddBuildingToPeta(InfoBuilding(b), p);
		b = NextBuilding(b);
	}

	b = FirstBuilding(p2->list_building);
	while(b != NULL)
	{
		AddBuildingToPeta(InfoBuilding(b), p);
		b = NextBuilding(b);
	}
}

void load(Player* p1, Player* p2, Player* current, Peta* p)
{
	STARTKATA();

	load_player(p1);
	load_player(p2);
	load_map(p1, p2, p);
	if(CKata.TabKata[1] == '1') current = p1;
	else current = p2;
}