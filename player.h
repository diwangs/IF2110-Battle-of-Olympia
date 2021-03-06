#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "listunit.h"
#include "listbuilding.h"

/* PLAYER1 dan PLAYER2 dijadikan global untuk memudahkan memindahkan data,
 * tetapi tetap harus diinisialisasi menggunakan InitializePlayer()
 */

typedef struct tListUnit ListUnit;
typedef struct tListVillage ListVillage;
typedef struct tUnit Unit;
typedef struct tVillage Village;

typedef struct tPlayer{    
    int gold;
    ListUnit list_unit;         // Kosong
    ListBuilding list_building;
    int income;
    int upkeep;
    char color;
} Player;

Player * CreatePlayer(char c);

void AddUnit(Player *player, Unit *unit);
void DelUnit(Player *player, Unit *unit);
void AddBuilding(Player *player, Building *building);
void DelLastBuilding(Player *player);

#endif
