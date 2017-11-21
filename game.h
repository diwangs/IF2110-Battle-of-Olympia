#ifndef _GAME_H_
#define _GAME_H_

#include "boolean.h"

/* Variable extern dibawah menyatakan variable global yang dapat di akses oleh
 * seluruh file yang meng-include "game.h", tetapi tetap harus di inisialisasi.
 */

typedef struct tPlayer Player;

extern boolean GAME_RUNNING;
Player * current;

void NewGame();
/* Membuat Game Baru,
 * Meminta masukan peta,
 * Membuat Peta baru,
 * Membuat 2 player baru,
 */

void TurnHandler();
/* Mengatur turn player berapa
 */

void PrintTurnInfo(Player * player);

void PlayerTurn(Player * player);
/* Mengatur bagian turn player
 */

#endif
