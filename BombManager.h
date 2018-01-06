#pragma once
#include "Bomb.h"
#include "DxLib.h"
#include <vector>

enum BombType { NORMAL, CROSS, MANJI };

class BombManager {
public:
	BombManager();
	//int BOMBTYPE;//爆弾の種類
	//int Stock(enum BombType);
	void Set(int type, int num);//ステージ毎の爆弾数
	void Explosion();
	int Getnum(int bombtype) { return num[bombtype]; }
	//const int BOMBNUM,CROSS_BOMBNUM,MANJI_BOMBNUM;
	//BombType bombtype;
	void Update();
	const int NEXT = 1;//bombed_countがNEXTに達したとき、次の爆弾に移行する
	//void FinCheck(int Num,);

private:
	int num[MANJI + 1];//種類ごとの爆弾数
	//list<Bomb> bomb;// = new Bomb;
	vector<Bomb> bomb;
	vector<Cross_Bomb> cross;// = new Cross_Bomb;
	vector<Manji_Bomb> manji;// = new Manji_Bomb;
	GarekiManager *g;// = new GarekiManager;
};

//int BombManager::BOMBTYPE = 1;