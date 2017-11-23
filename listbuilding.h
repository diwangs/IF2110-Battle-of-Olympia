/* File : listBuilding.h */
/* ADT ListBuilding dengan Double Pointer */
/* Representasi berkait dengan address_building adalah pointer */
/* infotypebuilding adalah integer */

#ifndef listbuilding_H
#define listbuilding_H

#include "boolean.h"
#include "building.h"

#define Nil NULL

/* Definisi Type Data */
typedef Building * infotypebuilding;
typedef struct tElmtlistBuilding * address_building;
typedef struct tElmtlistBuilding {
	infotypebuilding info;
	address_building next;
	address_building prev;
} ElmtBuildingList;
typedef struct tListBuilding {
	address_building First;
	address_building Last;
} ListBuilding;

/* Definisi ListBuilding : */
/* ListBuilding kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address_building P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define InfoBuilding(P) (P)->info
#define NextBuilding(P) (P)->next
#define PrevBuilding(P) (P)->prev
#define FirstBuilding(L) ((L).First)
#define LastBuilding(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST ListBuilding KOSONG ******************/
boolean IsEmptyListBuilding (ListBuilding L);
/* Mengirim true jika ListBuilding kosong. Lihat definisi di atas. */

/****************** PEMBUATAN ListBuilding KOSONG ******************/
void CreateEmptyListBuilding (ListBuilding *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk ListBuilding kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address_building AlokasiBuilding (infotypebuilding X);
/* Mengirimkan address_building hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address_building tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void DealokasiBuilding (address_building P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address_building P */

/****************** PENCARIAN SEBUAH ELEMEN ListBuilding ******************/
address_building SearchListBuilding (ListBuilding L, infotypebuilding X);
/* Mencari apakah ada elemen ListBuilding dengan Info(P)=X */
/* Jika ada, mengirimkan address_building elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListBuilding (ListBuilding *L, infotypebuilding X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastListBuilding (ListBuilding *L, infotypebuilding X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListBuilding di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListBuilding (ListBuilding *L, infotypebuilding *X);
/* I.S. ListBuilding L tidak kosong  */
/* F.S. Elemen pertama ListBuilding dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastListBuilding (ListBuilding *L, infotypebuilding *X);
/* I.S. ListBuilding tidak kosong */
/* F.S. Elemen terakhir ListBuilding dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListBuilding (ListBuilding *L, address_building P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_building P sebagai elemen pertama */
void InsertLastListBuilding (ListBuilding *L, address_building P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterListBuilding (ListBuilding *L, address_building P, address_building Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeListBuilding (ListBuilding *L, address_building P, address_building Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListBuilding (ListBuilding *L, address_building *P);
/* I.S. ListBuilding tidak kosong */
/* F.S. P adalah alamat elemen pertama ListBuilding sebelum penghapusan */
/*      Elemen ListBuilding berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastListBuilding (ListBuilding *L, address_building *P);
/* I.S. ListBuilding tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListBuilding sebelum penghapusan  */
/*      Elemen ListBuilding berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPListBuilding (ListBuilding *L, infotypebuilding X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListBuilding beraddress_building P, dengan Info(P)=X  */
/* maka P dihapus dari ListBuilding dan didealokasi */
/* Jika tidak ada elemen ListBuilding dengan Info(P)=X, maka ListBuilding tetap */
/* ListBuilding mungkin menjadi kosong karena penghapusan */
void DelAfterListBuilding (ListBuilding *L, address_building *Pdel, address_building Prec);
/* I.S. ListBuilding tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListBuilding yang dihapus  */
void DelBeforeListBuilding (ListBuilding *L, address_building *Pdel, address_building Succ);
/* I.S. ListBuilding tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen ListBuilding yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListBuilding ******************/

#endif
