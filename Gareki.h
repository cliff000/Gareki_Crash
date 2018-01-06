#pragma once
#include<vector>
#include<unordered_map>
#include "Block.h"


#define BLOCK_SIZE 32
#define STAGE_BOTTOM 480
#define GAREKI_EDGE_W 2
#define GAREKI_EDGE_COLOR 0xffffff

#define NON_BLOCK -1
#define NORMAL_BLOCK 0

#define SB SetBlock
#define SP SetPoint

using namespace std;
class Gareki
{
	unordered_map<int, Block*> block;
	double x = 0, y = 0, vy = 0, ay = 0.2;
	int w = 0, h = 0;
	void Igo2(int i, int j, int** hairetsu);//Igo()����Ă΂��


public:
	
	////------------------- ���I�����R���X�g���N�^�A�֐� --------------------------------------////
	/**/                                                                                         /**/
	/**/   Gareki();                                                                             /**/
	/**/   Gareki(int block_num, ...); //�u���b�N���Z�b�g�A���I�����@�@�@�@                    /**/
	/**/                               //�����F1�ځA    �Z�b�g����u���b�N�̐��@�@             /**/
	/**/                                     //2�ڈȍ~�A�Z�b�g����u���b�N�̍��W               /**/
	/**/   Gareki(vector<int> block, int x = 0, int y = 0);                                      /**/
	/**/   Gareki(vector<vector<int>> block, int x = 0, int y = 0);                              /**/
	/**/   Gareki(Gareki* gareki); //�R�s�[�R���X�g���N�^                                        /**/
    /**/                                                                                         /**/
	/**/   void SetBlock(int block_num, ...); //Gareki(int block_num, ...);�Ɠ���                /**/
	/**/   void SetBlock(vector<int> block, int x = 0, int y = 0);                               /**/
	/**/   void SetBlock(vector<vector<int>> block, int x = 0, int y = 0);                       /**/
	/**/   void AddBlock(int block);                                                             /**/
	/**/   inline void SetX(int x) { this->x = x * BLOCK_SIZE; } //X���W���Z�b�g                 /**/
	/**/   inline void SetY(int y) { this->y = y * BLOCK_SIZE; } //Y���W���Z�b�g                 /**/
	/**/   inline void SetPoint(int x, int y) { SetX(x);  SetY(y); } //���W���Z�b�g              /**/
	/**/                                                                                         /**/
	////-----------------------------------------------------------------------------------------////


	////---------------- ��{�I��GarekiManager�ȊO����Ă΂Ȃ����� --------------------------------////
	/**/                                                                                           /**/
	/**/   void Collision(Gareki* gareki);//�����̊��I�Ƃ̐ڐG����(�����ւ̏����͂Ȃ�)             /**/
	/**/   bool Break(int x, int y);//���W(x, y)�ɂ���u���b�N�j��                                 /**/
	/**/		        		   //�߂�l�F���j������true�A����ȊO��false��Ԃ�       �@�@�@�@�@/**/
	/**/   void Update();//�X�V                                                                    /**/
	/**/   void Draw();//�`��                                                                      /**/
	/**/   Gareki* Igo();//���I���������Ă邩����A����������@�[���D��T���H                      /**/
	/**/				 //�߂�l�F�����������I                                                    /**/
	/**/   int GetSize() { return block.size(); } //���I�̑傫��(�u���b�N�̐�)���擾               /**/
	/**/                                                                                           /**/
	////-------------------------------------------------------------------------------------------////


	////----------------- �O����͂��܂�Ă΂Ȃ���� ----------------------------------------------////
	/**/                                                                                           /**/
	/**/   ~Gareki();                                                                              /**/
	/**/                                                                                           /**/
	/**/   inline int GetX() { return (int)x; } //X���W���擾                                      /**/
	/**/   inline int GetY() { return (int)y; } //Y���W���擾                                      /**/
	/**/   void SetH(); //�������Z�b�g                                                             /**/
	/**/   void SetW(); //�����Z�b�g                                                               /**/
    /**/                                                                                           /**/
	////-------------------------------------------------------------------------------------------////
};