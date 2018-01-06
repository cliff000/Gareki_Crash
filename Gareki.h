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
	void Igo2(int i, int j, int** hairetsu);//Igo()から呼ばれる


public:
	
	////------------------- 瓦礫を作るコンストラクタ、関数 --------------------------------------////
	/**/                                                                                         /**/
	/**/   Gareki();                                                                             /**/
	/**/   Gareki(int block_num, ...); //ブロックをセット、瓦礫を作る　　　　                    /**/
	/**/                               //引数：1つ目、    セットするブロックの数　　             /**/
	/**/                                     //2つ目以降、セットするブロックの座標               /**/
	/**/   Gareki(vector<int> block, int x = 0, int y = 0);                                      /**/
	/**/   Gareki(vector<vector<int>> block, int x = 0, int y = 0);                              /**/
	/**/   Gareki(Gareki* gareki); //コピーコンストラクタ                                        /**/
    /**/                                                                                         /**/
	/**/   void SetBlock(int block_num, ...); //Gareki(int block_num, ...);と同じ                /**/
	/**/   void SetBlock(vector<int> block, int x = 0, int y = 0);                               /**/
	/**/   void SetBlock(vector<vector<int>> block, int x = 0, int y = 0);                       /**/
	/**/   void AddBlock(int block);                                                             /**/
	/**/   inline void SetX(int x) { this->x = x * BLOCK_SIZE; } //X座標をセット                 /**/
	/**/   inline void SetY(int y) { this->y = y * BLOCK_SIZE; } //Y座標をセット                 /**/
	/**/   inline void SetPoint(int x, int y) { SetX(x);  SetY(y); } //座標をセット              /**/
	/**/                                                                                         /**/
	////-----------------------------------------------------------------------------------------////


	////---------------- 基本的にGarekiManager以外から呼ばないもの --------------------------------////
	/**/                                                                                           /**/
	/**/   void Collision(Gareki* gareki);//引数の瓦礫との接触処理(引数への処理はない)             /**/
	/**/   bool Break(int x, int y);//座標(x, y)にあるブロック破壊                                 /**/
	/**/		        		   //戻り値：爆破したらtrue、それ以外はfalseを返す       　　　　　/**/
	/**/   void Update();//更新                                                                    /**/
	/**/   void Draw();//描画                                                                      /**/
	/**/   Gareki* Igo();//瓦礫が分離してるか判定、分離させる　深さ優先探索？                      /**/
	/**/				 //戻り値：分離した瓦礫                                                    /**/
	/**/   int GetSize() { return block.size(); } //瓦礫の大きさ(ブロックの数)を取得               /**/
	/**/                                                                                           /**/
	////-------------------------------------------------------------------------------------------////


	////----------------- 外からはあまり呼ばないやつ ----------------------------------------------////
	/**/                                                                                           /**/
	/**/   ~Gareki();                                                                              /**/
	/**/                                                                                           /**/
	/**/   inline int GetX() { return (int)x; } //X座標を取得                                      /**/
	/**/   inline int GetY() { return (int)y; } //Y座標を取得                                      /**/
	/**/   void SetH(); //高さをセット                                                             /**/
	/**/   void SetW(); //幅をセット                                                               /**/
    /**/                                                                                           /**/
	////-------------------------------------------------------------------------------------------////
};