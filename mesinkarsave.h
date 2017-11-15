/* File: mesinkar.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_SAVE_H_
#define __MESIN_KAR_SAVE_H_

#include "boolean.h"

#define MARK '.'
/* State Mesin */
extern char CC;
extern boolean EOP;

void start_save();
/* Menyiapkan mesin karakter untuk menulis ke file */

void write(char c);
/* Menulis karakter c pada file yang telah dibuka */

void end_save();
/* Menutup file output sehingga hasil save tertulis */

#endif
