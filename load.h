#include "mesinkarload.h"
#include "mesinkataload.h"
#include "player.h"
#include "playerq.h"

int kata_to_int(LKata K);

void load_unit(infotypeunit* u, Player* p);

void load_player(Player** p);

void load(Player** p1, Player** p2, Player** current, Peta* p, PlayerQ* pq);