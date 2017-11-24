#include "mesinsave.h"
#include "peta.h"
#include "unit.h"
#include "listunit.h"
#include "player.h"
#include <stdio.h>

void save_units(ListUnit L)
{
	address_unit curr_unit = FirstUnit(L);

	while(curr_unit != NULL)
	{
		Unit unit = *(InfoUnit(curr_unit));
		char data[Nmax];

		sprintf(data, "%d %d %d %d %d %c %d %d %d %d %d %c %c", GetUnitMaxHealth(unit), GetUnitHealth(unit),
			GetUnitAttack(unit), GetUnitMaxMovePoint(unit), GetUnitMovePoint(unit),
			GetUnitAttackType(unit), GetUnitCanAttack(unit), Absis(GetUnitCoordinate(unit)),
			Ordinat(GetUnitCoordinate(unit)), GetUnitPrice(unit), GetUnitIsDead(unit),
			GetUnitType(unit), (GetUnitOwner(unit))->color);

		write_data(data);

		curr_unit = NextUnit(curr_unit);
	}

	write_separator();
}

void save_player(Player* p)
{
	char data[Nmax];
	sprintf(data, "%d %d %d %c", p->gold, p->income, p->upkeep, p->color);
	write_data(data);
	write_separator();
}

void save_buildings(ListBuilding L)
{
	address_building curr_building = FirstBuilding(L);

	while(curr_building != NULL)
	{
		Building b = *(InfoBuilding(curr_building));

		char data[Nmax];
		sprintf(data, "%d %d %d %c %c", Absis(GetBuildingCoordinate(b)),
			Ordinat(GetBuildingCoordinate(b)), GetBuildingIncome(b),
			(GetBuildingOwner(b))->color, GetBuildingType(b));

		write_data(data);
		curr_building = NextBuilding(curr_building);
	}
	write_separator();
}

void save_map(Peta p)
{
	char data[Nmax];
	sprintf(data, "%d %d", p.n_brs, p.n_kol);
	write_data(data);
	write_separator();
}

void save_game(Player* p1, Player* p2, Player* current, Peta p)
{
	init_machine('w');
	save_player(p1);
	save_units((*p1).list_unit);
	save_buildings((*p1).list_building);
	save_player(p2);
	save_units((*p2).list_unit);
	save_buildings((*p2).list_building);
	save_map(p);
	if((*current).color == (*p1).color) write_data("P1");
	else write_data("P2");
	write_separator();
	write_end();
	end_machine();
}