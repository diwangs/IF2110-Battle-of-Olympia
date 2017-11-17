#include <stdio.h>
#include "listunit.h"
#include "listvillage.h"
#include "peta.h"
#include "game.h"
#include "player.h"
#include "unit.h"
#include "point.h"

void NewGame(){
    int brs_peta, kol_peta;

    printf("Baris peta? > ");
    scanf("%d", &brs_peta);
    printf("Kol peta? > ");
    scanf("%d", &kol_peta);

    MakePeta(brs_peta, kol_peta, &PETA);

    // inisialisasi pemain
    InitializePlayer(&PLAYER1, 'R');
    Unit king1 = MakeUnit(100, 100, 10, 10, 'M', true, MakePOINT(brs_peta - 2, 1), 5, false, "KING", &PLAYER1);
    AddUnit(&PLAYER1, &king1);
    AddUnitToCoordinate(&king1, king1.coordinate, &PETA);
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y], &PLAYER1, 'T');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X - 1][king1.coordinate.Y], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X + 1][king1.coordinate.Y], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y - 1], &PLAYER1, 'C');
    SetPetakPetaOwnerType(PETA.m[king1.coordinate.X][king1.coordinate.Y + 1], &PLAYER1, 'C');
  
    InitializePlayer(&PLAYER2, 'Y');
    Unit king2 = MakeUnit(100, 100, 10, 10, 'M', true, MakePOINT(1, kol_peta - 2), 5, false, "KING", &PLAYER2);
    AddUnit(&PLAYER2, &king2);
    AddUnitToCoordinate(&king2, king2.coordinate, &PETA);
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y], &PLAYER2, 'T');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X - 1][king2.coordinate.Y], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X + 1][king2.coordinate.Y], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y - 1], &PLAYER2, 'C');
    SetPetakPetaOwnerType(PETA.m[king2.coordinate.X][king2.coordinate.Y + 1], &PLAYER2, 'C');
    
    PrintPetaNormal(PETA);
}
