#include "mesincmd.h"
#include <stdio.h>

Kata Cmd;
char CCmd;

void ADV(){
	fscanf(stdin,"%c",&CCmd);
}

void get_cmd(){
	Cmd.Length = 0;
	ADV();
	while (CCmd != 10) {
		Cmd.TabKata[Cmd.Length] = CCmd;
		Cmd.Length++;
		ADV();
	}
}

boolean cmpkata(Kata K1, Kata K2){
	int i;
	boolean eq = true;

	if (K1.Length != K2.Length) eq = false;
	else {
		for (i=0; i<K1.Length-1; i++){
			if (K1.TabKata[i] != K2.TabKata[i]) eq = false;
		}
	}

	return eq;
}