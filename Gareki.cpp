#include "Gareki.h"
#include <stdarg.h>
#include <vector>
#include "DxLib.h"
#include "Block.h"

#define safe_delete(x) delete x;  x = nullptr;
#define i(itr) ((itr->first % 100) / 10)
#define j(itr) (itr->first % 10)
#define locate(h, w) (((h) * 10) + (w))
#define locate_itr(itr) (itr->first)


using namespace std;

Gareki::Gareki() {
}
Gareki::Gareki(int n, ...) {
	int _w = 0, _h = 0;

	va_list ptr;
	va_start(ptr, n);

	//配列に要素を代入
	va_start(ptr, n);
	for (int i = 0; i < n; i++) {
		int a = va_arg(ptr, int);
		int _i = a % 100 / 10;
		int _j = a % 10;
		block[locate(_i, _j)] = Block::Int_to_Block(a / 100);
	}

	va_end(ptr);
	SetH(); SetW();
}
Gareki::Gareki(vector<int> b, int _x, int _y) {
	for (int i = 0; i < b.size(); i++)
		block[b[i] % 100] = Block::Int_to_Block(b[i] / 100);
	SetPoint(_x, _y);
	SetH(); SetW();
}
Gareki::Gareki(vector<vector<int>> b, int _x, int _y) {
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[i].size(); j++) {
			if (b[i][j] > 0)
				block[locate(i, j)] = Block::Int_to_Block(b[i][j]);
		}
	}
	SetPoint(_x, _y);
	SetH(); SetW();
}
Gareki::Gareki(Gareki* g) {
	SetPoint(g->GetX() / BLOCK_SIZE, g->GetY() / BLOCK_SIZE);
	SetH(); SetW();
	for (auto itr = g->block.begin(); itr != g->block.end(); ++itr) {
		block[locate_itr(itr)] = g->block[locate_itr(itr)];
	}
}
Gareki::~Gareki() {
	block.clear();
}


void Gareki::SetBlock(int n, ...) {
	int _w = 0, _h = 0;
	int a;

	va_list ptr;
	va_start(ptr, n);

	//配列に要素を代入
	va_start(ptr, n);
	for (int i = 0; i < n; i++) {
		int a = va_arg(ptr, int);
		int _i = a % 100 / 10;
		int _j = a % 10;
		block[locate(_i, _j)] = Block::Int_to_Block(a / 100);
	}

	va_end(ptr);
	SetH(); SetW();
}
void Gareki::SetBlock(vector<int> b, int _x, int _y) {
	for (int i = 0; i < b.size(); i++)
		block[b[i] % 100] = Block::Int_to_Block(b[i] / 100);
	SetPoint(_x, _y);
	SetH(); SetW();
}
void Gareki::SetBlock(vector<vector<int>> b, int _x, int _y) {
	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[i].size(); j++) {
			if (b[i][j] > 0)
				block[locate(i, j)] = Block::Int_to_Block(b[i][j]);
		}
	}
	SetPoint(_x, _y);
	SetH(); SetW();
}
void Gareki::AddBlock(int b) {
	block[b % 100] = Block::Int_to_Block(b / 100);
	SetH(); SetW();
}


void Gareki::Collision(Gareki* g) {
	int dx = GetX() - g->GetX();
	int dy = GetY() - g->GetY();
	//位置が近いときのみ実行
	if (((dx > 0) ? dx <= g->w : -dx <= w) && ((dy > 0) ? dy <= g->h : -dy <= h)) {
		//当たり判定
		for (auto itr = block.begin(); itr != block.end(); ++itr) {;
			for (auto itr2 = g->block.begin(); itr2 != g->block.end(); ++itr2) {
				if (abs(GetY() + BLOCK_SIZE * i(itr) - (g->GetY() + BLOCK_SIZE * i(itr2))) < BLOCK_SIZE && abs(GetX() + BLOCK_SIZE * j(itr) - (g->GetX() + BLOCK_SIZE * j(itr2))) < BLOCK_SIZE) {
					if (GetY() + BLOCK_SIZE * i(itr) < g->GetY() + BLOCK_SIZE * i(itr2)) {//thisオブジェクトが上なら
						y -= (GetY() + BLOCK_SIZE * (i(itr) + 1)) - (g->GetY() + BLOCK_SIZE * i(itr2));
						vy = 0;
					}
				}
			}
		}
	}
}

bool Gareki::Break(int x, int y) {
	//瓦礫の範囲外の時終了
	if(x < GetX() || x > GetX() + w  ||  y < GetY() || y > GetY() + h)
		return false;  

	int j = (x - GetX()) / BLOCK_SIZE;
	int i = (y - GetY()) / BLOCK_SIZE;
	
	auto itr = block.find(locate(i, j));
	if (itr != block.end() && x == GetX() + j(itr) * BLOCK_SIZE && y == GetY() + i(itr) * BLOCK_SIZE) {
		if (itr->second->Break() == true) {
			block.erase(locate(i, j));
		}
		return true;
	}
	return false;
}


void Gareki::Update() {
	vy += ay;
	if (vy >= BLOCK_SIZE)
		vy = BLOCK_SIZE - 1; //終端速度
	y += vy;

	 //地面に当たった処理
	 if (y + h > STAGE_BOTTOM) {
		 for (auto itr = block.begin(); itr != block.end(); ++itr) {
			 if (GetY() + BLOCK_SIZE * (i(itr) + 1) > STAGE_BOTTOM) {
				 y -= GetY() + BLOCK_SIZE * (i(itr) + 1) - STAGE_BOTTOM;
				 vy = 0;
			 }
		 }
	 }
}
void Gareki::Draw() {
	//ブロック表示
	for (auto itr = block.begin(); itr != block.end(); ++itr) {
		itr->second->Draw(GetX() + BLOCK_SIZE * j(itr), GetY() + BLOCK_SIZE * i(itr));
	}

	//枠線表示
	DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 127);
	for (auto itr = block.begin(); itr != block.end(); ++itr) {
		int _x = x + j(itr) * BLOCK_SIZE;
		int _y = y + i(itr) * BLOCK_SIZE;

		int i = i(itr); int j = j(itr);

		if (i == 0 || block.find(locate(i - 1, j)) == block.end())
			DrawLine(_x, _y + GAREKI_EDGE_W / 2, _x + BLOCK_SIZE, _y + GAREKI_EDGE_W / 2, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);

		if (i == h - 1 || block.find(locate(i + 1, j)) == block.end())
			DrawLine(_x, _y + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _x + BLOCK_SIZE, _y + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);

		if (j == 0 || block.find(locate(i, j - 1)) == block.end()) {
			DrawLine(_x + GAREKI_EDGE_W / 2, _y + GAREKI_EDGE_W, _x + GAREKI_EDGE_W / 2, _y + BLOCK_SIZE - GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
			if (i != h- 1 && block.find(locate(i + 1, j)) != block.end())
				DrawLine(_x + GAREKI_EDGE_W / 2, _y + BLOCK_SIZE - GAREKI_EDGE_W, _x + GAREKI_EDGE_W / 2, _y + BLOCK_SIZE + GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
			if (i != 0 && block.find(locate(i - 1, j)) != block.end() && j != 0 && block.find(locate(i - 1, j - 1)) != block.end())
				DrawLine(_x + GAREKI_EDGE_W / 2, _y + GAREKI_EDGE_W, _x + GAREKI_EDGE_W / 2, _y - GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
		}

		if (j == w - 1 || block.find(locate(i, j + 1)) == block.end()) {
			DrawLine(_x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y + GAREKI_EDGE_W, _x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y + BLOCK_SIZE - GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
			if (i != h - 1 && block.find(locate(i + 1, j)) != block.end())
				DrawLine(_x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y + BLOCK_SIZE - GAREKI_EDGE_W, _x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y + BLOCK_SIZE + GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
			if (i != 0 && block.find(locate(i - 1, j)) != block.end() && j != w - 1 && block.find(locate(i - 1, j + 1)) != block.end())
				DrawLine(_x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y + GAREKI_EDGE_W, _x + BLOCK_SIZE - (GAREKI_EDGE_W + 1) / 2, _y - GAREKI_EDGE_W, GAREKI_EDGE_COLOR, GAREKI_EDGE_W);
		}
	}
	DxLib:: SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}


Gareki* Gareki::Igo() {
	//要素が1以下なら終了
	if (block.size() <= 1) return nullptr;

	//二次元配列aの動的確保
	int **a = new int*[h];
	for (int i = 0; i < h; i++) {
		a[i] = new int[w];
		for (int j = 0; j < w; j++)
			a[i][j] = 0;
	}

	bool separation = false;

	Gareki *g = new Gareki();//戻り値用
	g->x = GetX(); g->y = GetY();
	
	//ループ用
	int *place = new int[block.size()];
	int tmp = 0;
	int block_size = block.size();
	for (auto itr = block.begin(); itr != block.end(); ++itr)
		place[tmp++] = locate_itr(itr);

	Igo2(place[0] / 10, place[0] % 10, a);//最初の要素で実行


	//分離しているか確かめ，別の瓦礫に分ける
	for (int k = 0; k < block_size; k++) {
		// 前のIgo()で通ってなければ実行
		if (a[place[k] / 10][place[k] % 10] == 0) {
			separation = true;
			g->block[place[k]] = block[place[k]];
			block.erase(place[k]);
		}
	}

	//delete
	delete[] place;
	for (int i = 0; i<h; ++i)
		delete[] a[i];
	delete[] a;

	//分離した時の処理
	if (separation == true) {
		SetH(); SetW();
		g->SetH(); g->SetW();
		return g;
	}

	return nullptr;
}
void Gareki::Igo2(int i, int j, int** hairetsu) {
	hairetsu[i][j] = 1;

	int _i = i;
	int _j = j;
	
	_i = i;  _j = j + 1;
	if (block.find(locate(_i, _j)) != block.end() && hairetsu[_i][_j] != 1) {
		Igo2(_i, _j, hairetsu);
	}

	_i = i + 1; _j = j;
	if (block.find(locate(_i, _j)) != block.end() && hairetsu[_i][_j] != 1) {
		Igo2(_i, _j, hairetsu);
	}

	_i = i;  _j = j - 1;
	if (block.find(locate(_i, _j)) != block.end() && hairetsu[_i][_j] != 1) {
		Igo2(_i, _j, hairetsu);
	}

	_i = i - 1; _j = j;
	if (block.find(locate(_i, _j)) != block.end() && hairetsu[_i][_j] != 1) {
		Igo2(_i, _j, hairetsu);
	}
}


void Gareki::SetH() {
	auto itr = block.begin();
	int min = i(itr), max = i(itr);
	itr++;
	for (; itr != block.end(); ++itr) {
		min = (i(itr) < min) ? i(itr) : min;
		max = (i(itr) > max) ? i(itr) : max;
	}
	h = (max - min + 1) * BLOCK_SIZE;

	//位置調整
	if (min > 0) {
		int *place = new int[block.size()];
		int tmp = 0;
		int size = block.size();
		for (auto itr = block.begin(); itr != block.end(); ++itr) {
			place[tmp++] = locate_itr(itr);
		}

		for (int k = 0; k < size; k++) {
			block[locate(place[k] / 10 - min, place[k] % 10)] = block[place[k]];
			block.erase(place[k]);
		}
		y += min * BLOCK_SIZE;
		delete[] place;
	}
}
void Gareki::SetW() {
	auto itr = block.begin();
	int min = j(itr), max = j(itr);
	itr++;
	for (; itr != block.end(); ++itr) {
		min = (j(itr) < min) ? j(itr) : min;
		max = (j(itr) > max) ? j(itr) : max;
	}
	w = (max - min + 1) * BLOCK_SIZE;

	//位置調整
	if (min > 0) {
		int *place = new int[block.size()];
		int tmp = 0;
		int size = block.size();
		for (auto itr = block.begin(); itr != block.end(); ++itr) {
			place[tmp++] = locate_itr(itr);
		}

		for (int k = 0; k < size; k++) {
			block[locate(place[k] / 10, place[k] % 10 - min)] = block[place[k]];
			block.erase(place[k]);
		}
		x += min * BLOCK_SIZE;
		delete[] place;
	}
}