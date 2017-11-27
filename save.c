#include "jam.h"
#include "mesinkarsave.h"
#include "mesinsave.h"
#include "peta.h"
#include "unit.h"
#include "listunit.h"
#include "player.h"
#include <stdio.h>
#include <time.h>

void save_units(ListUnit L)
{
	//Simpan data mengenai tiap unit
	address_unit curr_unit = FirstUnit(L);
	while(curr_unit != NULL)
	{
		Unit unit = *(InfoUnit(curr_unit));
		char data[NMax];

		//Buat string yang berisi atribut unit yang sedang diproses
		sprintf(data, "%d %d %d %d %d %c %d %d %d %d %d %c %c", GetUnitMaxHealth(unit), GetUnitHealth(unit),
			GetUnitAttack(unit), GetUnitMaxMovePoint(unit), GetUnitMovePoint(unit),
			GetUnitAttackType(unit), GetUnitCanAttack(unit), Absis(GetUnitCoordinate(unit)),
			Ordinat(GetUnitCoordinate(unit)), GetUnitPrice(unit), GetUnitIsDead(unit),
			GetUnitType(unit), (GetUnitOwner(unit))->color);

		//Tulis string ke dalam file save
		write_data(data);

		curr_unit = NextUnit(curr_unit);
	}

	//Tulis separator sebagai penanda akhir dari data mengenai unit
	write_separator();
}

void save_player(Player* p)
{
	//Buat data mengenai gold, income, upkeep, dan color player
	char data[NMax];
	sprintf(data, "%d %d %d %c", p->gold, p->income, p->upkeep, p->color);

	//Tulis data ke dalam file dan tulis separator
	write_data(data);
	write_separator();
}

void save_buildings(ListBuilding L)
{
	//Simpan data mengenai tiap building
	address_building curr_building = FirstBuilding(L);
	while(curr_building != NULL)
	{
		Building b = *(InfoBuilding(curr_building));

		//Buat string yang berisi atribut-atribut yang dimiliki building
		char data[NMax];
		sprintf(data, "%d %d %d %c %c", Absis(GetBuildingCoordinate(b)),
			Ordinat(GetBuildingCoordinate(b)), GetBuildingIncome(b),
			(GetBuildingOwner(b))->color, GetBuildingType(b));

		//Tuliskan data mengenai atribut-atribut ke file
		write_data(data);
		curr_building = NextBuilding(curr_building);
	}

	//Tuliskan separator
	write_separator();
}

void save_map(Peta p)
{
	//Simpan ukuran peta ke file
	char data[NMax];
	sprintf(data, "%d %d", p.n_brs, p.n_kol);
	write_data(data);

	//Simpan data mengenai tiap building pada peta baik yang dimiliki maupun yang netral
	for(int i = 0; i < p.n_brs; i++)
	{
		for(int j = 0; j < p.n_kol; j++)
		{
			if(p.m[i][j]->building != NULL)
			{
				Building b = *(p.m[i][j]->building);
				Player* owner = GetBuildingOwner(b);
				char owner_color;
				if(owner == NULL) owner_color = 'Z';
				else owner_color = owner->color;
				sprintf(data, "%d %d %d %c %c",
					Absis(GetBuildingCoordinate(b)), Ordinat(GetBuildingCoordinate(b)),
					GetBuildingIncome(b), owner_color,
					GetBuildingType(b));
				write_data(data);
			}
		}
	}

	//Tulis separator
	write_separator();
}

void save_local_time()
{
	time_t rawtime;
   	struct tm *local_time;

   	//Ambil waktu saat ini sesuai zona waktu lokal
   	time(&rawtime);
   	local_time = localtime( &rawtime );

   	//Tuliskan waktu save dilakukan ke dalam file
   	char data[NMax];
   	sprintf(data, "%d %d %d", local_time->tm_sec, local_time->tm_min, local_time->tm_hour);
   	write_data(data);
}

void save_game(Player* p1, Player* p2, Player* current, Peta p)
{
	//Save semua data dalam game
	init_machine('w');
	save_player(p1);
	save_units((*p1).list_unit);
	save_buildings((*p1).list_building);
	save_player(p2);
	save_units((*p2).list_unit);
	save_buildings((*p2).list_building);
	save_map(p);
	//Simpan siapakah yang sedang bergerak saat save dilakukan
	if((*current).color == (*p1).color) write_data("P1");
	else write_data("P2");
	write_separator();
	save_local_time();
	write_separator();
	//Tulis MARK penanda akhir dari file
	write_end();
	end_machine();
}