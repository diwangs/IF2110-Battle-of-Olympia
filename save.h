#ifndef __SAVE_H__
#define __SAVE_H__

#include "unit.h"
#include "listunit.h"
#include "village.h"
#include "listvillage.h"

void save_units(List units);
/* Menyimpan data tentang semua unit dalam list units ke dalam file */

void save_villages(ListVillage villages);
/* Menyimpan data tentang semua village dalam list villages ke dalam file */

#endif