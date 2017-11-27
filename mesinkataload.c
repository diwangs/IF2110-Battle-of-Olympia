#include "boolean.h"
#include "mesinkataload.h"
#include "mesinkarload.h"
#include <stdio.h>

LKata CKata;
boolean EndKata;
boolean EndData;

void IgnoreBlank()
{
	/* Mengabaikan BLANK dan newline */
	while((CC == BLANK || CC == '\n') && CC != MARK) ADV();
}

void STARTKATA()
{
	/* Inisialisasi mesin kata dan salin kata pertama dari pita bila ada */
	start_load();
	IgnoreBlank();
	if(CC == MARK) EndKata = true;
	else if(CC == '|')
	{
		EndData = true;
		ADV();
		IgnoreBlank();
	}
	else
	{
		EndKata = false;
		SalinKata();
	}
}

void ADVKATA()
{
	/* Isi CKata dengan kata sekarang dan buat mesin karakter maju ke kata berikutnya */

	if(CC == MARK) EndKata = true;
	else if(CC == '|')
	{
		EndData = true;
		ADV();
		IgnoreBlank();
		SalinKata();
	}
	else
	{
		IgnoreBlank();
		EndData = false;
		SalinKata();
	}
	IgnoreBlank();
}

void SalinKata()
{
	/* Menyalin kata yang sekarang sedang ditunjuk oleh mesin karakter ke dalam CKata */
	CKata.length = 0;
	while(CC != MARK && CC != BLANK && CKata.length < NMax && CC != '|')
	{
		CKata.TabKata[CKata.length] = CC;
		CKata.length += 1;
		ADV();
	}
}