#pragma once

//-------------------------------------//
//     Gareki�N���X����Ăяo���̂�    //
//     ���̐l�͎g��Ȃ��N���X          //
//-------------------------------------//

class Block
{
protected:
	int hp = 1;//�u���b�N�̑ϋv�l
public:
	Block();
	virtual bool Break();//�߂�l�F�󂳂ꂽ��true�A����ȊO��false
	virtual void Draw(int x, int y);//�`��

	static Block* Int_to_Block(int num); //int���u���b�N�ɕϊ�
};

class ClearBlock : public Block
{
public:
	ClearBlock() { hp = 0; };
	bool Break() { return false; };
};

