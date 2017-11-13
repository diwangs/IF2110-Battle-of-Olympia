#include "listunit.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListUnit (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return FirstUnit(L) == Nil && LastUnit(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListUnit (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	FirstUnit(*L) = Nil;
	LastUnit(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address_unit AlokasiListUnit (infotypeunit X)
/* Mengirimkan address_unit hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_unit tidak Nil. */
/* Misalnya: menghasilkan P, maka InfoUnit(P)=X, NextUnit(P)=Nil, PrevUnit(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address_unit P;
	P = malloc(sizeof(ElmtUnitList));

	if (P != Nil) {
		InfoUnit(P) = X;
		NextUnit(P) = Nil;
		PrevUnit(P) = Nil;
	}

	return P;
}
void DealokasiListUnit (address_unit P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_unit P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address_unit SearchListUnit (List L, infotypeunit X)
/* Mencari apakah ada elemen list dengan InfoUnit(P)=X */
/* Jika ada, mengirimkan address_unit elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmptyListUnit(L)) {
		return Nil;
	}

	address_unit P;
	P = FirstUnit(L);

	while (NextUnit(P) != Nil) {
		if (IsEQUnit(InfoUnit(P), X)) {
			return P;
		}
		P = NextUnit(P);
	}

	if (IsEQUnit(InfoUnit(P), X)) {
		return P;
	}

	return Nil;
}

/****************** PRIMITIF BERDASARKAN NilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListUnit (List *L, infotypeunit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nilai X jika alokasi berhasil */
{
	address_unit P, P2;
	P = AlokasiListUnit(X);

	if (IsEmptyListUnit(*L)) {
		FirstUnit(*L) = P;
		LastUnit(*L) = P;
		return;
	}

	P2 = FirstUnit(*L);
	FirstUnit(*L) = P;
	NextUnit(P) = P2;
	PrevUnit(P2) = P;
}
void InsVLastListUnit (List *L, infotypeunit X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if (IsEmptyListUnit(*L)) {
		InsVFirstListUnit(L, X);
		return;
	}

	address_unit P, P2;
	P = AlokasiListUnit(X);
	P2 = LastUnit(*L);
	NextUnit(P2) = P;
	PrevUnit(P) = P2;
	LastUnit(*L) = P;
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListUnit (List *L, infotypeunit *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_unit P;
	P = FirstUnit(*L);
	*X = InfoUnit(P);

	FirstUnit(*L) = NextUnit(P);

	if (NextUnit(P) != Nil) {
		PrevUnit(FirstUnit(*L)) = Nil;
	} else {
		LastUnit(*L) = Nil;
	}

	DealokasiListUnit(P);
}
void DelVLastListUnit (List *L, infotypeunit *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_unit P;
	P = LastUnit(*L);
	*X = InfoUnit(P);
	LastUnit(*L) = PrevUnit(P);
	if (PrevUnit(P) != Nil) {
		NextUnit(PrevUnit(P)) = Nil;
	} else {
		FirstUnit(*L) = Nil;
	}

	DealokasiListUnit(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListUnit (List *L, address_unit P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_unit P sebagai elemen pertama */
{
	if (IsEmptyListUnit(*L)) {
		FirstUnit(*L) = P;
		LastUnit(*L) = P;
		return;
	}

	address_unit P2;
	P2 = FirstUnit(*L);
	FirstUnit(*L) = P;
	NextUnit(P) = P2;
	PrevUnit(P2) = P;
}
void InsertLastListUnit (List *L, address_unit P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyListUnit(*L)) {
		FirstUnit(*L) = P;
		LastUnit(*L) = P;
		return;
	}

	address_unit P2;
	P2 = LastUnit(*L);
	LastUnit(*L) = P;
	NextUnit(P2) = P;
	PrevUnit(P) = P2;
}
void InsertAfterListUnit (List *L, address_unit P, address_unit Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	address_unit P2;
	P2 = NextUnit(Prec);
	NextUnit(Prec) = P;
	PrevUnit(P) = Prec;
	NextUnit(P) = P2;
	if (P2 != Nil) {
		PrevUnit(P2) = P;
	} else {
		LastUnit(*L) = (P);
	}
}
void InsertBeforeListUnit (List *L, address_unit P, address_unit Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	address_unit P2;
	P2 = PrevUnit(Succ);
	NextUnit(P) = Succ;
	PrevUnit(Succ) = P;
	PrevUnit(P) = P2;
	if (P2 != Nil) {
		NextUnit(P2) = P;
	} else {
		FirstUnit(*L) = P;
	}

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListUnit (List *L, address_unit *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = FirstUnit(*L);
	if (NextUnit(*P) != Nil) {
		PrevUnit(NextUnit(*P)) = Nil;
	} else {
		LastUnit(*L) = Nil;
	}
	FirstUnit(*L) = NextUnit(*P);
}
void DelLastListUnit (List *L, address_unit *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = LastUnit(*L);
	if (PrevUnit(*P) != Nil) {
		NextUnit(PrevUnit(*P)) = Nil;
	} else {
		FirstUnit(*L) = Nil;
	}
	LastUnit(*L) = PrevUnit(*P);
}
void DelPListUnit (List *L, infotypeunit X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress_unit P, dengan InfoUnit(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan InfoUnit(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address_unit P;
	P = SearchListUnit(*L, X);

	if (P == Nil) {
		return;
	}

	if (PrevUnit(P) == NextUnit(P)) {
		FirstUnit(*L) = Nil;
		LastUnit(*L) = Nil;
		return;
	}

	if (PrevUnit(P) == Nil && NextUnit(P) != Nil) {
		PrevUnit(NextUnit(P)) = Nil;
		FirstUnit(*L) = NextUnit(P);
		return;
	}

	if (PrevUnit(P) != Nil && NextUnit(P) == Nil) {
		NextUnit(PrevUnit(P)) = Nil;
		LastUnit(*L) = PrevUnit(P);
		return;
	}

	NextUnit(PrevUnit(P)) = NextUnit(P);
	PrevUnit(NextUnit(P)) = PrevUnit(P);
}
void DelAfterListUnit (List *L, address_unit *Pdel, address_unit Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextUnit(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = NextUnit(Prec);
	NextUnit(Prec) = NextUnit(NextUnit(Prec));
	if (NextUnit(Prec) != Nil) {
		PrevUnit(NextUnit(Prec)) = Prec;
	} else {
		LastUnit(*L) = Prec;
	}
}
void DelBeforeListUnit (List *L, address_unit *Pdel, address_unit Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevUnit(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = PrevUnit(Succ);
	PrevUnit(Succ) = PrevUnit(PrevUnit(Succ));
	if (PrevUnit(Succ) != Nil) {
		NextUnit(PrevUnit(Succ)) = Succ;
	} else {
		FirstUnit(*L) = Succ;
	}
}
