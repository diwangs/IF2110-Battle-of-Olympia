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

void ADVC();
void get_cmd();
boolean cmpkata(Kata K1, Kata K2);

#endif
