#pragma once
#include<vector>
#include "Gareki.h"

class GarekiManager
{
	std::vector< Gareki> gareki;

public:
	////----------- GarekiManagerを作るのに使うコンストラクタ、関数 ------------------------------------------------------/**/
	/**/                                                                                                                  /**/
	/**/   GarekiManager();                                                                                               /**/
	/**/   GarekiManager(int gareki_num, ...);//複数の瓦礫を1つにまとめる(引数は最初以外Garekiオブジェクトを入れる)　　   /**/
	/**/   								      //引数：1つ目、    入れる瓦礫の数　　                                       /**/
	/**/									        //2つ目以降、入れるGarekiオブジェクト                                 /**/
	/**/   GarekiManager(vector<Gareki> gareki);                                                                          /**/
	/**/   ~GarekiManager();                                                                                              /**/
	/**/                                                                                                                  /**/
	/**/   void SetGareki(int n, ...);//GarekiManager(int gareki_num, ...);と同じ                                         /**/
	/**/   void SetGareki(vector<Gareki> gareki);                                                                         /**/
	/**/   void AddGareki(Gareki gareki);//瓦礫を追加                                                                     /**/
	/**/                                                                                                                  /**/
	////------------------------------------------------------------------------------------------------------------------////


	////------ 毎ループ実行するもの ------------////
	/**/                                        /**/
	/**/   void Update();//更新                 /**/
	/**/   void Update(GarekiManager* gareki);  /**/
	/**/   void Draw();//描画                   /**/
	/**/                                        /**/
	////----------------------------------------////


	//--------------- 瓦礫の破壊 -----------------------------------------------//// 
	/**/                                                                        /**/
	/**/   bool BreakBlock(int x, int y);//座標(x,y)にあるブロック1つを破壊     /**/
	/**/   bool BreakGareki(int x, int y);//座標(x,y)にある瓦礫1つを破壊        /**/
	/**/                                                                        /**/
	////------------------------------------------------------------------------////

	int GetY(unsigned int n);
	int GetX(unsigned int n);
};

