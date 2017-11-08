#ifndef _UNIT_H_
#define _UNIT_H_

#include "point.h"

/* struct Unit ini yang akan digunakan sebagai element pada ListUnit
 */
typedef struct tUnit {
    int max_health;
    int health;
    int attack;
    int max_movp;
    int movp;
    char attack_type; // M atau R
    boolean can_attack;
    Point coordinate;
    int price;
} Unit;

#endif
