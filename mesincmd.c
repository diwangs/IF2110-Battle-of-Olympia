#include "mesincmd.h"
#include <stdio.h>
#include <ctype.h>

Kata Cmd;
char CCmd;

void ADVC(){
	fscanf(stdin,"%c",&CCmd);
}

void get_cmd(){
	Cmd.Length = 0;
	ADVC();
	while (CCmd != 10) {
		if (Cmd.Length < 50){
			Cmd.TabKata[Cmd.Length] = toupper(CCmd);
			Cmd.Length++;
		}
		ADVC();
	}
}

boolean cmpkata(Kata K1, Kata K2){
	int i;
	boolean eq = true;

	if (K1.Length != K2.Length) eq = false;
	else {
		for (i=0; i<K1.Length; i++){
			if (K1.TabKata[i] != K2.TabKata[i]) eq = false;
		}
	}

	return eq;
}
