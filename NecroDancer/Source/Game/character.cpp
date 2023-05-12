#include "stdafx.h"
#include "character.h"

character::character(int _HP,int _damage, vector<vector<string>> files, COLORREF color)
{
	HP = _HP;
	damage = _damage;
	for (int i = 0; i < 2; i++)
	{
		img.push_back(game_framework::CMovingBitmap{});
		img[i].LoadBitmapByString(files[i],RGB(0,0,0));
		img[i].SetAnimation(100, false);
	}
	is_faceright = true;
}

//getter
int character::get_map_x()
{
	return map_x;
}

int character::get_map_y()
{
	return map_y;
}

int character::get_hp()
{
	return HP;
}

int character::get_damage()
{
	return damage;
}

bool character::get_faceright() 
{
	return is_faceright;
}

int character::get_move_direction()
{
	return move_direction[move_step % 8];
}
//---------------------------------------------------------
//setter
void character::set_map_position(int x, int y)
{
	map_x = x;
	map_y = y;
}

void character::set_show_position(int x, int y)
{
	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(x * 60, y * 60 - 10);
}

void character::set_faceright(bool _is_faceright)
{
	is_faceright = _is_faceright;
}

void character::lose_HP(int damage)
{
	HP -= damage;
}

void character::show()
{	
	img[is_faceright].ShowBitmap();
}

void character::move_step_increase()
{
	move_step++;
}
