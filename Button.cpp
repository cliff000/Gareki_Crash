#include <DxLib.h>
#include "Button.h"
#include "mouse.h"
#include <iostream>

using namespace std;

Button::Button() {}

Button::Button(int _x, int _y, int _w, int _h, const char* _str, int _color1, int _color2, int _color3)
{
	type = SQUARE_BUTTON;
	x = _x;  y = _y;  w = _w;  h = _h;
	str = _str;
	color1 = _color1;  color2 = _color2;  color3 = _color3;
}

Button::Button(int _x, int _y, int _r, const char* _str, int _color1, int _color2, int _color3)
{
	type = CIRCLE_BUTTON;
	x = _x;  y = _y;  r = _r;
	str = _str;
	color1 = _color1;  color2 = _color2;  color3 = _color3;
}


//ボタンの更新
void Button::Update() {
	int mx = Mouse[MOUSE_X];
	int my = Mouse[MOUSE_Y];

	//ボタンの形により判定式を変える
	bool shape_judge;
	if (type == SQUARE_BUTTON) {
		int _x = x - w / 2;
		int _y = y - h / 2;
		shape_judge = _x <= mx && mx <= _x + w && _y <= my && my <= _y + h;
	}
	else if (type == CIRCLE_BUTTON) {
		shape_judge = pow(x - mx, 2) + pow(y - my, 2) <= pow(r, 2);
	}
	
	

	//ボタンが押されてないとき
	if (Mouse[MOUSE_LEFT] == 0) {
		if (state == BUTTON_CLICKED || state == BUTTON_PRESSING)
			state = BUTTON_RELEASED;
		else {
			if (shape_judge) {//ボタンの上にマウスがあれば
				if (state == BUTTON_NORMAL)
					PlaySoundMem(se2, DX_PLAYTYPE_BACK, TRUE);
				state = BUTTON_ON_CURSOR;
			}
			else
				state = BUTTON_NORMAL;
		}
	}

	//ボタンが押されたとき
	if (Mouse[MOUSE_LEFT] == 1) {
		if (shape_judge) {//ボタンの上にマウスがあれば
			state = BUTTON_CLICKED;
		}
	}

	//ボタンが押されている時
	if (Mouse[MOUSE_LEFT] > 1) {
		if (shape_judge) {//ボタンの上にマウスがあれば
			if (state == BUTTON_CLICKED)
				state = BUTTON_PRESSING;
		}
	}


	//状況に応じた関数を呼びだす（オーバーライドして使う）
	switch (state) {
	case BUTTON_ON_CURSOR:
		On_Cursor();
		break;
	case BUTTON_CLICKED:
		Clicked();
		break;
	case BUTTON_PRESSING:
		Pressing();
		break;
	case BUTTON_RELEASED:
		Released();
		break;
	}
}


//ボタン描画
void Button::Draw() {
	if (type == SQUARE_BUTTON) {
		SquareDraw();
	}
	else if (type == CIRCLE_BUTTON) {
		CircleDraw();
	}
}

//矩形ボタンの描画
void Button::SquareDraw() {
	int waku = 2;
	int _x = x - w / 2;
	int _y = y - h / 2;
	int sub = 0;
	if (state == BUTTON_CLICKED || state == BUTTON_PRESSING) {
		sub = 3;
	}
	//ボタン表示
	if (state == BUTTON_ON_CURSOR) {//カーソルがのってるとき
		for (int i = 4; i >= 0; i--) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220 - 40 * i);
			DrawBox(_x - i, _y - i, _x + w + i, _y + h + i, color3, TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	}
	DrawBox(_x + sub, _y + sub, _x + w - sub, _y + h - sub, color2, TRUE);//枠
	DrawBox(_x + sub + waku, _y + sub + waku, _x + w - sub - waku, _y + h - sub - waku, color1, TRUE);//本体
	
	
	//文字表示
	int strW = GetDrawStringWidth(str, strlen(str));
	int strX = _x + w / 2 - strW / 2;
	int strY = _y + h / 2 - DEFAULT_FONT_SIZE / 2;
	DrawString(strX, strY, str, GetColor(0, 0, 0));
}

//円形ボタンの描画
void Button::CircleDraw() {
	int waku = 3;
	int sub = 0;
	if (state == BUTTON_CLICKED || state == BUTTON_PRESSING) {
		sub = 3;
	}

	//枠表示
	if (state == BUTTON_ON_CURSOR) {//カーソルがのってるとき
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		for (int i = 4; i >= 0; i--) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220 - 40 * i);
			DrawCircle(x, y, r + i, color3, TRUE);
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	}
	DrawCircle(x, y, r - sub, color2, TRUE);//枠
	DrawCircle(x, y, r - sub - waku, color1, TRUE);//本体

	
	//文字表示
	int strW = GetDrawStringWidth(str, strlen(str));
	int strX = x - strW / 2;
	int strY = y - DEFAULT_FONT_SIZE / 2;
	DrawString(strX, strY, str, GetColor(0, 0, 0));
}


//ボタンの状態を得る
bool Button::On_Cursor() {
	if (state == BUTTON_ON_CURSOR)
		return true;
	else
		return false;
}
bool Button::Clicked() {
	if (state == BUTTON_CLICKED)
		return true;
	else
		return false;
}
bool Button::Pressing() {
	if (state == BUTTON_PRESSING)
		return true;
	else
		return false;
}
bool Button::Released() {
	if (state == BUTTON_RELEASED)
		return true;
	else
		return false;
}
