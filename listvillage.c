#include "listvillage.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST ListVillage KOSONG ******************/
boolean IsEmptyListVillage (ListVillage L)
/* Mengirim true jika ListVillage kosong. Lihat definisi di atas. */
{
	return FirstVillage(L) == Nil && LastVillage(L) == Nil;
}

/****************** PEMBUATAN ListVillage KOSONG ******************/
void CreateEmptyListVillage (ListVillage *L)
/* I.S. L sembarang  */
/* F.S. Terbentuk ListVillage kosong. Lihat definisi di atas. */
{
	FirstVillage(*L) = Nil;
	LastVillage(*L) = Nil;
}
/****************** Manajemen Memori ******************/
address_village AlokasiListVillage (infotypevillage X)
/* Mengirimkan address_village hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_village tidak Nil. */
/* Misalnya: menghasilkan P, maka InfoVillage(P)=X, NextVillage(P)=Nil, PrevVillage(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
	address_village P;
	P = malloc(sizeof(ElmtVillageList));

	if (P != Nil) {
		InfoVillage(P) = X;
		NextVillage(P) = Nil;
		PrevVillage(P) = Nil;
	}

	return P;
}
void DealokasiListVillage (address_village P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_village P*/
{
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN ListVillage ******************/
address_village SearchListVillage (ListVillage L, infotypevillage X)
/* Mencari apakah ada elemen ListVillage dengan InfoVillage(P)=X */
/* Jika ada, mengirimkan address_village elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
	if (IsEmptyListVillage(L)) {
		return Nil;
	}

	address_village P;
	P = FirstVillage(L);

	while (NextVillage(P) != Nil) {
		if (InfoVillage(P) == X) {
			return P;
		}
		P = NextVillage(P);
	}

	if (InfoVillage(P) == X) {
		return P;
	}

	return Nil;
}

/****************** PRIMITIF BERDASARKAN NilAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListVillage (ListVillage *L, infotypevillage X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan Nilai X jika alokasi berhasil */
{
	address_village P, P2;
	P = AlokasiListVillage(X);

	if (IsEmptyListVillage(*L)) {
		FirstVillage(*L) = P;
		LastVillage(*L) = P;
		return;
	}

	P2 = FirstVillage(*L);
	FirstVillage(*L) = P;
	NextVillage(P) = P2;
	PrevVillage(P2) = P;
}
void InsVLastListVillage (ListVillage *L, infotypevillage X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListVillage di akhir: elemen terakhir yang baru */
/* berNilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
	if (IsEmptyListVillage(*L)) {
		InsVFirstListVillage(L, X);
		return;
	}

	address_village P, P2;
	P = AlokasiListVillage(X);
	P2 = LastVillage(*L);
	NextVillage(P2) = P;
	PrevVillage(P) = P2;
	LastVillage(*L) = P;
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListVillage (ListVillage *L, infotypevillage *X)
/* I.S. ListVillage L tidak kosong  */
/* F.S. Elemen pertama ListVillage dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
	address_village P;
	P = FirstVillage(*L);
	*X = InfoVillage(P);

	FirstVillage(*L) = NextVillage(P);

	if (NextVillage(P) != Nil) {
		PrevVillage(FirstVillage(*L)) = Nil;
	} else {
		LastVillage(*L) = Nil;
	}

	DealokasiListVillage(P);
}
void DelVLastListVillage (ListVillage *L, infotypevillage *X)
/* I.S. ListVillage tidak kosong */
/* F.S. Elemen terakhir ListVillage dihapus: Nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
	address_village P;
	P = LastVillage(*L);
	*X = InfoVillage(P);
	LastVillage(*L) = PrevVillage(P);
	if (PrevVillage(P) != Nil) {
		NextVillage(PrevVillage(P)) = Nil;
	} else {
		FirstVillage(*L) = Nil;
	}

	DealokasiListVillage(P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListVillage (ListVillage *L, address_village P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_village P sebagai elemen pertama */
{
	if (IsEmptyListVillage(*L)) {
		FirstVillage(*L) = P;
		LastVillage(*L) = P;
		return;
	}

	address_village P2;
	P2 = FirstVillage(*L);
	FirstVillage(*L) = P;
	NextVillage(P) = P2;
	PrevVillage(P2) = P;
}
void InsertLastListVillage (ListVillage *L, address_village P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	if (IsEmptyListVillage(*L)) {
		FirstVillage(*L) = P;
		LastVillage(*L) = P;
		return;
	}

	address_village P2;
	P2 = LastVillage(*L);
	LastVillage(*L) = P;
	NextVillage(P2) = P;
	PrevVillage(P) = P2;
}
void InsertAfterListVillage (ListVillage *L, address_village P, address_village Prec)
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	address_village P2;
	P2 = NextVillage(Prec);
	NextVillage(Prec) = P;
	PrevVillage(P) = Prec;
	NextVillage(P) = P2;
	if (P2 != Nil) {
		PrevVillage(P2) = P;
	} else {
		LastVillage(*L) = (P);
	}
}
void InsertBeforeListVillage (ListVillage *L, address_village P, address_village Succ)
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
{
	address_village P2;
	P2 = PrevVillage(Succ);
	NextVillage(P) = Succ;
	PrevVillage(Succ) = P;
	PrevVillage(P) = P2;
	if (P2 != Nil) {
		NextVillage(P2) = P;
	} else {
		FirstVillage(*L) = P;
	}

}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListVillage (ListVillage *L, address_village *P)
/* I.S. ListVillage tidak kosong */
/* F.S. P adalah alamat elemen pertama ListVillage sebelum penghapusan */
/*      Elemen ListVillage berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
	*P = FirstVillage(*L);
	if (NextVillage(*P) != Nil) {
		PrevVillage(NextVillage(*P)) = Nil;
	} else {
		LastVillage(*L) = Nil;
	}
	FirstVillage(*L) = NextVillage(*P);
}
void DelLastListVillage (ListVillage *L, address_village *P)
/* I.S. ListVillage tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListVillage sebelum penghapusan  */
/*      Elemen ListVillage berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
{
	*P = LastVillage(*L);
	if (PrevVillage(*P) != Nil) {
		NextVillage(PrevVillage(*P)) = Nil;
	} else {
		FirstVillage(*L) = Nil;
	}
	LastVillage(*L) = PrevVillage(*P);
}
void DelPListVillage (ListVillage *L, infotypevillage X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListVillage beraddress_village P, dengan InfoVillage(P)=X  */
/* maka P dihapus dari ListVillage dan didealokasi */
/* Jika tidak ada elemen ListVillage dengan InfoVillage(P)=X, maka ListVillage tetap */
/* ListVillage mungkin menjadi kosong karena penghapusan */
{
	address_village P;
	P = SearchListVillage(*L, X);

	if (P == Nil) {
		return;
	}

	if (PrevVillage(P) == NextVillage(P)) {
		FirstVillage(*L) = Nil;
		LastVillage(*L) = Nil;
		return;
	}

	if (PrevVillage(P) == Nil && NextVillage(P) != Nil) {
		PrevVillage(NextVillage(P)) = Nil;
		FirstVillage(*L) = NextVillage(P);
		return;
	}

	if (PrevVillage(P) != Nil && NextVillage(P) == Nil) {
		NextVillage(PrevVillage(P)) = Nil;
		LastVillage(*L) = PrevVillage(P);
		return;
	}

	NextVillage(PrevVillage(P)) = NextVillage(P);
	PrevVillage(NextVillage(P)) = PrevVillage(P);
}
void DelAfterListVillage (ListVillage *L, address_village *Pdel, address_village Prec)
/* I.S. ListVillage tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus NextVillage(Prec): */
/*      Pdel adalah alamat elemen ListVillage yang dihapus  */
{
	*Pdel = NextVillage(Prec);
	NextVillage(Prec) = NextVillage(NextVillage(Prec));
	if (NextVillage(Prec) != Nil) {
		PrevVillage(NextVillage(Prec)) = Prec;
	} else {
		LastVillage(*L) = Prec;
	}
}
void DelBeforeListVillage (ListVillage *L, address_village *Pdel, address_village Succ)
/* I.S. ListVillage tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus PrevVillage(Succ): */
/*      Pdel adalah alamat elemen ListVillage yang dihapus  */
{
	*Pdel = PrevVillage(Succ);
	PrevVillage(Succ) = PrevVillage(PrevVillage(Succ));
	if (PrevVillage(Succ) != Nil) {
		NextVillage(PrevVillage(Succ)) = Succ;
	} else {
		FirstVillage(*L) = Succ;
	}
}
