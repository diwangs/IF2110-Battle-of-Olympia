/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINCMD_H__
#define __MESINCMD_H__

#include "boolean.h"

#define NMax 50

typedef struct {
  char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern Kata Cmd;
extern char CCmd;

#define move (Kata){"MOVE", 4}
#define undo (Kata){"UNDO", 4}
#define change_unit (Kata){"CHANGE_UNIT", 11}
#define recruit (Kata){"RECRUIT", 7}
#define attack (Kata){"ATTACK", 6}
#define map (Kata){"MAP", 3}
#define info (Kata){"INFO", 4}
#define end_turn (Kata){"END_TURN", 8}
#define save (Kata){"SAVE", 4}
#define exit (Kata){"EXIT", 4}

void ADV();
void get_cmd();
boolean cmpkata(Kata K1, Kata K2);

#endif