#include <stdio.h>
#include "peta.h"
#include "point.h"

Peta PETA;

void MakePetakPeta(Point coor, char type, PetakPeta *petak){
    petak->coordinate = coor;
    petak->type = type;
    petak->owner = 0;
}

void MakePeta(int nb, int nk, Peta *peta){
    peta->n_brs = nb;
    peta->n_kol = nk;

    for(int i = 0; i < nb; i++)
        for(int j = 0; j< nk; j++){
            MakePetakPeta(MakePOINT(i, j), 'N', &(peta->m[i][j]));
        }
}

void PrintPetaNormal(Peta peta){
    printf("B %d K %d\n", peta.n_brs, peta.n_kol);
    printf("    ");
    for(int i = 0; i < peta.n_kol; i++)
        printf("%3d ", i);
    printf("\n");
    printf("   *");
    for(int i = 0; i < peta.n_kol; i++)
        printf("****");
    printf("\n");
    for(int i = 0; i < peta.n_brs; i++){
        // Cetak baris pertama dan bangunan
        printf("   *");
        for(int j = 0; j < peta.n_kol; j++)
            printf("   *");
        printf("\n");

        // Cetak nomor baris dan unit
        printf("%2d *", i);
        for(int j = 0; j < peta.n_kol; j++)
            printf("   *");
        printf("\n");
        
        // cetak baris terakhir dan range jika perlu
        printf("   *");
        for(int j = 0; j < peta.n_kol; j++)
            printf("   *");
        printf("\n");

        // cetak garis
        printf("   *");
        for(int j = 0; j < peta.n_kol; j++)
            printf("****");
        printf("\n");
    }

}
