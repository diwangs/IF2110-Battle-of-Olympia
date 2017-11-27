/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

void start_load();
/* Initialize mesin kata untuk load */

void ADV();
/* Pita dimajukan satu karakter, bila ditemukan MARK, maka EOP menjadi true */

#endif
