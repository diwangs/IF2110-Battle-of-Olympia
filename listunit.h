/* File : listunit.h */
/* ADT ListUnit dengan Double Pointer */
/* Representasi berkait dengan address_unit adalah pointer */
/* infotypeunit adalah integer */

#ifndef listunit_H
#define listunit_H

#include "boolean.h"
#include "unit.h"
#include <stdio.h>

#define Nil NULL

/* Definisi Type Data */
typedef Unit * infotypeunit;
typedef struct tElmtListUnit *address_unit;
typedef struct tElmtListUnit {
	infotypeunit info;
	address_unit next;
	address_unit prev;
} ElmtUnitList;
typedef struct tListUnit {
	address_unit First;
	address_unit Last;
} ListUnit;

/* Definisi ListUnit : */
/* ListUnit kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address_unit P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define InfoUnit(P) (P)->info
#define NextUnit(P) (P)->next
#define PrevUnit(P) (P)->prev
#define FirstUnit(L) ((L).First)
#define LastUnit(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST ListUnit KOSONG ******************/
boolean IsEmptyListUnit (ListUnit L);
/* Mengirim true jika ListUnit kosong. Lihat definisi di atas. */

/****************** PEMBUATAN ListUnit KOSONG ******************/
void CreateEmptyListUnit (ListUnit *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk ListUnit kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address_unit AlokasiListUnit (infotypeunit X);
/* Mengirimkan address_unit hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_unit tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiListUnit (address_unit P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_unit P */

/****************** PENCARIAN SEBUAH ELEMEN ListUnit ******************/
address_unit SearchListUnit (ListUnit L, infotypeunit X);
/* Mencari apakah ada elemen ListUnit dengan Info(P)=X */
/* Jika ada, mengirimkan address_unit elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListUnit (ListUnit *L, infotypeunit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastListUnit (ListUnit *L, infotypeunit X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListUnit di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListUnit (ListUnit *L, infotypeunit *X);
/* I.S. ListUnit L tidak kosong  */
/* F.S. Elemen pertama ListUnit dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastListUnit (ListUnit *L, infotypeunit *X);
/* I.S. ListUnit tidak kosong */
/* F.S. Elemen terakhir ListUnit dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListUnit (ListUnit *L, address_unit P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_unit P sebagai elemen pertama */
void InsertLastListUnit (ListUnit *L, address_unit P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterListUnit (ListUnit *L, address_unit P, address_unit Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeListUnit (ListUnit *L, address_unit P, address_unit Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListUnit (ListUnit *L, address_unit *P);
/* I.S. ListUnit tidak kosong */
/* F.S. P adalah alamat elemen pertama ListUnit sebelum penghapusan */
/*      Elemen ListUnit berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastListUnit (ListUnit *L, address_unit *P);
/* I.S. ListUnit tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListUnit sebelum penghapusan  */
/*      Elemen ListUnit berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPListUnit (ListUnit *L, infotypeunit X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListUnit beraddress_unit P, dengan Info(P)=X  */
/* maka P dihapus dari ListUnit dan didealokasi */
/* Jika tidak ada elemen ListUnit dengan Info(P)=X, maka ListUnit tetap */
/* ListUnit mungkin menjadi kosong karena penghapusan */
void DelAfterListUnit (ListUnit *L, address_unit *Pdel, address_unit Prec);
/* I.S. ListUnit tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListUnit yang dihapus  */
void DelBeforeListUnit (ListUnit *L, address_unit *Pdel, address_unit Succ);
/* I.S. ListUnit tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen ListUnit yang dihapus  */
void PrintListUnit(ListUnit L);
/* Print seluruh Unit beserta keterangannya */

boolean IsNthUnitExist(ListUnit L, int pos);
Unit * SelectNthUnit(ListUnit L, int pos);

/****************** PROSES SEMUA ELEMEN ListUnit ******************/

#endif
