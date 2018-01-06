#include "Stage.h"
#include "DxLib.h"
#include "Gareki.h"
#include "Bomb.h"

Stage::Stage() {
	Gareki g[15];
	g[0].SetBlock(3, 0, 1, 11);
	g[1].SetBlock(3, 0, 1, 11);
	g[2].SetBlock(4, 0, 1, 11, 21);
	g[3].SetBlock(4, 0, 1, 11, 21);
	g[4].SetBlock(4, 0, 1, 2, 10);
	g[5].SetBlock(4, 0, 1, 10, 20);
	g[6].SetBlock(3, 0, 10, 20);
	g[7].SetBlock(3, 0, 10, 20);
	g[8].SetBlock(3, 0, 1, 2);
	g[9].SetBlock(2, 0, 1);
	g[10].SetBlock(2, 0, 1);
	g[11].SetBlock(4, 0, 1, 10, 11);
	g[12].SetBlock(5, 0, 1, 2, 11, 21);
	g[13].SB({ 1, 10, 11, 12, 21, 31 }, 12, 6);
	g[14].SB({
		{ 1,1,1,1,1 },
		{ 1,0,1,0,1 }, 
		{ 1,1,1,1,1 }, 
		{ 1,1,1,1,1 }
	}, 0, 3);
	g[0].SP(5, 13);
	g[1].SetPoint(10, 9);
	g[2].SetPoint(5, 5);
	g[3].SetPoint(6,8 );
	g[4].SetPoint(8,10 );
	g[5].SetPoint(13,12 );
	g[6].SetPoint(8,12 );
	g[7].SetPoint(9,7 );
	g[8].SetPoint(12,10 );
	g[9].SetPoint(8,6 );
	g[10].SetPoint(10,14 );
	g[11].SetPoint(6,11 );
	g[12].SetPoint(10,11 );
	for (int i = 0; i < 15; i++)
		gareki.AddGareki(g[i]);
	
	Gareki g2[10];
	for (int i = 0; i < 10; i++) {
		g2[i].AddBlock(900);
		g2[i].SP((i + 5), 0);
		gareki.AddGareki(g2[i]);
	}

	

	Cross_Bomb a;
}

void Stage::Update() {
	gareki.Update();
	juzi.Update(&gareki);
}

void Stage::Draw() {
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 20; j++) {
			DrawFormatString(j*32 + 8, i*32 + 8, 0xffffff, "%d", stage[i][j]);
		}
	}

	gareki.Draw();
	//ステージの表示
}

/*
ガレキを置く
*/