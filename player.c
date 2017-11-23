#include "listunit.h"
#include "listbuilding.h"
#include "player.h"

Player PLAYER1, PLAYER2;

void InitializePlayer(Player *player, char c) {
    player->gold = 50;

    CreateEmptyListUnit(&(player->list_unit));
    CreateEmptyListBuilding(&(player->list_building));

    player->income = 0;
    player->upkeep = 0;
    player->color = c;
}

void AddUnit(Player *player, Unit *unit) {
    player->upkeep += 1;
    InsVLastListUnit(&player->list_unit, unit);
}

void AddBuilding(Player *player, Building *building) {
    player->income += building->income;
    InsVLastListBuilding(&player->list_building, building);
}
