#ifndef __SAVE_H__
#define __SAVE_H__

#include "unit.h"
#include "listunit.h"
#include "building.h"
#include "listbuilding.h"

void save_units(ListUnit L);
/* Menyimpan data tentang semua unit dalam list unit ke dalam file */

void save_player(Player* p);
/* Simpan data mengenai player p */

void save_buildings(ListBuilding L);
/* Simpan data mengenai building dalam list L */

void save_map(Peta p);
/* Simpan ukuran dan bangunan pada peta p */

void save_local_time();
/* Simpan waktu lokal saat dilakukan save */

void save_game(Player* p1, Player* p2, Player* current, Peta p);
/* Simipan data-data dalam game */

#endif