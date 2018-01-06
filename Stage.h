#pragma once
#include "DxLib.h"
#include "GarekiManager.h"
#include "Bomb.h"

class Stage {
public:
	Stage();
	void Update();
	void Draw();
	GarekiManager gareki;
	Bomb Bomb;
	Cross_Bomb juzi;

	char stage[15][20] = {0};
};




