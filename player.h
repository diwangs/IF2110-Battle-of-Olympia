#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "ListUnit.h"
#include "ListVillage.h"

/* PLAYER1 dan PLAYER2 dijadikan global untuk memudahkan memindahkan data,
 * tetapi tetap harus diinisialisasi menggunakan InitializePlayer()
 */
extern Player PLAYER1, PLAYER2;

typedef struct Player{    
    int gold;
    ListUnit list_unit;         // Pada awalnya hanya berisi sebuah King
    ListVillage list_village;
    int income;
    int upkeep;
    char color;
} Player;

void InitializePlayer(Player *player);

#endif
