#ifndef __SAVE_H__
#define __SAVE_H__

#include "unit.h"
#include "listunit.h"
#include "building.h"
#include "listbuilding.h"

void save_units(ListUnit L);
/* Menyimpan data tentang semua unit dalam list units ke dalam file */

void save_player(Player* p);

void save_buildings(ListBuilding L);

void save_map(Peta p);

void save_local_time();

void save_game(Player* p1, Player* p2, Player* current, Peta p);

#endif