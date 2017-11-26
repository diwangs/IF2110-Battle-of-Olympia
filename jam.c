/* Nama : Jonathan Alvaro
   NIM : 13516023
   Tanggal : 29 Agustus 2017
   Topik : 
   Deskripsi : Implementasi ADT Jam
*/

#include <stdio.h>
#include "jam.h"

boolean IsJAMValid (int H, int M, int S)
{
	//Return true jika (H:M:S) adalah jam valid
	return ((H >= 0 && H < 24) && (M >= 0 && M < 60) && (S >= 0 && S < 60));
}

JAM MakeJAM (int HH, int MM, int SS)
{
	//Buat dan return sebuah objek JAM yang valid
	JAM result;
	Hour(result) = HH;
	Minute(result) = MM;
	Second(result) = SS;
	return result;
}

void BacaJAM (JAM * J) 
{
	//Baca input hingga valid
	int h, m, s = -1;
	scanf("%d %d %d", &h, &m, &s);
	while(!(IsJAMValid(h, m, s)))
	{
		printf("Jam tidak valid\n");
		scanf("%d %d %d", &h, &m, &s);
	}
	
	//Isi J dengan waktu yang valid
	Hour(*J) = h;
	Minute(*J) = m;
	Second(*J) = s;
}

void TulisJAM (JAM J)
{
	printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
}

long JAMToDetik (JAM J)
{
	//Return jumlah detik dari jam 0:0:0
	return (Hour(J) * 3600 + Minute(J) * 60 + Second(J));
}

JAM DetikToJAM (long N)
{
	/*Konversi detik menjadi suatu objek jam yang valid*/

	//Pastikan jumlah detik < 86400
	if(N >= 86400) N %= 86400;

	//Konversi N menjadi JAM
	JAM result;
	Hour(result) = (int) N / 3600;
	N %= 3600;
	Minute(result) = (int) N / 60;
	N %= 60;
	Second(result) = (int) N;
	return result;
}

boolean JEQ (JAM J1, JAM J2)
{
	/*Return true bila J1 == J2*/
	
	//Bandingkan tiap komponen J1 dan J2
	return (Hour(J1) == Hour(J2) && Minute(J1) == Minute(J2) && Second(J1) == Second(J2));
}

boolean JNEQ (JAM J1, JAM J2)
{
	/*Return true bila J1 != J2*/
	return (Hour(J1) != Hour(J2) && Minute(J1) != Minute(J2) && Second(J1) != Second(J2));
}

boolean JLT(JAM J1, JAM J2)
{
	/*Return true jika J1 < J2*/
	return (JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
{
	/*Return true jika J1 > J2*/
	return (JAMToDetik(J1) > JAMToDetik(J2));
}

JAM NextDetik (JAM J)
{
	/*return sebuah objek jam yang nilainya J + 1 detik*/
	long detik = JAMToDetik(J) + 1;
	return(DetikToJAM((detik >= 86400) ? detik % 86400 : detik));
}

JAM NextNDetik (JAM J, int N)
{
	/*return sebuah objek jam yang nilainya J + N detik*/
	JAM result = J;
	for(int i = 0; i < N; i++)
	{
		result = NextDetik(result);
	}
	return result;
}

JAM PrevDetik (JAM J)
{
	/*return sebuah objek jam yang nilainya J - 1 detik*/
	long detik = JAMToDetik(J) - 1;
	return(DetikToJAM((detik < 0) ? detik + 86400 : detik));
}

JAM PrevNDetik (JAM J, int N)
{
	/*return sebuah objek jam yang nilainya J - N detik*/
	JAM result = J;
	for(int i = 0; i < N; i++)
	{
		result = PrevDetik(result);
	}
	return result;
}

long Durasi (JAM JAw, JAM JAkh)
{
	/*Mengirim JAkh - JAw dalam detik*/
	
	//Konversi kedalam detik
	long awal, akhir, durasi;
	awal = JAMToDetik(JAw);
	akhir = JAMToDetik(JAkh);

	//Jika akhir < awal, maka akhir adalah 1 hari setelah awal
	akhir += (akhir < awal) ? 3600 * 24 : 0;
	return(akhir - awal);	
}
