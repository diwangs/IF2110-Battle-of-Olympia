#ifndef _UNIT_H_
#define _UNIT_H_

#include "point.h"
#include "boolean.h"

/* struct Unit ini yang akan digunakan sebagai element pada ListUnit
 */

typedef struct tPlayer Player;

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
    boolean is_dead;
    char type;
    Player * owner;
} Unit;

/* Constructor */
Unit * MakeUnit(
    int max_health, int health,
    int max_movp, int movp,
    int attack, char attack_type, 
    boolean can_attack, Point coordinate, 
    int price, boolean is_dead, 
    char type, Player * owner);

/* Selector (Getter) */

int GetUnitMaxHealth(Unit unit);
int GetUnitHealth(Unit unit);
int GetUnitAttack(Unit unit);
int GetUnitMaxMovePoint(Unit unit);
int GetUnitMovePoint(Unit unit);
char GetUnitAttackType(Unit unit);
boolean GetUnitCanAttack(Unit unit);
Point GetUnitCoordinate(Unit unit);
int GetUnitPrice(Unit unit);
boolean GetUnitIsDead(Unit unit);
char GetUnitType(Unit unit);
Player * GetUnitOwner(Unit unit);

/* Setter */

void SetUnitMaxHealth(Unit * unit, int max_health);
void SetUnitHealth(Unit * unit, int health);
void SetUnitAttack(Unit * unit, int attack);
void SetUnitMaxMovePoint(Unit * unit, int max_movp);
void SetUnitMovePoint(Unit * unit, int movp);
void SetUnitAttackType(Unit * unit, char attack_type);
void SetUnitCanAttack(Unit * unit, boolean can_attack);
void SetUnitCoordinate(Unit * unit, Point coordinate);
void SetUnitPrice(Unit * unit, int price);
void SetUnitIsDead(Unit * unit, boolean is_dead);
void SetUnitType(Unit * unit, char type);
void SetUnitOwner(Unit * unit, Player * owner);

/* Misc Functions */

Unit CopyUnit(Unit unit, Point coordinate);
boolean CanUnitMoveThatFar(Unit * unit, int x, int y);
void MoveUnit(Unit * unit, int x, int y);
boolean IsEQUnit(Unit u1, Unit u2);
void AttackUnit(Unit * from, Unit * target);

#endif
