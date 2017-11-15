/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarsave.h"

#define NMax 100
#define BLANK ' '
#define SEPARATOR '|'

typedef struct {
	char TabKata[NMax]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void init_machine();
/* Menginisialisasi mesinkata dan mesinkarakter untuk operasi write */

void write_data(char* data);
/*
	Menuliskan sebaris data dalam CKata ke output file, menuliskan newline diakhir setiap baris data
	
	I.S. : CKata kosong atau CKata merupakan kata sebelumnya
*/

void next_kata(char* kata);
/* Memasukkan kata selanjutnya yang akan ditulis kedalam CKata */

void write_separator();
/* Menuliskan SEPARATOR yang menandakan akhir data dari salah satu jenis objek dalam game */

void end_machine();
/* Menutup file output sehingga output keluar */

#endif

