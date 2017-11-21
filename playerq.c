#include <stdlib.h>
#include "playerq.h"

int CountPlayer (PlayerQ Q) {
	if (FirstPlayerQ(Q) == NULL) return 0;
	int n = 1;
	address_playerQ A = FirstPlayerQ(Q);
	while (NextElmtPlayerQ(A) != FirstPlayerQ(Q)) {
		A = NextElmtPlayerQ(A);
		n++;
	}
	return n;
}

void CreateEmptyPlayerQ (PlayerQ * Q) {FirstPlayerQ(*Q) = NULL;}

address_playerQ AlokElmtPlayerQ (Player P) {
	address_playerQ A = (address_playerQ) malloc(sizeof(ElmtPlayerQ));
	if (A == NULL) return NULL;
	InfoElmtPlayerQ(A) = P;
	NextElmtPlayerQ(A) = NULL;
	return A;
}

void DealokElmtPlayerQ(address_playerQ A) {free(A);}

void AddPlayer (PlayerQ * Q, Player P) {
	address_playerQ A = AlokElmtPlayerQ(P);
	if (A != NULL) {
		if (CountPlayer(*Q) == 0) {
			FirstPlayerQ(*Q) = A; 
			NextElmtPlayerQ(A) = A;
		} else {
			address_playerQ last = FirstPlayerQ(*Q);
			while (NextElmtPlayerQ(last) != FirstPlayerQ(*Q)) {last = NextElmtPlayerQ(last);}
			NextElmtPlayerQ(last) = A;
			NextElmtPlayerQ(A) = FirstPlayerQ(*Q);
		}
	}
}

void NextPlayer(PlayerQ *Q) {FirstPlayerQ(*Q) = NextElmtPlayerQ(FirstPlayerQ(*Q));}

void DelPlayer (PlayerQ * Q, Player *P) {
	address_playerQ Del = FirstPlayerQ(*Q);
	*P = InfoElmtPlayerQ(Del);
	if (CountPlayer(*Q) == 1) FirstPlayerQ(*Q) = NULL; else {
		FirstPlayerQ(*Q) = NextElmtPlayerQ(FirstPlayerQ(*Q));
		address_playerQ last = FirstPlayerQ(*Q);
		while (NextElmtPlayerQ(last) != Del) last = NextElmtPlayerQ(last);
		NextElmtPlayerQ(last) = FirstPlayerQ(*Q);
	}
	DealokElmtPlayerQ(Del);
}