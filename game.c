#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "load.h"
#include "save.h"
#include "listunit.h"
#include "listbuilding.h"
#include "peta.h"
#include "game.h"
#include "mesincmd.h"
#include "player.h"
#include "playerq.h"
#include "unit.h"
#include "building.h"
#include "point.h"
#include "pcolor/pcolor.h"
#include "util.h"
#include "template.h"
#include "stackt.h"

Player * PLAYER1, * PLAYER2;
Player * current;
boolean wincondition;
address_playerQ currentq;
Peta PETA;
PlayerQ PQ;
Stack moves;

void NewGame(){
    wincondition = false;
    srand(time(NULL));
    int brs_peta, kol_peta;

    printf("Baris peta? > ");
    get_cmd();
    brs_peta = KataToInt(Cmd);
    while ((brs_peta < 8) || (brs_peta > 15)) {
        printf("Baris must higher than 7 and lower than 16\n");
        printf("Baris peta? > ");
        get_cmd();
        brs_peta = KataToInt(Cmd);
    }
    printf("Kol peta? > ");
    get_cmd();
    kol_peta = KataToInt(Cmd);
    while ((kol_peta < 8) || (kol_peta > 15)) {
        printf("Kolom must higher than 7 and lower than 16\n");
        printf("Kol peta? > ");
        get_cmd();
        kol_peta = KataToInt(Cmd);
    }

    MakePeta(brs_peta, kol_peta, &PETA);

    // inisialisasi pemain
    PLAYER1 = CreatePlayer('R');
    Unit * king1 = CreateUnitKing(PLAYER1, brs_peta - 2, 1);
    BindPlayerUnitPeta(PLAYER1, king1, &PETA);

    BindPlayerBuildingPeta(PLAYER1, MakeBuilding(king1->coordinate, 1, PLAYER1, 'T'), &PETA);

    BindPlayerBuildingPeta(PLAYER1, MakeBuilding(PlusDelta(king1->coordinate, 1, 0), 0, PLAYER1, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER1, MakeBuilding(PlusDelta(king1->coordinate, -1, 0), 0, PLAYER1, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER1, MakeBuilding(PlusDelta(king1->coordinate, 0, 1), 0, PLAYER1, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER1, MakeBuilding(PlusDelta(king1->coordinate, 0, -1), 0, PLAYER1, 'C'), &PETA);

    PLAYER2 = CreatePlayer('C');
    Unit * king2 = CreateUnitKing(PLAYER2, 1, kol_peta - 2);
    BindPlayerUnitPeta(PLAYER2, king2, &PETA);

    BindPlayerBuildingPeta(PLAYER2, MakeBuilding(king2->coordinate, 1, PLAYER2, 'T'), &PETA);
    BindPlayerBuildingPeta(PLAYER2, MakeBuilding(PlusDelta(king2->coordinate, 1, 0), 0, PLAYER2, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER2, MakeBuilding(PlusDelta(king2->coordinate, -1, 0), 0, PLAYER2, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER2, MakeBuilding(PlusDelta(king2->coordinate, 0, 1), 0, PLAYER2, 'C'), &PETA);
    BindPlayerBuildingPeta(PLAYER2, MakeBuilding(PlusDelta(king2->coordinate, 0, -1), 0, PLAYER2, 'C'), &PETA);

    int nbuilding = brs_peta * kol_peta / 10;
    for(int i = 0; i < nbuilding; i++)
        while(true){
            int r = rand() % brs_peta;
            int c = rand() % kol_peta;
            if(PETA.m[r][c]->building == NULL){
                AddBuildingToPeta(MakeBuilding(MakePOINT(r, c), 1, NULL, 'V'), &PETA);
                break;
            }
        }

    // Call

    AddPlayer(&PQ, PLAYER1);
    AddPlayer(&PQ, PLAYER2);
    CreateEmptyStack(&moves);

    currentq = (FirstPlayerQ(PQ));

    TurnHandler();
}

void LoadGame()
{
    wincondition = false;
	load(&PLAYER1, &PLAYER2, &current, &PETA, &PQ);
    getchar();
	currentq = FirstPlayerQ(PQ);
	TurnHandler();
}

void TurnHandler(){
    // untuk diganti dengan queue
    while(true){
        current = InfoElmtPlayerQ(currentq);
        PlayerTurn(current);
        currentq = (NextElmtPlayerQ(currentq));
        if (wincondition) return;
    }
}

void PrintTurnInfo(Player * player, Unit * currentUnit){
    printf("%s", CharToColor(player->color));
    if(player == PLAYER1){
        printf("Player 1's turn.\n");
    } else {
        printf("Player 2's turn.\n");
    }
    printf("%s", NORMAL);
    // print status
    printf("Cash : %dG | Income : %dG | Upkeep : %dG\n", player->gold, player->income, player->upkeep);


    // print units
    printf("Current unit:\n");
    printf("%c(%2d, %2d) | Movement Point : %3d/%3d | HP %3d/%3d | Can attack : %s\n",
            currentUnit->type,
            currentUnit->coordinate.X,
            currentUnit->coordinate.Y,
            currentUnit->movp,
            currentUnit->max_movp,
            currentUnit->health,
            currentUnit->max_health,
            currentUnit->can_attack == 1 ? "Yes" : "No"
            );
}

void PlayerTurn(Player * player) {
    boolean executed = false;
    int selection;
    int x, y;
    Kata move = (Kata){"MOVE", 4};
    Kata undo = (Kata){"UNDO", 4};
    Kata change_unit = (Kata){"CHANGE_UNIT", 11};
    Kata recruit = (Kata){"RECRUIT", 7};
    Kata attack = (Kata){"ATTACK", 6};
    Kata map = (Kata){"MAP", 3};
    Kata info = (Kata){"INFO", 4};
    Kata end_turn = (Kata){"END_TURN", 8};
    Kata save = (Kata){"SAVE", 4};
    Kata keluar = (Kata){"EXIT", 4};
	
    // income
    current->gold += current->income;
	
    system("clear");
    
    // refill movp + heal + reset can_attack
    address_unit u = current->list_unit.First;
    while(u != NULL){
        u->info->movp = u->info->max_movp;
        u->info->can_attack = true;
	if (u->info->type == 'M')
            HealHandler(current, u->info);
        u = u->next;
    }

    for(int i = 0; i < 50; i++)
        printf("=");
    printf("\n");
    Unit * currentUnit = player->list_unit.First->info;
    PrintTurnInfo(player, currentUnit);
    PrintPetaNormal(PETA, NULL);

    while (!executed) {
        printf("Your Command > ");
        get_cmd();
        
        if (cmpkata(move,Cmd)) {
            MoveHandler(current, currentUnit);
        } else if (cmpkata(undo,Cmd)) {
            UndoHandler(currentUnit);
        } else if (cmpkata(change_unit,Cmd)) {
            CreateEmptyStack(&moves);
            PrintListUnit(player->list_unit);
            printf("Please enter the no. of unit you want to select: ");
            get_cmd();
            selection = KataToInt(Cmd);
            if (IsNthUnitExist(player->list_unit, selection)) {
                currentUnit = SelectNthUnit(player->list_unit, selection);
                printf("You are now selecting %c\n", GetUnitType(*currentUnit));
            } else {
                printf("Unit doesn't exist.\n");
                executed = false;
            }
        } else if (cmpkata(recruit,Cmd)) {
            CreateEmptyStack(&moves);
            RecruitHandler(current, currentUnit);
        } else if (cmpkata(attack,Cmd)) {
            CreateEmptyStack(&moves);
            AttackHandler(current, currentUnit);
        } else if (cmpkata(map,Cmd)) {
            PrintPetaNormal(PETA, NULL);
        } else if (cmpkata(info,Cmd)) {
            PrintTurnInfo(current, currentUnit);
        } else if (cmpkata(end_turn,Cmd)) {
            CreateEmptyStack(&moves);
            // kurangi gold
            current->gold -= current->upkeep;
            executed = true;
        } else if (cmpkata(save,Cmd)    ) {
            save_game(PLAYER1, PLAYER2, current, PETA);
        } else if (cmpkata(keluar,Cmd)) {
            exit(0);
        } else {
            printf("Command not found.\n");
        }

        if (wincondition) executed = true;
    }
}

void UndoHandler(Unit * currentUnit)
{
    if (IsEmptyStack(moves)) {
        printf("You haven't made any moves!\n");
        return;
    }

    ElmtStack S;
    S = InfoTop(moves);

    unBindPlayerUnitPeta(currentUnit->owner, currentUnit, &PETA);

    PetakPeta * p = PETA.m[S.current.X][S.current.Y];
    if((p->building != NULL) && (p->building->type == 'V')){
        Building * b = p->building;
        b->owner = current;
        DelLastBuilding(current);
        b->owner = NULL;
    }

    currentUnit->coordinate = S.prev;
    currentUnit->movp = S.prevmovp;

    Pop(&moves, &S);

    BindPlayerUnitPeta(currentUnit->owner, currentUnit, &PETA);

    printf("You have undo your %c move from ", currentUnit->type);
    TulisPOINT(S.current);
    printf(" to ");
    TulisPOINT(S.prev);
    printf("\n");
}

void MoveHandler(Player * current, Unit * currentUnit){
    PrintPetaNormal(PETA, currentUnit);
    int x, y;
    if(currentUnit->movp <= 0){
        printf("You can't move this(%c) unit anymore.\n", currentUnit->type);
        return;
    }

    printf("Map Coordinate R : ");
    get_cmd();
    x = KataToInt(Cmd);
    printf("Map Coordinate C : ");
    get_cmd();
    y = KataToInt(Cmd);

    if (IsInsidePeta(PETA, x, y) && CanUnitMoveThatFar(currentUnit, x, y) && !IsPetakOccupied(x, y)) {
        ElmtStack S;
        S.prev = GetUnitCoordinate(*currentUnit);
        S.prevmovp = GetUnitMovePoint(*currentUnit);
        PETA.m[Absis(currentUnit->coordinate)][Ordinat(currentUnit->coordinate)]->unit = NULL;
        MoveUnit(currentUnit, x, y);
        AddUnitToPeta(currentUnit, &PETA);
        printf("You have moved your %c to ", GetUnitType(*currentUnit));
        TulisPOINT(GetUnitCoordinate(*currentUnit));
        printf("\n");
        S.current = GetUnitCoordinate(*currentUnit);
        Push(&moves, S);

        PetakPeta * p = PETA.m[currentUnit->coordinate.X][currentUnit->coordinate.Y];
        if((p->building != NULL) && (p->building->type == 'V')){
            Building * b = p->building;
            b->owner = current;
            AddBuilding(current, b);
            SetUnitMovePoint(currentUnit, 0);
            printf("You acquire a building!\n");
        }
    } else {
        printf("You can't move your unit to there.\n");
    }
}

void HealHandler(Player * current, Unit * currentUnit){
    Point p = currentUnit->coordinate;

    int newHealth;
    Unit * u;
    Point offset[] = {MakePOINT(p.X + 1,p.Y), MakePOINT(p.X - 1, p.Y), MakePOINT(p.X, p.Y + 1), MakePOINT(p.X, p.Y - 1)};

    for(int i = 0; i < 4; i++)
        if ((offset[i].X < 0) || (offset[i].Y < 0) || (offset[i].X > PETA.n_brs-1) || (offset[i].Y > PETA.n_kol-1)) continue;
        else if(PETA.m[offset[i].X][offset[i].Y]->unit != NULL){
            u = PETA.m[offset[i].X][offset[i].Y]->unit;
            if (u->owner == current){
                //do heal
                newHealth = (u->health + currentUnit->attack);
                if (newHealth > u->max_health)
                    newHealth -= (newHealth % u->max_health);
                if (newHealth != u->health){
                        printf("Unit %s%c%s (%d, %d) health increased by %d ", CharToColor(u->owner->color), u->type, NORMAL, u->coordinate.X, u->coordinate.Y, newHealth - u->health);
                        puts("");
                        u->health = newHealth;
                    }
            }
        }
}

void AttackHandler(Player * current, Unit * currentUnit){
    if(!currentUnit->can_attack){
        printf("This unit cannot attack.\n");
        return;
    }
   
    Point p = currentUnit->coordinate;
    int c = 0;
    Unit *cc[4];
    Unit * u;
    Point offset[] = {MakePOINT(p.X + 1,p.Y), MakePOINT(p.X - 1, p.Y), MakePOINT(p.X, p.Y + 1), MakePOINT(p.X, p.Y - 1)};

    for(int i = 0; i < 4; i++)
    if ((offset[i].X < 0) || (offset[i].Y < 0) || (offset[i].X > PETA.n_brs-1) || (offset[i].Y > PETA.n_kol-1)) continue;
        else if (PETA.m[offset[i].X][offset[i].Y]->unit != NULL){
            u = PETA.m[offset[i].X][offset[i].Y]->unit;
            if (u->owner != current){
                    cc[++c] = u;
                    printf("%d. %s%c%s (%d, %d)", c, CharToColor(u->owner->color), u->type, NORMAL, u->coordinate.X, u->coordinate.Y);
                    printf(" | HP %d/%d", u->health, u->max_health);
                    printf(" | Attack Type %c", u->attack_type);
                    puts("");
                }
        }

    if (c == 0) {
        printf("No enemy unit around your current unit\n");
        return;
    }

    printf("Current unit %s%c%s attack type is %c, attack point is %d\n", CharToColor(currentUnit->owner->color), currentUnit->type, NORMAL, currentUnit->attack_type, currentUnit->attack);
    int s;
    printf("Select the no. of the unit you want to attack > ");
    get_cmd();
    s = KataToInt(Cmd);
    if((s <= 0) || (c < s)){
        printf("Invalid unit selected, cancelled attack\n");
        return;
    }

    u = cc[s];

    printf("Selected %s%c%s (%d, %d)", CharToColor(u->owner->color), u->type, NORMAL, u->coordinate.X, u->coordinate.Y);
    printf(" | HP %d/%d", u->health, u->max_health);
    printf(" | Attack Type %c", u->attack_type);
    puts("");

    // START ATTACK LOGIC
    u->health -= currentUnit->attack;

    if (u->health <= 0){
        printf("Enemy %s%c%s (%d, %d) is dead.\n", CharToColor(u->owner->color), u->type, NORMAL, u->coordinate.X, u->coordinate.Y);
        if (u->type == 'K') {
            printf("===============GAME OVER===============\n");
            if(current == PLAYER1){
                printf("%sPlayer 1%s has win this game!\n", CharToColor(PLAYER1->color), NORMAL);
            } else {
                printf("%sPlayer 2%s has win this game!\n", CharToColor(PLAYER2->color), NORMAL);
            }
            wincondition = 1;
        }
        unBindPlayerUnitPeta(u->owner, u, &PETA);
        //dealokasi u
        return;
    }

    // Counter attack logic
    if((u->health > 0) && ((u->attack_type == currentUnit->attack_type)||(u->type == 'K'))){
        printf("Enemy unit %s, he counterattacks!\n", u->type == 'K' ? "is a king" :  "has the same attack type");
        currentUnit->health -= u->attack;

        if(currentUnit->health <= 0){
            printf("Current unit %s%c%s is dead.\n", CharToColor(currentUnit->owner->color), currentUnit->type, NORMAL);
            if (currentUnit->type == 'K') {
                printf("===============GAME OVER===============\n");
                if(current == PLAYER1){
                    printf("%sPlayer 2%s has win this game!\n", CharToColor(PLAYER2->color), NORMAL);
                } else {
                    printf("%sPlayer 1%s has win this game!\n", CharToColor(PLAYER1->color), NORMAL);
                }
                wincondition = true;
                return;
            }
            unBindPlayerUnitPeta(current, currentUnit, &PETA);
            //dealokasi currentunit
        }
    }
    
    currentUnit->can_attack = 0;
    printf("Enemy %s%c%s (%d, %d)", CharToColor(u->owner->color), u->type, NORMAL, u->coordinate.X, u->coordinate.Y);
    printf(" | HP %d/%d", u->health, u->max_health);
    printf(" | Attack Type %c", u->attack_type);
    puts("");
    PrintTurnInfo(current, currentUnit);
}

void RecruitHandler(Player * current, Unit * currentUnit){
    Building * tower = current->list_building.First->info;
    Unit * u;
    int HARGA_UNIT[] = {-1, 5, 6, 7}; // archer, swordsman, mage

    if (currentUnit->type != 'K') {
        printf("Change unit to king first\n");
        return;
    }

    if(!EQ(currentUnit->coordinate, tower->coordinate)){
        printf("Your king is not at the tower\n");
        return;
    } else if(current->gold < 5) {
        printf("You dont have enough gold\n");
        return;
    }
    // Check if any castle is empty
    address_building f = current->list_building.First;
    while(f != NULL){
        if(f->info->type == 'C')
            if(!IsPetakOccupied(f->info->coordinate.X, f->info->coordinate.Y))
                break;

        f = f->next;
    }
    if(f == NULL){
        printf("No empty castle available\n");
        return;
    } 

    PrintListBuildingByType(current->list_building, 'C');
    while(true){
        printf("Select where you want to recruit your unit > ");
        get_cmd();
        int s = KataToInt(Cmd);
        while((0 > s) || (s > 4)){
            printf("Select where you want to recruit your unit > ");
            get_cmd();
            s = KataToInt(Cmd);
        }
        
        f = current->list_building.First;
        while((f != NULL) && (s > 0)){
            if(f->info->type == 'C')
                s--;
            if(s == 0) break;
            f = f->next;
        }
        if(!IsPetakOccupied(f->info->coordinate.X, f->info->coordinate.Y))
            break;
        printf("Space is occupied\n");
    }

    printf("1. Archer | %dG\n", HARGA_UNIT[1]);
    printf("2. Swordsman | %dG\n", HARGA_UNIT[2]);
    printf("3. White Mage | %dG\n", HARGA_UNIT[3]);
    printf("Select the unit you want to recruit > ");
    get_cmd();
    int s = KataToInt(Cmd);
    while((0 > s) || (s > 3) || (HARGA_UNIT[s] > current->gold)){
        printf("Select the unit you want to recruit > ");
        get_cmd();
        s = KataToInt(Cmd);
    }
    switch(s){
        case 1 : u = CreateUnitArcher(current, f->info->coordinate.X, f->info->coordinate.Y); break;
        case 2 : u = CreateUnitSwordsman(current, f->info->coordinate.X, f->info->coordinate.Y); break;
        case 3 : u = CreateUnitMage(current, f->info->coordinate.X, f->info->coordinate.Y); break;
    }
    BindPlayerUnitPeta(current, u, &PETA);
    u->movp = 0;
    current->gold -= HARGA_UNIT[s];
}

void BindPlayerUnitPeta(Player * player, Unit * unit, Peta * peta){
    unit->owner = player;
    AddUnit(player, unit);
    AddUnitToPeta(unit, peta);
}

void unBindPlayerUnitPeta(Player * player, Unit * unit, Peta * peta){
    unit->owner = player;
    DelUnit(player, unit);
    DeleteUnitFromPeta(unit, peta);
}

void BindPlayerBuildingPeta(Player * player, Building * building, Peta * peta){
    building->owner = player;
    AddBuilding(player, building);
    AddBuildingToPeta(building, peta);
}
