/* File : listVillage.h */
/* ADT ListVillage dengan Double Pointer */
/* Representasi berkait dengan address_village adalah pointer */
/* infotypevillage adalah integer */

#ifndef listvillage_H
#define listvillage_H

#include "boolean.h"
#include "village.h"

#define Nil NULL

/* Definisi Type Data */
typedef Village * infotypevillage;
typedef struct tElmtlistVillage * address_village;
typedef struct tElmtlistVillage {
	infotypevillage info;
	address_village next;
	address_village prev;
} ElmtVillageList;
typedef struct tListVillage {
	address_village First;
	address_village Last;
} ListVillage;

/* Definisi ListVillage : */
/* ListVillage kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address_village P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define InfoVillage(P) (P)->info
#define NextVillage(P) (P)->next
#define PrevVillage(P) (P)->prev
#define FirstVillage(L) ((L).First)
#define LastVillage(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST ListVillage KOSONG ******************/
boolean IsEmptyListVillage (ListVillage L);
/* Mengirim true jika ListVillage kosong. Lihat definisi di atas. */

/****************** PEMBUATAN ListVillage KOSONG ******************/
void CreateEmptyListVillage (ListVillage *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk ListVillage kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address_village AlokasiVillage (infotypevillage X);
/* Mengirimkan address_village hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_village tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiVillage (address_village P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_village P */

/****************** PENCARIAN SEBUAH ELEMEN ListVillage ******************/
address_village SearchListVillage (ListVillage L, infotypevillage X);
/* Mencari apakah ada elemen ListVillage dengan Info(P)=X */
/* Jika ada, mengirimkan address_village elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListVillage (ListVillage *L, infotypevillage X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastListVillage (ListVillage *L, infotypevillage X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListVillage di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListVillage (ListVillage *L, infotypevillage *X);
/* I.S. ListVillage L tidak kosong  */
/* F.S. Elemen pertama ListVillage dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastListVillage (ListVillage *L, infotypevillage *X);
/* I.S. ListVillage tidak kosong */
/* F.S. Elemen terakhir ListVillage dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListVillage (ListVillage *L, address_village P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_village P sebagai elemen pertama */
void InsertLastListVillage (ListVillage *L, address_village P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterListVillage (ListVillage *L, address_village P, address_village Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeListVillage (ListVillage *L, address_village P, address_village Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListVillage (ListVillage *L, address_village *P);
/* I.S. ListVillage tidak kosong */
/* F.S. P adalah alamat elemen pertama ListVillage sebelum penghapusan */
/*      Elemen ListVillage berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastListVillage (ListVillage *L, address_village *P);
/* I.S. ListVillage tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListVillage sebelum penghapusan  */
/*      Elemen ListVillage berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPListVillage (ListVillage *L, infotypevillage X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListVillage beraddress_village P, dengan Info(P)=X  */
/* maka P dihapus dari ListVillage dan didealokasi */
/* Jika tidak ada elemen ListVillage dengan Info(P)=X, maka ListVillage tetap */
/* ListVillage mungkin menjadi kosong karena penghapusan */
void DelAfterListVillage (ListVillage *L, address_village *Pdel, address_village Prec);
/* I.S. ListVillage tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListVillage yang dihapus  */
void DelBeforeListVillage (ListVillage *L, address_village *Pdel, address_village Succ);
/* I.S. ListVillage tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen ListVillage yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListVillage ******************/

#endif
