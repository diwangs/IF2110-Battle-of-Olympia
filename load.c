#include "jam.h"
#include "load.h"
#include "listbuilding.h"
#include "listunit.h"
#include "mesinkarload.h"
#include "mesinkataload.h"
#include "point.h"
#include "playerq.h"

int kata_to_int(LKata K)
{
	//Convert bilangan dalam bentuk string menjadi integer
	int res = 0;
	for(int i = 0; i < K.length; i++)
	{
		res *= 10;
		res += K.TabKata[i] -'0';
	}

	return res;
}

void load_unit(infotypeunit* u, Player* p)
{
	//Ambil data-data yang dibutuhkan untuk membuat 1 unit dari savefile
	int max_health = kata_to_int(CKata);
	ADVKATA();
	int health = kata_to_int(CKata);
	ADVKATA();
	int attack = kata_to_int(CKata);
	ADVKATA();
	int maxmove = kata_to_int(CKata);
	ADVKATA();
	int move = kata_to_int(CKata);
	ADVKATA();
	char att_type = CKata.TabKata[0];
	ADVKATA();
	boolean can_attack = kata_to_int(CKata);
	ADVKATA();
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	ADVKATA();
	int price = kata_to_int(CKata);
	ADVKATA();
	boolean is_dead = kata_to_int(CKata);
	ADVKATA();
	char type = CKata.TabKata[0];
	ADVKATA();
	ADVKATA();

	//Buat unit sesuai data yang diterima dari savefile
	*u = MakeUnit(max_health, health, maxmove, move, attack, att_type,
		can_attack, MakePOINT(pos_x, pos_y), price, is_dead, type, p);
}

void load_building(infotypebuilding* b, Player* p)
{
	//Ambil semua atribut building dari savefile
	int pos_x, pos_y;
	pos_x = kata_to_int(CKata);
	ADVKATA();
	pos_y = kata_to_int(CKata);
	ADVKATA();
	int income = kata_to_int(CKata);
	ADVKATA();
	ADVKATA();
	char type = CKata.TabKata[0];
	ADVKATA();

	//Gunakan atribut hasil load untuk membuat building
	*b = MakeBuilding(MakePOINT(pos_x, pos_y), income, p, type);
}

void load_player(Player** p)
{
	//Load data dasar milik player (gold, income, upkeep, dan warna)
	if(!EndData)
	{
		int gold, income, upkeep;
		gold = kata_to_int(CKata);
		ADVKATA();
		income = kata_to_int(CKata);
		ADVKATA();
		upkeep = kata_to_int(CKata);
		ADVKATA();
		char color = CKata.TabKata[0];

		//Buat player baru sesuai data dalam savefile
		*p = CreatePlayer(color);
		(*p)->gold = gold;
		(*p)->income = income;
		(*p)->upkeep = upkeep;
	}

	//Siapkan list kosong untuk menyimpan daftar unit dan building milik player
	CreateEmptyListUnit(&((*p)->list_unit));
	CreateEmptyListBuilding(&((*p)->list_building));
	ADVKATA();
	EndData = false;

	//Load data unit hingga ditemukan karakter '|' yang berfungsi sebagai separator antar tipe data
	while(!EndData)
	{
		//Baca data mengenai unit dari savefile, buat sebuah unit baru, dan masukkan ke dalam list unit milik player
		infotypeunit unit;
		load_unit(&unit, *p);
        unit->owner = *p;
		InsVLastListUnit(&((*p)->list_unit), unit);
	}

	EndData = false;

	//Load data building hingga ditemukan karakter '|' yang berfungsi sebagai separator antar tipe data
	while(!EndData)
	{
		//Baca data mengenai tiap building dari savefile, buat building sesuai data tersebut, masukkan ke dalam list building milik player
		Building* building;
		load_building(&building, *p);
		InsVLastListBuilding(&((*p)->list_building), building);
	}

	EndData = false;
}

void load_map(Player* p1, Player* p2, Peta* p)
{
	//Baca data ukuran map
	int brs, kol;
	brs = kata_to_int(CKata);
	ADVKATA();
	kol = kata_to_int(CKata);
	ADVKATA();

	//Buat peta sesuai ukuran yang dibaca
	MakePeta(brs, kol, p);

	//Tandai lokasi semua unit milik player1 dan player2 pada peta
	address_unit u = FirstUnit(p1->list_unit);
	while(u != NULL)
	{
		AddUnitToPeta(InfoUnit(u), p);
		u = NextUnit(u);
	}

	u = FirstUnit(p2->list_unit);
	while(u != NULL)
	{
		AddUnitToPeta(InfoUnit(u), p);
		u = NextUnit(u);
	}

	//Tandai lokasi semua building milik player1 dan player2 pada peta
	address_building b = FirstBuilding(p1->list_building);
	while(b != NULL)
	{
		AddBuildingToPeta(InfoBuilding(b), p);
		b = NextBuilding(b);
	}

	b = FirstBuilding(p2->list_building);
	while(b != NULL)
	{
		AddBuildingToPeta(InfoBuilding(b), p);
		b = NextBuilding(b);
	}

	//Load data building yang tidak dimiliki siapapun pada peta
	while(!EndData)
	{
		int pos_x, pos_y;
		pos_x = kata_to_int(CKata);
		ADVKATA();
		pos_y = kata_to_int(CKata);
		ADVKATA();

		int income = kata_to_int(CKata);
		ADVKATA();

		char owner = CKata.TabKata[0];
		ADVKATA();

		char type = CKata.TabKata[0];
		ADVKATA();

		//owner == 'Z' menandakan bahwa building tidak dimiliki siapapun
		if(owner == 'Z')
		{
			AddBuildingToPeta(MakeBuilding(MakePOINT(pos_x, pos_y),
				income, NULL, type), p);
		}
	}
}

void load_save_time(JAM* J)
{
	//Load waktu kapan savefile yang akan diload dibuat
	int sec, min, hour;
	sec = kata_to_int(CKata);
	ADVKATA();
	min = kata_to_int(CKata);
	ADVKATA();
	hour = kata_to_int(CKata);
	ADVKATA();

	*J = MakeJAM(hour, min, sec);
}

void load(Player** p1, Player** p2, Player** current, Peta* p, PlayerQ* pq)
{
	//Load semua data yang dibutuhkan untuk memulai permainan
	STARTKATA();
	load_player(p1);
	load_player(p2);
	load_map(*p1, *p2, p);
	CreateEmptyPlayerQ(pq);

	//Inisialisasi pula player queue untuk memastikan urutan turn sama seperti saat save
	if(CKata.TabKata[1] == '1')
	{
		*current = *p1;
		AddPlayer(pq, *p1);
		AddPlayer(pq, *p2);
	}
	else
	{
		*current = *p2;
		AddPlayer(pq, *p2);
		AddPlayer(pq, *p1);
	}
	ADVKATA();

	//Print waktu savefile yang digunakan dibuat
	JAM J;
	load_save_time(&J);
	printf("Loaded data from %d:%d:%d", Hour(J), Minute(J), Second(J));
}
