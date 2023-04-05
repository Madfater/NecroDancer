#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"

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

int character::get_camera_x()
{
	return camera_x;
}

int character::get_camera_y()
{
	return camera_y;
}

bool character::get_is_moving()
{
	return is_moving;
}

bool character::get_faceright() 
{
	return is_faceright;
}

int character::get_move_direction()
{
	return move_direction[move_step % 4];
}
//---------------------------------------------------------
//setter
void character::set_map_position(int x, int y)
{
	map_x = x;
	map_y = y;
}

void character::set_moving()
{
	is_moving = true;
}

void character::set_camera_position(int x, int y)
{
	camera_x = x;
	camera_y = y;
	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(camera_x * 60, camera_y * 60 - 10);
}

void character::set_faceright(bool _is_faceright)
{
	is_faceright = _is_faceright;
}
//---------------------------------------------------------
//action
void character::attack(character* c)
{
	c->lose_HP(damage);
}

void character::lose_HP(int damage)
{
	HP -= damage;
}

void character::show()
{	
	img[is_faceright].ShowBitmap();
}

void character::move_animation()
{
	if (is_falling == false) 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8); 
		if (img[is_faceright].GetTop() <= camera_y * 60 - 40)
			is_falling = true;
	}
	else 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8); 
		if (img[is_faceright].GetTop() >= camera_y * 60-10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}
void character::move_step_increase()
{
	move_step++;
}
//---------------------------------------------------------
//bat override
//---------------------------------------------------------
//slime override
//---------------------------------------------------------
//dragon override
void dragon::set_camera_position(int x, int y)
{
	camera_x = x;
	camera_y = y;
	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(camera_x * 60 - 92, camera_y * 60 - 78);
}

int dragon::get_move_direction()
{
	return 0;
}

void dragon::move_animation()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8);
		if (img[is_faceright].GetTop() <= camera_y * 60 - 78 - 40)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8);
		if (img[is_faceright].GetTop() >= camera_y * 60 - 78 - 10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}
//---------------------------------------------------------