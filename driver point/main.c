#include "../point.h"
#include <stdio.h>

int main(){
	POINT P1, P2;

	printf("Masukkan Point 1 : ");
	BacaPOINT(&P1);
	printf("Masukkan Point 2 : ");
	BacaPOINT(&P2);
	printf("\n");

	printf("Point 1 :");
	TulisPOINT(P1);
	printf("\n");
	printf("Point 2 :");
	TulisPOINT(P2);
	printf("\n");

	if (EQ(P1,P2))
		printf("Point 1 == Point 2\n");

	printf("Jarak P1 ke P2 : %d\n", Panjang(P1,P2));

	return 0;
}