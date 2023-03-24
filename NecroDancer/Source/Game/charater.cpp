#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"
#include "img_path.h"

character::character(int _HP, vector<vector<string>> files, COLORREF color)
{
	HP = _HP;
	for (int i = 0; i < 2; i++)
	{
		img[i].LoadBitmapByString(files[i], color);
		img[i].SetAnimation(120, false);
	}
	is_faceright = true;
}

void character::set_position_camera(int camera_x, int camera_y)
{
	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(camera_x * 60, camera_y * 60 - 10);
}

void character::set_position_map(int _x, int _y)
{
	map_x = _x;
	map_y = _y;
}

int character::get_x()
{
	return map_x;
}

int character::get_y()
{
	return map_y;
}

void character::moving()
{
	is_moving = true;
}

bool character::get_is_moving()
{
	return is_moving;
}

bool character::get_faceright() {
	return is_faceright;
}

void character::set_move_position(int position)
{
	move_position = position;
}

void character::set_faceright(bool _is_faceright) {
	is_faceright = _is_faceright;
}

void character::show()
{	
	img[is_faceright].ShowBitmap();
}


void main_character::move()
{
	if (is_falling == false) 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8); 
		if (img[is_faceright].GetTop() <= move_position * 60 - 40)
			is_falling = true;
	}
	else 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8); 
		if (img[is_faceright].GetTop() >= move_position * 60-10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}

void monster::move()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8);
		if (img[is_faceright].GetTop() <= move_position * 60 - 40)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8);
		if (img[is_faceright].GetTop() >= move_position * 60 - 10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}


