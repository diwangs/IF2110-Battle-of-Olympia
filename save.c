#include "listunit.h"
#include "listvillage.h"
#include "mesinsave.h"
#include "point.h"
#include "unit.h"
#include "village.h"
#include <stdio.h>
#include <string.h>

void save_units(List units)
{
	/* Menyimpan data tentang semua unit dalam list units ke dalam file */
	
	//Jika kosong, segera keluar dari fungsi.
	if(IsEmptyListUnit(units))
	{
		write_separator();
		return;
	}

	//Simpan setiap unit sebagai string dalam file, dimana setiap baris merepresentasikan data mengenai satu unit.
	address_unit current_unit = FirstUnit(units);
	Unit unit;
	char unit_data[NMax];

	while(current_unit != LastUnit(units))
	{
		unit = InfoUnit(current_unit);

		sprintf(unit_data, "%d %d %d %d %d %c %d %d %d %d %d", GetUnitMaxHealth(unit), GetUnitHealth(unit),
			GetUnitAttack(unit), GetUnitMaxMovePoint(unit), GetUnitMovePoint(unit), GetUnitAttackType(unit), GetUnitCanAttack(unit),
			Absis(GetUnitCoordinate(unit)), Ordinat(GetUnitCoordinate(unit)), GetUnitPrice(unit), GetUnitIsDead(unit));

		write_data(unit_data);

		current_unit = NextUnit(current_unit);
	}

	unit = InfoUnit(current_unit);

	sprintf(unit_data, "%d %d %d %d %d %c %d %d %d %d %d", GetUnitMaxHealth(unit), GetUnitHealth(unit),
		GetUnitAttack(unit), GetUnitMaxMovePoint(unit), GetUnitMovePoint(unit), GetUnitAttackType(unit), GetUnitCanAttack(unit),
		Absis(GetUnitCoordinate(unit)), Ordinat(GetUnitCoordinate(unit)), GetUnitPrice(unit), GetUnitIsDead(unit));

	write_data(unit_data);

	//Tulis separator sebagai penanda batas terakhir data tentang unit
	write_separator();
}

void save_villages(ListVillage villages)
{
	/* Menyimpan data tentang semua village dalam list villages ke dalam file */

	//Jika kosong, tidak ada yang perlu diproses
	if(IsEmptyListVillage(villages))
	{
		write_separator();
		return;
	}

	//Simpan data setiap village sebagai baris yang berbeda dalam file
	address_village current_village = FirstVillage(villages);
	Village v;
	char village_data[100];

	while(current_village != LastVillage(villages))
	{
		v = InfoVillage(current_village);

		sprintf(village_data, "%d %d %d %d", Absis(GetVillageCoordinate(v)), Ordinat(GetVillageCoordinate(v)), GetVillageIncome(v), GetVillageOwner(v));

		write_data(village_data);

		current_village = NextVillage(current_village);
	}

	v = InfoVillage(current_village);

	sprintf(village_data, "%d %d %d %d", Absis(GetVillageCoordinate(v)), Ordinat(GetVillageCoordinate(v)), GetVillageIncome(v), GetVillageOwner(v));
	printf("%s\n", village_data);
	// printf("%c\n", village_data[strlen(village_data)]);

	write_data(village_data);

	//Tulis separator sebagai penanda akhir data mengenai village
	write_separator();
}