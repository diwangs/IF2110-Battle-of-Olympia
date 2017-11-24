/* File : playerqueue.h */
/* Definisi ADT Queue termodifikasi dengan representasi list linier sirkuler (semacam round robin)*/

#ifndef PLAYERQ_H
#define PLAYERQ_H

#include "boolean.h"
#include "player.h"

/* Definisi elemen dan address */
typedef struct tElmtqueue *address_playerQ;
typedef struct tElmtqueue { 
	Player * info;
	address_playerQ next;
} ElmtPlayerQ;
typedef struct {
	address_playerQ First;
} PlayerQ;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* ********* AKSES (Selektor) ********* */
#define InfoElmtPlayerQ(A) (A)->info
#define NextElmtPlayerQ(A) (A)->next
#define FirstPlayerQ(Q) ((Q).First)

/* ********* Prototype ********* */
int CountPlayer (PlayerQ Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmptyPlayerQ (PlayerQ * Q);
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi */
/* atau : jika alokasi gagal, Q kosong */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
address_playerQ AlokElmtPlayerQ (Player * P);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void DealokElmtPlayerQ(address_playerQ A);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi */

/* *** Primitif Add/Delete *** */
void AddPlayer (PlayerQ * Q, Player * P);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
void NextPlayer(PlayerQ *Q);
/* I.S. Q tidak kosong
F.S. First(Q) pindah ke Next(First(Q)) */
void DelPlayer (PlayerQ * Q, Player ** P);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */

#endif

// Ini copas dari ADT sebelah, jadi sorry kalo commentnya agak ga nyambung