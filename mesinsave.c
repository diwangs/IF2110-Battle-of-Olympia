#include "boolean.h"
#include "mesinsave.h"
#include "mesinkarsave.h"
#include <stdio.h>
#include <string.h>

Kata CKata;
boolean EndKata;

void init_machine()
{
	/* Menginisialisasi mesinkata dan mesinkarakter untuk operasi write */
	start_save();
}

void next_line(char* line)
{
	/* Memasukkan kata selanjutnya yang akan ditulis kedalam CKata */
	strcpy(CKata.TabKata, line);
	CKata.Length = strlen(line);
}

void write_data(char* data)
{
	/*
	Menuliskan sebaris data dalam CKata ke output file, menuliskan newline diakhir setiap baris data
	
	I.S. : CKata kosong atau CKata merupakan kata sebelumnya
	*/

	next_line(data);
	for(int index = 0; index < CKata.Length; index++)
	{
		write(CKata.TabKata[index]);
	}
	write('\n');
}

void write_separator()
{
	/* Menulis karakter '|' sebagai separator data setiap jenis objek dalam game */
	write(SEPARATOR);
	write('\n');
}

void end_machine()
{
	/* Menutup file output */
	end_save();
}