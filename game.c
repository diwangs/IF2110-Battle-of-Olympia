#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "listunit.h"
#include "listbuilding.h"
#include "peta.h"
#include "game.h"
#include "mesincmd.h"
#include "player.h"
#include "unit.h"
#include "building.h"
#include "point.h"
#include "pcolor/pcolor.h"
#include "util.h"

void NewGame(){
    srand(time(NULL));
    int brs_peta, kol_peta;

    printf("Baris peta? > ");
    scanf("%d", &brs_peta);
    printf("Kol peta? > ");
    scanf(" %d", &kol_peta);
    getchar();

    MakePeta(brs_peta, kol_peta, &PETA);

    // inisialisasi pemain
    Building * btemp;
    InitializePlayer(&PLAYER1, 'R');
    Unit king1 = MakeUnit(100, 100, 6, 6, 'M', true, MakePOINT(brs_peta - 2, 1), 5, false, "KING", &PLAYER1);
    AddUnit(&PLAYER1, &king1);
    AddUnitToPeta(&king1, &PETA);

    btemp = MakeBuilding(king1.coordinate, 1, &PLAYER1, 'T');
    AddBuilding(&PLAYER1, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king1.coordinate, 1, 0), 1, &PLAYER1, 'C');
    AddBuilding(&PLAYER1, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king1.coordinate, -1, 0), 1, &PLAYER1, 'C');
    AddBuilding(&PLAYER1, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king1.coordinate, 0, 1), 1, &PLAYER1, 'C');
    AddBuilding(&PLAYER1, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king1.coordinate, 0, -1), 1, &PLAYER1, 'C');
    AddBuilding(&PLAYER1, btemp); AddBuildingToPeta(btemp, &PETA);

    InitializePlayer(&PLAYER2, 'Y');
    Unit king2 = MakeUnit(100, 100, 6, 6, 'M', true, MakePOINT(1, kol_peta - 2), 5, false, "KING", &PLAYER2);
    AddUnit(&PLAYER2, &king2);
    AddUnitToPeta(&king2, &PETA);

    btemp = MakeBuilding(king2.coordinate, 1, &PLAYER2, 'T');
    AddBuilding(&PLAYER2, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king2.coordinate, 1, 0), 1, &PLAYER2, 'C');
    AddBuilding(&PLAYER2, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king2.coordinate, -1, 0), 1, &PLAYER2, 'C');
    AddBuilding(&PLAYER2, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king2.coordinate, 0, 1), 1, &PLAYER2, 'C');
    AddBuilding(&PLAYER2, btemp); AddBuildingToPeta(btemp, &PETA);
    btemp = MakeBuilding(PlusDelta(king2.coordinate, 0, -1), 1, &PLAYER2, 'C');
    AddBuilding(&PLAYER2, btemp); AddBuildingToPeta(btemp, &PETA);

    int nbuilding = brs_peta * kol_peta / 20;
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
    current = &PLAYER1;
    PrintPetaNormal(PETA, NULL);

    TurnHandler();
}

void TurnHandler(){
    // untuk diganti dengan queue
    while(true){
        if(current == &PLAYER1){
            PlayerTurn(&PLAYER1);
            current = &PLAYER2;
        } else {
            PlayerTurn(&PLAYER2);
            current = &PLAYER1;
        }
    }
}

void PrintTurnInfo(Player * player, Unit * currentUnit){
    printf("%s", CharToColor(player->color));
    if(player == &PLAYER1){
        printf("Player 1's turn.\n");
    } else {
        printf("Player 2's turn.\n");
    }
    printf("%s", NORMAL);
    // print status
    printf("Cash : %dG | Income : %dG | Upkeep : %dG\n", player->gold, player->income, player->upkeep);


    // print units
    printf("Current unit:\n");
    address_unit f = player->list_unit.First;
    printf("%s(%2d, %2d) | Movement Point : %3d/%3d | HP %3d/%3d | Can attack : %s\n",
            f->info->type,
            f->info->coordinate.X,
            f->info->coordinate.Y,
            f->info->movp,
            f->info->max_movp,
            f->info->health,
            f->info->max_health,
            f->info->can_attack == 1 ? "Yes" : "No"
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
            PrintPetaNormal(PETA, currentUnit);
            printf("Map Coordinate R : ");
            get_cmd();
            x = KataToInt(Cmd);
            printf("Map Coordinate C : ");
            get_cmd();
            y = KataToInt(Cmd);

            if (IsInsidePeta(PETA, x, y) && CanUnitMoveThatFar(currentUnit, x, y) && !IsPetakOccupied(x, y)) {
                PETA.m[Absis(currentUnit->coordinate)][Ordinat(currentUnit->coordinate)]->unit = NULL;
                MoveUnit(currentUnit, x, y);
                AddUnitToPeta(currentUnit, &PETA);
                printf("You have moved your %s to ", GetUnitType(*currentUnit));
                TulisPOINT(GetUnitCoordinate(*currentUnit));
                printf("\n");

                PetakPeta * p = PETA.m[currentUnit->coordinate.X][currentUnit->coordinate.Y];
                if((p->building != NULL) && (p->building->type == 'V')){
                    Building * b = p->building;
                    b->owner = current;
                    AddBuilding(current, b);
                    printf("You acquire a building!\n");
                }
            } else {
                printf("You can't move your unit to there.\n");
            }
        } else if (cmpkata(undo,Cmd)) {
            printf("undo...\n");
        } else if (cmpkata(change_unit,Cmd)) {
            PrintListUnit(player->list_unit);
            printf("Please enter the no. of unit you want to select: ");
            get_cmd();
            selection = KataToInt(Cmd);
            if (IsNthUnitExist(player->list_unit, selection)) {
                currentUnit = SelectNthUnit(player->list_unit, selection);
                printf("You are now selecting %s\n", GetUnitType(*currentUnit));
            } else {
                printf("Unit doesn't exist.\n");
                executed = false;
            }
        } else if (cmpkata(recruit,Cmd)) {
            printf("recruit...\n");
        } else if (cmpkata(attack,Cmd)) {
            printf("attack...\n");
        } else if (cmpkata(map,Cmd)) {
            PrintPetaNormal(PETA, NULL);
        } else if (cmpkata(info,Cmd)) {
            PrintTurnInfo(current, currentUnit);
        } else if (cmpkata(end_turn,Cmd)) {
            // kurangi gold
            current->gold -= current->upkeep;
            executed = true;
        } else if (cmpkata(save,Cmd)) {
            printf("save...\n");
        } else if (cmpkata(keluar,Cmd)) {
            exit(0);
            break;
        } else {
            printf("Command not found.\n");
        }
    }
}

