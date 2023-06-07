#include "Main.h"
#include "Game.h"
int leftclickcount;
int rightclickcount;
int mousex;
int mousey;

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	leftclickcount = 0;
	rightclickcount = 0;
	mousex = 0;
	mousey = 0;
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
	if (PushMouseInput(0x0001))
	{
		leftclickcount++;
	}
	if (CheckMouseInput(0x0002))
	{
		rightclickcount++;
	}

	GetMousePoint(&mousex, &mousey);
		//come from the same functions
	//mousex = GetMouseX(); 
	//mousey = GetMouseY();
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------


void GameRender()
{
	DrawString( 20, 20, "�}�E�X���𕶎���ŕ\��", GetColor( 255, 255, 255 ) );
	DrawFormatString( 20, 20+20, GetColor( 255, 255, 255 ), "Get left click on push = %d", leftclickcount );
	DrawFormatString( 20, 20+40, GetColor( 255, 255, 255 ), "Get right click on hold = %d", rightclickcount );
	//print two value in one line
	//DrawFormatString(20, 20 + 80, GetColor(255, 255, 0), "�}�E�X X,Y ���W = %d X , %d Y", mousex, mousey);
	//%4d stores a 4 digit empty space inside the string when the digit goes down. Including negative signs
	DrawFormatString(20, 20 + 80, GetColor(255, 255, 0), "�}�E�X X,Y ���W = %4d X , %4d Y", mousex, mousey);

}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
}
