#include "BombManager.h"
#include "Bomb.h"
#include "DxLib.h"

void BombManager::Set(int type, int Num) {
	switch (type) {
	case NORMAL:
		num[NORMAL] = Num;
		bomb.resize(Num);
		break;
	case CROSS:
		num[CROSS] = Num;
		cross.resize(Num);
		break;
	case MANJI:
		num[MANJI] = Num;
		manji.resize(Num);
		break;
	default:
		break;
	}
}

void BombManager::Explosion() {
	for (int i = 0;i < 256;i++) {
		if (bomb[0].Explosion(g) == TRUE) {
			num[NORMAL]--;
		}
		else if (cross[0].Explosion(g) == TRUE) {
			num[CROSS]--;
		}
		else if (manji[0].Explosion(g) == TRUE) {
			num[MANJI]--;
		}
	}
	
}

void BombManager::Update() {

	if (num[NORMAL] > 0) {
		bomb[num[NORMAL] - 1].Update(g);

		if (bomb[num[NORMAL] - 1].bombed_count >= NEXT) {
			num[NORMAL - 1]--;
			bomb.pop_back();
		}
	}

	if (num[CROSS] > 0) {
		cross[num[CROSS] - 1].Update(g);

		if (cross[num[CROSS] - 1].bombed_count >= NEXT) {
			num[CROSS - 1]--;
			cross.pop_back();
		}
	}

	if (num[MANJI] > 0) {
		manji[num[MANJI] - 1].Update(g);

		if (manji[num[MANJI] - 1].bombed_count >= NEXT) {
			num[MANJI - 1]--;
			manji.pop_back();
		}
	}

}

/*
int BombManager::Stock(enum BombType) {
	switch (BombType bombtype) {
	case NORMAL:
		return Bomb::NUM
	case CROSS:
		return Cross_Bomb::NUM
}
}


void BombManager::Set(int BOMBNUM,int CROSS_BOMBNUM, int MANJI_BOMBNUM) {
		Bomb::NUM = BOMBNUM;
		Cross_Bomb::NUM = CROSS_BOMBNUM;
		Manji_Bomb::NUM = MANJI_BOMBNUM;
}

int BombManager::Set_BOMBTYPE(int NUM) {
	BOMBTYPE = NUM;
	return BOMBTYPE;
}*/