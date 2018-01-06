#pragma once
#include "GarekiManager.h"
#include <vector>
#include "Dxlib.h"

class Bomb {
public:
	Bomb();
	//bool Bombcheck(int bomb_range);//�e�}�X�ɔ������肠�邩�Ȃ���
	//void Bombed_xy();
	bool Explosion(GarekiManager *g);
	void Hold();
	//void Put();
	void Update(GarekiManager *g);
	void Draw();
	bool hold = FALSE;
	bool bombed;//�����������ǂ���
	int bombed_count;//������̃J�E���g�@���̔��e�Ɉڍs����܂ł̕`��ȂǂɎg�p
	//static int NUM;
protected:
	//BombManager *manager = new BombManager;
	int x, y;//��������}�X�̍�����W
	int X_RANGE, Y_RANGE;
	//int bombed_x[1][1] = { 0 }, bombed_y[1][1] = { 0 };//�e��������}�X�̍��W
	vector<vector<bool>> bomb_range;//�����͈͂ƌ`

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