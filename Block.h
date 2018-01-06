#pragma once

//-------------------------------------//
//     Garekiクラスから呼び出すのみ    //
//     他の人は使わないクラス          //
//-------------------------------------//

class Block
{
protected:
	int hp = 1;//ブロックの耐久値
public:
	Block();
	virtual bool Break();//戻り値：壊されたらtrue、それ以外はfalse
	virtual void Draw(int x, int y);//描画

	static Block* Int_to_Block(int num); //intをブロックに変換
};

class ClearBlock : public Block
{
public:
	ClearBlock() { hp = 0; };
	bool Break() { return false; };
};

