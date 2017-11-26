#include "boolean.h"
#include "mesinkataload.h"
#include "mesinkarload.h"
#include <stdio.h>

LKata CKata;
boolean EndKata;
boolean EndData;

void IgnoreBlank()
{
	/* Mengabaikan satu atau beberapa BLANK
	   I.S. : CC sembarang 
	   F.S. : CC ≠ BLANK atau CC = MARK */
	while((CC == BLANK || CC == '\n') && CC != MARK) ADV();
}

void STARTKATA()
{
	/* I.S. : CC sembarang 
	   F.S. : EndKata = true, dan CC = MARK; 
	          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
	          CC karakter pertama sesudah karakter terakhir kata */
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
	/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
	   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
	          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
	          Jika CC = MARK, EndKata = true.		  
	   Proses : Akuisisi kata menggunakan procedure SalinKata */
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
	/* Mengakuisisi kata, menyimpan dalam CKata
	   I.S. : CC adalah karakter pertama dari kata
	   F.S. : CKata berisi kata yang sudah diakuisisi; 
	          CC = BLANK atau CC = MARK; 
	          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
	          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	CKata.length = 0;
	while(CC != MARK && CC != BLANK && CKata.length < NMax && CC != '|')
	{
		CKata.TabKata[CKata.length] = CC;
		CKata.length += 1;
		ADV();
	}
}