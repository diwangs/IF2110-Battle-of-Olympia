#ifndef _TEMPLATE_H_
#define _TEMPLATE_H_

#include "unit.h"

extern Unit king, archer, swordsman, mage;

Unit CreateUnitKing(Player * P, int brs, int kol);
Unit CreateUnitArcher(Player * P, int brs, int kol);
Unit CreateUnitSwordsman(Player * P, int brs, int kol);
Unit CreateUnitMage(Player * P, int brs, int kol);

#endif