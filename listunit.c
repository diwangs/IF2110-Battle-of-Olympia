#include "listunit.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
	return First(L) == Nil && Last(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
	First(*L) = Nil;
	Last(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address P;
	P = malloc(sizeof(ElmtList));

	if (P != Nil) {
		Info(P) = X;
		Next(P) = Nil;
		Prev(P) = Nil;
	}

	return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmpty(L)) {
		return Nil;
	}

	address P;
	P = First(L);

	while (Next(P) != Nil) {
		if (IsEQUnit(Info(P), X)) {
			return P;
		}
		P = Next(P);
	}

	if (IsEQUnit(Info(P), X)) {
		return P;
	}

	return Nil;
}

/****************** PRIMITIF BERDASARKAN NilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nilai X jika alokasi berhasil */
{
	address P, P2;
	P = Alokasi(X);

	if (IsEmpty(*L)) {
		First(*L) = P;
		Last(*L) = P;
		return;
	}

	P2 = First(*L);
	First(*L) = P;
	Next(P) = P2;
	Prev(P2) = P;
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* berNilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if (IsEmpty(*L)) {
		InsVFirst(L, X);
		return;
	}

	address P, P2;
	P = Alokasi(X);
	P2 = Last(*L);
	Next(P2) = P;
	Prev(P) = P2;
	Last(*L) = P;
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address P;
	P = First(*L);
	*X = Info(P);

	First(*L) = Next(P);

	if (Next(P) != Nil) {
		Prev(First(*L)) = Nil;
	} else {
		Last(*L) = Nil;
	}

	Dealokasi(P);
}
void DelVLast (List *L, infotype *X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address P;
	P = Last(*L);
	*X = Info(P);
	Last(*L) = Prev(P);
	if (Prev(P) != Nil) {
		Next(Prev(P)) = Nil;
	} else {
		First(*L) = Nil;
	}

	Dealokasi(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
	if (IsEmpty(*L)) {
		First(*L) = P;
		Last(*L) = P;
		return;
	}

	address P2;
	P2 = First(*L);
	First(*L) = P;
	Next(P) = P2;
	Prev(P2) = P;
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmpty(*L)) {
		First(*L) = P;
		Last(*L) = P;
		return;
	}

	address P2;
	P2 = Last(*L);
	Last(*L) = P;
	Next(P2) = P;
	Prev(P) = P2;
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	address P2;
	P2 = Next(Prec);
	Next(Prec) = P;
	Prev(P) = Prec;
	Next(P) = P2;
	if (P2 != Nil) {
		Prev(P2) = P;
	} else {
		Last(*L) = (P);
	}
}
void InsertBefore (List *L, address P, address Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	address P2;
	P2 = Prev(Succ);
	Next(P) = Succ;
	Prev(Succ) = P;
	Prev(P) = P2;
	if (P2 != Nil) {
		Next(P2) = P;
	} else {
		First(*L) = P;
	}

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = First(*L);
	if (Next(*P) != Nil) {
		Prev(Next(*P)) = Nil;
	} else {
		Last(*L) = Nil;
	}
	First(*L) = Next(*P);
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = Last(*L);
	if (Prev(*P) != Nil) {
		Next(Prev(*P)) = Nil;
	} else {
		First(*L) = Nil;
	}
	Last(*L) = Prev(*P);
}
void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	address P;
	P = Search(*L, X);

	if (P == Nil) {
		return;
	}

	if (Prev(P) == Next(P)) {
		First(*L) = Nil;
		Last(*L) = Nil;
		return;
	}

	if (Prev(P) == Nil && Next(P) != Nil) {
		Prev(Next(P)) = Nil;
		First(*L) = Next(P);
		return;
	}

	if (Prev(P) != Nil && Next(P) == Nil) {
		Next(Prev(P)) = Nil;
		Last(*L) = Prev(P);
		return;
	}

	Next(Prev(P)) = Next(P);
	Prev(Next(P)) = Prev(P);
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(Next(Prec));
	if (Next(Prec) != Nil) {
		Prev(Next(Prec)) = Prec;
	} else {
		Last(*L) = Prec;
	}
}
void DelBefore (List *L, address *Pdel, address Succ)
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
	*Pdel = Prev(Succ);
	Prev(Succ) = Prev(Prev(Succ));
	if (Prev(Succ) != Nil) {
		Next(Prev(Succ)) = Succ;
	} else {
		First(*L) = Succ;
	}
}
