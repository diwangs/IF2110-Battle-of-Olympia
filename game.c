#include <stdio.h>
#include "peta.h"
#include "game.h"
#include "player.h"

void NewGame(){
    int brs_peta, kol_peta;

    printf("Baris peta? > ");
    scanf("%d", &brs_peta);
    printf("Kol peta? > ");
    scanf("%d", &kol_peta);

    MakePeta(brs_peta, kol_peta, &PETA);
    PrintPetaNormal(PETA);

    // inisialisasi pemain
    InitializePlayer(&PLAYER1, 'R');
}
