#include "stdafx.h"
#include "monster.h"

Monster::Monster(int _HP,int _damage, vector<vector<string>> files, COLORREF color)
{
	full_HP = _HP;
	HP = _HP;
	damage = _damage;
	is_faceright = true;

	for (int i = 0; i < 2; i++)
	{
		img.push_back(game_framework::CMovingBitmap{});
		img[i].LoadBitmapByString(files[i],RGB(0,0,0));
		img[i].SetAnimation(100, false);
	}
}

bool Monster::get_faceright() 
{
	return is_faceright;
}

bool Monster::get_is_moving()
{
	return is_moving;
}
bool Monster::get_is_damaged()
{
	return is_damaged;
}

int Monster::get_hp()
{
	return HP;
}

int Monster::get_damage()
{
	return damage;
}

int Monster::get_x()
{
	return x;
}

int Monster::get_y()
{
	return y;
}

int Monster::get_camera_x()
{
	return camera_x;
}

int Monster::get_camera_y()
{
	return camera_y;
}

void Monster::set_position(int _x, int _y, int player_x, int player_y)
{
	camera_x = _x - player_x + 7;
	camera_y = _y - player_y + 4;
	x = _x;
	y = _y;

	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(camera_x * 60, camera_y * 60 - 10);
}

void Monster::set_faceright(bool _is_faceright)
{
	is_faceright = _is_faceright;
}

void Monster::set_is_moving()
{
	is_moving = true;
}

void Monster::lose_HP(int damage)
{
	HP -= damage;
	is_damaged = true;
	hearts.clear();
	for (int i = 0; i < HP; i++)
	{
		hearts.push_back(game_framework::CMovingBitmap{});
		hearts[i].LoadBitmapByString({ img_health_temp_full }, RGB(0, 0, 0));
	}
	for (int i = HP; i < full_HP; i++)
	{
		hearts.push_back(game_framework::CMovingBitmap{});
		hearts[i].LoadBitmapByString({ img_health_temp_empty }, RGB(0, 0, 0));
	}
	for (int i = 0; i < full_HP; i++) {
		hearts[i].SetTopLeft(camera_x * 60 + 30 * i - full_HP/2*30 +15, camera_y * 60 - 30);
	}
}

void Monster::move_animation()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 5);
		if (img[is_faceright].GetTop() <= camera_y * 60 - 40)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 5);
		if (img[is_faceright].GetTop() >= camera_y * 60 - 10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}

void Monster::show()
{			
	img[is_faceright].ShowBitmap();
}

void Monster::show_hp()
{
	for (int i = 0; i < full_HP; i++)
	{
		hearts[i].SetTopLeft(camera_x * 60 + 30 * i - full_HP / 2 * 30 + 15, camera_y * 60 - 30);
		hearts[i].ShowBitmap();
	}
}

int bat::move(int _x, int _y)
{
	return bat_step[(step_cnt++) % bat_step.size()] ;
}

int slime::move(int _x, int _y)
{
	return slime_step[(step_cnt++) % slime_step.size()] ;
}