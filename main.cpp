#include "DxLib.h"
#include "Gareki.h"
#include "GarekiManager.h"
#include "Stage.h"
#include "mouse.h"
#include "Button.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	Stage stage1 = Stage();

	int a = 0;
	Button b = Button(100, 100, 100, 50, "�e�X�g");
	// while(����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A, �L�[�̍X�V)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateMouse() == 0) {
		stage1.Draw();
		stage1.Update();
		b.Update();
		b.Draw();
	}
	DxLib_End(); // DX���C�u�����I������
	return 0;
}
