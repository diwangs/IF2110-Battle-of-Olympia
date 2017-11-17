#ifndef _PLAYER_H_
#define _PLAYER_H_

/* PLAYER1 dan PLAYER2 dijadikan global untuk memudahkan memindahkan data,
 * tetapi tetap harus diinisialisasi menggunakan InitializePlayer()
 */

typedef struct tListUnit ListUnit;
typedef struct tListVillage ListVillage;
typedef struct tUnit Unit;

typedef struct tPlayer{    
    int gold;
    ListUnit list_unit;         // Kosong
    ListVillage list_village;
    int income;
    int upkeep;
    char color;
} Player;

extern Player PLAYER1, PLAYER2;

void InitializePlayer(Player *player, char c);
// Inisialisasi semua field struct Player, kedua list kosong

void AddUnit(Player *player, Unit *unit);

#endif
