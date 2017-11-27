#include "boolean.h"
#include "mesinsave.h"
#include "mesinkarsave.h"
#include <stdio.h>

void init_machine()
{
	/* Menginisialisasi mesinkata dan mesinkarakter untuk operasi write */
	start_save('w');
}

void write_word(char word[])
{
	/* Tulis tiap karakter dalam word ke dalam file */
	int i = 0;
	while(word[i] != '\0')
	{
		write(word[i]);
		i += 1;
	}
}

int read_word(char* string, int pos, char* res)
{
	/* Simpan kata dalam string yang berada pada posisi pos ke dalam res */
	int i = 0;
	while(string[pos] != ' ' && string[pos] != '\0')
	{
		res[i] = string[pos];
		pos += 1;
		i += 1;
	}
	res[i] = '\0';
	if(string[pos] == ' ') pos = pos + 1;

	//Mengembalikan posisi kata selanjutnya pada string
	return pos;
}

void write_data(char* data)
{
	/*
	Menuliskan sebaris data ke output file, menuliskan newline diakhir setiap baris data
	*/

	char word[50];
	int x = 0;
	while(data[x] != '\0')
	{
		x = read_word(data, x, word);
		write_word(word);
		write(' ');
	}
	write('\n');
}

void write_separator()
{
	/* Menulis karakter '|' sebagai separator data setiap jenis objek dalam game */
	write(SEPARATOR);
	write('\n');
}

void write_end()
{
	/* Menuliskan karakter penanada akhir savefile */
	write('.');
}

void end_machine()
{
	/* Menutup file output */
	end_save();
}