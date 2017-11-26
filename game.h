#ifndef _GAME_H_
#define _GAME_H_

#include "boolean.h"
#include "peta.h"

/* Variable extern dibawah menyatakan variable global yang dapat di akses oleh
 * seluruh file yang meng-include "game.h", tetapi tetap harus di inisialisasi.
 */

typedef struct tPlayer Player;
typedef struct tUnit Unit;
typedef struct tBuilding Building;

extern boolean GAME_RUNNING;
extern Player * current;

void NewGame();
/* Membuat Game Baru,
 * Meminta masukan peta,
 * Membuat Peta baru,
 * Membuat 2 player baru,
 */

void LoadGame();
/* Load game yang sudah disimpan */

void TurnHandler();
/* Mengatur turn player berapa
 */

void BindPlayerUnitPeta(Player * player, Unit * unit, Peta * peta);
void unBindPlayerUnitPeta(Player * player, Unit * unit, Peta * peta);
void BindPlayerBuildingPeta(Player * player, Building * building, Peta * peta);

void PrintTurnInfo(Player * player, Unit * currentUnit);

void PlayerTurn(Player * player);
/* Mengatur bagian turn player
 */

void HealHandler(Player * current, Unit * currentUnit);
void UndoHandler(Unit * currentUnit);
void MoveHandler(Player * current, Unit * currentUnit);
void AttackHandler(Player * current, Unit * currentUnit);
void RecruitHandler(Player * current, Unit * currentUnit);

#endif
