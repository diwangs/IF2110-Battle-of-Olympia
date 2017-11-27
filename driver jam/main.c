#include "../jam.h"
#include <stdio.h>

int main() {
	JAM J1, J2;
	
	BacaJAM(&J1);
	BacaJAM(&J2);
	
	TulisJAM(J1);
	printf(" ");
	TulisJAM(J2);
	
	if (JEQ(J1,J2)){
		printf("\nJ1 == J2\n");
	}
	if (JNEQ(J1,J2)){
		printf("\nJ1 <> J2\n");
	}
	
	printf("\n");
	J1 = NextDetik(J1);
	TulisJAM(J1);
	printf("\nJ1 + 1 second\n");
	
	printf("\n");
	J2 = PrevDetik(J2);
	TulisJAM(J2);
	printf("\nJ2 - 1 second\n");
	
	printf("\n");
	J1 = NextNDetik(J1,60);
	TulisJAM(J1);
	printf("\nJ1 + 60 second\n");
	
	printf("\n");
	J2 = PrevNDetik(J2,60);
	TulisJAM(J2);
	printf("\nJ2 - 60 second\n");
	
	if (JLT(J1,J2)) {
		printf("J1<J2\n");
	}
	if (JGT(J1,J2)) {
		printf("J1>J2\n");
	}
	
	printf("lama waktu (J1-J2) = %ld\n", Durasi(J2,J1));
	
}