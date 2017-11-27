#include "mesinkarload.h"
#include "mesinkataload.h"
#include "player.h"
#include "playerq.h"

int kata_to_int(LKata K);
/* Mengubah kata dalam CKata menjadi integer */

void load_unit(infotypeunit* u, Player* p);
/* Load data-data dari save file sebagai unit milik p */

void load_building(infotypebuilding* b, Player* p);
/* Load data dari savefile sebagai building milik p */

void load_player(Player** p);
/* Load semua data (unit, income, gold, building, dsb.) milik Player p */

void load_map(Player* p1, Player* p2, Peta* p);
/* Load benda-benda pada peta */

void load(Player** p1, Player** p2, Player** current, Peta* p, PlayerQ* pq);
/* Load semua data yang ada pada savefile */