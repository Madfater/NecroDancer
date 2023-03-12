#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"

character::character(int _HP, int _x, int _y,vector<string> files, COLORREF color)
{
	HP = _HP;
	img.LoadBitmapByString(files,color);
	img.SetTopLeft(_x*60, _y*60-30);
	img.SetAnimation(120, false);
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

void character::show()
{
	img.ShowBitmap();
}

bool main_character::move()
{
	if (is_falling == false) 
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() - 8); //控制上升速度
		if (img.GetTop() <= y * 60 - 60) //跳躍高度
			is_falling = true;;
	}
	else 
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() + 8); //控制下降速度
		if (img.GetTop() >= y * 60 - 30)//下降高度
		{
			is_falling = false;
			return false;
		}
	}
	return true;
}