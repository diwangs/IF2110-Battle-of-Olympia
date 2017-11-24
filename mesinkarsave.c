/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "mesinkarsave.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void start_save(char mode)
{
  /* Menyiapkan mesin karakter untuk menulis ke file */
  pita = fopen("pitakar.txt", "w");
}

void write(char c)
{
  	fprintf(pita, "%c", c);
}

void end_save()
{
	fclose(pita);
}