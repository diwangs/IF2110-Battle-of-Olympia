#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "listunit.h"
#include "listvillage.h"
#include "peta.h"
#include "game.h"
#include "mesincmd.h"
#include "player.h"
#include "unit.h"
#include "point.h"
#include "pcolor/pcolor.h"

void NewGame(){
    srand(time(NULL));
    int brs_peta, kol_peta;

    printf("Baris peta? > ");
    scanf("%d", &brs_peta);
    printf("Kol peta? > ");
    scanf(" %d", &kol_peta);

    MakePeta(brs_peta, kol_peta, &PETA);

    // inisialisasi pemain
    InitializePlayer(&PLAYER1, 'R');
    Unit king1 = MakeUnit(100, 100, 10, 10, 'M', true, MakePOINT(brs_peta - 2, 1), 5, false, "KING", &PLAYER1);
    AddUnit(&PLAYER1, &king1);
    AddUnitToPeta(&king1, &PETA);
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y], &PLAYER1, 'T');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X - 1][king1.coordinate.Y], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X + 1][king1.coordinate.Y], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y - 1], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y + 1], &PLAYER1, 'C');

    InitializePlayer(&PLAYER2, 'Y');
    Unit king2 = MakeUnit(100, 100, 10, 10, 'M', true, MakePOINT(1, kol_peta - 2), 5, false, "KING", &PLAYER2);
    AddUnit(&PLAYER2, &king2);
    AddUnitToPeta(&king2, &PETA);
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y], &PLAYER2, 'T');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X - 1][king2.coordinate.Y], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X + 1][king2.coordinate.Y], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y - 1], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y + 1], &PLAYER2, 'C');

    // TODO Generate Village

    // Call
    PrintPetaNormal(PETA);
    current = &PLAYER1;

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

void PlayerTurn(Player * player){
    for(int i = 0; i < 50; i++)
        printf("=");
    printf("\n");
    Unit * currentUnit = player->list_unit.First->info;
    PrintTurnInfo(player, currentUnit);

    char command[100];
    printf("Your Command > ");
    get_cmd();
    if (cmpkata(move,Cmd)) printf("move...\n");
	else if (cmpkata(undo,Cmd)) printf("undo...\n");
    else if (cmpkata(change_unit,Cmd)) printf("change unit...\n");
    else if (cmpkata(recruit,Cmd)) printf("recruit...\n");
    else if (cmpkata(attack,Cmd)) printf("attack...\n");
    else if (cmpkata(map,Cmd)) printf("map...\n");
    else if (cmpkata(info,Cmd)) printf("info...\n");
    else if (cmpkata(end_turn,Cmd)) printf("end_turn...\n");
    else if (cmpkata(save,Cmd)) printf("save...\n");
    else if (cmpkata(exit,Cmd)) break;
}

