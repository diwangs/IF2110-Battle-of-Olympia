#include "../stackt.h"
#include "../point.h"
#include <stdio.h>
#include <string.h>

int main() {

	Stack S;
	ElmtStack P;
	char a[20];

	printf("Command List : \n");
	printf("1.Push - push to stack\n");
	printf("2.Pop - pop from stack\n");
	printf("3.Full - is stack full?\n");
	printf("4.Exit - close driver\n");

	CreateEmptyStack(&S);

	while (1){
		printf(">> ");
		scanf("%20s", a);

		if (!strcmp(a,"push")) {
			if (IsFullStack(S)) printf("Stack Full\n");
			else {
				printf("Masukkan Point 1 : ");
				BacaPOINT(&P.prev);
				printf("Masukkan Point 2 : ");
				BacaPOINT(&P.current);
				printf("Masukkan int : ");
				scanf("%d", &P.prevmovp);
				Push(&S,P);
				printf("data telah di push\n");
			}
		} else if (!strcmp(a,"pop")) {
			if (!IsEmptyStack(S)){
				Pop(&S,&P);
				printf("Point 1 :");
				TulisPOINT(P.prev);
				printf("\n");
				printf("Point 2 :");
				TulisPOINT(P.current);
				printf("\nint : %d\n", P.prevmovp);
			}
			else printf("Stack Empty\n");
		} else if (!strcmp(a,"full")) {
			if (IsFullStack(S)) printf("Stack full\n");
			else printf("Stack not full\n");
		} else if (!strcmp(a,"exit")) {
			break;
		}
	}

	return 0;
}