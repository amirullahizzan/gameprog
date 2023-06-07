#include "Main.h"
#include "Game.h"

//	�v���C���[�摜�p�̕ϐ�
int player_image;
//	�v���C���[���W
int player_x;
int player_y;

int mouse_x;
int mouse_y;
int textboundary;

//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	//	�v���C���[�摜�̓ǂݍ���
	player_image = LoadGraph( "data/player.bmp" );
	//	�Ƃ肠�����̏������W
	player_x = 100;
	player_y = 200;
	mouse_x = 0;
	mouse_y = 0;
	textboundary = 50;
}

int textoffset_y = 0;
int textoffset_x = 0;

void TextDisplayHandler()
{
	textoffset_y = 0;
	textoffset_x = 0;
	if (mouse_x > SCREEN_W - 100)
	{
		textoffset_x = 55;
	}
	if (mouse_y < 0+100)
	{
		textoffset_y = 150;
	}
}

void PlayerPosHandler()
{
	GetMousePoint(&mouse_x, &mouse_y);
	player_x = mouse_x - 50;
	player_y = mouse_y - 50;

	if (mouse_x < 0 + 50)
	{
		player_x = 0;
	}
	if (mouse_x > SCREEN_W - 50)
	{
		player_x = SCREEN_W - 100;
	}

	if (mouse_y < 0 + 50)
	{
		player_y = 0;
	}
	if (mouse_y > SCREEN_H - 50)
	{
		player_y = SCREEN_H - 100;
	}
}

void ResetPos()
{
	player_x = SCREEN_W / 2 - 50;
	player_y = SCREEN_H / 2 - 50;
	textoffset_y = 0;
	textoffset_x = 0;
}


void GameUpdate()
{

	if (CheckMouseInput(0x0001))
	{
		TextDisplayHandler();
		PlayerPosHandler();
	}
	if (CheckMouseInput(0x0002))
	{
		ResetPos();
	}
}
//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------

void GameRender()
{
	//	�v���C���[�摜�̕`��
	DrawGraph( player_x, player_y, player_image, TRUE );
	DrawString(player_x-2 -textoffset_x, player_y-40+textoffset_y, "�v���C���[���W", GetColor(120, 230, 255), 0);
	DrawFormatString(player_x - textoffset_x, player_y-20 + textoffset_y, GetColor(120, 230, 255), "X = %3d , Y = %3d", player_x, player_y);


	DrawString( 20, 20, "�}�E�X�{�^���������F�v���C���[�摜�̒��S���}�E�X���W�ɗ���悤��", GetColor( 255, 255, 0 ) );
	DrawString( 20, 40, "�v���C���[���W�𕶎���ŕ`��i�v���C���[�̏��Ɂj", GetColor( 255, 255, 0 ) );
	DrawString( 20, 60, "�v���C���[�摜�̊O�ɍs���Ȃ��悤�ɂ��Ă݂�", GetColor(120, 230, 255));
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
	DeleteGraph( player_image );
}
