#ifndef _GAME_H_
#define _GAME_H_

#include "boolean.h"

/* Variable extern dibawah menyatakan variable global yang dapat di akses oleh
 * seluruh file yang meng-include "game.h", tetapi tetap harus di inisialisasi.
 */
extern boolean GAME_RUNNING;

void NewGame();
/* Membuat Game Baru,
 * Meminta masukan peta,
 * Membuat Peta baru,
 * Membuat 2 player baru,
 */

// void PlayerTurn(Player player);
/* Mengatur bagian turn player
 */

#endif
