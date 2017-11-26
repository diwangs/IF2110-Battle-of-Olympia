#include <stdlib.h>
#include "listunit.h"
#include "listbuilding.h"
#include "player.h"

Player * CreatePlayer(char c) {
    Player * player = malloc(sizeof(Player));
    player->gold = 50;

    CreateEmptyListUnit(&(player->list_unit));
    CreateEmptyListBuilding(&(player->list_building));

    player->income = 0;
    player->upkeep = 0;
    player->color = c;
    
    return player;
}

void AddUnit(Player *player, Unit *unit) {
    player->upkeep += 1;
    InsVLastListUnit(&player->list_unit, unit);
}

void DelUnit(Player *player, Unit *unit) {
    player->upkeep -= 1;
    DelPListUnit(&player->list_unit, unit);
}

void AddBuilding(Player *player, Building *building) {
    player->income += building->income;
    InsVLastListBuilding(&player->list_building, building);
}

void DelLastBuilding(Player *player) {
    Building * building;
    DelVLastListBuilding(&player->list_building, &building);
    player->income -= building->income;
}
