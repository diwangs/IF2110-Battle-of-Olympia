#include "load.h"
#include "listbuilding.h"
#include "listunit.h"
#include "mesinkarload.h"
#include "mesinkataload.h"
#include "point.h"
#include "playerq.h"

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

void load_unit(infotypeunit* u, Player* p)
{
	int max_health = kata_to_int(CKata);
	ADVKATA();
	int health = kata_to_int(CKata);
	ADVKATA();
	int attack = kata_to_int(CKata);
	ADVKATA();
	int maxmove = kata_to_int(CKata);
	ADVKATA();
	int move = kata_to_int(CKata);
	ADVKATA();
	char att_type = CKata.TabKata[0];
	ADVKATA();
	boolean can_attack = kata_to_int(CKata);
	ADVKATA();
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	ADVKATA();
	int price = kata_to_int(CKata);
	ADVKATA();
	boolean is_dead = kata_to_int(CKata);
	ADVKATA();
	char type = CKata.TabKata[0];
	ADVKATA();
	ADVKATA();
	*u = MakeUnit(max_health, health, maxmove, move, attack, att_type,
		can_attack, MakePOINT(pos_x, pos_y), price, is_dead, type, p);
}

void load_building(infotypebuilding* b, Player* p)
{
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	ADVKATA();
	int income = kata_to_int(CKata);
	ADVKATA();
	ADVKATA();
	char type = CKata.TabKata[0];
	ADVKATA();

	*b = MakeBuilding(MakePOINT(pos_x, pos_y), income, p, type);
}

void load_player(Player** p)
{
	if(!EndData)
	{
		int gold, income, upkeep;
		gold = kata_to_int(CKata);
		ADVKATA();
		income = kata_to_int(CKata);
		ADVKATA();
		upkeep = kata_to_int(CKata);
		ADVKATA();
		char color = CKata.TabKata[0];
		*p = CreatePlayer(color);
		(*p)->gold = gold;
		(*p)->income = income;
		(*p)->upkeep = upkeep;
	}

	CreateEmptyListUnit(&((*p)->list_unit));
	CreateEmptyListBuilding(&((*p)->list_building));
	ADVKATA();
	EndData = false;

	while(!EndData)
	{
		infotypeunit unit;
		load_unit(&unit, *p);
        unit->owner = *p;
		InsVLastListUnit(&((*p)->list_unit), unit);
	}

	EndData = false;

	while(!EndData)
	{
		Building* building;
		load_building(&building, *p);
		InsVLastListBuilding(&((*p)->list_building), building);
	}

	EndData = false;
}

void load_map(Player* p1, Player* p2, Peta* p)
{
	int brs, kol;
	brs = kata_to_int(CKata);
	ADVKATA();
	kol = kata_to_int(CKata);
	ADVKATA();

	MakePeta(brs, kol, p);

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

	while(!EndData)
	{
		int pos_x, pos_y;
		pos_x = kata_to_int(CKata);
		ADVKATA();
		pos_y = kata_to_int(CKata);
		ADVKATA();

		int income = kata_to_int(CKata);
		ADVKATA();

		char owner = CKata.TabKata[0];
		ADVKATA();

		char type = CKata.TabKata[0];
		ADVKATA();

		if(owner == 'Z')
		{
			AddBuildingToPeta(MakeBuilding(MakePOINT(pos_x, pos_y),
				income, NULL, type), p);
		}
	}
}

void load(Player** p1, Player** p2, Player** current, Peta* p, PlayerQ* pq)
{
	STARTKATA();
	load_player(p1);
	load_player(p2);
	load_map(*p1, *p2, p);
	CreateEmptyPlayerQ(pq);
	ListBuilding L = (*p1)->list_building;
	address_building x = FirstBuilding(L);
	while(x != NULL)
	{
		x = NextBuilding(x);
	}

	ListUnit L1 = (*p1)->list_unit;
	address_unit y = FirstUnit(L1);
	while(y != NULL)
	{
		y = NextBuilding(y);
	}
	if(CKata.TabKata[1] == '1')
	{
		*current = *p1;
		AddPlayer(pq, *p1);
		AddPlayer(pq, *p2);
	}
	else
	{
		*current = *p2;
		AddPlayer(pq, *p2);
		AddPlayer(pq, *p1);
	}
}
