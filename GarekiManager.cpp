#include "GarekiManager.h"
#include <stdarg.h>
#include <vector>
#include "DxLib.h"


GarekiManager::GarekiManager()
{
}
GarekiManager::GarekiManager(int n, ...)
{
	gareki.resize(n);

	va_list ptr;
	va_start(ptr, n);
	for (int i = 0; i < n; i++) {
		gareki[i] = va_arg(ptr, Gareki);
	}
}
GarekiManager::GarekiManager(vector<Gareki> gareki2) {
	gareki = gareki2;
}
GarekiManager::~GarekiManager()
{
	gareki.clear();
}


void GarekiManager::SetGareki(int n, ...) {
	gareki.resize(n);

	va_list ptr;
	va_start(ptr, n);
	for (int i = 0; i < n; i++) {
		gareki[i] = va_arg(ptr, Gareki);
	}
}
void GarekiManager::SetGareki(vector<Gareki> gareki2) {
	gareki = gareki2;
}
void GarekiManager::AddGareki(Gareki g) {
	gareki.push_back(g);
}


bool GarekiManager::BreakBlock(int x, int y) {
	bool r = false; //�߂�l
	for (int i = 0; i < gareki.size(); i++) {
		if (gareki[i].Break(x, y) == true) {
			r = true;
			//Igo���s
			Gareki *g = nullptr;
			for (int i = 0; i < gareki.size(); i++) {
				g = gareki[i].Igo();
				if (g != nullptr)
					gareki.push_back(*g);
			}
			delete g;
		}
	}

	//���I�̃u���b�N��0�Ȃ����
	for (int i = gareki.size() - 1; i >= 0; i--) {
		if (gareki[i].GetSize() == 0) {
			gareki.erase(gareki.begin() + i);
		}
	}

	return r;
}
bool GarekiManager::BreakGareki(int x, int y) {
	bool r = false; //�߂�l
	for (int i = 0; i < gareki.size(); i++) {
		if (gareki[i].Break(x, y) == 0) {
			r = true;
			gareki.erase(gareki.begin() + i);
		}
	}

	return r;
}


void GarekiManager::Update() {
	for (int i = 0; i < gareki.size(); i++) {
		gareki[i].Update();

		for (int j = 0; j < gareki.size(); j++) {
			if(j != i)
				gareki[i].Collision(&gareki[j]);
		}
	}
}
void GarekiManager::Update(GarekiManager* gm) {
	//this�̃A�b�v�f�[�g
	for (int i = 0; i < gareki.size(); i++) {
		gareki[i].Update();

		for (int j = 0; j < gareki.size(); j++) {
			if (j != i)
				gareki[i].Collision(&gareki[j]);
		}
		for (int j = 0; j < gm->gareki.size(); j++) {//gm�Ɠ����蔻��
			gareki[i].Collision(&gm->gareki[j]);
		}
	}

	//gm�̃A�b�v�f�[�g
	for (int i = 0; i < gm->gareki.size(); i++) {
		gm->gareki[i].Update();

		for (int j = 0; j < gm->gareki.size(); j++) {
			if (j != i)
				gm->gareki[i].Collision(&gm->gareki[j]);
		}
		for (int j = 0; j < gareki.size(); j++) {//this�Ɠ����蔻��
			gm->gareki[i].Collision(&gareki[j]);
		}
	}
}

void GarekiManager::Draw() {
	for (int i = 0; i < gareki.size(); i++)
		gareki[i].Draw();
}

int GarekiManager::GetY(unsigned int n) {
	if (n < gareki.size())
		return gareki[n].GetY();
	else {
		return -1;
	}
}
int GarekiManager::GetX(unsigned int n) {
	if (n < gareki.size())
		return gareki[n].GetX();
	else {
		return -1;
	}
}