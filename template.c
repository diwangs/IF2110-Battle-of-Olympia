#include <stdlib.h>
#include "template.h"
#include "point.h"
#include "unit.h"

Unit * CreateUnitKing(Player * P, int brs, int kol)
{
    Point p1 = MakePOINT(brs, kol);
    Unit * u = MakeUnit(
        10, 10,
        5, 5,
        2, 'M', 1,
        p1, 1,
        0, 'K', P);

    return u;
}

Unit * CreateUnitArcher(Player * P, int brs, int kol)
{
    Point p1 = MakePOINT(brs, kol);
    Unit * u = MakeUnit(
        10, 10,
        1, 1,
        2, 'R', 1,
        p1, 1,
        0, 'A', P);

    return u;
}

Unit * CreateUnitSwordsman(Player * P, int brs, int kol)
{
    Point p1 = MakePOINT(brs, kol);
    Unit * u = MakeUnit(
        10, 10,
        1, 1,
        3, 'M', 1,
        p1, 1,
        0, 'S', P);

    return u;
}

Unit * CreateUnitMage(Player * P, int brs, int kol)
{
    Point p1 = MakePOINT(brs, kol);
    Unit * u = MakeUnit(
        10, 10,
        1, 1,
        2, 'R', 1,
        p1, 1,
        0, 'M', P);

    return u;
}
