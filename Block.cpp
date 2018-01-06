#include "Block.h"
#include "Dxlib.h"
#include "Gareki.h"


Block::Block()
{
}
bool Block::Break() {
	hp--;
	if (hp <= 0)
		return true;
	else
		return false;
}
void Block::Draw(int _x, int _y) {
	if (hp > 0)
		DrawBox(_x, _y, _x + BLOCK_SIZE, _y + BLOCK_SIZE, 0xdd0000, TRUE);
}

Block* Block::Int_to_Block(int num) {
	switch (num) {
	case 0:
		return new Block();
	case 1:
		return new Block();
	case 9:
		return new ClearBlock();
	}
}