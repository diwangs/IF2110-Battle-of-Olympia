/* File: mesinkar.c */
/* Implementasi Mesin Karakter */

#include "boolean.h"
#include "mesinkarload.h"
#include <stdio.h>

char CC;
boolean EOP;

static FILE * pita;
static int retval;

void start_load() {
	pita = fopen("pitakar.txt","r");
	ADV();
}

void ADV() {
  fscanf(pita, "%c", &CC);
  if(CC == MARK) EOP = true;
}
