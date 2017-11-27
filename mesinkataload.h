/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarload.h"

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int length;
} LKata;

/* State Mesin Kata */
extern boolean EndKata;
extern boolean EndData;
extern LKata CKata;

void IgnoreBlank();
/* Mengabaikan BLANK dan newline */

void STARTKATA();
/* Inisialisasi mesin kata dan salin kata pertama dari pita bila ada */

void ADVKATA();
/* Isi CKata dengan kata sekarang dan buat mesin karakter maju ke kata berikutnya */

void SalinKata();
/* Menyalin kata yang sekarang sedang ditunjuk oleh mesin karakter ke dalam CKata */

#endif

