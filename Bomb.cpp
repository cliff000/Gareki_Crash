#include "DxLib.h"
#include "Bomb.h"
#include "Gareki.h"
#include "mouse.h"
#include "GarekiManager.h"
#include "BombManager.h"

Bomb::Bomb() {
	x = 0, y = 0;
	X_RANGE = 1;
	Y_RANGE = 1;
	bomb_range = { {1} };
}
//int Bomb::NUM = 10;

Cross_Bomb::Cross_Bomb() {
	x = BLOCK_SIZE, y = 0;
	X_RANGE = 3;
	Y_RANGE = 3;
	bomb_range = {
		{ 0,1,0 },
		{ 1,1,1 },
		{ 0,1,0 } };
}
//int Cross_Bomb::NUM = 10;

Manji_Bomb::Manji_Bomb() {
	x = BLOCK_SIZE*2, y = 0;
	X_RANGE = 5;
	Y_RANGE = 5;
	bomb_range = {
		{ 1,1,1,0,1 },
		{ 0,0,1,0,1 },
		{ 1,1,1,1,1 },
		{ 1,0,1,0,0 },
		{ 1,0,1,1,1 } };
}


/*
bool Bomb::Bombcheck(int bomb_range) {
	if (bomb_range == TRUE) return TRUE;
	else return FALSE;
}
*/

/*void Bomb::Bombed_xy() {
	for (int i = 0;i < Y_RANGE;i++) {
		for (int j = 0;j < X_RANGE;j++) {
			if (Bombcheck(bomb_range[i][j])) {
				bombed_x[i][j] = x + BLOCK_SIZE*j;
				bombed_y[i][j] = y + BLOCK_SIZE*i;
			}
		}
	}
}*/

bool Bomb::Explosion(GarekiManager *g) {
	if (hold == TRUE&&Mouse[MOUSE_LEFT] == 0) {
		for (int i = 0;i < Y_RANGE;i++) {
			for (int j = 0;j < X_RANGE;j++) {
				if (bomb_range[i][j]) {
					g->BreakBlock(x + BLOCK_SIZE*(j - 1), y + BLOCK_SIZE*(i - 1));
					//bombed_x[i][j] = x + BLOCK_SIZE*j;
					//bombed_y[i][j] = y + BLOCK_SIZE*i;
					//g->BreakBlock(bombed_x[i][j], bombed_y[i][j]);
				}
			}
		}
		hold = FALSE;
		return TRUE;
	}
	else FALSE;
}

void Bomb::Hold() {
	if (Mouse[MOUSE_LEFT] >= 1) { //&& x <= Mouse[MOUSE_X] && Mouse[MOUSE_X] <= x + BLOCK_SIZE\
		//&& y <= Mouse[MOUSE_Y] && Mouse[MOUSE_Y] <= y + BLOCK_SIZE) {
		x = Mouse[MOUSE_X] - Mouse[MOUSE_X] % BLOCK_SIZE, y = Mouse[MOUSE_Y] - Mouse[MOUSE_Y] % BLOCK_SIZE;
		hold = TRUE;
	}
}

/*void Bomb::Put() {
	if (Hold()) {//爆弾を置くとき、座標をブロックの左上に合わせる
		x = x - x%BLOCK_SIZE, y = y - y%BLOCK_SIZE;
	}
}*/

void Bomb::Draw() {
	//if (NUM > 0) {
		if (hold) {
			DrawCircle(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, BLOCK_SIZE / 2, GetColor(255, 255, 255), TRUE);
		}
		else {
			DrawCircle(x + BLOCK_SIZE / 2, y + BLOCK_SIZE / 2, BLOCK_SIZE / 2, GetColor(255, 255, 255), FALSE);
		}
	//}
}

void Bomb::Update(GarekiManager *g) {
	//for (int i = 0;i < manager->Getnum[NORMAL];i++) {
		//if (bomb[manager->Getnum(NORMAL)] == manager->Getnum[NORMAL] - 1) {
			//if (NUM > 0) {
				//計算フェーズ
			Hold();
			//Bombed_xy();
			//if (hold == TRUE && Mouse[MOUSE_LEFT] == 0) {
			//Explosion(g);
			if (Explosion(g) == TRUE) {
				bombed = TRUE;
			}

			if (bombed == TRUE) {
				bombed_count++;//爆発の描画に関する
			}
			//hold = FALSE;
			//}

			//描画フェーズ
			Draw();
			//}
		//}
	//}
}