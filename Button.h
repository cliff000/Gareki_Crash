#pragma once

#define BUTTON_NORMAL 0
#define BUTTON_ON_CURSOR 1
#define BUTTON_CLICKED 2
#define BUTTON_PRESSING 3
#define BUTTON_RELEASED 4

#define SQUARE_BUTTON 0
#define CIRCLE_BUTTON 1

class Button {
	int x, y, w, h, r;
	int color1, color2, color3;
	int type;
	int state = 0; //ボタンの状態を保存　0:押されてない　1:押した時　2:押されている間　3:離された時
	const char *str;
	int se1, se2;
	void SquareDraw();
	void CircleDraw();

public:
	Button();
	Button(int x, int y, int w, int h, const char* str, int color1 = 0x64ffff, int color2 = 0x000000, int color3 = 0xffffff);
	Button(int x, int y, int r, const char* str, int color1 = 0x64ffff, int color2 = 0x000000, int color3 = 0xffffff);
	void Update();
	void Draw();
	virtual bool On_Cursor();
	virtual bool Clicked();
	virtual bool Pressing();
	virtual bool Released();

	void SetX(int x) { this->x = x; }
	void SetY(int y) { this->y = y; }
	void SetPoint(int x, int y) { SetX(x); SetY(y); }
};

