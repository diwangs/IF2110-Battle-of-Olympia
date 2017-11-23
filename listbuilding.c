#include "listbuilding.h"
#include <stdio.h>
#include <stdlib.h>
#include "peta.h"

/* PROTOTYPE */
/****************** TEST ListBuilding KOSONG ******************/
boolean IsEmptyListBuilding (ListBuilding L)
/* Mengirim true jika ListBuilding kosong. Lihat definisi di atas. */
{
	return FirstBuilding(L) == Nil && LastBuilding(L) == Nil;
}

/****************** PEMBUATAN ListBuilding KOSONG ******************/
void CreateEmptyListBuilding (ListBuilding *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk ListBuilding kosong. Lihat definisi di atas. */
{
	FirstBuilding(*L) = Nil;
	LastBuilding(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address_building AlokasiListBuilding (infotypebuilding X)
/* Mengirimkan address_building hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_building tidak Nil. */
/* Misalnya: menghasilkan P, maka InfoBuilding(P)=X, NextBuilding(P)=Nil, PrevBuilding(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address_building P;
	P = malloc(sizeof(ElmtBuildingList));

	if (P != Nil) {
		InfoBuilding(P) = X;
		NextBuilding(P) = Nil;
		PrevBuilding(P) = Nil;
	}

	return P;
}
void DealokasiListBuilding (address_building P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_building P*/
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN ListBuilding ******************/
address_building SearchListBuilding (ListBuilding L, infotypebuilding X)
/* Mencari apakah ada elemen ListBuilding dengan InfoBuilding(P)=X */
/* Jika ada, mengirimkan address_building elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmptyListBuilding(L)) {
		return Nil;
	}

	address_building P;
	P = FirstBuilding(L);

	while (NextBuilding(P) != Nil) {
		if (InfoBuilding(P) == X) {
			return P;
		}
		P = NextBuilding(P);
	}

	if (InfoBuilding(P) == X) {
		return P;
	}

	return Nil;
}

/****************** PRIMITIF BERDASARKAN NilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListBuilding (ListBuilding *L, infotypebuilding X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nilai X jika alokasi berhasil */
{
	address_building P, P2;
	P = AlokasiListBuilding(X);

	if (IsEmptyListBuilding(*L)) {
		FirstBuilding(*L) = P;
		LastBuilding(*L) = P;
		return;
	}

	P2 = FirstBuilding(*L);
	FirstBuilding(*L) = P;
	NextBuilding(P) = P2;
	PrevBuilding(P2) = P;
}
void InsVLastListBuilding (ListBuilding *L, infotypebuilding X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListBuilding di akhir: elemen terakhir yang baru */
/* berNilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if (IsEmptyListBuilding(*L)) {
		InsVFirstListBuilding(L, X);
		return;
	}

	address_building P, P2;
	P = AlokasiListBuilding(X);
	P2 = LastBuilding(*L);
	NextBuilding(P2) = P;
	PrevBuilding(P) = P2;
	LastBuilding(*L) = P;
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListBuilding (ListBuilding *L, infotypebuilding *X)
/* I.S. ListBuilding L tidak kosong  */
/* F.S. Elemen pertama ListBuilding dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_building P;
	P = FirstBuilding(*L);
	*X = InfoBuilding(P);

	FirstBuilding(*L) = NextBuilding(P);

	if (NextBuilding(P) != Nil) {
		PrevBuilding(FirstBuilding(*L)) = Nil;
	} else {
		LastBuilding(*L) = Nil;
	}

	DealokasiListBuilding(P);
}
void DelVLastListBuilding (ListBuilding *L, infotypebuilding *X)
/* I.S. ListBuilding tidak kosong */
/* F.S. Elemen terakhir ListBuilding dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_building P;
	P = LastBuilding(*L);
	*X = InfoBuilding(P);
	LastBuilding(*L) = PrevBuilding(P);
	if (PrevBuilding(P) != Nil) {
		NextBuilding(PrevBuilding(P)) = Nil;
	} else {
		FirstBuilding(*L) = Nil;
	}

	DealokasiListBuilding(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListBuilding (ListBuilding *L, address_building P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_building P sebagai elemen pertama */
{
	if (IsEmptyListBuilding(*L)) {
		FirstBuilding(*L) = P;
		LastBuilding(*L) = P;
		return;
	}

	address_building P2;
	P2 = FirstBuilding(*L);
	FirstBuilding(*L) = P;
	NextBuilding(P) = P2;
	PrevBuilding(P2) = P;
}
void InsertLastListBuilding (ListBuilding *L, address_building P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyListBuilding(*L)) {
		FirstBuilding(*L) = P;
		LastBuilding(*L) = P;
		return;
	}

	address_building P2;
	P2 = LastBuilding(*L);
	LastBuilding(*L) = P;
	NextBuilding(P2) = P;
	PrevBuilding(P) = P2;
}
void InsertAfterListBuilding (ListBuilding *L, address_building P, address_building Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	address_building P2;
	P2 = NextBuilding(Prec);
	NextBuilding(Prec) = P;
	PrevBuilding(P) = Prec;
	NextBuilding(P) = P2;
	if (P2 != Nil) {
		PrevBuilding(P2) = P;
	} else {
		LastBuilding(*L) = (P);
	}
}
void InsertBeforeListBuilding (ListBuilding *L, address_building P, address_building Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	address_building P2;
	P2 = PrevBuilding(Succ);
	NextBuilding(P) = Succ;
	PrevBuilding(Succ) = P;
	PrevBuilding(P) = P2;
	if (P2 != Nil) {
		NextBuilding(P2) = P;
	} else {
		FirstBuilding(*L) = P;
	}

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListBuilding (ListBuilding *L, address_building *P)
/* I.S. ListBuilding tidak kosong */
/* F.S. P adalah alamat elemen pertama ListBuilding sebelum penghapusan */
/*      Elemen ListBuilding berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = FirstBuilding(*L);
	if (NextBuilding(*P) != Nil) {
		PrevBuilding(NextBuilding(*P)) = Nil;
	} else {
		LastBuilding(*L) = Nil;
	}
	FirstBuilding(*L) = NextBuilding(*P);
}
void DelLastListBuilding (ListBuilding *L, address_building *P)
/* I.S. ListBuilding tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListBuilding sebelum penghapusan  */
/*      Elemen ListBuilding berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = LastBuilding(*L);
	if (PrevBuilding(*P) != Nil) {
		NextBuilding(PrevBuilding(*P)) = Nil;
	} else {
		FirstBuilding(*L) = Nil;
	}
	LastBuilding(*L) = PrevBuilding(*P);
}
void DelPListBuilding (ListBuilding *L, infotypebuilding X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListBuilding beraddress_building P, dengan InfoBuilding(P)=X  */
/* maka P dihapus dari ListBuilding dan didealokasi */
/* Jika tidak ada elemen ListBuilding dengan InfoBuilding(P)=X, maka ListBuilding tetap */
/* ListBuilding mungkin menjadi kosong karena penghapusan */
{
	address_building P;
	P = SearchListBuilding(*L, X);

	if (P == Nil) {
		return;
	}

	if (PrevBuilding(P) == NextBuilding(P)) {
		FirstBuilding(*L) = Nil;
		LastBuilding(*L) = Nil;
		return;
	}

	if (PrevBuilding(P) == Nil && NextBuilding(P) != Nil) {
		PrevBuilding(NextBuilding(P)) = Nil;
		FirstBuilding(*L) = NextBuilding(P);
		return;
	}

	if (PrevBuilding(P) != Nil && NextBuilding(P) == Nil) {
		NextBuilding(PrevBuilding(P)) = Nil;
		LastBuilding(*L) = PrevBuilding(P);
		return;
	}

	NextBuilding(PrevBuilding(P)) = NextBuilding(P);
	PrevBuilding(NextBuilding(P)) = PrevBuilding(P);
}
void DelAfterListBuilding (ListBuilding *L, address_building *Pdel, address_building Prec)
/* I.S. ListBuilding tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextBuilding(Prec): */
/*      Pdel adalah alamat elemen ListBuilding yang dihapus  */
{
	*Pdel = NextBuilding(Prec);
	NextBuilding(Prec) = NextBuilding(NextBuilding(Prec));
	if (NextBuilding(Prec) != Nil) {
		PrevBuilding(NextBuilding(Prec)) = Prec;
	} else {
		LastBuilding(*L) = Prec;
	}
}
void DelBeforeListBuilding (ListBuilding *L, address_building *Pdel, address_building Succ)
/* I.S. ListBuilding tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevBuilding(Succ): */
/*      Pdel adalah alamat elemen ListBuilding yang dihapus  */
{
	*Pdel = PrevBuilding(Succ);
	PrevBuilding(Succ) = PrevBuilding(PrevBuilding(Succ));
	if (PrevBuilding(Succ) != Nil) {
		NextBuilding(PrevBuilding(Succ)) = Succ;
	} else {
		FirstBuilding(*L) = Succ;
	}
}

boolean IsBuildingTypeExist (ListBuilding L, char type)
{
	address_building P = FirstBuilding(L);

	while (P != Nil) {
		if (InfoBuilding(P)->type == type) {
			return true;
		}
	}

	return false;
}

void PrintListBuilding(ListBuilding L)
/* Print seluruh Building beserta keterangannya */
{
	int count = 1;
	address_building P;
	Point P1;

	P = FirstBuilding(L);

	if (P == Nil) {
		printf("You don't have any building.\n");
		return;
	}

	while (P != Nil) {
		P1 = GetBuildingCoordinate(*(InfoBuilding(P)));
		printf("%d. %c ", count, GetBuildingType(*(InfoBuilding(P))));
		TulisPOINT(P1);
		if (IsPetakOccupied(Absis(P1), Ordinat(P1))) {
			printf(" | Occupied");
		}
		printf("\n");
		count++;
		P = NextBuilding(P);
	}
}

void PrintListBuildingByType(ListBuilding L, char type)
/* Print seluruh Building beserta keterangannya */
{
	int count = 1;
	address_building P;
	Point P1;

	P = FirstBuilding(L);

	if (P == Nil) {
		printf("You don't have any building.\n");
		return;
	}

	while (P != Nil) {
		P1 = GetBuildingCoordinate(*(InfoBuilding(P)));
		if (InfoBuilding(P)->type == type) {
			printf("%d. %c ", count, GetBuildingType(*(InfoBuilding(P))));
			TulisPOINT(P1);
			if (IsPetakOccupied(Absis(P1), Ordinat(P1))) {
				printf(" | Occupied");
			}
			printf("\n");
		}
		count++;
		P = NextBuilding(P);
	}
}