#include "../unit.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../peta.h"

Peta PETA;

int main() {
    srand(time(NULL));
    Unit * U1;
    Unit U2;
    int max_health, health, max_movp, movp,
        attack, price, x, y;
    char attack_type, type;
    int is_dead, can_attack;
    Point coordinate;
    Player * owner;

    x = rand();
    y = rand();

    max_health = rand();
    health = rand();
    max_movp = rand();
    movp = rand();
    attack = rand();
    attack_type = 'r';
    type = 'k';
    is_dead = 0;
    can_attack = 1;
    coordinate = MakePOINT(rand(), rand());Peta PETA;
    owner = NULL;

    U1 = MakeUnit(
    max_health, health,
    max_movp, movp,
    attack, attack_type,
    can_attack, coordinate,
    price, is_dead,
    type, owner);

    (U2) = CopyUnit(*U1, coordinate);

    printf("CHECK MAX_HEALTH = %d\n", max_health == U1->max_health);
    printf("CHECK HEALTH = %d\n", health == U1->health);
    printf("CHECK MAX_MOVP = %d\n", max_movp == U1->max_movp);
    printf("CHECK MOVP = %d\n", movp == U1->movp);
    printf("CHECK ATTACK = %d\n", attack == U1->attack);
    printf("CHECK ATTACK_TYPE = %d\n", attack_type == U1->attack_type);
    printf("CHECK TYPE = %d\n", type == U1->type);
    printf("CHECK IS_DEAD = %d\n", is_dead == U1->is_dead);
    printf("CHECK coordinate = %d\n", EQ(coordinate, U1->coordinate));
    printf("CHECK EQ UNIT = %d\n", IsEQUnit(*U1, U2));

    MoveUnit(U1, x, y);
    printf("CHECK MOVE COMMAND = %d\n", EQ(U1->coordinate, MakePOINT(x, y)));

}