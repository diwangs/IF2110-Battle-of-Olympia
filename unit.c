#include "unit.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct tPlayer Player;

/* Constructor */
Unit MakeUnit(int max_health, int health, 
    int max_movp, int movp, 
    char attack_type, boolean can_attack, 
    Point coordinate, int price, 
    boolean is_dead, char type, Player * owner)
{
    Unit u1;
    SetUnitMaxHealth(&u1, max_health);
    SetUnitHealth(&u1, health);
    SetUnitMaxMovePoint(&u1, max_movp);
    SetUnitMovePoint(&u1, movp);
    SetUnitAttackType(&u1, attack_type);
    SetUnitCanAttack(&u1, can_attack);
    SetUnitCoordinate(&u1, coordinate);
    SetUnitPrice(&u1, price);
    SetUnitIsDead(&u1, is_dead);
    SetUnitType(&u1, type);
    SetUnitOwner(&u1, owner);

    return u1;
}

/* Selector (Getter) */

int GetUnitMaxHealth(Unit unit)
{
    return unit.max_health;
}

int GetUnitHealth(Unit unit)
{
    return unit.health;
}

int GetUnitAttack(Unit unit)
{
    return unit.attack;
}

int GetUnitMaxMovePoint(Unit unit)
{
    return unit.max_movp;
}

int GetUnitMovePoint(Unit unit)
{
    return unit.movp;
}

char GetUnitAttackType(Unit unit)
{
    return unit.attack_type;
}

boolean GetUnitCanAttack(Unit unit)
{
    return unit.can_attack;
}

Point GetUnitCoordinate(Unit unit)
{
    return unit.coordinate;
}

int GetUnitPrice(Unit unit)
{
    return unit.price;
}

boolean GetUnitIsDead(Unit unit)
{
    return unit.is_dead;
}

char GetUnitType(Unit unit)
{
    return unit.type;
}

Player * GetUnitOwner(Unit unit)
{
    return unit.owner;
}

/* Setter */

void SetUnitMaxHealth(Unit * unit, int max_health)
{
    unit->max_health = max_health;
}

void SetUnitHealth(Unit * unit, int health)
{
    unit->health = health;
}

void SetUnitAttack(Unit * unit, int attack)
{
    unit->attack = attack;
}

void SetUnitMaxMovePoint(Unit * unit, int max_movp)
{
    unit->max_movp = max_movp;
}

void SetUnitMovePoint(Unit * unit, int movp)
{
    unit->movp = movp;
}

void SetUnitAttackType(Unit * unit, char attack_type)
{
    unit->attack_type = attack_type;
}

void SetUnitCanAttack(Unit * unit, boolean can_attack)
{
    unit->can_attack = can_attack;
}

void SetUnitCoordinate(Unit * unit, Point coordinate)
{
    unit->coordinate = coordinate;
}

void SetUnitPrice(Unit * unit, int price)
{
    unit->price = price;
}

void SetUnitIsDead(Unit * unit, boolean is_dead)
{
    unit->is_dead = is_dead;
}

void SetUnitType(Unit * unit, char type)
{
    unit->type = type;
}

void SetUnitOwner(Unit * unit, Player * owner)
{
    unit->owner = owner;
}

/* Misc Functions */

Unit CopyUnit(Unit unit, Point coordinate)
{
    Unit u1;
    u1 = MakeUnit(
        GetUnitMaxHealth(unit)
        , GetUnitHealth(unit)
        , GetUnitMaxMovePoint(unit)
        , GetUnitMovePoint(unit)
        , GetUnitAttackType(unit)
        , GetUnitCanAttack(unit)
        , coordinate
        , GetUnitPrice(unit)
        , GetUnitIsDead(unit)
        , GetUnitType(unit)
        , GetUnitOwner(unit)
    );

    return u1;
}

boolean CanUnitMoveThatFar(Unit * unit, int x, int y)
{
    int absis = Absis(GetUnitCoordinate(*unit));
    int ordinat = Ordinat(GetUnitCoordinate(*unit));

    return ((abs(x-absis) + abs(y-ordinat)) <= unit->movp);
}

void MoveUnit(Unit * unit, int x, int y)
{
    Point p1;
    int absis = Absis(GetUnitCoordinate(*unit));
    int ordinat = Ordinat(GetUnitCoordinate(*unit));

    unit->movp -= (abs(x-absis) + abs(y-ordinat));
    p1 = MakePOINT(x,y);
    unit->coordinate = p1;
}

boolean IsEQUnit(Unit u1, Unit u2)
{
    return
        GetUnitHealth(u1) == GetUnitHealth(u2) &&
        GetUnitPrice(u1) == GetUnitPrice(u2) &&
        EQ(GetUnitCoordinate(u1), GetUnitCoordinate(u2)) &&
        GetUnitAttack(u1) == GetUnitAttack(u2) &&
        GetUnitIsDead(u1) == GetUnitIsDead(u2) &&
        GetUnitCanAttack(u1) == GetUnitCanAttack(u2) &&
        GetUnitAttackType(u1) == GetUnitAttackType(u2) &&
        GetUnitMovePoint(u1) == GetUnitMovePoint(u2) &&
        GetUnitMaxHealth(u1) == GetUnitMaxHealth(u2) &&
        GetUnitType(u1) == GetUnitType(u2) &&
        GetUnitMaxMovePoint(u1) == GetUnitMaxMovePoint(u2) &&
        GetUnitOwner(u1) == GetUnitOwner(u2);
}
