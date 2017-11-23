#include "listunit.h"
#include "listvillage.h"
#include "player.h"

Player PLAYER1, PLAYER2;

void InitializePlayer(Player *player, char c) {
    player->gold = 50;

    CreateEmptyListUnit(&(player->list_unit));
    CreateEmptyListVillage(&(player->list_village));

    player->income = 0;
    player->upkeep = 0;
    player->color = c;
}

void AddUnit(Player *player, Unit *unit) {
    player->upkeep += 1;
    InsVLastListUnit(&player->list_unit, unit);
}

void AddVillage(Player *player, Village *village) {
    player->income += 1;
    InsVLastListVillage(&player->list_village, village);
}
