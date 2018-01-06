#pragma once
#include "GarekiManager.h"
#include <vector>
#include "Dxlib.h"

class Bomb {
public:
	Bomb();
	//bool Bombcheck(int bomb_range);//各マスに爆発判定あるかないか
	//void Bombed_xy();
	bool Explosion(GarekiManager *g);
	void Hold();
	//void Put();
	void Update(GarekiManager *g);
	void Draw();
	bool hold = FALSE;
	bool bombed;//爆発したかどうか
	int bombed_count;//爆発後のカウント　次の爆弾に移行するまでの描画などに使用
	//static int NUM;
protected:
	//BombManager *manager = new BombManager;
	int x, y;//爆発するマスの左上座標
	int X_RANGE, Y_RANGE;
	//int bombed_x[1][1] = { 0 }, bombed_y[1][1] = { 0 };//各爆発するマスの座標
	vector<vector<bool>> bomb_range;//爆発範囲と形

};

class Cross_Bomb :public Bomb {
public:
	Cross_Bomb();
private:

};

class Manji_Bomb :public Bomb {
public:
	Manji_Bomb();
private:
};

//enum BombType { NORMAL, CROSS, MANJI };