/* File : listVillage.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address_village adalah pointer */
/* infotypevillage adalah integer */

#ifndef listvillage_H
#define listvillage_H

#include "boolean.h"
#include "village.h"

#define Nil NULL

/* Definisi Type Data */
typedef Village infotypevillage;
typedef struct tElmtlistVillage * address_village;
typedef struct tElmtlistVillage { 
	infotypevillage info;
	address_village next;
	address_village prev;
} ElmtVillageList;
typedef struct {
	address_village First;
	address_village Last;
} List;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address_village P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define InfoVillage(P) (P)->info
#define NextVillage(P) (P)->next
#define PrevVillage(P) (P)->prev
#define FirstVillage(L) ((L).First)
#define LastVillage(L) ((L).Last)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyListVillage (List L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmptyListVillage (List *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address_village SearchListVillage (List L, infotypevillage X);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address_village elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstListVillage (List *L, infotypevillage X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastListVillage (List *L, infotypevillage X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstListVillage (List *L, infotypevillage *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastListVillage (List *L, infotypevillage *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstListVillage (List *L, address_village P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address_village P sebagai elemen pertama */
void InsertLastListVillage (List *L, address_village P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterListVillage (List *L, address_village P, address_village Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeListVillage (List *L, address_village P, address_village Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstListVillage (List *L, address_village *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastListVillage (List *L, address_village *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPListVillage (List *L, infotypevillage X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress_village P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfterListVillage (List *L, address_village *Pdel, address_village Prec);
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeListVillage (List *L, address_village *Pdel, address_village Succ);
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/

#endif