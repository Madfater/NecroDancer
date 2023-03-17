#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"

character::character(int _HP, int _x, int _y,bool _is_faceright,vector<vector<string>> files, COLORREF color)
{
	HP = _HP;
	for (int i = 0; i < 2; i++)
	{
		img[i].LoadBitmapByString(files[i], color);
		img[i].SetTopLeft(_x * 60, _y * 60 - 30);
		img[i].SetAnimation(120, false);
	}
	is_faceright = _is_faceright;
	x = _x;
	y = _y;
}

int character::get_x()
{
	return x;
}

int character::get_y()
{
	return y;
}
bool character::get_faceright() {
	return is_faceright;
}
void character::set_faceright(bool _is_faceright) {
	is_faceright = _is_faceright;
}

void character::show()
{	
	img[is_faceright].ShowBitmap();
}

bool main_character::move()
{
	if (is_falling == false) 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8); //控制上升速度
		if (img[is_faceright].GetTop() <= y * 60 - 60) //跳躍高度
			is_falling = true;
	}
	else 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8); //控制下降速度
		if (img[is_faceright].GetTop() >= y * 60 - 30)//下降高度
		{
			is_falling = false;
			return false;
		}
	}
	return true;
}