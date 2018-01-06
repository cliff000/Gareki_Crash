#include "DxLib.h"
#include "Gareki.h"
#include "GarekiManager.h"
#include "Stage.h"
#include "mouse.h"
#include "Button.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	Stage stage1 = Stage();

	int a = 0;
	Button b = Button(100, 100, 100, 50, "テスト");
	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア, キーの更新)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateMouse() == 0) {
		stage1.Draw();
		stage1.Update();
		b.Update();
		b.Draw();
	}
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
