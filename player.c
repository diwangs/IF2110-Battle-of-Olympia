#include "player.h"
#include "listunit.h"
#include "listvillage.h"

Player PLAYER1, PLAYER2;

void InitializePlayer(Player *player, char c) {
   player->gold = 0;

   CreateEmptyListUnit(&(player->list_unit));
   CreateEmptyListVillage(&(player->list_village));

   player->income = 0;
   player->upkeep = 0;
   player->color = c;
}

void AddUnit(Player *player, Unit *unit) {

}
