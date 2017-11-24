/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarsave.h"

#define NMax 100
#define BLANK ' '
#define SEPARATOR '|'

void init_machine();
/* Menginisialisasi mesinkata dan mesinkarakter untuk operasi write */

void write_word(char word[]);
/*
	Menuliskan sebaris data ke output file, menuliskan newline diakhir setiap baris data
*/

int read_word(char* string, int pos, char* res);
/* Membaca word selanjutnya dari string */

void write_data(char* data);
/*
	Menuliskan sebaris data ke output file, menuliskan newline diakhir setiap baris data
*/

void write_separator();
/* Menuliskan SEPARATOR yang menandakan akhir data dari salah satu jenis objek dalam game */

void end_machine();
/* Menutup file output sehingga output keluar */

#endif

