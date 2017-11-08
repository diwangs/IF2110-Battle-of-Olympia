#ifndef _VILLAGE_H_
#define _VILLAGE_H_

#include "point.h"

typedef struct tVillage {
    Point coordinate;
    int income;         // banyak gold yang diberikan village tiap turn
    int owner;          // 0 jika tidak ada, else 1 atau 2
} Village;

#endif
