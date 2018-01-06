#pragma once
#include<vector>
#include "Gareki.h"

class GarekiManager
{
	std::vector< Gareki> gareki;

public:
	////----------- GarekiManager�����̂Ɏg���R���X�g���N�^�A�֐� ------------------------------------------------------/**/
	/**/                                                                                                                  /**/
	/**/   GarekiManager();                                                                                               /**/
	/**/   GarekiManager(int gareki_num, ...);//�����̊��I��1�ɂ܂Ƃ߂�(�����͍ŏ��ȊOGareki�I�u�W�F�N�g������)�@�@   /**/
	/**/   								      //�����F1�ځA    ����銢�I�̐��@�@                                       /**/
	/**/									        //2�ڈȍ~�A�����Gareki�I�u�W�F�N�g                                 /**/
	/**/   GarekiManager(vector<Gareki> gareki);                                                                          /**/
	/**/   ~GarekiManager();                                                                                              /**/
	/**/                                                                                                                  /**/
	/**/   void SetGareki(int n, ...);//GarekiManager(int gareki_num, ...);�Ɠ���                                         /**/
	/**/   void SetGareki(vector<Gareki> gareki);                                                                         /**/
	/**/   void AddGareki(Gareki gareki);//���I��ǉ�                                                                     /**/
	/**/                                                                                                                  /**/
	////------------------------------------------------------------------------------------------------------------------////


	////------ �����[�v���s������� ------------////
	/**/                                        /**/
	/**/   void Update();//�X�V                 /**/
	/**/   void Update(GarekiManager* gareki);  /**/
	/**/   void Draw();//�`��                   /**/
	/**/                                        /**/
	////----------------------------------------////


	//--------------- ���I�̔j�� -----------------------------------------------//// 
	/**/                                                                        /**/
	/**/   bool BreakBlock(int x, int y);//���W(x,y)�ɂ���u���b�N1��j��     /**/
	/**/   bool BreakGareki(int x, int y);//���W(x,y)�ɂ��銢�I1��j��        /**/
	/**/                                                                        /**/
	////------------------------------------------------------------------------////

	int GetY(unsigned int n);
	int GetX(unsigned int n);
};

