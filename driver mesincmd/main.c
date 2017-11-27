#include <stdio.h>
#include "../mesincmd.h"

void printKata(Kata x){
	int i;

	for (i=0; i<x.Length; i++){
		printf("%c", x.TabKata[i]);
	}
	printf("\n");
}

int main() {
	Kata exit = {"EXIT", 4};

	while (1) {
		get_cmd();
		printKata(Cmd);
		if (cmpkata(Cmd, exit)) {
			printf("Exit from loop\n");		
			break;
		}
	}
	return 0;
}